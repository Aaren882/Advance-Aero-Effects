class CfgFunctions
{
	class AAE
	{
		class MainInit
		{
			file="MG8\AVDAVFX\Functions";
			class Init;
		};
		//Eventhandlers
		class Eventhandlers
		{
			file="MG8\AVDAVFX\Functions\Eventhanders";
			class EngineEH;
			class GearEH;
			class InitEH;
			class SurfaceTypeEH;
			class DeleteEH;
			class landedEH;
		};
		//Components
		class ComponentsFn
		{
			file="MG8\AVDAVFX\Functions\Components";
			class Main_process;
			class Fast_process;
			class Exhaust_Dir;
			class Find_engine;
			class Exhaust_Offsets;
		};
		//Sound Handler
		class SoundFn
		{
			file="MG8\AVDAVFX\Functions\Sound";
			class Play_Sound;
			class Play_Sound3D;
			class PlayAlarm;
			class PlayBreathing;
			class PlayRumA;
			class PlayRumB;
		};
		class GeneralFn
		{
			file="MG8\AVDAVFX\Functions\General";
			class ground;
			class sonicboom;
			class vapor;
			class camshake;
			class gForces;
			class gearFactor;
			class Burner;
		};
		class LandedFn
		{
			file="MG8\AVDAVFX\Functions\Wheels";
			class wheels;
			class landed;
			class execution;
			class taxing;
		};
		class TurbulentFn
		{
			file="MG8\AVDAVFX\Functions\Turbulent";
			class turbulent;
			class turbulentW;
			class turbulentSnd;
		};
	};
	class A3_Jets
	{
		class AircrfatCarrier
		{
			delete Carrier01CatapultActionAdd;
		};
		class AAE
		{
			file="MG8\AVDAVFX\Functions\Carrier";
			class Carrier01CatapultActionAdd;
		};
	};
};