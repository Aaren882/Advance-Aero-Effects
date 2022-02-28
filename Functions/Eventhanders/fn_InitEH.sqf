//Basic Definitions
_config = configFile >> "CfgVehicles" >> typeOf _plane;

//Find Wingspan
_Wingspan = getNumber (_config >> "Aircraft_Wingspan");
_plane setVariable ["AAE_Wingspan",_Wingspan];

//Check AB
_Default_AB = getNumber (_config >> "AAE_Have_AB");
_plane setVariable ["AAE_Burner_Offset",getArray (_config >> "AAE_Burner_Offset")];

//-FIR
_FIRAB_config = _config >> "ABSystem";

//-USAF
_USAFAB_config = _config >> "USAF_Afterburner";

//_FIR_AB = isclass _FIRAB_config;
//_AB_source = "ABSwitch";
_Have_AB_source = (isText (_config >> "AB_Source") or (isclass _FIRAB_config) or (isclass _USAFAB_config));
_AB_source = getText (_config >> "AB_Source");

// -is FIR
if (isclass _FIRAB_config) then {
  if (isText (_FIRAB_config >>"AB_Source")) then {
    _AB_source = getText (_FIRAB_config >> "AB_Source");
  } else {
    _AB_source = getText (_FIRAB_config >> "ABSwitchName");
  };
};

// -is USAF
if ((isclass _USAFAB_config)) then {
  _AB_source = getText (_USAFAB_config >> "animStretch");
};

_plane setVariable ["AAE_Have_AB_Source",_Have_AB_source];
_plane setVariable ["AAE_AB_Source",_AB_source];

// -Have AB
_have_AB = (_Default_AB == 1) or (_Have_AB_source);
_plane setVariable ["AAE_Have_AB",_have_AB];

// Find Engine POS
call AAE_fnc_find_engine;
