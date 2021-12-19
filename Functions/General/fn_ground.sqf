params ["_plane","_engine1","_engine2","_AGL_POS","_ASL_POS","_ATL_POS","_ASLW_POS","_velocity","_speed","_Surfacetype"];

//////////////////////////////Functions/////////////////////////////////////////

_particles = {
	params["_plane","_SurfaceType_Pick","_Depos","_velocity","_speed","_ParticleShape","_engine1","_Particle00_Setups","_Particle01_Setups"];
	//Definations
	_Particle00_Time = _Particle00_Setups # 0;
	_Particle01_Time = _Particle01_Setups # 0;

	_Particle00_Size = _Particle00_Setups # 1;
	_Particle01_Size = _Particle01_Setups # 1;

	_particle01_CycleSpeed = _Particle01_Setups # 2;

	_SurfaceChanged = _plane getVariable ["AAE_Ground_Type_Changed",false];
	//_Ground_Particles_Refrash = _plane getVariable ["AAE_Ground_Particles_Refrash",false];

	//Speed Limitation
	if (_speed <= 250) then {
	   _speed = 250;
	};
	if (_speed >= 400) then {
	   _speed = 400;
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
	};

	_Ground_Paricles = _plane getVariable ["AAE_Ground_Paricles",[]];
	_Particle_Count = count _Ground_Paricles;

	if (_Particle_Count > 0) then {
		_source00 = _Ground_Paricles # 0;
		_source01 = _Ground_Paricles # 1;
		_source00 setPos _Depos;
		_source01 setPos _Depos;
	};

	if (_Particle_Count > 0) then {
		_source00 setParticleParams [
		_ParticleShape, "", "Billboard",
		1, _Particle00_Time, [((_velocity # 0) * 0.05), (((_velocity # 1) * 0.05) - (_speed*0.05)), 0], [0, 0, 0], 1.25, 2.2, 0.8, 0.1, _Particle00_Size,
		(getArray _SurfaceType_Pick),
		[1000], 0.1, 0.05, "", "", _plane, 0, true];
		_source00 setParticleCircle [1.2, [(_speed*0.02), (_speed*0.02), 1]];
		_source00 setDropInterval 0.005;

		_source01 setParticleParams [
		_ParticleShape, "", "Billboard",
		1, _Particle01_Time, [((_velocity # 0) * 0.05), (((_velocity # 1) * 0.05) - (_speed*0.05)), 0], [0, 0, 0], 1.25, 2.2, 0.8, 0.1, _Particle01_Size,
		(getArray _SurfaceType_Pick),
		[1000], 0.1, 0.05, "", "", _plane, 0, true];
		_source01 setParticleCircle [5, [(_speed*_particle01_CycleSpeed), (_speed*_particle01_CycleSpeed), 0]];
		_source01 setParticleRandom [0.8, [0, 0, 0], [1,1,1], 20, 0.2, [0, 0, 0, 0], 0.1, 0.05, 0];
		_source01 setDropInterval 0.005;
	};

	if ((isNull _plane)or !(_plane getVariable "AAE_Ground_Activated") or _SurfaceChanged or (_plane getVariable ["AAE_Ground_Particles_Refrash",false])) then {
		if (_Particle_Count > 0) then {
			{deleteVehicle _x} foreach _Ground_Paricles;
			_plane setVariable ["AAE_Ground_Paricles", []];
		};
	};
};

_effect = {
	params["_plane","_Particle_Pick","_Depos","_velocity","_speed","_particles","_ParticleShape","_engine1","_Particle00_Setups","_Particle01_Setups"];

	//Color Picking
	_SurfaceType_Pick = configFile >> "CfgVehicles">> typeOf _plane >> "AAE_Config_Handler" >> _Particle_Pick;

	[_plane,_SurfaceType_Pick,_Depos,_velocity,_speed,_ParticleShape,_engine1,_Particle00_Setups,_Particle01_Setups] spawn _particles;
};
////////////////////////////////////////////////////////////////////////////////

//Definations
/* _beach = "Beach";
_dust = "Dust";
_Default = "Default";
_water = "Water"; */

_Particle_Pick = _Surfacetype;

_ParticleShape = ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 13, 0];

_Particle00_Time = 1.2;
_Particle01_Time = 3;

_Particle00_Size = [4,6];
_Particle01_Size = [5,10,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15];

_particle01_CycleSpeed = 0.02;

_Height = _AGL_POS # 2;
_groundH = _ATL_POS # 2;
_seaH = _ASLW_POS # 2;

//_backPos = _plane modelToWorld [0,(_engine1 # 1),0];
_backPos = [0,(_engine1 # 1),0];

_Depos = [((_AGL_POS select 0) + (_backPos select 0)), ((_AGL_POS select 1) + (_backPos select 1)), 0];
_SDepos = [((_ASLW_POS select 0) + (_backPos select 0)), ((_ASLW_POS select 1) + (_backPos select 1)), 0];

//SurfaceType Eventhadler
[_plane,_Surfacetype,_Depos] spawn AAE_fnc_SurfaceTypeEH;

//Activations
//Water
if (surfaceIsWater _SDepos) then {

	_Particle00_Time = 0.4;
	_Particle01_Time = 0.8;

	_Particle01_Size = [3,5,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7];

	_particle01_CycleSpeed = 0.05;

	_ParticleShape = ["\A3\data_f\ParticleEffects\Universal\Universal", 16, 13, 10, 0];
};

[
	_plane,_Particle_Pick,_Depos,_velocity,_speed,_particles,_ParticleShape,
	_engine1,
	[_Particle00_Time,_Particle00_Size],
	[_Particle01_Time,_Particle01_Size,_particle01_CycleSpeed]
] call _effect;
