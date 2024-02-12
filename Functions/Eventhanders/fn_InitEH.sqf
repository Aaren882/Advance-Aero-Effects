params ["_plane"];
private [
  "_class","_cache","_LocalCache","_config",
  "_Wingspan",
  "_Default_AB","_FIRAB_config","_USAFAB_config","_Have_AB_source",
  "_AB_source","_AB_Sound","_have_AB"
];
_class = typeOf _plane;

//- Create Cache if the cache is nil
_cache = localNamespace getVariable ["AAE_Basic_Cache", createHashMap];

if (_class in _cache) exitWith {
  _cache get _class;
};

_LocalCache = createHashMap;

//Basic Definitions
_config = configFile >> "CfgVehicles" >> _class;

//Find Wingspan
_Wingspan = getNumber (_config >> "Aircraft_Wingspan");
_LocalCache set ["AAE_Wingspan", _Wingspan];

//Check AB
_Default_AB = getNumber (_config >> "AAE_Have_AB");
_LocalCache set ["AAE_Burner_Offset",getArray (_config >> "AAE_Burner_Offset")];

//-FIR
_FIRAB_config = _config >> "ABSystem";

//-USAF
_USAFAB_config = _config >> "USAF_Afterburner";

_Have_AB_source = (isText (_config >> "AB_Source") || (isclass _FIRAB_config) || (isclass _USAFAB_config));
_AB_source = getText (_config >> "AB_Source");
_AB_Sound = getText (_config >> "AAE_AB_Sound");

// -is FIR
if (isclass _FIRAB_config) then {
  _AB_source = if (isText (_FIRAB_config >>"AB_Source")) then {
    getText (_FIRAB_config >> "AB_Source");
  } else {
    getText (_FIRAB_config >> "ABSwitchName");
  };
};

// -is USAF
if ((isclass _USAFAB_config)) then {
  _AB_source = getText (_USAFAB_config >> "animStretch");
};

_LocalCache set ["AAE_Have_AB_Source",_Have_AB_source];
_LocalCache set ["AAE_AB_Source",_AB_source];

// -Have AB
_have_AB = (_Default_AB == 1) || (_Have_AB_source);
_LocalCache set ["AAE_Have_AB",_have_AB];
__LocalCache set ["AAE_AB_Sound", _AB_Sound];

// Find Engine POS
call AAE_fnc_find_engine;

_cache set [_class, _LocalCache];
localNamespace setVariable ["AAE_Basic_Cache",_cache];