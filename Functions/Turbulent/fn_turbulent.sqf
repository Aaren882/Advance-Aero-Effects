params ["_plane","_Exhausts_count"];

enableCamShake true;

//Turbulent Effect

_Source_Distance = _plane getVariable "AAE_Turbulent_Source_Distance";
_Source_Distance params [["_dis0",-1],["_dis1",-1],["_dis2",-1],["_dis3",-1]];

//Trigger Range
_fq = 10;
if (
		((_dis0 > 0) and (_dis0 <= 30) and (_dis0 > 20)) or
		((_dis1 > 0) and (_dis1 <= 30) and (_dis1 > 20)) or
		((_dis2 > 0) and (_dis2 <= 30) and (_dis2 > 20)) or
		((_dis3 > 0) and (_dis3 <= 30) and (_dis3 > 20))
	) then {
	_fq = 35;
};
if (
		((_dis0 > 0) and (_dis0 <= 20)) or
		((_dis1 > 0) and (_dis1 <= 20)) or
		((_dis2 > 0) and (_dis2 <= 20)) or
		((_dis3 > 0) and (_dis3 <= 20))
	) then {
	_fq = 45;
};

if (
		((_dis0 > 0) and (_dis0 <= turbulent_sdr)) or
		((_dis1 > 0) and (_dis1 <= turbulent_sdr)) or
		((_dis2 > 0) and (_dis2 <= turbulent_sdr)) or
		((_dis3 > 0) and (_dis3 <= turbulent_sdr))
	) then {
	addCamShake [2, 2, _fq];
	[_plane] call AAE_fnc_turbulentSnd;
};
