private ["_Fade_Out_F","_var","_currentGForce"];

_Fade_Out_F = localNamespace getVariable ["AAE_GForce_Sound_Fade_Out_F",true];
_var = localNamespace getVariable "AAE_SoundVol_Var";
_currentGForce = _plane getVariable ["AAE_CurrentGForce",0];

_last_Volume = _var get "last_Sound_Volume";

//Volume Changed
call AAE_fnc_VolumeChangedEH;

if (_currentGForce >= 0.15) then {
  if (_Fade_Out_F) then {
    3 fadeSound _last_Volume*(gforces_Vol_sdr)*0.01;
    localNamespace setVariable ["AAE_GForce_Sound_Fade_Out_F",false];
  };
} else {
  if !(_Fade_Out_F) then {
    2 fadeSound _last_Volume;
    localNamespace setVariable ["AAE_GForce_Sound_Fade_Out_F",true];
  };
};

localNamespace setVariable ["AAE_SoundVol_Var",_var];