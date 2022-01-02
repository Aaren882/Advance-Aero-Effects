class CfgPatches
{
	class AVDAVFX
	{
		units[]={};
		weapons[]={};
		requiredVersion=2;
		requiredAddons[]=
		{
			"A3_Air_F",
			"A3_Data_F",
			"A3_Data_F_Jets",
			"A3_Weapons_F",
			"A3_Weapons_F_Jets",
			"A3_Data_F_ParticleEffects",
			"A3_Air_F_Beta_Heli_Transport_01",
			"A3_Air_F_Heli_Heli_Transport_03",
			"A3_Air_F_EPC_Plane_CAS_01",
			"A3_Air_F_Jets_Plane_Fighter_01",
			"A3_Air_F_Jets_Plane_Fighter_02",
			"A3_Air_F_Jets_Plane_Fighter_04"
		};
	};
};

/*class AAE_EH
{
	engine="_this execVM 'MG8\AVDAVFX\Functions\fn_init.sqf'";
	LandedTouchDown="if (TDSound_fn) then {playSound [""touchdown"", true]};";
	engine="_this execvm 'MG8\AVDAVFX\Functions\Turbulent\fn_turbulentInit.sqf'";
};*/

class DefaultEventHandlers
{
	//class AAE_EH: AAE_EH{};
};

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
/*class Extended_PreStart_EventHandlers
{
	class AAE_EH
	{
		init = "call compile preprocessFileLineNumbers 'MG8\AVDAVFX\addons\AVDAVFX\XEH_preStart.sqf'";
	};
};*/
class CfgVehicles
{
	class AllVehicles;
	class Air: AllVehicles
	{
		class Eventhandlers: DefaultEventHandlers {};
		#include "Configs\AAE_Settings.hpp"
	};
	
	class Plane: Air {};
	class Plane_Base_F: Plane {};
	//Vapor Effects
	#include "Wing_Effect\Jet_Configs.hpp"
	
	//Plane MODs
	#include "MOD_EH.hpp"
	
	//Helis
	class Helicopter_Base_H;
	
	#include "Configs\Skins.hpp"
	#include "Configs\Heli_Settings.hpp"
};
////////////////////////////////////
class CfgAmmo
{
	class MissileBase;
	class ammo_Missile_MediumRangeAABase: MissileBase
	{
		initTime = 0.3;
		thrust = 400;
	};
};
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

//CfgCloudlets
#include "Configs\CfgCloudlets.hpp"

//Effects
#include "Effects.hpp"

//Sound Effects
#include "Configs\CfgSounds.hpp"
