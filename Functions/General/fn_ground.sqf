params["_plane"];

//////////////////////////////Functions/////////////////////////////////////////
private _particle_Setups = {
	params [
		"_source00","_source01",
		"_ParticleShape","_ParticleShape01",
		"_Particle00_Time","_Particle01_Time",
		"_velocity","_speed",
		"_weight","_volume",
		"_Particle00_Size","_Particle01_Size",
		"_SurfaceType_Pick"
	];
	
	_source00 setParticleParams [
	_ParticleShape, "", "Billboard",
	1, _Particle00_Time, [0, (((_velocity # 1) * 0.05) - (_speed*0.05)), 0], [0, 0, 0], 1.25, _weight, _volume, 0.1, _Particle00_Size,
	(getArray _SurfaceType_Pick),
	[1000], 0.1, 0.05, "", "", _source00, 0, true];

	_source01 setParticleParams [
	_ParticleShape01, "", "Billboard",
	1, _Particle01_Time, [0, (((_velocity # 1) * 0.05) - (_speed*0.05)), 0], [0, 0, 0], 1.25, _weight, _volume, 0.1, _Particle01_Size,
	(getArray _SurfaceType_Pick),
	[1000], 0.1, 0.05, "", "", _source01, 0, true];
};

private _particles = {
	params["_plane","_SurfaceType_Pick","_Depos","_velocity","_speed","_particle01_CycleSpeed"];

	//Math Stuff
	_Engine_Offset = -0.06*_speed;

	//Speed Limitations
	if (_speed <= 300) then {
	   _speed = 300;
	};
	if (_speed >= 500) then {
	   _speed = 500;
	};

	//Vars
	_Ground_Paricles = _plane getVariable ["AAE_Ground_Particles",[]];

	if (count _Ground_Paricles > 0) then {
		_Ground_Paricles params["_source00","_source01"];

		_source00 attachTo [_plane, [0, (_Engine_Offset - 5),0]];
		_source01 attachTo [_plane, [0, (_Engine_Offset - 5),0]];

		//Source00
		_source00 setParticleCircle [1.2, [(_speed*0.02), (_speed*0.02), 1]];
		_source00 setParticleRandom [0.8, [0, 0, 0], [0, 0, 0], 10, 0.4, [0, 0, 0, 0], 0.1, 0.05, 0];
		_source00 setDropInterval 0.005;
		//Source01
		_source01 setParticleCircle [5, [(_speed*_particle01_CycleSpeed), (_speed*_particle01_CycleSpeed), 0]];
		_source01 setParticleRandom [0.8, [0, 0, 0], [0.1,0.1,2], 20, 0.4, [0, 0, 0, 0], 0.1, 0.05, 0];
		_source01 setDropInterval 0.005;
	};
};

_effect = {
	params["_plane","_Particle_Pick","_Depos","_velocity","_speed","_particle01_CycleSpeed"];

	//Color Picking
	_SurfaceType_Pick = configFile >> "CfgVehicles">> typeOf _plane >> "AAE_Config_Handler" >> _Particle_Pick;

	[_plane,_SurfaceType_Pick,_Depos,_velocity,_speed,_particle01_CycleSpeed] call _particles;
};
////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------//

_Ground_Paricles = _plane getVariable ["AAE_Ground_Particles",[]];
_Depos = _plane modelToWorld [0,-5,0];

//SurfaceType Eventhadler
call AAE_fnc_SurfaceTypeEH;
_Particle_Pick = _plane getVariable ["AAE_Ground_Type","Default"];

_source00 = "#particlesource" createVehicleLocal [0,0,0];
_source01 = "#particlesource" createVehicleLocal [0,0,0];
_plane setVariable ["AAE_Ground_Particles", [_source00,_source01]];

_SurfaceType_Pick = configFile >> "CfgVehicles">> typeOf _plane >> "AAE_Config_Handler" >> _Particle_Pick;

_ParticleShape = ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 13, 0];
_ParticleShape01 = _ParticleShape;
_Particle00_Time = 2;
_Particle01_Time = 4;

_Particle00_Size = [4,6];
_Particle01_Size = [5,10,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15];

_weight = 2.2;
_volume = 0.8;

_speed = speed _plane;
_velocity = velocity _plane;

//Activations
//Water
if (surfaceIsWater _Depos) then {
	_Particle00_Size = [2,4];
	_Particle01_Size = [3,5,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7];

	_Particle00_Time = 1.5;
	_Particle01_Time = 2;

	_weight = 1.5;
	_volume = 0.8;

	_ParticleShape = ["\A3\data_f\ParticleEffects\Universal\UniversalOnSurface", 16, 13, 11, 0];
	//_ParticleShape01 = ["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 13, 0];
};

//Particle Effects
[
	_source00,_source01,
	_ParticleShape,_ParticleShape01,
	_Particle00_Time,_Particle01_Time,
	_velocity,_speed,
	_weight,_volume,
	_Particle00_Size,_Particle01_Size,
	_SurfaceType_Pick
] call _particle_Setups;

//----------------------------------------------------------------------------------------//
[{
	params["_plane","_particles","_effect","_Particle_Pick","",""];
	_Depos = _plane modelToWorld [0,-5,0];

	//SurfaceType Eventhadler
	call AAE_fnc_SurfaceTypeEH;

	_speed = speed _plane;
	_velocity = velocity _plane;

	//_particle01_CycleSpeed = 0.02;

	[
		_plane,_Particle_Pick,_Depos,_velocity,_speed,0.02
	] call _effect;

	(!(alive _plane) || !(_plane getVariable ["AAE_Ground_Activated",false]))
},{
	params["_plane","","","","_source00","_source01"];
	//Vars
	{deleteVehicle _x} foreach [_source00,_source01];
	_plane setVariable ["AAE_Ground_Particles",nil];
}, [
		_plane,_particles,_effect,_Particle_Pick,_source00,_source01
	]
] call CBA_fnc_waitUntilAndExecute;
