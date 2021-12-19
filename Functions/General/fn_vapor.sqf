params ["_plane","_engine1","_engine2"];

_source00 = "#particlesource" createVehicleLocal [0,0,0];
_source01 = "#particlesource" createVehicleLocal [0,0,0];

_source00 attachTo [_plane, _engine1];
_source01 attachTo [_plane, _engine2];

_plane setVariable ["AAE_Vapor_Paricles",[_source00,_source01]];

_source00 setParticleClass "AAE_Vapor_Trail";
_source01 setParticleClass "AAE_Vapor_Trail";

//Vars
_Vapor_Paricles = _plane getVariable ["AAE_Vapor_Paricles",[]];

waituntil {!(_plane getVariable ["AAE_Vapor_Activated", false])};

{deleteVehicle _x} foreach _Vapor_Paricles;
_plane setVariable ["AAE_Vapor_Paricles",[]];
