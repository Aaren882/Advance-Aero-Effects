params ["_plane"];

//Sound Files
_sound_Alarm = getText (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Alarm_Int");
_sound_Rum = getText (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Rumble_Int");

//Debug
/* if (_config_Alarm isEqualTo "") then {
  _config_Alarm = "AAE_Alarm";
};

if (_config_Rum isEqualTo "") then {
  _config_Rum = "AAE_Rumble";
}; */

//Turbulent Effect
if (((_plane getVariable ["Alarm_execution_time", -1]) < time) and turbulent_snd_alarm_fn) then {
	[_plane,_sound_Alarm] call AAE_fnc_PlayAlarm;
};
if (((_plane getVariable ["RumA_execution_time", -1]) < time) and turbulent_snd_rum_fn) then {
	[_plane,_sound_Rum] call AAE_fnc_PlayRumA;
};
