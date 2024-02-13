//Sound Files
private _sound_Alarm = getText (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Alarm_Int");
private _sound_Rum = getText (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Rumble_Int");

//Turbulent Effect
if (((_plane getVariable ["Alarm_execution_time", -1]) < time) && turbulent_snd_alarm_fn) then {
	[_plane,_sound_Alarm] call AAE_fnc_PlayAlarm;
};
if (((_plane getVariable ["RumA_execution_time", -1]) < time) && turbulent_snd_rum_fn) then {
	[_plane,_sound_Rum] call AAE_fnc_PlayRumA;
};
