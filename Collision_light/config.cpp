class CfgPatches
{
	class AVDAVFX_C_Collision
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			//RHS
			//USAF
			#if __has_include("\rhsusf\addons\rhsusf_c_a2port_air\config.bin")
				"RHS_US_A2_AirImport",
				"rhsusf_c_ch53",
				"rhsusf_c_f22",
			#endif
			//AFRF
			#if __has_include("\rhsafrf\addons\rhs_c_a2port_air\config.bin")
				"rhs_c_a2port_air",
				"rhs_c_mi28",
				"rhs_c_air",
			#endif
			//RHSGREF
			#if __has_include("\rhsgref\addons\rhsgref_c_air\config.bin")
				"rhsgref_c_air",
				"RHSGREF_c_A29",
			#endif
			"A3_Air_F",
			"A3_Air_F_Jets_Plane_Fighter_01",
			"A3_Air_F_Jets_Plane_Fighter_02",
			"A3_Air_F_Jets_Plane_Fighter_04",
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