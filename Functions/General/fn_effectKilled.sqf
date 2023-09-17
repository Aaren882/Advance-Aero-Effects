params["_vehicle","","","_playEffects"];

for "_i" from 1 to getCustomSoundControllerCount _vehicle do { setCustomSoundController [_vehicle, format ["CustomSoundController%1", _i], 0] };

if (!_playEffects) exitWith {};

if (_vehicle iskindof "car" || {_vehicle iskindof "ship"}) then {
	[_vehicle] remoteExec ["BIS_fnc_effectKilledSecondaries", 2];
} else {
	if (_vehicle iskindof "tank") then {
		[_vehicle, round((fuel _vehicle) * (2 + random 2))] remoteExec ["BIS_fnc_effectKilledSecondaries", 2];
	}	else {
		if (_vehicle iskindof "helicopter" || {_vehicle iskindof "plane"}) then	{
			[_vehicle] remoteExec ["BIS_fnc_effectKilledAirDestruction", 2];

			//-Add Camshake on Local End
			if (cameraon in _vehicle && crashShake_fn) then {
				[{
					(((getPosVisual _this # 2) < 0.2) or (isTouchingGround _this)) && !(isnull _this)
				}, {
					if (speed _this > 0.1) then {
					  addCamShake [10, 5, 50];
					};
				}, _vehicle] call CBA_fnc_waitUntilAndExecute;
			};

		};
	};
};
