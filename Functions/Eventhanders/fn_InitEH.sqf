params ["_plane"];
//Basic Definitions

//Find Wingspan
_Wingspan = getNumber (configFile >> "CfgVehicles" >> typeOf _plane >> "Aircraft_Wingspan");
_plane setVariable ["AAE_Wingspan",_Wingspan];

//Check AB
_have_AB = getNumber (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Have_AB");
_plane setVariable ["AAE_Have_AB",(_have_AB == 1)];

// Find Engine POS
_return = _plane call AAE_fnc_find_engine;
