params ["_plane","_source00","_source01"];

enableCamShake true;

//Turbulent Effect

//Trigger Range
_dis0 = _plane distance _source00;
_dis1 = _plane distance _source01;

_fq = 10;

if (((_dis0 <= 30) and (_dis0 > 20)) or ((_dis1 <= 30) and (_dis1 > 20))) then {
	_fq = 35;
};
if ((_dis0 <= 20) or (_dis1 <= 20)) then {
	_fq = 45;
};

if ((_dis0 <= turbulent_sdr) or (_dis1 < turbulent_sdr)) then {
	addCamShake [2, 2, _fq];
	[_plane] call AAE_fnc_turbulentSnd;
};
