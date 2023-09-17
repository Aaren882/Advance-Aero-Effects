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
// Exhaust
class ExhaustsEffectPlane
{
	class ExhaustsEffectRefract01
	{
		type = "ExhaustSmokeRefractPlane";
		enabled = "vehicleSpeedSize interpolate [13.99,14,-1,1]";
	};
};
class ExhaustsEffectPlaneHP
{
	class ExhaustsEffectRefract01
	{
		type = "ExhaustSmokeRefractPlane";
		enabled = "vehicleSpeedSize interpolate [13.99,14,-1,1]";
	};
};
class ExhaustsEffectJet
{
	class ExhaustsEffectRefract01
	{
		type = "ExhaustSmokeRefractPlane";
		enabled = "vehicleSpeedSize interpolate [13.99,14,-1,1]";
	};
};
// FIR
class fir_ExhaustsEffectPlane_big
{
	class ExhaustsEffect01
	{
		type = "ExhaustSmoke1PlaneHP";
	};
	class ExhaustsEffectRefract01_big
	{
		type = "ExhaustSmokeRefractPlane";
	};
};
////////////////////////////////////////////////////////////
//Super Hornets
class FX_FA18_WingVapour
{
	class FX_FA18_WingOverVapour_LOW
	{
		simulation="particles";
		type="AAE_BodyTrail_FighterJet_Short";
		qualityLevel=0;
		enabled="accelY interpolate [59.99,60,-1,1]";
	};
	class FX_FA18_WingOverVapour_MD
	{
		simulation="particles";
		type="AAE_BodyTrail_FighterJet_Short";
		qualityLevel=1;
		enabled="accelY interpolate [59.99,60,-1,1]";
	};
	class FX_FA18_WingOverVapour_HD
	{
		simulation="particles";
		type="AAE_BodyTrail_FighterJet_Short";
		qualityLevel=2;
		enabled="accelY interpolate [59.99,60,-1,1]";
	};
};
class FX_FA18_Fuselagevapour
{
	class FX_FA18_BodyTrail_LOW
	{
		simulation="particles";
		type="FX_BodyTrail_FighterJet";
		qualityLevel=0;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};
	class FX_FA18_BodyTrail_MD
	{
		simulation="particles";
		type="FX_BodyTrail_FighterJet";
		qualityLevel=1;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};
	class FX_FA18_BodyTrail_HD
	{
		simulation="particles";
		type="FX_BodyTrail_FighterJet";
		qualityLevel=2;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};
};
class FX_FA18_Fuselagevapour2
{
	class FX_FA18_BodyTrail2_LOW
	{
		simulation="particles";
		type="FX_FA18_BodyTrail";
		qualityLevel=0;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};
	class FX_FA18_BodyTrail2_MD
	{
		simulation="particles";
		type="FX_FA18_BodyTrail";
		qualityLevel=1;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};
	class FX_FA18_BodyTrail2_HD
	{
		simulation="particles";
		type="FX_FA18_BodyTrail";
		qualityLevel=2;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};
};
class FX_FA18_WingVortices
{
	class FX_FA18_WingTrail_LOW
	{
		simulation="particles";
		type="FX_WingTrail_FighterJet";
		qualityLevel=0;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};
	class FX_FA18_WingTrail_MD
	{
		simulation="particles";
		type="FX_WingTrail_FighterJet";
		qualityLevel=1;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};
	class FX_FA18_WingTrail_HD
	{
		simulation="particles";
		type="FX_WingTrail_FighterJet";
		qualityLevel=2;
		enabled="accelY interpolate [39.99,40,-1,1]";
	};
	class FX_Plane_WingTrail_slow
	{
		simulation = "particles";
		type = "FX_WingTrail_FighterJet_Slow";
		qualityLevel = 1;
		enabled = "(speed interpolate [62.49,62.5,-1,1])";
	};
};
////////////////////////////////////////////////////////////
//FIR
class FIR_WingVortices
{
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
	delete FIR_BodyTrail1;
	delete FIR_BodyTrail1Med;
	class BodyTrail
	{
		simulation = "particles";
		type = "FX_BodyTrail_FighterJet";
		enabled = "accelY interpolate [69.99,70,-1,1]";
		qualityLevel = 2;
	};
};
class FIR_WingTrails_top
{
	delete FIR_wingTrails_top1;
	class wingTrails
	{
		simulation = "particles";
		type = "AAE_WingTrail_FighterJet_FIR";
		enabled = "accelY interpolate [79.99,80,-1,1]";
		position[] = {0,-0.2,0};
		qualityLevel = 2;
	};
};
//FIR Weapons
class FIR_m61_cloud
{
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
class FIR_Gau8_cloud
{
	delete FIR_Gau8_cloud;
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
class AAE_TailHook_Sprak
{
	class Sparks
	{
		simulation = "Light";
		//type = "AAE_TailHook_Sprak_Light";
		type = "AAW_WP_Burst_Trail_Light";
		position[] = {0,0,0};
		intensity = 1;
		interval = 1;
		lifeTime = 3;
	};
};
#if __has_include("\ANZ_MissileEfxMod\config.cpp")
#else
	class FIR_MissileEffect
	{
		delete FIR_MissileEffect;
		class Missile3
		{
			simulation = "particles";
			type = "Missile3";
			position[] = {0,0,0};
			intensity = 1;
			interval = 1;
			lifeTime = 1;
		};
	};
	class FIR_MissileEffect2
	{
		delete FIR_MissileEffect2;
		class Missile3
		{
			simulation = "particles";
			type = "Missile3";
			position[] = {0,0,0};
			intensity = 1;
			interval = 1;
			lifeTime = 1;
		};
	};
	
	//SAM
	class FX_Missile_SAM_LongRange
	{
		class FX_Missile_SAM_light_01
		{
			intensity = 1;
		};
		class FX_Plane_Missile_SAM_high
		{
			interval = 1;
		};
		class FX_Plane_Missile_SAM_medium
		{
			interval = 1;
		};
		class FX_Plane_Missile_SAM_low
		{
			interval = 1;
		};
	};
	//AA
	class FX_Missile_AA;
	class AAE_Missile_AA_Short: FX_Missile_AA
	{
		delete FX_Plane_Missile_AA_high;
		delete FX_Plane_Missile_AA_medium;
		delete FX_Plane_Missile_AA_low;
		class Trail
		{
			simulation = "particles";
			type = "AAE_Short_Missile";
			position[] = {0,0,0};
			intensity = 1;
			interval = 1;
			lifeTime = 1;
		};
	};
#endif
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
		drawLight = 1;
		blinking = 0;
		delete Attenuation;
		/*class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 0;
			quadratic = 1;
			hardLimitStart = 100;
			hardLimitEnd = 200;
		};*/
	};
	class AAE_TailHook_Sprak_Light
	{
		intensity=500;
		flareMaxDistance=500;
		flareSize=0.2;
		useFlare=1;
		brightness = 3;
		color[]={0.5,0.5,0.5};
		ambient[]={0.5,0.5,0.5};
		diffuse[]={1,0.5,0.2};
		position[]={0,0,0};
		class Attenuation
		{
			start = 0.3;
			constant = 0;
			linear = 0;
			quadratic = 1;
			hardLimitStart = 1;
			hardLimitEnd = 150;
		};
	};
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
