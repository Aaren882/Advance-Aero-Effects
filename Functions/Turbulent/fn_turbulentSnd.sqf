params ["_plane"];

//Sound Files
_config_Alarm = getArray (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Alarm_Int");
_config_Rum = getArray (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Rumble_Int");

//Debug
if (_config_Alarm isEqualTo []) then {
  _config_Alarm = ["MG8\AVDAVFX\snd\Alarm.ogg","AAE_Alarm"];
};

if (_config_Rum isEqualTo []) then {
  _config_Rum = ["AAE_Rumble"];
};

_file_Alarm = _config_Alarm # 0;
_sound_Rum = _config_Rum # 0;

_sound_Alarm = _config_Alarm # 1;

//Turbulent Effect
if (((_plane getVariable ["Alarm_execution_time", -1]) < time) and turbulent_snd_alarm_fn) then {
	[_plane,_sound_Alarm,_file_Alarm] call AAE_fnc_PlayAlarm;
};
if (((_plane getVariable ["RumA_execution_time", -1]) < time) and turbulent_snd_rum_fn) then {
	[_plane,_sound_Rum] call AAE_fnc_PlayRumA;
};
