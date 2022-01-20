params ["_plane"];

if (_plane getvariable "AAE_Landed_Counter") then {
  sleep 0.25;
  _plane setvariable ["AAE_Landed_Counter",false];

  _Landed_Sources = _plane getVariable "AAE_Landed_Sources";
  {deleteVehicle _x} foreach _Landed_Sources;
  _plane setVariable ["AAE_Ground_Paricles", []];
  _plane setVariable ["AAE_Landing_Activated", false];

  //End loop
  removeMissionEventHandler ["EachFrame", (_plane getVariable ["AAE_Landed_Handler",-1])];
  _plane setVariable ["AAE_Landed_Handler",-1];
};
