params ["_plane","_engine1","_engine2","_AGL_POS","_ASL_POS","_ATL_POS","_ASLW_POS","_velocity","_speed"];

_beach = configFile >> "CfgCloudlets" >> "AAE_Dust01" >> "Color";
_dust = configFile >> "CfgCloudlets" >> "AAE_Dust01" >> "Color";
_other = configFile >> "CfgCloudlets" >> "AAE_Dust01" >> "Color";
_water = configFile >> "CfgCloudlets" >> "AAE_Water01" >> "Color";

_Height = _AGL_POS # 2;
_groundH = _ATL_POS # 2;
_seaH = _ASLW_POS # 2;

_backPos = _engine1;

_Depos = [((_AGL_POS select 0) + (_backPos select 0)), ((_AGL_POS select 1) + (_backPos select 1)), 0];
_SDepos = [((_ASLW_POS select 0) + (_backPos select 0)), ((_ASLW_POS select 1) + (_backPos select 1)), 0];

_effect = {
	_source00 = "#particlesource" createVehicleLocal _Depos;
	_source01 = "#particlesource" createVehicleLocal _Depos;

	_source00 setParticleParams [
	["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 13, 0], "", "Billboard",
	1, 1, [((_velocity # 0) * 0.01), (((_velocity # 1) * 0.01) - (_speed*0.05)), 0], [0, 0, 0], 1.25, 1, 1, 0.01, [4,6,0],
	(getArray SurfaceType_Pick),
	[0], 0.1, 0.05, "", "", _plane, 0, true];
	_source00 setParticleCircle [1.2, [(_speed*0.02), (_speed*0.02), 1]];
	_source01 setParticleRandom [0.4, [4, 4, 0.5], [5,1,1], 0.5, 0.2, [0, 0, 0, 0], 0, 0, 0];
	_source00 setDropInterval 0.005;

	_source01 setParticleParams [
	["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 13, 0], "", "Billboard",
	1, 2, [((_velocity # 0) * 0.01), (((_velocity # 1) * 0.01) - (_speed*0.05)), 0], [0, 0, 0], 1.25, 1, 1, 0.01, [20,12,0],
	(getArray SurfaceType_Pick),
	[0], 0.1, 0.05, "", "", _plane, 0, true];
	_source01 setParticleCircle [3, [(_speed*0.02), (_speed*0.02), 0]];
	_source01 setParticleRandom [0.4, [10, 4, 0.5], [5,1,1], 0.5, 0.2, [0, 0, 0, 0], 0, 0, 0];
	_source01 setDropInterval 0.005;

	sleep 0.08;
	//waituntil {!(_plane getVariable ["AAE_Ground_Activated", false])};
	deleteVehicle _source00;
	deleteVehicle _source01;
};

//Dust Effect
if ((_groundH >= 5) and (_groundH <= groundP_sdr)) then {

	if ((surfaceType _Depos != "#GdtStratisConcrete") and (surfaceType _Depos != "#GdtConcrete") and (surfaceType _Depos != "#GdtSeabed") and (surfaceType _Depos != "#GdtBeach") and !(surfaceIsWater getpos _plane)) then {
		PlanePOS = _ATL_POS;
		SurfaceType_Pick = _dust;
		call _effect;
	};
};

//Water Effect
if ((_seaH >= 5) and (_seaH <= groundP_sdr)) then {

	if (surfaceIsWater _SDepos) then {
		PlanePOS = _ASLW_POS;
		SurfaceType_Pick = _water;
		call _effect;

	} else {
		//Beach
		if ((surfaceType _Depos == "#GdtBeach") and !(surfaceIsWater _AGL_POS)) then {
			PlanePOS = _ATL_POS;
			SurfaceType_Pick = _beach;
			call _effect;

		};
	};
};

//Other Effect
/* if ((_groundH >= 5) and (_groundH <= groundP_sdr)) then {
	if (surfaceType _Depos == "#GdtConcrete") then {
		PlanePOS = _AGL_POS;
		SurfaceType_Pick = _other;
		call _effect;

	};
}; */
