if !(hasInterface) exitWith {};

_tempMap = createHashMap;

_tempMap set ["old_time", 0];
_tempMap set ["changed", true];
_tempMap set ["last_Sound_Volume", call AAE_fnc_getSoundVolume];

localNamespace setVariable [
  "AAE_SoundVol_Var",
  _tempMap
];
_tempMap = nil;

["AAE_Init",AAE_fnc_Init] call CBA_fnc_addEventHandler;
["AAE_Init",[]] call CBA_fnc_localEvent;