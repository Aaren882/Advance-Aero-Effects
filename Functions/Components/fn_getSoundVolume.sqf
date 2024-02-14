//- Get Sound Volume with ACE compat
//- Return: Volume

#if __has_include("\z\ace\addons\volume\config.bin")
  if (acex_volume_enabled) then {
    private _reductionGame = (acex_volume_reduction / 10) * ace_volume_initialGameVolume;
    (ace_volume_initialGameVolume - _reductionGame)
  } else {
    getAudioOptionVolumes # 0
  };
#else
  getAudioOptionVolumes # 0
#endif