params ["_plane","_speed"];
private ["_sound","_result"];

//Sound Files
_sound = getText (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Rumble_Taxiing");

//Debug
if (_sound isEqualTo "") then {
  _sound = "AAE_RumbleG";
};

_result = vectorLinearConversion [0, 150, _speed, [0,0,0], [1,6,0], true];
_result params ["_pw","_fq"];

addCamShake [_pw, 1, _fq];

if ((_speed > 100) && (Taxing_sound_fn) && ((_plane getVariable ["RumB_execution_time", -1]) < time)) then {
  [_plane,_sound] call AAE_fnc_PlayRumB;
};
