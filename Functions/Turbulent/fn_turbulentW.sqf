params ["_plane","_height","_speed"];

//Sound Files
_config_Alarm = getArray (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Alarm_Int");

//Debug
if (_config_Alarm isEqualTo []) then {
  _config_Alarm = ["MG8\AVDAVFX\snd\Alarm.ogg","AAE_Alarm"];
};

_file_Alarm = _config_Alarm # 0;
_sound_Alarm = _config_Alarm # 1;

//Turbulent World Effect
_fqT = selectRandom [8,5,6];

if ((turbulentS_fn) and (_speed < 200) and (_height < 1000)) then {
	addCamShake [1, 1, _fqT];
	if (((_plane getVariable ["Alarm_execution_time", -1]) < time) and turbulentS_snd_alarm_fn) then {
    [_plane,_sound_Alarm,_file_Alarm] call AAE_fnc_PlayAlarm;
  };
};
if ((turbulentH_fn) and (_speed > 700) and (_height < turbulentT_sdr)) then {
	addCamShake [1, 2, _fqT];
	if (((_plane getVariable ["Alarm_execution_time", -1]) < time) and turbulentH_snd_alarm_fn) then {
    [_plane,_sound_Alarm,_file_Alarm] call AAE_fnc_PlayAlarm;
  };
};
