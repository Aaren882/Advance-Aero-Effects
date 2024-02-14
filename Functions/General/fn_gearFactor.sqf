params ["_plane","_speed"];

//Landing Gear
private _gear = _plane getSoundController "gear";

if ((_gear < 0.6) && (_speed > gearP_sdr)) then {
  private ["_config","_sound_Alarm","_sound_Rum"];
  addCamShake [2, 2, linearConversion [gearP_sdr,800 max 1000,_speed,2,20,true]];

  //Sound Files
  _config = configOf _plane;
  _sound_Alarm = getText (_config >> "AAE_Alarm_Int");
  _sound_Rum = getText (_config >> "AAE_Rumble_Int");

  //Debug
  if (_sound_Alarm == "") then {
    _sound_Alarm = "AAE_Alarm";
  };

  if (_sound_Rum == "") then {
    _sound_Rum = "AAE_Rumble";
  };

  if (((_plane getVariable ["Alarm_execution_time", -1]) < time) and gear_snd_alarm_fn) then {
    [_plane,_sound_Alarm] call AAE_fnc_PlayAlarm;
  };
  if (((_plane getVariable ["RumA_execution_time", -1]) < time) and gear_snd_rum_fn) then {
    [_plane,_sound_Rum] call AAE_fnc_PlayRumA;
  };
};
