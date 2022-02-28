params ["_plane"];

if (_plane getvariable "AAE_Landed_Counter") then {
  sleep 0.25;
  _plane setvariable ["AAE_Landed_Counter",false];

  //Cool Down
  _plane setVariable ["AAE_Landed_CoolDown",true];
  sleep 1;
  _plane setVariable ["AAE_Landed_CoolDown",false];
};
