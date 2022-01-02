//Jets DLC
class FX_FuselageVapour_FighterJet
{
	delete FX_Plane_BodyTrail_low;
	delete FX_Plane_BodyTrail_medium;
	delete FX_Plane_BodyTrail_high;
	class FX_Plane_BodyTrail
	{
		simulation = "particles";
		type = "FX_BodyTrail_FighterJet";
		enabled = "accelY interpolate [69.99,70,-1,1]";
	};
};
class FX_WingVortices_FighterJet
{
	class FX_Plane_WingTrail_slow
	{
		simulation = "particles";
		type = "FX_WingTrail_FighterJet_Slow";
		enabled = "(speed interpolate [62.49,62.5,-1,1])";
	};
};

//Vanilla
class WingVortices
{
	delete WingTrail1;
	delete WingTrail1Med;
	class FX_Plane_WingTrail
	{
		simulation = "particles";
		type = "FX_WingTrail_FighterJet";
		enabled = "accelY interpolate [29.99,30,-1,1]";
	};
	class FX_Plane_WingTrail_slow
	{
		simulation = "particles";
		type = "FX_WingTrail_FighterJet_Slow";
		enabled = "(speed interpolate [55.99,56,-1,1])";
	};
};
class BodyVortices
{
	class BodyTrail1
	{
		simulation = "particles";
		type = "BodyTrail";
		qualityLevel = 1;
		enabled = "accelY interpolate [29.99,30,-1,1]";
	};
	class BodyTrail1Med
	{
		simulation = "particles";
		type = "BodyTrailMed";
		qualityLevel = 2;
		enabled = "accelY interpolate [29.99,30,-1,1]";
	};
};

//Super Hornets
class FX_FA18_WingVortices
{
	class FX_FA18_WingTrail_LOW
	{
		simulation="particles";
		type="FX_FA18_WingTrail";
		qualityLevel=0;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};
	class FX_FA18_WingTrail_MD
	{
		simulation="particles";
		type="FX_FA18_WingTrail";
		qualityLevel=1;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};
	class FX_FA18_WingTrail_HD
	{
		simulation="particles";
		type="FX_FA18_WingTrail";
		qualityLevel=2;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};
	class FX_Plane_WingTrail_slow
	{
		simulation = "particles";
		type = "FX_WingTrail_FighterJet_Slow";
		enabled = "(speed interpolate [62.49,62.5,-1,1])";
	};
};

//FIR
class FIR_WingVortices
{
	/*class FIR_WingTrail1
	{
		simulation="particles";
		type="FIR_WingTrail";
		qualityLevel=2;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};
	class FIR_WingTrail1Med
	{
		simulation="particles";
		type="FIR_WingTrailMed";
		qualityLevel=1;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};*/
	delete FIR_WingTrail1;
	delete FIR_WingTrail1Med;
	class FX_Plane_WingTrail
	{
		simulation = "particles";
		type = "FX_WingTrail_FighterJet";
		enabled = "accelY interpolate [29.99,30,-1,1]";
	};
	class FX_Plane_WingTrail_slow
	{
		simulation = "particles";
		type = "FX_WingTrail_FighterJet_Slow";
		enabled = "(speed interpolate [55.99,56,-1,1])";
	};
};
class FIR_BodyVortices
{
	/*class FIR_BodyTrail1
	{
		simulation = "particles";
		type = "FIR_BodyTrail";
		qualityLevel = 2;
		enabled = "accelY interpolate [70,160,0,1]";
	};
	class FIR_BodyTrail1Med
	{
		simulation = "particles";
		type = "FIR_BodyTrailMed";
		qualityLevel = 1;
		enabled = "accelY interpolate [70,160,0,1]";
	};*/
	delete FIR_BodyTrail1;
	delete FIR_BodyTrail1Med;
	class BodyTrail
	{
		simulation = "particles";
		type = "FX_BodyTrail_FighterJet";
		enabled = "accelY interpolate [69.99,70,-1,1]";
	};
};
class FIR_WingTrails_top
{
	/*class FIR_wingTrails_top1
	{
		simulation = "particles";
		type = "FIR_WingTrail_top";
		qualityLevel = 2;
		enabled = "accelY interpolate [70,240,0,1]";
	};*/
	delete FIR_wingTrails_top1;
	class wingTrails
	{
		simulation = "particles";
		type = "AAE_WingTrail_FighterJet_FIR";
		enabled = "accelY interpolate [79.99,80,-1,1]";
		position[] = {0,-0.2,0};
	};
};
//FIR Weapons
class FIR_m61_cloud
{
	/*class FIR_Gau8_cloud2
	{
		simulation = "particles";
		type = "FIR_Gau8_cloud2";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.05;
	};*/
	delete FIR_Gau8_cloud2;
	class MachineGun3
	{
		simulation = "particles";
		type = "MachineGun3";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 0.05;
	};
};

//Lights
class CfgLights
{
	class RocketLight
	{
		diffuse[] = {1,0.25,0.05};
		color[] = {1,0.6,0.3};
		ambient[] = {0,0,0};
		brightness = "18 * fireIntensity";
		size = 1;
		intensity = 25000;
		drawLight = 0;
		blinking = 0;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 0;
			quadratic = 1;
			hardLimitStart = 100;
			hardLimitEnd = 200;
		};
	};
	class FighterBurner: RocketLight
	{
		color[] = {0.98,0.85,0.3};
		ambient[] = {0.98,0.85,0.3};
		brightness = 1;
		intensity = "25000*(vehicleSpeedSize interpolate [167.5,278,0,1])";
		position[] = {"positionX","positionY","positionZ-2"};
		class Attenuation: Attenuation
		{
			hardLimitStart = 50;
			hardLimitEnd = 1000;
		};
	};
};

//AB
class ExhaustsEffectPlaneHP
{
	class ExhaustsEffect01
	{
		simulation = "particles";
		type = "ExhaustSmoke1PlaneHP";
	};
	class ExhaustsEffectRefract01
	{
		simulation = "particles";
		type = "ExhaustSmokeRefractPlane";
	};
	/*class Light1
	{
		simulation = "light";
		type = "FighterBurner";
		//lifeTime = "speed interpolate [164.99,165,0,100]";
	};*/
};

#include "Wing_Effect\Fighter01.hpp"
#include "Wing_Effect\Fighter02.hpp"
#include "Wing_Effect\Fighter04.hpp"

//CAS_01
#include "Wing_Effect\CAS_01.hpp"
//CAS_02
#include "Wing_Effect\CAS_02.hpp"
//CAS_03
#include "Wing_Effect\CAS_03.hpp"

/*class AAE_Dust
{
	class AAE_Dust02
	{
		simulation = "particles";
		type = "AAE_Dust02";
		qualityLevel = 1;
	};
	class AAE_Dust03
	{
		simulation = "particles";
		type = "AAE_Dust03";
		qualityLevel = 0;
	};
	class AAE_Dust04
	{
		simulation = "particles";
		type = "AAE_Dust04";
		qualityLevel = 2;
	};
	class AAE_Dust05
	{
		simulation = "particles";
		type = "AAE_Dust05";
		qualityLevel = 1;
	};
};*/