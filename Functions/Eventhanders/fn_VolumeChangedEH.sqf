private ["_changed","_old_Vol","_old_time"];

_changed = _var get "changed";
_old_Vol = _var get "old_Volume";
_old_time = _var get "old_time";

if (_changed) then {
  _last_Volume = soundVolume;
};
_changed = false;

if (abs(soundVolume - _old_Vol) > 0.2) then {
  _changed = true;
};

_var set ["changed",_changed];
_var set ["last_Sound_Volume",_last_Volume];

if ((time - _old_time) < 0.2) exitWith {};
_var set ["old_time",time];
_var set ["old_Volume",soundVolume];