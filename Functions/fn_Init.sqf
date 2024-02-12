//-Add Eventhadlers
["Plane","Gear",AAE_fnc_GearEH] call CBA_fnc_addClassEventHandler;
["Plane","Engine",AAE_fnc_EngineEH] call CBA_fnc_addClassEventHandler;
["Plane","Deleted",AAE_fnc_DeleteEH] call CBA_fnc_addClassEventHandler;
["Plane","LandedTouchDown",AAE_fnc_landedEH] call CBA_fnc_addClassEventHandler;
["Plane","GetIn",{(_this # 0) call AAE_fnc_InitEH}] call CBA_fnc_addClassEventHandler;

//-Create New Events
["AAE_PlaySound",AAE_fnc_Play_Sound] call CBA_fnc_addEventHandler;
["AAE_PlaySound3D",AAE_fnc_Play_Sound3D] call CBA_fnc_addEventHandler;
["AAE_PlaySound_Alarm",AAE_fnc_PlayAlarm] call CBA_fnc_addEventHandler;

player setVariable ["Have_AAE_Loaded",true,true];
localNamespace setVariable ["AAE_Basic_Cache", createHashMap];

if (allPlayers findIf {(_x getVariable ["AAE_EachFrame_EH",-1]) != -1} != -1) then {
	call AAE_fnc_ClientPFH;
} else {
	call AAE_fnc_ServerPFH;
};
