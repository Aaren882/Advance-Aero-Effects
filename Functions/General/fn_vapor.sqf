params ["_plane","_Exhausts_count","_Exhausts_POS"];

_source = "#particlesource";
_Sources = [];

//Vapor Effect
for "_i" from 0 to (_Exhausts_count - 1) step 1 do {
  _Engine = _Exhausts_POS # _i;

  _particle_source = _source createVehicleLocal [0,0,0];

  //Attach
  _Particle_source attachTo [_plane, [0,-5,0], _Engine];

  //Particle Effect
  _Particle_source setParticleParams [
	["\A3\Data_F\ParticleEffects\Universal\Universal",16,12,8,0], "", "Billboard",
	1, 20, [0,0,0], [0, 0, 0], 20, 1.25, 1, 0.01, [8,15,25,30,40],
	[[0.7,0.8,1,0],[0.7,0.8,1,0.3],[0.7,0.8,1,0.5],[0.7,0.8,1,0.3],[0.7,0.8,1,0.2],[0.7,0.8,1,0.1],[0.7,0.8,1,0]],
	[1000], 0.1, 0.05, "", "", _Particle_source];
  _Particle_source setParticleRandom [2,[2,2,0.5],[0.4,0.4,0.4],3,0.4,[0,0,0,0.12],0,0,1];

  //Return
  _Sources pushBack _Particle_source;
  _plane setVariable ["AAE_Vapor_Paricles",_Sources];
};

//Vars
_Vapor_Paricles = _plane getVariable ["AAE_Vapor_Paricles",[]];

waituntil {
  //Set Interval
  {
    private _interval = (0.025-(0.000013*(Speed _plane))) max 0.01;
    _x setDropInterval _interval;
  } forEach _Vapor_Paricles;

  !(_plane getVariable ["AAE_Vapor_Activated",false])
};

{deleteVehicle _x} foreach _Vapor_Paricles;
_plane setVariable ["AAE_Vapor_Paricles",nil];
