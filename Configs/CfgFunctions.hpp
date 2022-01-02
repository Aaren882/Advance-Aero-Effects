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
			class SurfaceTypeEH;
			class DeletedEH;
		};
		//Counter
		class Counters
		{
			file="MG8\AVDAVFX\Functions\General\Counters";
			class Ground_Counter;
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
			//class sonicboom2;
			class vapor;
			class camshake;
			class gForces;
			class gearFactor;
		};
		class WheelsFn
		{
			file="MG8\AVDAVFX\Functions\Wheels";
			class wheels;
			class landingEH;
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
};