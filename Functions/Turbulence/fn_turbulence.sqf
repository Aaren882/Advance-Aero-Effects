params ["_plane","_Exhausts_count"];

enableCamShake true;

//Turbulent Effect
_Source_Distance = _plane getVariable "AAE_Turbulent_Source_Distance";
_Source_Distance params [["_dis0",-1],["_dis1",-1],["_dis2",-1],["_dis3",-1]];

_dis = selectMin _Source_Distance;

//Trigger Range
_fq = 10;
if (
		(_dis > 0) and (_dis <= 30) and (_dis > 20)
	) then {
	_fq = 35;
};
if (
		(_dis > 0) and (_dis <= 20)
	) then {
	_fq = 45;
};

if (
		(_dis > 0) and (_dis <= turbulent_sdr)
	) then {
	addCamShake [2, 2, _fq];
	_plane call AAE_fnc_turbulenceSnd;
};
