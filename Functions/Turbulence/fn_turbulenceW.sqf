params ["_plane","_height","_speed"];

//Exclude
if (_plane iskindof "VTOL_Base_F" or _plane iskindof "CUP_B_MV22_USMC") exitWith {};

_stall_speed = getNumber (configFile >> "CfgVehicles" >> typeOf _plane >> "stallSpeed");
_Max_speed = getNumber (configFile >> "CfgVehicles" >> typeOf _plane >> "maxSpeed");

//Sound Files
_sound_Alarm = getText (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Alarm_Int");

//Debug
if (_sound_Alarm isEqualTo "") then {
  _sound_Alarm = "AAE_Alarm";
};

//Turbulent World Effect
_fqT = selectRandom [8,5,6];

if (_speed >= 50) then {
  if ((turbulentS_fn) and (_speed < _stall_speed) and (_height < 1000)) then {
  	addCamShake [1, 1, _fqT];
  	if (((_plane getVariable ["Alarm_execution_time", -1]) < time) and turbulentS_snd_alarm_fn) then {
      [_plane,_sound_Alarm] call AAE_fnc_PlayAlarm;
    };
  };
  if ((turbulentH_fn) and (_speed > _Max_speed) and (_height < turbulentT_sdr)) then {
  	addCamShake [1, 2, _fqT];
  	if (((_plane getVariable ["Alarm_execution_time", -1]) < time) and turbulentH_snd_alarm_fn) then {
      [_plane,_sound_Alarm] call AAE_fnc_PlayAlarm;
    };
  };
};
