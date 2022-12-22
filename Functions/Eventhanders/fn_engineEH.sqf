params ["_plane","_Engine_State"];

if (alive _plane and _Engine_State) then {
  if !(_plane getVariable ["AAE_Find_Engine",false]) then {
    call AAE_fnc_InitEH
  };

  _plane setvariable ["AAE_Vapor_toggle",vapor_sdr + random 20];

  AAE_GForces_Filter = ppEffectCreate ["ColorCorrections", 6500];
  AAE_GForces_Filter ppEffectForceInNVG true;
  AAE_GForces_Filter ppEffectAdjust [1,1,0,[0,0,0,0],[0,0,0,0],[1,1,1,1],[10,10,0,0,0,0.1,0.5]];
  AAE_GForces_Filter ppEffectCommit 0.4;

  if (_plane iskindof "Plane") then {
    AAE_GForces_Filter ppEffectEnable true;
  };

  //EachFrame # 41
  /* _AAE_handler_Engine = addMissionEventHandler ["EachFrame", {

  },[
    _plane,
    _Engine_Offsets,
    _Exhausts_count,
    _Exhausts_POS,
    _Wingspan,
    _have_AB
  ]];
  _plane setVariable ["AAE_EachFrame_Engine", _AAE_handler_Engine];*/
} else {
  _plane call AAE_fnc_DeleteEH;
};
