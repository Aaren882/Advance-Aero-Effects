params ["_plane","_Exhausts_count","_engine_offsets"];

_engine_offsets params [["_engine1",[0,0,0]],["_engine2",[0,0,0]],["_engine3",[0,0,0]],["_engine4",[0,0,0]]];

_source = "#particlesource";
_effect = "AAE_Vapor_Trail";

//Vapor Effect
switch (_Exhausts_count) do
{
  case 1: {
    _particle_source00 = _source createVehicleLocal [0,0,0];
    _particle_source00 attachTo [_plane, _engine1];
    _particle_source00 setParticleClass _effect;
    _plane setVariable ["AAE_Vapor_Paricles",[_particle_source00]];
  };
  case 2: {
    _particle_source00 = _source createVehicleLocal [0,0,0];
    _particle_source01 = _source createVehicleLocal [0,0,0];
    _particle_source00 setParticleClass _effect;
    _particle_source01 setParticleClass _effect;
    _particle_source00 attachTo [_plane, _engine1];
    _particle_source01 attachTo [_plane, _engine2];
    _plane setVariable ["AAE_Vapor_Paricles",[_particle_source00,_particle_source01]];
  };
  case 3: {
    _particle_source00 = _source createVehicleLocal [0,0,0];
    _particle_source01 = _source createVehicleLocal [0,0,0];
    _particle_source02 = _source createVehicleLocal [0,0,0];
    _particle_source00 setParticleClass _effect;
    _particle_source01 setParticleClass _effect;
    _particle_source02 setParticleClass _effect;
    _particle_source00 attachTo [_plane, _engine1];
    _particle_source01 attachTo [_plane, _engine2];
    _particle_source02 attachTo [_plane, _engine3];
    _plane setVariable ["AAE_Vapor_Paricles",[_particle_source00,_particle_source01,_particle_source02]];
  };
  case 4: {
    _particle_source00 = _source createVehicleLocal [0,0,0];
    _particle_source01 = _source createVehicleLocal [0,0,0];
    _particle_source02 = _source createVehicleLocal [0,0,0];
    _particle_source03 = _source createVehicleLocal [0,0,0];
    _particle_source00 setParticleClass _effect;
    _particle_source01 setParticleClass _effect;
    _particle_source02 setParticleClass _effect;
    _particle_source03 setParticleClass _effect;
    _particle_source00 attachTo [_plane, _engine1];
    _particle_source01 attachTo [_plane, _engine2];
    _particle_source02 attachTo [_plane, _engine3];
    _particle_source03 attachTo [_plane, _engine4];
    _plane setVariable ["AAE_Vapor_Paricles",[_particle_source00,_particle_source01,_particle_source02,_particle_source03]];
  };
};

waituntil {
  !(_plane getVariable ["AAE_Vapor_Activated",false])
};
//Vars
_Vapor_Paricles = _plane getVariable ["AAE_Vapor_Paricles",[]];
{deleteVehicle _x} foreach _Vapor_Paricles;
_plane setVariable ["AAE_Vapor_Paricles",[]];
