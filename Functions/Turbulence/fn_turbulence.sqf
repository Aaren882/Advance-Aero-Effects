params [["_var",-1],"_plane"];
private ["_var","_fq"];
enableCamShake true;

if (_var < 0) exitWith {};

//Trigger Range
_fq = linearConversion [3, turbulent_sdr + 5, _var, 45, 10, true];
addCamShake [2, 0.1, _fq];

if (_fq > 15) then {
  call AAE_fnc_turbulenceSnd;
};