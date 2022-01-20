params ["_plane", "_gearState"];

_Wheels_Selections = _plane getVariable ["AAE_Wheels_Selections",[]];
//Wheels
if (_Wheels_Selections isEqualTo []) then {
  _wheels = _plane call AAE_fnc_wheels;
  _plane setVariable ["AAE_Wheels_Selections",_wheels];
};
