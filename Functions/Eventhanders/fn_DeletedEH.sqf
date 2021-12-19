//Remove EachFrame EH
params ["_plane"];
if (_plane getVariable ["AAE_Actived", false]) then {
  //Engine EH
  _plane setVariable ["AAE_Actived", false];
  //Loop Remove
  removeMissionEventHandler ["EachFrame", (_plane getVariable ["AAE_EachFrame_Handler", -1])];
};
