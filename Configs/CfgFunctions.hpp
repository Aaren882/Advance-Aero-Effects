class CfgFunctions
{
	class AAE
	{
		class MainInit
		{
			file="MG8\AVDAVFX\Functions";
			class Init;
			class ServerPFH;
			class ClientPFH;
		};
		//Eventhandlers
		class Eventhandlers
		{
			file="MG8\AVDAVFX\Functions\Eventhanders";
			class EngineEH;
			class InitEH;
			class SurfaceTypeEH;
			class VolumeChangedEH;
			class DeleteEH;
			class landedEH;
		};
		//Components
		class ComponentsFn
		{
			file="MG8\AVDAVFX\Functions\Components";
			class Main_process;
			class Find_engine;
			class Exhaust_Offsets;
			class ChangeVolume;
			class wheels;
			class getSoundVolume;
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
			class taxiing;
		};
		class LandedFn
		{
			file="MG8\AVDAVFX\Functions\Landed";
			class landed;
			class Cooldown;
		};
		class TurbulenceFn
		{
			file="MG8\AVDAVFX\Functions\Turbulence";
			class turbulence;
			class turbulenceW;
			class turbulenceSnd;
		};
	};
	//Catapult FX
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
	class A3
	{
		class Effects
		{
			delete effectKilled;
		};
		class AAE
		{
			file = "MG8\AVDAVFX\Functions\General";
			class effectKilled;
		};
	};
	class TTT
	{
		class CatapultEvents
		{
			delete launchPlane;
		};
		class AAE
		{
			file="MG8\AVDAVFX\Functions\Carrier";
			class launchPlane;
		};
	};
};
