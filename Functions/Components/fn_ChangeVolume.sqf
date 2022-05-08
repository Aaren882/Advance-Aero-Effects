_Fade_Out_F = player getVariable ["AAE_GForce_Sound_Fade_Out_F",true];
_currentGForce = _plane getVariable ["AAE_CurrentGForce",0];

if (_currentGForce >= 0.15) then {
  if (_Fade_Out_F) then {
    3 fadeSound last_Sound_Volume*(gforces_Vol_sdr)*0.01;
    player setVariable ["AAE_GForce_Sound_Fade_Out_F",false];
  };
} else {
  if !(_Fade_Out_F) then {
    2 fadeSound last_Sound_Volume;
    player setVariable ["AAE_GForce_Sound_Fade_Out_F",true];
  };
};
