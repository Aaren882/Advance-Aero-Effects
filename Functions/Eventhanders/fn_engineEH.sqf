params ["_plane","_Engine_State"];

if !(_plane isKindOf "plane") exitWith {};
HaveACE = isClass (configFile >> "CfgPatches" >> "ace_main");
if (_Engine_State) then {
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

  //Gound Effect
  Ground_Paricles = [];

  //Sonic Settings
  _SpeedSet = 1195;
  _sonicboom_speed_01 = _SpeedSet - 20;//1175
  _sonicboom_speed_02 = _SpeedSet - 10;//1185
  _sonicboom_speed_03 = _SpeedSet + 10;//1205

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

      //Engine
      _engines = _thisArgs # 1;
      _engine1 = _engines # 0;
      _engine2 = _engines # 1;

      //SonicBoom
      _sonicboom_Setting = _thisArgs # 2;
      _sonicboom_speed_01 = _sonicboom_Setting # 0;
      _sonicboom_speed_02 = _sonicboom_Setting # 1;
      _sonicboom_speed_03 = _sonicboom_Setting # 2;

      //BackUp objects
      /* _objects = _thisArgs # 3;
      _source00 = _objects # 0;
      _source01 = _objects # 1; */

      //Turbulent Settings
      _source00 = _plane modelToWorldVisual [(_engine1 # 0), (_engine1 # 1)+(-10-turbulent_sdr),(_engine1 # 2)];
      _source01 = _plane modelToWorldVisual [(_engine2 # 0), (_engine2 # 1)+(-10-turbulent_sdr),(_engine2 # 2)];

      //POS
      _AGL_POS= _plane getVariable ["AAE_veh_AGL", (getPos _plane)];
      _ASL_POS= _plane getVariable ["AAE_veh_ASL", (getPosASL _plane)];
      _ATL_POS= _plane getVariable ["AAE_veh_ATL", (getPosATL _plane)];
      _ASLW_POS= _plane getVariable ["AAE_veh_ASLW", (getPosASLW _plane)];

      //Speeds
      _velocity = velocity _plane;
      _speed = speed _plane;

      //Vars
      _Vapor_Activated = _plane getVariable ["AAE_Vapor_Activated", false];
      _Ground_Activated = _plane getVariable ["AAE_Ground_Activated", false];
      _Sonic_MC = _plane getVariable ["SonicBoom_Main_Activated", false];
      _Sonic_SC = _plane getVariable ["SonicBoom_Second_Activated", false];

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
      if ((_ASL_POS # 2 > (vapor_sdr + random 20)) and (vapor_fn) and (alive _plane)) then {
        if (!_Vapor_Activated) then {
          [_plane,_engine1,_engine2,_AGL_POS,_ASL_POS] Spawn AAE_fnc_vapor;
          _plane setVariable ["AAE_Vapor_Activated", true];
        };
      } else {
        _plane setVariable ["AAE_Vapor_Activated", false];
      };

      //Camshake
      if ((isTouchingGround player) and (_speed >=150) and !(player in _plane) and (camshake_fn)) then {
        [_plane] Spawn AAE_fnc_camshake;
      };

      //Sonic
      if (sonicboom_fn) then {
        if ((_speed >= _sonicboom_speed_01) and (_speed <= _sonicboom_speed_02)) then {
          if (!_Sonic_SC) then {
            [_plane,_velocity] Spawn AAE_fnc_sonicboom2;
            _plane setVariable ["SonicBoom_Second_Activated", true];
          };
        } else {
          _plane setVariable ["SonicBoom_Second_Activated", false];
        };

        if ((_speed > _sonicboom_speed_02) and (_speed <= _sonicboom_speed_03)) then {
          if (!_Sonic_MC) then {
            [_plane,_velocity] Spawn AAE_fnc_sonicboom;
            _plane setVariable ["SonicBoom_Main_Activated", true];
          };
        } else {
          _plane setVariable ["SonicBoom_Main_Activated", false];
        };
      };

      //Ground
      if (!(isTouchingGround _plane) and ((_AGL_POS # 2) < groundP_sdr) and (ground_fn)) then {
        [_plane,_engine1,_engine2,_AGL_POS,_ASL_POS,_ATL_POS,_ASLW_POS,_velocity,_speed] Spawn AAE_fnc_ground;
        _plane setVariable ["AAE_Ground_Activated", true];
      } else {
        _plane setVariable ["AAE_Ground_Activated", false];
      };
    };
  },
  [
    _plane,
    [_Engine_Offset1,_Engine_Offset2],
    [_sonicboom_speed_01,_sonicboom_speed_02,_sonicboom_speed_03]
  ]];
} else {
  if (_plane getVariable ["AAE_Actived", false]) then {
    removeMissionEventHandler ["EachFrame", AAE_handler_Engine];
    GForces_Filter ppEffectEnable false;
    ppEffectDestroy GForces_Filter;
    _plane setVariable ["AAE_Actived", false];
  };
};
