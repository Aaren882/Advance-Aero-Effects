//Add Eventhadlers
["Air","Engine",AAE_fnc_engineEH] call CBA_fnc_addClassEventHandler;
["Plane","LandedTouchDown",AAE_fnc_landingEH] call CBA_fnc_addClassEventHandler;
//Create New Events
["AAE_PlaySound",AAE_fnc_PlaySound] call CBA_fnc_addEventHandler;
["AAE_PlaySound3D",AAE_fnc_PlaySound3D] call CBA_fnc_addEventHandler;
["AAE_PlaySound_Alarm",AAE_fnc_PlaySound_Alarm] call CBA_fnc_addEventHandler;
