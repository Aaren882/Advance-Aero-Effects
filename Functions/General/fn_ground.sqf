params ["_plane","_engine1","_engine2","_AGL_POS","_ASL_POS","_ATL_POS","_ASLW_POS","_velocity","_speed"];

//////////////////////////////Functions/////////////////////////////////////////
_particles = {
	params["_plane","_SurfaceType_Pick","_Depos","_velocity","_speed"];

	if (count Ground_Paricles != 1) then {
		Ground_source00 = "#particlesource" createVehicleLocal _Depos;
		Ground_source01 = "#particlesource" createVehicleLocal _Depos;
		Ground_Paricles pushback [Ground_source00,Ground_source01];
	};
	if (AAE_Ground_Type_Changed && (count Ground_Paricles) > 0) then {
		Ground_source00 setParticleParams [
		["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 13, 0], "", "Billboard",
		1, 1, [((_velocity # 0) * 0.01), (((_velocity # 1) * 0.01) - (_speed*0.05)), 0], [0, 0, 0], 1.25, 1, 1, 0.01, [4,6,0],
		(getArray _SurfaceType_Pick),
		[0], 0.1, 0.05, "", "", _plane, 0, true];
		Ground_source00 setParticleCircle [1.2, [(_speed*0.02), (_speed*0.02), 1]];
		Ground_source00 setParticleRandom [0.4, [4, 4, 0.5], [5,1,1], 0.5, 0.2, [0, 0, 0, 0], 0, 0, 0];
		Ground_source00 setDropInterval 0.005;

		Ground_source01 setParticleParams [
		["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 13, 0], "", "Billboard",
		1, 2, [((_velocity # 0) * 0.01), (((_velocity # 1) * 0.01) - (_speed*0.05)), 0], [0, 0, 0], 1.25, 1, 1, 0.01, [20,12,0],
		(getArray _SurfaceType_Pick),
		[0], 0.1, 0.05, "", "", _plane, 0, true];
		Ground_source01 setParticleCircle [3, [(_speed*0.02), (_speed*0.02), 0]];
		Ground_source01 setParticleRandom [0.4, [10, 4, 0.5], [5,1,1], 0.5, 0.2, [0, 0, 0, 0], 0, 0, 0];
		Ground_source01 setDropInterval 0.005;

		hintsilent str [(getArray _SurfaceType_Pick),time];
	};
	waitUntil {!(_plane getVariable "AAE_Ground_Activated")};
	if (count Ground_Paricles > 0) then {
		deleteVehicle Ground_source00;
		deleteVehicle Ground_source01;
		Ground_Paricles = [];
	};
};

_effect = {
	params["_plane","_Particle_Pick","_Depos","_velocity","_speed","_particles"];

	//Color Picking
	_SurfaceType_Pick = configFile >> "CfgVehicles">> typeOf _plane >> "AAE_Config_Handler" >> _Particle_Pick;

	[_plane,_SurfaceType_Pick,_Depos,_velocity,_speed] spawn _particles;
};
////////////////////////////////////////////////////////////////////////////////

//Definations
_beach = "Beach";
_dust = "Dust";
_Default = "Default";
_water = "Water";

Particle_Pick = "Default";

_Height = _AGL_POS # 2;
_groundH = _ATL_POS # 2;
_seaH = _ASLW_POS # 2;

_backPos = _engine1;

_Depos = [((_AGL_POS select 0) + (_backPos select 0)), ((_AGL_POS select 1) + (_backPos select 1)), 0];
_SDepos = [((_ASLW_POS select 0) + (_backPos select 0)), ((_ASLW_POS select 1) + (_backPos select 1)), 0];

//Activations
if ((_groundH >= 5) and (_groundH <= groundP_sdr)) then {
	//Dust
	if ((surfaceType _Depos != "#GdtStratisConcrete") and (surfaceType _Depos != "#GdtConcrete") and (surfaceType _Depos != "#GdtSeabed") and (surfaceType _Depos != "#GdtBeach") and !(surfaceIsWater getpos _plane)) then {
		Particle_Pick = _dust;
		call AAE_fnc_SurfaceTypeEH;
		[_plane,Particle_Pick,_Depos,_velocity,_speed,_particles] spawn _effect;
	};
};

if ((_seaH >= 5) and (_seaH <= groundP_sdr)) then {
	//Water
	if (surfaceIsWater _SDepos) then {
		Particle_Pick = _water;
		call AAE_fnc_SurfaceTypeEH;
		[_plane,Particle_Pick,_Depos,_velocity,_speed,_particles] spawn _effect;

	} else {
		//Beach
		if ((surfaceType _Depos == "#GdtBeach") and !(surfaceIsWater _AGL_POS)) then {
			Particle_Pick = _beach;
			call AAE_fnc_SurfaceTypeEH;
			[_plane,Particle_Pick,_Depos,_velocity,_speed,_particles] spawn _effect;
		};
	};
};
