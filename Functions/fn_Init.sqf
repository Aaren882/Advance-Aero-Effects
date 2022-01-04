//-ACE Detection
HaveACE = isClass (configFile >> "CfgPatches" >> "ace_main");

// -Basic Definitions
//-Sonic Settings
AAE_SpeedSet = 1195;
AAE_sonicboom_speed_01 = AAE_SpeedSet - 20;//1175
AAE_sonicboom_speed_02 = AAE_SpeedSet - 10;//1185
AAE_sonicboom_speed_03 = AAE_SpeedSet + 10;//1205

//-ACE Vars
GForces = [];
GForces resize 30;
GForces = GForces apply {1};
GForces_Index = 0;
lastUpdateTime = 0;
oldVel = [0,0,0];

//-Add Eventhadlers
["Air","Engine",AAE_fnc_EngineEH] call CBA_fnc_addClassEventHandler;
["Air","Deleted",AAE_fnc_DeletedEH] call CBA_fnc_addClassEventHandler;
["Plane","LandedTouchDown",AAE_fnc_landingEH] call CBA_fnc_addClassEventHandler;
//-Create New Events
["AAE_PlaySound",AAE_fnc_Play_Sound] call CBA_fnc_addEventHandler;
["AAE_PlaySound3D",AAE_fnc_Play_Sound3D] call CBA_fnc_addEventHandler;
["AAE_PlaySound_Alarm",AAE_fnc_PlaySound_Alarm] call CBA_fnc_addEventHandler;
