params ["_plane","_Engine_State"];

if (alive _plane and _Engine_State) then {
  _plane call AAE_fnc_InitEH;

  _Engine_Offsets = _plane getVariable "AAE_veh_Engine_Offset";
  _Exhausts_count = _plane getVariable "AAE_Exhausts_Count";
  _Exhausts_POS = _plane getVariable "AAE_Exhaust_POS";
  _plane setvariable ["AAE_Vapor_toggle",vapor_sdr + random 20];

  GForces_Filter = ppEffectCreate ["ColorCorrections", 6500];
  GForces_Filter ppEffectForceInNVG true;
  GForces_Filter ppEffectAdjust [1,1,0,[0,0,0,0],[0,0,0,0],[1,1,1,1],[10,10,0,0,0,0.1,0.5]];
  GForces_Filter ppEffectCommit 0.4;

  if (player in _plane) then {
    GForces_Filter ppEffectEnable true;
  };

  //Wingspan
  _Wingspan = _plane getVariable "AAE_Wingspan";
  _have_AB = _plane getVariable "AAE_Have_AB";

  AAE_handler_Engine = addMissionEventHandler ["EachFrame", {
    if !(isGamePaused) then {
      _plane = _thisArgs # 0;
      _planePlayer = vehicle player;

      _plane setVariable ["AAE_Actived", true];
      _plane setVariable ["AAE_EachFrame_Engine", AAE_handler_Engine];

      //Engine
      _engine_offsets = _thisArgs # 1;
      _Exhausts_count = _thisArgs # 2;
      _Exhausts_POS =_thisArgs # 3;

      _engine_offsets params [["_engine1",[0,0,0]],["_engine2",[0,0,0]],["_engine3",[0,0,0]],["_engine4",[0,0,0]]];

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

      //Vapor
      _Vapor_Activated = _plane getVariable ["AAE_Vapor_Activated", false];

      //Ground
      _Ground_Activated = _plane getVariable ["AAE_Ground_Activated", false];
      _pitchBank = _plane call BIS_fnc_getPitchBank;

      call AAE_fnc_Fast_process;
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
} else {
  call AAE_fnc_DeleteEH;
};
