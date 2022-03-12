params ["_plane","_speed"];

//Sound Files
_sound_Alarm = getText (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Alarm_Int");
_sound_Rum = getText (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Rumble_Int");

//Debug
if (_sound_Alarm isEqualTo "") then {
  _sound_Alarm = "AAE_Alarm";
};

if (_sound_Rum isEqualTo "") then {
  _sound_Rum = "AAE_Rumble";
};

//Landing Gear
_gear = _plane getSoundController "gear";

if ((_gear < 0.6) and (_speed > gearP_sdr)) then {
  addCamShake [2, 2, 2];

  if (((_plane getVariable ["Alarm_execution_time", -1]) < time) and gear_snd_alarm_fn) then {
    [_plane,_sound_Alarm] call AAE_fnc_PlayAlarm;
  };
  if (((_plane getVariable ["RumA_execution_time", -1]) < time) and gear_snd_rum_fn) then {
    [_plane,_sound_Rum] call AAE_fnc_PlayRumA;
  };
};
