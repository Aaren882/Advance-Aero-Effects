class CfgPatches
{
	class AVDAVFX
	{
		units[]={};
		weapons[]={};
		requiredVersion=2;
		requiredAddons[]=
		{
			#if __has_include("\FIR_AirWeaponSystem_US_cfg\config.bin")
				"FIR_AirWeaponSystem_US",
			#endif
			//Super Hornet
			#if __has_include("\js_jc_fa18\config.bin")
				"JS_JC_FA18",
			#endif
			"A3_Air_F",
			"A3_Data_F",
			"A3_Data_F_Jets",
			"A3_Data_F_Sams",
			"A3_Weapons_F",
			"A3_Weapons_F_Jets",
			"A3_Weapons_F_Sams",
			"A3_Data_F_ParticleEffects",
			"A3_Air_F_Beta_Heli_Transport_01",
			"A3_Air_F_Heli_Heli_Transport_03",
			"A3_Air_F_EPC_Plane_CAS_01",
			"A3_Air_F_Jets_Plane_Fighter_01",
			"A3_Air_F_Jets_Plane_Fighter_02",
			"A3_Air_F_Jets_Plane_Fighter_04",
			"A3_Functions_F",
			"A3_Functions_F_Jets",
			"A3_Structures_F_Enoch_VR_Helpers"
		};
	};
};

class DefaultEventHandlers;

class Extended_PreInit_EventHandlers
{
	class AAE_EH
	{
		init = "call compile preprocessFileLineNumbers 'MG8\AVDAVFX\XEH_preInit.sqf'";
	};
};
class Extended_PostInit_EventHandlers
{
	class AAE_EH
	{
		init = "call compile preprocessFileLineNumbers 'MG8\AVDAVFX\XEH_postInit.sqf'";
	};
};
class CfgVehicles
{
	class AllVehicles;
	class Air: AllVehicles
	{
		Aircraft_WingSpan = 14;
		AAE_Have_AB = 0;
		class Eventhandlers: DefaultEventHandlers {};
		#include "Configs\AAE_Settings.hpp"
	};

	class Plane: Air {};
	class Plane_Base_F: Plane {};
	class UAV;
	
	//Vapor Effects
	#include "Wing_Effect\Jet_Configs.hpp"

	//Plane MODs
	#include "Configs\CfgVehicles.hpp"

	//Helis
	class Helicopter_Base_H;

	#include "Configs\Skins.hpp"
	#include "Configs\Heli_Settings.hpp"

	///////////////////////////After Burner///////////////////////////////
	class Reflector_Base_F;
	class Reflector_Cone_01_base_F: Reflector_Base_F
	{
		class Reflectors
		{
			class Light_1;
			class Light_1_Flare;
		};
	};
	class AAE_AfterBurner_Reflector: Reflector_Cone_01_base_F
	{
		scope = 1;
		scopeCurator = 0;
		displayName = "After Burner (Advance Aero Effects)";
		class Reflectors: Reflectors
		{
			class Light_1: Light_1
			{
				color[] = {0.8,0.2,0};
				ambient[] = {0.8,0.2,0};
				intensity = 5000;
				innerAngle = 0;
				outerAngle = 120;
				coneFadeCoef = 3;
				class Attenuation
				{
					start = 0;
					constant = 0;
					linear = 5;
					quadratic = 1;
					hardLimitStart = 0.1;
					hardLimitEnd = 10;
				};
			};
			class Light_2: Light_1_Flare
			{
				useFlare = 0;
				color[] = {0.07,0.06,1};
				ambient[] = {0.07,0.06,1};
				intensity = 60000;
				innerAngle = 5;
				outerAngle = 60;
				coneFadeCoef = 8;
				class Attenuation
				{
					start = 0.2;
					constant = 0;
					linear = 5;
					quadratic = 1;
					hardLimitStart = 0.1;
					hardLimitEnd = 3;
				};
			};
		};
	};
	class AAE_AfterBurner_Reflector_Flare: AAE_AfterBurner_Reflector
	{
		displayName = "After Burner Flare (Advance Aero Effects)";
		class Reflectors: Reflectors
		{
			class Light_1_Flare: Light_1_Flare
			{
				color[]={1,0.58,0.16};
				ambient[]={1,0.58,0.16};
				diffuse[]={1,0.58,0.16};
				intensity = 70;
				innerAngle = 60;
				outerAngle = 120;
				coneFadeCoef = 4;

				useFlare = 1;
				flareSize = 5;
				flareMaxDistance = 20000;
				drawLight=1;
				dayLight=1;
				brightness=2;
				class Attenuation
				{
					start = 0;
					constant = 0;
					linear = 1;
					quadratic = 1;
					hardLimitStart = 0.01;
					hardLimitEnd = 0.01;
				};
			};
		};
	};
};
////////////////////////////////////
class CfgMagazines
{
	class VehicleMagazine;
	class magazine_Missile_AMRAAM_C_x1: VehicleMagazine
	{
		initSpeedY = -10;
	};
	class magazine_Missile_AMRAAM_D_x1: VehicleMagazine
	{
		initSpeedY = -10;
	};
};
////////////////////////////////////
//CfgFunctions
#include "Configs\CfgFunctions.hpp"

//CfgWeapons
#include "Configs\CfgWeapons.hpp"

//CfgAmmo
#include "Configs\CfgAmmo.hpp"

//CfgCloudlets
#include "Configs\CfgCloudlets.hpp"

//Effects
#include "Effects.hpp"

//Sound Effects
#include "Configs\CfgSounds.hpp"
