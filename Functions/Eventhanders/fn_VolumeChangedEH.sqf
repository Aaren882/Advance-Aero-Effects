if (SoundVolume_changed) then {
  last_Sound_Volume = soundVolume;
};
SoundVolume_changed = false;

if (abs(soundVolume - SoundVolume_old) > 0.2) then {
  SoundVolume_changed = true;
};

if ((time - SoundVolume_old_time) < 0.2) exitWith {};
SoundVolume_old_time = time;
SoundVolume_old = soundVolume;
