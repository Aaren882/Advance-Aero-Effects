params ["_plane","_sound"];

_duration = getNumber (configFile >> "CfgSounds" >> _sound >> "EndTime");

if (isNil {_duration}) then {
  _duration = 0;
};
["AAE_PlaySound",[_sound]] call CBA_fnc_localEvent;
_plane setVariable ["RumA_execution_time", (time + _duration)];
