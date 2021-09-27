#include "CBA_Setting.hpp"

/*["Plane","Engine",{
	params ["_plane", "_engineState"];
	[_plane, _engineState] call AAE_fnc_init;

  [_plane, _engineState] remoteExecCall ["AAE_fnc_init",0];
	["AAE_triggered",_plane] call CBA_fnc_globalEvent;

}, true,[], true] call CBA_fnc_addClassEventHandler;

["Plane","LandedTouchDown",{

	if (TDSound_fn) then {
	    playSound ["touchdown", true];
	};

}, true,[], true] call CBA_fnc_addClassEventHandler;*/
//player setVariable [_AEE_EH, [vehicle player, assignedVehicleRole player]];

//addMissionEventHandler ["Loaded", {[] execvm "MG8\AVDAVFX\Functions\fn_initMis.sqf"}];
