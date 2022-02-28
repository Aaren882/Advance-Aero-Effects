params ["_plane", "_nimspots"];
private _catName = _plane getVariable "ttt_nimitz_catName";
private _catObj = _plane getVariable "ttt_nimitz_catObj";
private _catEnd = _nimspots modelToWorld (_nimspots selectionPosition (format["%1T", _catName]));

[_plane, _plane getDir _catEnd, _catName, _nimspots, _catObj] spawn {
	params ["_plane", "_finalDir", "_catName", "_nimspots", "_catObj"];
	private _unitzVarname = format ["ttt_nimitz_unitz_%1", _catName];
	private _crew = _nimspots getVariable _unitzVarname;
	private _catNr = 0;
	switch (_catName) do {
		case "C1": { _catNr = 1; };
		case "C2": { _catNr = 2; };
		case "C3": { _catNr = 3; };
		case "C4": { _catNr = 4; };
	};
	[_catNr, _crew] call ttt_salute_func;

	detach _plane;

	//internal sound
	[] spawn {
		_plane = cameraon;
		waituntil {
			!(isTouchingGround _plane)
		};
		if ((_plane iskindof "Plane") and (cameraView == "INTERNAL")) then {
			playsound "Catapult_End";
		};
	};

	if ((_plane iskindof "Plane") and (cameraView == "INTERNAL")) then {
		playsound "Catapult_Nimitz";
		playsound "Catapult_Start";
	};

	//playSound3D ["jdg_carrier\sounds\Catapult Launch.ogg", _catObj, false, getPosASL _catObj, 5, 1, 1000];
	[_nimspots getVariable "TTT_NimitzParent", "ttt_nimitz_planeLaunching", [_catName, _plane, _nimspots], false] call BIS_fnc_callScriptedEventHandler;
	private _vSpeed = 60; // meter / second?
	private _vertSpeed = 1.3;
	private _v = 1;
	while {(_v < _vSpeed) and (alive _plane)} do {
		// TeTeT: set the vert velocity to _vertSpeed to jump over the gaps
		// (vehicle _plane) setVelocity [_v * sin _finalDir, _v * cos _finalDir, _vertSpeed];
		(vehicle _plane) setVelocityModelSpace [0, _v, _vertSpeed];
		// Yanko: accelerate proportionally to max 69.44 m/s = 250 km/h
		_v = _v + 5 * _vSpeed / 69.44;
		// TeTeT: increase delay to accelerate until end of runway on carrier
		sleep 0.25;
	};
	_plane animate ["launchbar", 0];
	[_nimspots getVariable "TTT_NimitzParent", "ttt_nimitz_planeLaunched", [_catName, _plane, _nimspots], false] call BIS_fnc_callScriptedEventHandler;
};
_plane;
