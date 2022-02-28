class CfgPatches
{
	class AVDAVFX_C_Collision
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			#include "MODs.hpp"
			"A3_Air_F",
			"A3_Air_F_Jets_Plane_Fighter_01",
			"A3_Air_F_Jets_Plane_Fighter_02",
			"A3_Air_F_Jets_Plane_Fighter_04",
			"A3_Air_F_Jets_UAV_05",
			"A3_Roads_F",
			"A3_Boat_F_Jets_Carrier_01",
			"A3_Boat_F_Destroyer_Destroyer_01"
		};
	};
};
class CfgVehicles
{
	class House_F;
	class House;
	#include "Navigation.hpp"
	#include "Carrier.hpp"
	#include "Destroryer.hpp"
	class AllVehicles;
	#include "Vehicles.hpp"
};