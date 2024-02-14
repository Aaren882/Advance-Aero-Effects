params ["_plane","_height","_speed"];
private ["_config","_stall_speed","_Max_speed","_sound_Alarm"];
//Exclude
if (_plane iskindof "VTOL_Base_F" || _plane iskindof "CUP_B_MV22_USMC") exitWith {};

_config = configOf _plane;
_stall_speed = getNumber (_config >> "stallSpeed");
_Max_speed = getNumber (_config >> "maxSpeed");

//Sound Files
_sound_Alarm = getText (_config >> "AAE_Alarm_Int");

//Debug
if (_sound_Alarm == "") then {
  _sound_Alarm = "AAE_Alarm";
};

//Turbulent World Effect
_fqT = selectRandom [8,5,6];

if (_speed >= 50) then {
  if ((turbulentS_fn) && (_speed < _stall_speed) && (_height < 1000)) then {
  	addCamShake [1, 1, _fqT];
  	if (((_plane getVariable ["Alarm_execution_time", -1]) < time) && turbulentS_snd_alarm_fn) then {
      [_plane,_sound_Alarm] call AAE_fnc_PlayAlarm;
    };
  };
  if ((turbulentH_fn) && (_speed > 700) && (_height < turbulentT_sdr)) then {
  	addCamShake [1, 2, _fqT];
  	if (((_plane getVariable ["Alarm_execution_time", -1]) < time) && turbulentH_snd_alarm_fn) then {
      [_plane,_sound_Alarm] call AAE_fnc_PlayAlarm;
    };
  };
};
