params["_plane"];

//////////////////////////////Functions/////////////////////////////////////////
_particle_Setups = {
	params [
		"_source00","_source01",
		"_ParticleShape",
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
	_ParticleShape, "", "Billboard",
	1, _Particle01_Time, [0, (((_velocity # 1) * 0.05) - (_speed*0.05)), 0], [0, 0, 0], 1.25, _weight, _volume, 0.1, _Particle01_Size,
	(getArray _SurfaceType_Pick),
	[1000], 0.1, 0.05, "", "", _source01, 0, true];
};

_particles = {
	params["_plane","_SurfaceType_Pick","_Depos","_velocity","_speed","_ParticleShape","_Particle_Settings","_Particle00_Setups","_Particle01_Setups","_particle_Setups"];
	//Definitions
	_weight = _Particle_Settings # 0;
	_volume = _Particle_Settings # 1;

	_Particle00_Time = _Particle00_Setups # 0;
	_Particle01_Time = _Particle01_Setups # 0;

	_Particle00_Size = _Particle00_Setups # 1;
	_Particle01_Size = _Particle01_Setups # 1;

	_particle01_CycleSpeed = _Particle01_Setups # 2;

	_SurfaceChanged = _plane getVariable ["AAE_Ground_Type_Changed",false];

	//Math Stuff
	_Engine_Offset = -0.06*_speed;

	//Speed Limitations
	if (_speed <= 300) then {
	   _speed = 300;
	};
	if (_speed >= 500) then {
	   _speed = 500;
	};

	//FAKE Particle Sources
	_source00 = objNull;
	_source01 = objNull;

	//Vars
	_Ground_Paricles = _plane getVariable ["AAE_Ground_Paricles",[]];
	_Particle_Count = count _Ground_Paricles;

	if (_Particle_Count == 0) then {
		//True Particle Sources
		_source00 = "#particlesource" createVehicleLocal _Depos;
		_source01 = "#particlesource" createVehicleLocal _Depos;
		_plane setVariable ["AAE_Ground_Paricles", [_source00,_source01]];

		//Particle Effects
		[
		_source00,_source01,
		_ParticleShape,
		_Particle00_Time,_Particle01_Time,
		_velocity,_speed,
		_weight,_volume,
		_Particle00_Size,_Particle01_Size,
		_SurfaceType_Pick] call _particle_Setups;
	};

	if (_Particle_Count > 0) then {

		_source00 = _Ground_Paricles # 0;
		_source01 = _Ground_Paricles # 1;
		_source00 attachTo [_plane, [0, (-5 + _Engine_Offset),0]];
		_source01 attachTo [_plane, [0, (-5 + _Engine_Offset),0]];

		//Source00
		_source00 setParticleCircle [1.2, [(_speed*0.02), (_speed*0.02), 1]];
		_source00 setParticleRandom [0.8, [0, 0, 0], [0, 0, 0], 10, 0.4, [0, 0, 0, 0], 0.1, 0.05, 0];
		_source00 setDropInterval 0.005;
		//Source01
		_source01 setParticleCircle [5, [(_speed*_particle01_CycleSpeed), (_speed*_particle01_CycleSpeed), 0]];
		_source01 setParticleRandom [0.8, [0, 0, 0], [0.1,0.1,2], 20, 0.4, [0, 0, 0, 0], 0.1, 0.05, 0];
		_source01 setDropInterval 0.005;
	};

	if ((isNull _plane) or !(_plane getVariable "AAE_Ground_Activated") or (_SurfaceChanged)) then {
		if (_Particle_Count > 0) then {
			{deleteVehicle _x} foreach _Ground_Paricles;
			_plane setVariable ["AAE_Ground_Paricles", []];
			_plane setVariable ["AAE_Ground_Activated",false];
		};
	};
};

_effect = {
	params["_plane","_Particle_Pick","_Depos","_velocity","_speed","_particles","_ParticleShape","_Particle_Settings","_Particle00_Setups","_Particle01_Setups","_particle_Setups"];

	//Color Picking
	_SurfaceType_Pick = configFile >> "CfgVehicles">> typeOf _plane >> "AAE_Config_Handler" >> _Particle_Pick;

	[_plane,_SurfaceType_Pick,_Depos,_velocity,_speed,_ParticleShape,_Particle_Settings,_Particle00_Setups,_Particle01_Setups,_particle_Setups] call _particles;
};
////////////////////////////////////////////////////////////////////////////////

_Particle_Pick = _plane getVariable ["AAE_Ground_Type","Default"];

waitUntil {
	_ParticleShape = ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 13, 0];

	_Particle00_Time = 2;
	_Particle01_Time = 4;

	_Particle00_Size = [4,6];
	_Particle01_Size = [5,10,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15];

	_particle01_CycleSpeed = 0.02;

	_weight = 2.2;
	_volume = 0.8;

	_Depos = _plane modelToWorld [0,-5,0];

	_speed = speed _plane;
	_velocity = velocity _plane;

	//SurfaceType Eventhadler
	call AAE_fnc_SurfaceTypeEH;

	//Activations
	//Water
	if (surfaceIsWater _Depos) then {
		_Particle01_Size = [3,5,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7];

		_Particle00_Time = 1;
		_Particle01_Time = 2;

		_ParticleShape = ["\A3\data_f\ParticleEffects\Universal\Universal", 16, 13, 10, 0];
	};

	[
		_plane,_Particle_Pick,_Depos,_velocity,_speed,_particles,_ParticleShape,
		[_weight,_volume],
		[_Particle00_Time,_Particle00_Size],
		[_Particle01_Time,_Particle01_Size,_particle01_CycleSpeed],
		_particle_Setups
	] call _effect;

	!(_plane getVariable ["AAE_Ground_Activated",false])
};
