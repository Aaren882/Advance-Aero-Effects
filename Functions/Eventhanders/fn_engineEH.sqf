params ["_plane","_Engine_State"];

[_plane] spawn AAE_fnc_Ground_counter;

if !(_plane isKindOf "plane") exitWith {};

HaveACE = isClass (configFile >> "CfgPatches" >> "ace_main");
if (_Engine_State and (alive _plane)) then {
  _engine1_Name = "HitEngine";
  _engine2_Name = "HitEngine2";

  _engine1 = _plane selectionPosition _engine1_Name;
  _engine2 = _plane selectionPosition _engine2_Name;

  _Engine_Offset1= _plane getVariable ["AAE_veh_Engine_Offset1", _engine1];
  _Engine_Offset2= _plane getVariable ["AAE_veh_Engine_Offset2", _engine2];

  //ACE Vars
  GForces = [];
  GForces resize 30;
  GForces = GForces apply {1};
  GForces_Index = 0;
  lastUpdateTime = 0;
  oldVel = [0,0,0];

  //Sonic Settings
  AAE_SpeedSet = 1195;
  AAE_sonicboom_speed_01 = AAE_SpeedSet - 20;//1175
  AAE_sonicboom_speed_02 = AAE_SpeedSet - 10;//1185
  AAE_sonicboom_speed_03 = AAE_SpeedSet + 10;//1205

  GForces_Filter = ppEffectCreate ["ColorCorrections", 6500];
  GForces_Filter ppEffectForceInNVG true;
  GForces_Filter ppEffectAdjust [1,1,0,[0,0,0,0],[0,0,0,0],[1,1,1,1],[10,10,0,0,0,0.1,0.5]];
  GForces_Filter ppEffectCommit 0.4;

  if (player in _plane) then {
    GForces_Filter ppEffectEnable true;
  };

  AAE_handler_Engine = addMissionEventHandler ["EachFrame", {
    if !(isGamePaused) then {
      _plane = _thisArgs # 0;
      _planePlayer = vehicle player;

      _plane setVariable ["AAE_Actived", true];
      _plane setVariable ["AAE_EachFrame_Handler", AAE_handler_Engine];

      //Engine
      _engines = _thisArgs # 1;
      _engine1 = _engines # 0;
      _engine2 = _engines # 1;

      //Turbulent Settings
      _source00 = _plane modelToWorldVisual [(_engine1 # 0), (_engine1 # 1)+(-10-turbulent_sdr),(_engine1 # 2)];
      _source01 = _plane modelToWorldVisual [(_engine2 # 0), (_engine2 # 1)+(-10-turbulent_sdr),(_engine2 # 2)];

      //POS
      _AGL_POS = getPos _plane;
      _ASL_POS = getPosASL _plane;
      _ATL_POS = getPosATL _plane;
      _ASLW_POS = getPosASLW _plane;

      //Speeds
      _velocity = velocity _plane;
      _speed = speed _plane;

      //Vapor
      _Vapor_Activated = _plane getVariable ["AAE_Vapor_Activated", false];

      //Ground
      _Ground_Activated = _plane getVariable ["AAE_Ground_Activated", false];

      //Player only
      if (_planePlayer isKindOf "plane") then {
        //Gear Factor
        if (!(isTouchingGround _plane) and (cameraView == "internal") and (gear_fn)) then {
          [_planePlayer,(speed _planePlayer)] Spawn AAE_fnc_gearFactor;
        };

        //Turbulent Plane       //It's Flying
        if (((speed _planePlayer) > 200) and !(isTouchingGround _planePlayer) and (turbulentP_fn)) then {
          [_planePlayer,_source00,_source01] Spawn AAE_fnc_turbulent;
        };

        //Turbulent World
        if (!(isTouchingGround _planePlayer) and (cameraView == "internal") and (turbulentS_fn)) then {
          [_planePlayer,((getpos _planePlayer) # 2),(speed _planePlayer)] Spawn AAE_fnc_turbulentW;
        };

        //Taxing
        if ((isTouchingGround _planePlayer) and (cameraView == "internal") and (taxing_fn)) then {
          [_planePlayer,(speed _planePlayer)] Spawn AAE_fnc_taxing;
        };

        //GForces
        if !(isTouchingGround _planePlayer) then {
          [_planePlayer] Spawn AAE_fnc_gforces;
        };
      };

      //Vapor Trail
      if ((_ASL_POS # 2 > (vapor_sdr + random 20)) and (vapor_fn) and !(isNull _plane)) then {
        if (!_Vapor_Activated) then {
          [_plane,_engine1,_engine2] Spawn AAE_fnc_vapor;
          _plane setVariable ["AAE_Vapor_Activated", true];
        };
      } else {
        _plane setVariable ["AAE_Vapor_Activated", false];
      };

      //Camshake
      if ((isTouchingGround player) and (_speed >= 150) and !(player in _plane) and (camshake_fn)and !(isNull _plane)) then {
        [_plane] Spawn AAE_fnc_camshake;
      };

      //Sonic
      if (sonicboom_fn) then {
        [_plane,_velocity,_speed] Spawn AAE_fnc_sonicboom;
      };

      //Ground
      if (!(isTouchingGround _plane) and ((_AGL_POS # 2) < groundP_sdr) and (ground_fn) and !(isNull _plane)) then {
        _type = _plane getVariable ["AAE_Ground_Type","Default"];

        [_plane,_engine1,_engine2,_AGL_POS,_ASL_POS,_ATL_POS,_ASLW_POS,_velocity,_speed,_type] Spawn AAE_fnc_ground;
        _plane setVariable ["AAE_Ground_Activated", true];
      } else {
        _plane setVariable ["AAE_Ground_Activated", false];
      };
    };
  },
  [
    _plane,
    [_Engine_Offset1,_Engine_Offset2]
  ]];
} else {
  if (_plane getVariable ["AAE_Actived", false]) then {
    //Engine EH
    _plane setVariable ["AAE_Actived", false];
    //Loop Remove
    removeMissionEventHandler ["EachFrame", (_plane getVariable ["AAE_EachFrame_Handler", -1])];

    //G Forces
    GForces_Filter ppEffectEnable false;
    ppEffectDestroy GForces_Filter;

    //Vars
    _Vapor_Paricles = _plane getVariable ["AAE_Vapor_Paricles",[]];
    _Sonic_Paricles = _plane getVariable ["AAE_Sonic_Paricles",[]];
    _Ground_Paricles = _plane getVariable ["AAE_Ground_Paricles",[]];

    //Vapor
    _plane setVariable ["AAE_Vapor_Activated", false];
    if (count (_plane getVariable "AAE_Vapor_Paricles") > 0) then {
      {deleteVehicle _x} foreach _Vapor_Paricles;
  		_plane setVariable ["AAE_Vapor_Paricles", []];
  	};

    //SonicBoom
    _plane setVariable ["AAE_SonicBoom_Main_Activated", false];
    _plane setVariable ["AAE_SonicBoom_Small_Activated", false];
    _Sonic_source00 = _plane getVariable ["AAE_SonicBoom_Small_Particle",objNull];
    _Sonic_source01 = _plane getVariable ["AAE_SonicBoom_Main_Particle",objNull];

    //Ground
    _plane setVariable ["AAE_Ground_Type_Changed",false];
    _plane setVariable ["AAE_Ground_Activated", false];
    if (count _Ground_Paricles > 0) then {
      {deleteVehicle _x} foreach _Ground_Paricles;
  		_plane setVariable ["AAE_Ground_Paricles", []];
  	};
  };
};
