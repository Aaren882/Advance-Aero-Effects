class Air: AllVehicles
{
	class MarkerLights
	{
		class PositionRed
		{
			color[] = {10,0,0};
			ambient[] = {0.1,0,0};
			intensity = 50;
			name = "PositionLight_red_1_pos";
			drawLight = 1;
			drawLightSize = 0.15;
			drawLightCenterSize = 0.04;
			activeLight = 1;
			blinking = 0;
			dayLight = 1;
			useFlare = 1;
			brightness = 1;
			FlareSize = 0.15;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 8;
			};
		};
		class PositionGreen: PositionRed
		{
			color[] = {0,10,0};
			ambient[] = {0,0.8,0};
			name = "PositionLight_green_1_pos";
		};
		class PositionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "PositionLight_white_1_pos";
			drawLightSize = 0.2;
			activeLight = 1;
		};
		class CollisionRed: PositionRed
		{
			color[] = {9,1.5,1};
			ambient[] = {0.09,0.015,0.01};
			name = "CollisionLight_red_1_pos";
			blinking = 1;
			FlareSize = 1;
			intensity = 70;
			blinkingPattern[] = {0.2,1.3};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.25;
			drawLightCenterSize = 0.08;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 10;
				quadratic = 0.01;
				hardLimitStart = 1;
				hardLimitEnd = 2;
			};
		};
		class CollisionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "CollisionLight_white_1_pos";
			intensity = 50;
			FlareSize = 1;
			blinking = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.2;
			drawLightCenterSize = 0.04;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 0.5;
				hardLimitEnd = 8;
			};
		};
	};
};
class Helicopter: Air {};
class Helicopter_Base_F: Helicopter {};
class Helicopter_Base_H: Helicopter_Base_F {};
class Heli_Light_01_base_F: Helicopter_Base_H
{
	class MarkerLights
	{
		class PositionRed
		{
			color[] = {10,0,0};
			ambient[] = {0.1,0,0};
			intensity = 50;
			name = "PositionLight_red_1_pos";
			drawLight = 1;
			drawLightSize = 0.15;
			drawLightCenterSize = 0.04;
			activeLight = 1;
			blinking = 0;
			dayLight = 1;
			useFlare = 1;
			brightness = 1;
			FlareSize = 0.15;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 25;
				quadratic = 10;
				hardLimitStart = 0.5;
				hardLimitEnd = 3;
			};
		};
		class PositionGreen: PositionRed
		{
			color[] = {0,10,0};
			ambient[] = {0,0.8,0};
			name = "PositionLight_green_1_pos";
		};
		class PositionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "PositionLight_white_1_pos";
			drawLightSize = 0.2;
			activeLight = 1;
		};
		class CollisionRed: PositionRed
		{
			color[] = {9,1.5,1};
			ambient[] = {0.09,0.015,0.01};
			name = "CollisionLight_red_1_pos";
			blinking = 1;
			FlareSize = 1;
			intensity = 70;
			blinkingPattern[] = {0.2,1.3};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.25;
			drawLightCenterSize = 0.08;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 10;
				quadratic = 0.01;
				hardLimitStart = 0.5;
				hardLimitEnd = 1;
			};
		};
		class CollisionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "CollisionLight_white_1_pos";
			intensity = 300;
			blinking = 1;
			FlareSize = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.2;
			drawLightCenterSize = 0.04;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 10;
				quadratic = 0.01;
				hardLimitStart = 1;
				hardLimitEnd = 2;
			};
		};
	};
};

class Heli_Light_02_base_F: Helicopter_Base_H
{
	class MarkerLights
	{
		class PositionRed
		{
			color[] = {10,0,0};
			ambient[] = {0.1,0,0};
			intensity = 50;
			name = "PositionLight_red_1_pos";
			drawLight = 1;
			drawLightSize = 0.15;
			drawLightCenterSize = 0.04;
			activeLight = 1;
			blinking = 0;
			dayLight = 1;
			useFlare = 1;
			brightness = 1;
			FlareSize = 0.15;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 25;
				quadratic = 10;
				hardLimitStart = 0.5;
				hardLimitEnd = 3;
			};
		};
		class PositionGreen: PositionRed
		{
			color[] = {0,10,0};
			ambient[] = {0,0.8,0};
			name = "PositionLight_green_1_pos";
		};
		class PositionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "PositionLight_white_1_pos";
			drawLightSize = 0.2;
		};
		class CollisionRed: PositionRed
		{
			color[] = {9,1.5,1};
			ambient[] = {0.09,0.015,0.01};
			name = "CollisionLight_red_1_pos";
			blinking = 1;
			FlareSize = 1;
			intensity = 70;
			blinkingPattern[] = {0.2,1.3};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.25;
			drawLightCenterSize = 0.08;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 2;
			};
		};
		class CollisionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "CollisionLight_white_1_pos";
			intensity = 300;
			blinking = 1;
			FlareSize = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.2;
			drawLightCenterSize = 0.04;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 10;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 2;
			};
		};
	};
};
class Heli_Attack_01_base_F: Helicopter_Base_F
{
	class MarkerLights
	{
		class PositionRed
		{
			color[] = {10,0,0};
			ambient[] = {0.1,0,0};
			intensity = 50;
			name = "PositionLight_red_1_pos";
			drawLight = 1;
			drawLightSize = 0.15;
			drawLightCenterSize = 0.04;
			activeLight = 1;
			blinking = 0;
			dayLight = 1;
			useFlare = 1;
			brightness = 1;
			FlareSize = 0.15;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 25;
				quadratic = 10;
				hardLimitStart = 0.5;
				hardLimitEnd = 3;
			};
		};
		class PositionGreen: PositionRed
		{
			color[] = {0,10,0};
			ambient[] = {0,0.8,0};
			name = "PositionLight_green_1_pos";
		};
		class PositionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "PositionLight_white_1_pos";
			drawLightSize = 0.2;
			activeLight = 1;
		};
		class CollisionRed: PositionRed
		{
			color[] = {9,1.5,1};
			ambient[] = {0.09,0.015,0.01};
			name = "CollisionLight_red_1_pos";
			blinking = 1;
			FlareSize = 1;
			intensity = 70;
			blinkingPattern[] = {0.2,1.3};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.25;
			drawLightCenterSize = 0.08;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 10;
				quadratic = 0.01;
				hardLimitStart = 0.5;
				hardLimitEnd = 1;
			};
		};
		class CollisionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "CollisionLight_white_1_pos";
			intensity = 300;
			blinking = 1;
			FlareSize = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.2;
			drawLightCenterSize = 0.04;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 10;
				quadratic = 0.01;
				hardLimitStart = 1;
				hardLimitEnd = 2;
			};
		};
	};
};
class Plane_Base_F;
class Plane_CAS_01_base_F: Plane_Base_F
{
	class MarkerLights
	{
		class PositionRed
		{
			color[] = {10,0,0};
			ambient[] = {0.1,0,0};
			intensity = 50;
			name = "PositionLight_red_1_pos";
			drawLight = 1;
			drawLightSize = 0.15;
			drawLightCenterSize = 0.04;
			activeLight = 1;
			blinking = 0;
			dayLight = 1;
			useFlare = 1;
			brightness = 1;
			FlareSize = 0.15;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 8;
			};
		};
		class PositionGreen: PositionRed
		{
			color[] = {0,10,0};
			ambient[] = {0,0.8,0};
			name = "PositionLight_green_1_pos";
		};
		class PositionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "PositionLight_white_1_pos";
			drawLightSize = 0.2;
			activeLight = 0;
		};
		class CollisionRed: PositionRed
		{
			color[] = {9,1.5,1};
			ambient[] = {0.09,0.015,0.01};
			name = "CollisionLight_red_1_pos";
			blinking = 1;
			FlareSize = 1;
			intensity = 70;
			blinkingPattern[] = {0.2,1.3};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.25;
			drawLightCenterSize = 0.08;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 10;
				quadratic = 0.01;
				hardLimitStart = 1;
				hardLimitEnd = 2;
			};
		};
		class CollisionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "CollisionLight_white_1_pos";
			intensity = 100;
			FlareSize = 1;
			blinking = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.2;
			drawLightCenterSize = 0.04;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 0.5;
				hardLimitEnd = 10;
			};
		};
	};
};
class VTOL_Base_F;
class VTOL_01_base_F: VTOL_Base_F
{
	class MarkerLights
	{
		class PositionRed
		{
			color[] = {10,0,0};
			ambient[] = {0.1,0,0};
			intensity = 70;
			name = "PositionLight_red_1_pos";
			drawLight = 1;
			drawLightSize = 0.15;
			drawLightCenterSize = 0.04;
			activeLight = 1;
			blinking = 0;
			FlareSize = 0.15;
			dayLight = 1;
			useFlare = 0;
			brightness = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 15;
			};
		};
		class PositionGreen: PositionRed
		{
			color[] = {0,10,0};
			ambient[] = {0,0.8,0};
			name = "PositionLight_green_1_pos";
		};
		class PositionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "PositionLight_white_1_pos";
			drawLightSize = 0.2;
			useFlare = 1;
		};
		class CollisionRed: PositionRed
		{
			color[] = {9,1.5,1};
			ambient[] = {0.09,0.015,0.01};
			name = "CollisionLight_red_1_pos";
			blinking = 1;
			FlareSize = 1;
			intensity = 70;
			useFlare = 1;
			blinkingPattern[] = {0.2,1.3};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.25;
			drawLightCenterSize = 0.08;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 50;
			};
		};
		class CollisionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "CollisionLight_white_1_pos";
			intensity = 300;
			blinking = 1;
			FlareSize = 1;
			useFlare = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.2;
			drawLightCenterSize = 0.04;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 100;
			};
		};
		class PositionWhite_2: PositionWhite
		{
			name = "PositionLight_white_2_pos";
		};
	};
};
class VTOL_02_base_F: VTOL_Base_F
{
	class MarkerLights
	{
		class PositionRed
		{
			color[] = {10,0,0};
			ambient[] = {0.1,0,0};
			intensity = 70;
			name = "PositionLight_red_1_pos";
			drawLight = 1;
			drawLightSize = 0.15;
			drawLightCenterSize = 0.04;
			activeLight = 1;
			blinking = 0;
			FlareSize = 0.15;
			dayLight = 1;
			useFlare = 1;
			brightness = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 8;
			};
		};
		class PositionGreen: PositionRed
		{
			color[] = {0,10,0};
			ambient[] = {0,0.8,0};
			name = "PositionLight_green_1_pos";
		};
		class PositionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "PositionLight_white_1_pos";
			drawLightSize = 0.2;
		};
		class CollisionRed: PositionRed
		{
			color[] = {9,1.5,1};
			ambient[] = {0.09,0.015,0.01};
			name = "CollisionLight_red_1_pos";
			blinking = 1;
			FlareSize = 1;
			intensity = 70;
			blinkingPattern[] = {0.2,1.3};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.25;
			drawLightCenterSize = 0.08;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 10;
				quadratic = 0.01;
				hardLimitStart = 1;
				hardLimitEnd = 5;
			};
		};
		class CollisionWhite: PositionRed
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "CollisionLight_white_1_pos";
			intensity = 150;
			blinking = 1;
			FlareSize = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.2;
			drawLightCenterSize = 0.04;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 50;
			};
		};
		class PositionWhite_2: PositionWhite
		{
			name = "PositionLight_white_2_pos";
		};
	};
};
class Plane_Fighter_01_Base_F: Plane_Base_F
{
	class MarkerLights
	{
		class CollisionLightRed1
		{
			color[] = {10,0,0};
			ambient[] = {0.1,0,0};
			intensity = 50;
			name = "pos_collision_light_red_1";
			drawLight = 1;
			drawLightSize = 0.25;
			drawLightCenterSize = 0.05;
			activeLight = 1;
			blinking = 0;
			dayLight = 1;
			useFlare = 1;
			brightness = 1;
			FlareSize = 0.15;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 10;
				quadratic = 10;
				hardLimitStart = 1;
				hardLimitEnd = 2;
			};
		};
		class CollisionLightRed2: CollisionLightRed1
		{
			name = "pos_collision_light_red_2";
			useFlare = 0;
			
		};
		class CollisionLightGreen1: CollisionLightRed1
		{
			color[] = {0,10,0};
			ambient[] = {0,0.8,0};
			name = "pos_collision_light_green_1";
			useFlare = 0;
		};
		class CollisionLightGreen2: CollisionLightRed1
		{
			color[] = {0,10,0};
			ambient[] = {0,0.8,0};
			name = "pos_collision_light_green_2";
		};
		class CollisionLightWhite1: CollisionLightRed1
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "pos_collision_light_white_1";
			blinking = 1;
			FlareSize = 1;
			intensity = 100;
			blinkingStartsOn = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingPatternGuarantee = 1;
			drawLightSize = 0.35;
			drawLightCenterSize = 0.05;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 10;
			};
		};
	};
};
class Plane_Fighter_02_Base_F: Plane_Base_F
{
	class MarkerLights
	{
		class CollisionLight_wingtip_red
		{
			color[] = {10,0,0};
			ambient[] = {0.1,0,0};
			intensity = 50;
			name = "wingtip_marker_light_red";
			drawLight = 1;
			drawLightSize = 0.25;
			drawLightCenterSize = 0.05;
			activeLight = 1;
			blinking = 0;
			FlareSize = 0.15;
			dayLight = 1;
			useFlare = 1;
			brightness = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 8;
			};
		};
		class CollisionLight_wingtip_green: CollisionLight_wingtip_red
		{
			color[] = {0,10,0};
			ambient[] = {0,0.8,0};
			name = "wingtip_marker_light_green";
		};
		class CollisionLightWhite1
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "marker_light_white_rear";
			intensity = 70;
			drawLight = 1;
			drawLightSize = 0.35;
			drawLightCenterSize = 0.05;
			activeLight = 1;
			dayLight = 1;
			useFlare = 1;
			blinking = 1;
			FlareSize = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingStartsOn = 1;
			blinkingPatternGuarantee = 1;
			brightness = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 8;
			};
		};
		class CollisionLightWhite2: CollisionLightWhite1
		{
			name = "marker_light_white";
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 0.01;
				hardLimitEnd = 3;
			};
		};
	};
};
class Plane_Fighter_04_Base_F: Plane_Base_F
{
	class MarkerLights
	{
		class Marker_Light_red
		{
			color[] = {10,0,0};
			ambient[] = {0.10,0,0};
			intensity = 50;
			name = "marker_light_red";
			drawLight = 1;
			drawLightSize = 0.25;
			drawLightCenterSize = 0.05;
			activeLight = 1;
			blinking = 0;
			FlareSize = 0.15;
			dayLight = 1;
			useFlare = 1;
			brightness = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 0.05;
				hardLimitEnd = 2;
			};
		};
		class Marker_Light_green: Marker_Light_red
		{
			color[] = {0,10,0};
			ambient[] = {0,0.8,0};
			name = "marker_light_green";
		};
		class Marker_Light_hull_red: Marker_Light_red
		{
			name = "marker_light_hull_red";
		};
		class Marker_Light_hull_green: Marker_Light_red
		{
			color[] = {0,10,0};
			ambient[] = {0,0.8,0};
			name = "marker_light_hull_green";
		};
		class CollisionLightWhite1
		{
			color[] = {50,50,50};
			ambient[] = {0.1,0.1,0.1};
			name = "pos_collision_light_white_1";
			intensity = 70;
			drawLight = 1;
			drawLightSize = 0.35;
			drawLightCenterSize = 0.05;
			activeLight = 1;
			dayLight = 1;
			useFlare = 1;
			blinking = 1;
			FlareSize = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingStartsOn = 1;
			blinkingPatternGuarantee = 1;
			brightness = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 0.05;
				hardLimitEnd = 8;
			};
		};
	};
};
class Heli_Transport_02_base_F;
class Heli_Light_03_base_F;
class Plane_Fighter_03_base_F;
class Heli_Attack_02_base_F;
class O_Plane_CAS_02_F;
//RHSUSAF
#if __has_include("\rhsusf\addons\rhsusf_c_a2port_air\config.bin")
	#include "RHS\USA\A10.hpp"
	#include "RHS\USA\F22.hpp"
	#include "RHS\USA\C130.hpp"
	#include "RHS\USA\AH64.hpp"
	#include "RHS\USA\AH1Z.hpp"
	#include "RHS\USA\CH47.hpp"
	#include "RHS\USA\UH1Y.hpp"
	#include "RHS\USA\UH60.hpp"
	#include "RHS\USA\CH53.hpp"
	//#include "RHS\USA\MELB.hpp"
#endif
//RHSAFRF
#if __has_include("\rhsafrf\addons\rhs_c_a2port_air\config.bin")
	#include "RHS\RU\KA52.hpp"
	#include "RHS\RU\Mi8.hpp"
	#include "RHS\RU\Mi24.hpp"
	#include "RHS\RU\Mi28.hpp"
	#include "RHS\RU\Su25.hpp"
	#include "RHS\RU\Mig29.hpp"
	#include "RHS\RU\T50.hpp"
	#include "RHS\RU\Tu95.hpp"
#endif
//RHSGREF
#if __has_include("\rhsgref\addons\rhsgref_c_air\config.bin")
	#include "RHS\GREF\AN2.hpp"
	#include "RHS\GREF\L159.hpp"
	#include "RHS\GREF\UH1H.hpp"
#endif