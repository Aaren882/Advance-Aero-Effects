params ["_plane","_engine1","_engine2","_AGL_POS","_ASL_POS"];

_source00 = "#particlesource" createVehicleLocal [0,0,0];
_source01 = "#particlesource" createVehicleLocal [0,0,0];

_source00 attachTo [_plane, _engine1];
_source01 attachTo [_plane, _engine2];

_source00 setParticleClass "AAE_Vapor_Trail";
_source01 setParticleClass "AAE_Vapor_Trail";

waituntil {!(_plane getVariable ["AAE_Vapor_Activated", false])};

deleteVehicle _source00;
deleteVehicle _source01;
