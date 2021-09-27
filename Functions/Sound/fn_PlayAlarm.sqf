params ["_plane","_sound","_file_path"];

_duration = getNumber (configFile >> "CfgSounds" >> _sound >> "EndTime");

if (isNil {_duration}) then {
  _duration = 0;
};
["AAE_PlaySound3D",[_file_Alarm]] call CBA_fnc_localEvent;
_plane setVariable ["Alarm_execution_time", (time + _duration)];
