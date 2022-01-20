/*
	Author: Jiri Wainar

	Description:
	Creates a hold action for launching player's aircraft from the carrier.

	Parameter(s):
		0: trigger that is adding the action

	Returns:
	Handle to the hold action.

	Example:
	[_trigger,_target] call bis_fnc_carrier01CatapultActionAdd;


	////////////////////////////////////////////////////////////
	EDITED: Aaren
*/

#include "\a3\functions_f_jets\Functions\AircraftCarrier\defines.inc"

private _trigger = param [0, objNull];
private _target = param [1, objNull,[[],objNull]];

if (_target isEqualType []) then
{
	_target = (_target select {_x isKindOf "Plane" && {_x isEqualTo cameraOn}}) param [0, objNull];
};

if (isNull _target) exitWith {["[x] Adding of launch action failed, valid airplane cannot be detected."] call bis_fnc_error;};

//terminate if catapult launch action is already present on cameraOn or player's vehicle
if ({GET_ACTION_ID(_x) > -1} count [vehicle player,cameraOn] > 0) exitWith {};

//store carrier deck trigger on player
SET_TRIGGER(_trigger);

//store airplane with action on trigger
SET_AIRPLANE(_trigger,_target);

private _onStart =
{
	private _catapultData = GET_CATAPULT_DATA; if (count _catapultData == 0) exitWith {SET_CATAPULT_STATE(LAUNCH_CANCELLED)};

	SET_CATAPULT_STATE(LAUNCH_STARTED);

	_catapultData params
	[
		["_part", objNull],
		["_memPoint", ""],
		["_dirOffset", 0],
		["_animations", 0],
		["_actionName", ""]
	];

	ANIMATE_DEFLECTOR(_part,_animations,ANIMATE_UP);

	//animate plane to catapult and lock it to it
	_catapultData spawn bis_fnc_carrier01CatapultLockTo;

	//execute custom code from mision config
	private _codeStart = getText(missionConfigFile >> "CfgCarrier" >> "LaunchSettings" >> "codeStart");

	if (_codeStart != "") then
	{
		call compile _codeStart;
	};

	private _plane = cameraOn;
	//Get Wheels
	_Wheels_Selections = _plane getVariable ["AAE_Wheels_Selections",[]];
	if (_Wheels_Selections isEqualTo []) then {
	  _wheels = _plane call AAE_fnc_wheels;
	  _plane setVariable ["AAE_Wheels_Selections",_wheels];
	};
};

private _onProgress =
{
	private _catapultData = GET_CATAPULT_DATA; if (count _catapultData == 0) exitWith {SET_CATAPULT_STATE(LAUNCH_CANCELLED)};
	private _currentProgress = param [4,-1,[123]];

	SET_CATAPULT_STATE(_currentProgress);

	_catapultData params
	[
		["_part", objNull],
		["_memPoint", ""],
		["_dirOffset", 0],
		["_animations", 0],
		["_actionName", ""]
	];

	private _plane = cameraOn;

	//control throttle
	if (IS_ATTACHED_TO_CATAPULT || {!(isNull attachedTo _plane)}) then
	{
		if (_currentProgress > 11) then
		{
				private _throttleCurrent = _plane animationSourcePhase "throttle";
				private _throttle = (_currentProgress - 11)/12 max _throttleCurrent min 1;

				_plane setAirplaneThrottle _throttle;
		};
	}
	else
	{
		_plane setAirplaneThrottle 0.2;
	};
};

private _onCompleted =
{
	private _catapultData = GET_CATAPULT_DATA; if (count _catapultData == 0) exitWith {};

	SET_CATAPULT_STATE(LAUNCH_COMPLETED);
	hintSilent str time;
	_catapultData params
	[
		["_part", objNull],
		["_memPoint", ""],
		["_dirOffset", 0],
		["_animations", 0],
		["_actionName", ""]
	];

	private _plane = cameraOn;

	//set throttle to max
	_plane setAirplaneThrottle 1;

	ANIMATE_DEFLECTOR(_part,_animations,ANIMATE_DOWN);

	private _dirCatapult = (getDir _part - _dirOffset - 180) % 360;

	[_plane,_dirCatapult] call BIS_fnc_AircraftCatapultLaunch;

	//execute custom code from mision config
	private _codeEnd = getText(missionConfigFile >> "CfgCarrier" >> "LaunchSettings" >> "codeEnd");

	if (_codeEnd != "") then
	{
		call compile _codeEnd;
	};

	//Get Wheels
	_vars = _plane getvariable "AAE_Wheels_Selections";

	_vars params [
	  "_plane",["_AV8",false],["_lifetime",10],["_size",[2,2]],
	  ["_Hvar",0.84],["_HvarR",0.84],
	  ["_gear0",[0,0,0]],["_gear1",[0,0,0]],["_gear2",[0,0,0]],["_gear3",[0,0,0]],
	  ["_offset",0],["_OffsetF",0]
	];

	_color = [[0.7,0.8,1,0.8],[0.7,0.8,1,0.5],[0.7,0.8,1,0.3],[0.7,0.8,1,0.15],[0.7,0.8,1,0.05],[0.7,0.8,1,0.01],[0.7,0.8,1,0.0]];
	_velocity = velocity _plane;
	_VelocityFX = [0.4*(_Velocity select 0),0.4*(_Velocity select 1), 0];

	//////////////////////////////////////////////////////////////////////////
	_effect00 = "#particlesource" createVehicleLocal [0,0,0];
	_effect00 attachTo [_plane, _gear0];

	_effect00 setParticleParams [
  ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 16, 0], "", "Billboard",
  0, _lifetime, [0, _offset, _OffsetF], _VelocityFX, 1.25, 1.2, 1, 0, _size,
  _color,
  [0], 0.5, 0, "", "", _effect00];
  _effect00 setDropInterval 0.01;
  _effect00 setParticleRandom [0.5, [0, 0, 0], [4.5,1,0.01], 0.5, 0.5, [0, 0, 0, 0], 0.1, 0.02, 90];
	//////////////////////////////////////////////////////////////////////////

	ATTACHED_TO_CATAPULT(false);

	waitUntil{
		!(isTouchingGround _plane)
	};
	deleteVehicle _effect00;
};

private _onInterrupted =
{
	private _catapultData = GET_CATAPULTS_DATA(GET_TRIGGER) param [GET_CATAPULT_LAST_ID,[]]; if (count _catapultData == 0) exitWith {};

	SET_CATAPULT_STATE(LAUNCH_CANCELLED);

	_catapultData params
	[
		["_part", objNull],
		["_memPoint", ""],
		["_dirOffset", 0],
		["_animations", 0],
		["_actionName", ""]
	];

	//set throttle to 0
	cameraOn setAirplaneThrottle 0;

	ANIMATE_DEFLECTOR(_part,_animations,ANIMATE_DOWN);
	ATTACHED_TO_CATAPULT(false);
};

private _cfgSettings = missionConfigFile >> "CfgCarrier" >> "LaunchSettings";
private _duration = getNumber(_cfgSettings >> "duration") max 6;
private _distance = getNumber(_cfgSettings >> "distance"); if (_distance == 0) then {_distance = 15} else {_distance = _distance max 0.1 min 15};
private _condShow = getText(_cfgSettings >> "condShow"); if (_condShow == "") then {_condShow = "true"};
private _condProgress = getText(_cfgSettings >> "condProgres"); if (_condProgress == "") then {_condProgress = "true"};

//add the launch action
private _actionID =
[
/* 0 object */							_target,
/* 1 action title */					if (isLocalized "STR_A3_action_useCatapult") then {localize "STR_A3_action_useCatapult"} else {"Initiate Launch Sequence"},
/* 2 idle icon */						"\A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_takeOff1_ca.paa",
/* 3 progress icon */					"\A3\Ui_f\data\IGUI\Cfg\HoldActions\holdAction_takeOff2_ca.paa",
/* 4 condition to show */				format["([{%1},%2] call bis_fnc_carrier01CatapultID) != -1",_condShow,_distance],
/* 5 condition to progress */			format["([{%1},%2] call bis_fnc_carrier01CatapultID) != -1",_condProgress,_distance],
/* 6 code executed on start */			_onStart,
/* 7 code executed per tick */			_onProgress,
/* 8 code executed on completion */		_onCompleted,
/* 9 code executed on interruption */	_onInterrupted,
/* 10 arguments */						[],
/* 11 action duration */				_duration,
/* 12 priority */						1000,
/* 13 remove on completion */			true,
/* 14 show unconscious */				false
]
call BIS_fnc_holdActionAdd;

SET_ACTION_ID(_target,_actionID);
