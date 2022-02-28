params ["_plane","_speed"];

//Sound Files
_config = getArray (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Rumble_Taxing");

//Debug
if (_config isEqualTo "") then {
  _config = ["AAE_RumbleG"];
};

_sound = _config # 0;

_fq = 0;
_pw = 0;

if ((_speed >= 10) and (_speed < 60)) then {
    _fq = 3;
    _pw = 0.3;
};
if ((_speed >= 60) and (_speed < 150)) then {
    _fq = 5;
    _pw = 1;
};
if (_speed >= 150) then {
    _fq = 6;
    _pw = 1;
};

addCamShake [_pw, 1, _fq];

if ((_speed > 100) and (Taxing_sound_fn) and ((_plane getVariable ["RumB_execution_time", -1]) < time)) then {
  [_plane,_sound] call AAE_fnc_PlayRumB;
};
