params ["_plane","_Engine_State"];

if (alive _plane and _Engine_State) then {
  if !(_plane getVariable ["AAE_Find_Engine",false]) then {
    call AAE_fnc_InitEH
  };

  _Engine_Offsets = _plane getVariable "AAE_veh_Engine_Offset";
  _Exhausts_count = _plane getVariable "AAE_Exhausts_Count";
  _Exhausts_POS = _plane getVariable "AAE_Exhaust_POS";
  _plane setvariable ["AAE_Vapor_toggle",vapor_sdr + random 20];

  GForces_Filter = ppEffectCreate ["ColorCorrections", 6500];
  GForces_Filter ppEffectForceInNVG true;
  GForces_Filter ppEffectAdjust [1,1,0,[0,0,0,0],[0,0,0,0],[1,1,1,1],[10,10,0,0,0,0.1,0.5]];
  GForces_Filter ppEffectCommit 0.4;

  if (_plane iskindof "Plane") then {
    GForces_Filter ppEffectEnable true;
  };

  //Wingspan
  _Wingspan = _plane getVariable "AAE_Wingspan";

  //Have Burner
  _have_AB = _plane getVariable ["AAE_Have_AB",false];

  _AAE_handler_Engine = addMissionEventHandler ["EachFrame", {
    if !(isGamePaused) then {
      _plane = _thisArgs # 0;
      _planePlayer = cameraOn;

      _plane setVariable ["AAE_Actived", true];

      //Engine
      _engine_offsets = _thisArgs # 1;
      _Exhausts_count = _thisArgs # 2;
      _Exhausts_POS =_thisArgs # 3;

      //Wing Span
      _Wingspan = _thisArgs # 4;

      //Have AB
      _have_AB = _thisArgs # 5;

      //POS
      _AGL_POS = getPos _plane;
      _ASL_POS = getPosASL _plane;
      _ATL_POS = getPosATL _plane;
      _ASLW_POS = getPosASLW _plane;

      //Speeds
      _velocity = velocity _plane;
      _speed = speed _plane;
      _speed_Player = speed _planePlayer;

      //Temperature
      _air_Temp = ambientTemperature # 0;

      //Vapor
      _Vapor_Activated = _plane getVariable ["AAE_Vapor_Activated", false];

      if (vapor_sim_fn) then {
        Vapor_sim = (_air_Temp - (((_ASL_POS # 2) / 100) * 0.98)) <= -20;
      };

      //Ground
      _Ground_Activated = _plane getVariable ["AAE_Ground_Activated", false];
      _pitchBank = _plane call BIS_fnc_getPitchBank;

      //Burner
      _Burner_Activated = _plane getVariable ["AAE_BurnerActived",false];

      //Source
      _plane_thrust = (_plane getSoundController "thrust") > 0.9;

      if (_plane getVariable ["AAE_Have_AB_Source",false]) then {
        _plane_thrust = (
          _plane animationSourcePhase (_plane getVariable "AAE_AB_Source") > 0.9 or
          _plane animationphase (_plane getVariable "AAE_AB_Source") > 0.9
        );
      };

      //-Sonic Settings
      if (sonicboom_tmp_fn) then {
        AAE_SpeedSet = (331+(0.6*_air_Temp))*3.6; // 1195 as Default
        AAE_sonicboom_speed_01 = AAE_SpeedSet - 20;
        AAE_sonicboom_speed_02 = AAE_SpeedSet - 10;
        AAE_sonicboom_speed_03 = AAE_SpeedSet + 10;
      };

      call AAE_fnc_Main_process;
    };
  },[
    _plane,
    _Engine_Offsets,
    _Exhausts_count,
    _Exhausts_POS,
    _Wingspan,
    _have_AB
  ]];
  _plane setVariable ["AAE_EachFrame_Engine", _AAE_handler_Engine];
} else {
  call AAE_fnc_DeleteEH;
};
