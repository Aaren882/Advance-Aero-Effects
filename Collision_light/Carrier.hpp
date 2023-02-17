//Carrier
class Land_Carrier_01_hull_base_F: House_F
{
	class MarkerLights
	{
		class M_light_base
		{
			name = "";
			color[] = {95,85,15};
			ambient[] = {0.95,0.85,0.15};
			intensity = 30;
			drawLight = 1;
			drawLightSize = SHIPNAVSIZE;
			drawLightCenterSize = SHIPNAVSIZECEN;
			flaresize = SHIPFLASIZE;
			activeLight = 1;
			blinking = 0;
			dayLight = 0;
			useFlare = 1;
			class Attenuation
			{
				start = 1;
				constant = 0;
				linear = 2;
				quadratic = 0.5;
				hardLimitStart = 0.5;
				hardLimitEnd = 5;
			};
		};
		class M_Ylow_base_strong: M_light_base
		{
			color[] = {90,90,5};
			ambient[] = {0.9,0.9,0.05};
		};
		class M_Ylow_base_weak: M_light_base
		{
			color[] = {85,85,5};
			ambient[] = {0.85,0.85,0.5};
		};
		class M_White_base: M_light_base
		{
			color[] = {10,10,10};
			ambient[] = {0.1,0.1,0.1};
		};
		class M_Red_base: M_light_base
		{
			color[] = {0.9,0,0};
			ambient[] = {0.9,0,0};
			activeLight = 0;
		};
		class M_blue_base: M_light_base
		{
			color[] = {0,0,0.9};
			ambient[] = {0,0,0.9};
		};
		class M_interior_light_base
		{
			name = "empty";
			color[] = {0.2,1,0,1};
			ambient[] = {0,0,0};
			brightness = 1;
			intensity = 4000;
			drawLight = 0;
			blinking = 0;
			dayLight = 0;
			useFlare = 0;
			class Attenuation
			{
				start = 0;
				constant = 1;
				linear = 0;
				quadratic = 10;
			};
			position[] = {0,0.2,0};
			diffuse[] = {0.02,0.1,0};
		};
		class M_interior_light_White_base: M_interior_light_base
		{
			color[] = {1,1,1};
			diffuse[] = {1,1,1};
		};
		class M_interior_light_Green_base: M_interior_light_base
		{
			color[] = {0.2,1,0.1};
			diffuse[] = {0.02,0.1,0};
		};
		class M_interior_light_Red_base: M_interior_light_base
		{
			color[] = {1,0,0.025};
			diffuse[] = {0.1,0,0.0025};
		};
		class M_interior_light_Blue_base: M_interior_light_base
		{
			color[] = {0,0.6,1};
			diffuse[] = {0,0.6,1};
		};
	};
};
class Land_Carrier_01_hull_06_1_F: Land_Carrier_01_hull_base_F
{
	class MarkerLights: MarkerLights
	{
		class M_White_13: M_White_base
		{
			name = "M_White_13_pos";
		};
		class M_Ylow_24: M_Ylow_base_strong
		{
			name = "M_Ylow_24_pos";
		};
		class M_Ylow_26: M_Ylow_base_strong
		{
			name = "M_Ylow_26_pos";
		};
		class M_Ylow_28: M_Ylow_base_strong
		{
			name = "M_Ylow_28_pos";
		};
		class M_Ylow_30: M_Ylow_base_strong
		{
			name = "M_Ylow_30_pos";
		};
		class M_Ylow_23: M_Ylow_base_weak
		{
			name = "M_Ylow_23_pos";
		};
		class M_Ylow_25: M_Ylow_base_weak
		{
			name = "M_Ylow_25_pos";
		};
		class M_Ylow_27: M_Ylow_base_weak
		{
			name = "M_Ylow_27_pos";
		};
		class M_Ylow_29: M_Ylow_base_weak
		{
			name = "M_Ylow_29_pos";
		};
		class Landing_Red_01: M_Red_base
		{
			name="Landing_Red_01_pos";
			activeLight = 0;
			drawLightSize=0.3;
			drawLightCenterSize=0.3;
			flaresize=0.2;
		};
		class Landing_Red_02: Landing_Red_01
		{
			name="Landing_Red_02_pos";
		};
		class Landing_Red_03: Landing_Red_01
		{
			name="Landing_Red_03_pos";
		};
		class Landing_Red_04: Landing_Red_01
		{
			name="Landing_Red_04_pos";
		};
		class Landing_Red_05: Landing_Red_01
		{
			name="Landing_Red_05_pos";
		};
		class Landing_Red_06: Landing_Red_01
		{
			name="Landing_Red_06_pos";
		};
		class Landing_Red_07: Landing_Red_01
		{
			name="Landing_Red_07_pos";
		};
		class Landing_Red_08: Landing_Red_01
		{
			name="Landing_Red_08_pos";
		};
		class Landing_Red_09: Landing_Red_01
		{
			name="Landing_Red_09_pos";
		};
		class Landing_Red_10: Landing_Red_01
		{
			name="Landing_Red_10_pos";
		};
		class Landing_Red_11: Landing_Red_01
		{
			name="Landing_Red_11_pos";
		};
		class Landing_Red_12: Landing_Red_01
		{
			name="Landing_Red_12_pos";
		};
		class Landing_Red_13: Landing_Red_01
		{
			name="Landing_Red_13_pos";
		};
		class Landing_Red_14: Landing_Red_01
		{
			name="Landing_Red_14_pos";
		};
		class Landing_Red_15: Landing_Red_01
		{
			name="Landing_Red_15_pos";
		};
		class Landing_Red_16: Landing_Red_01
		{
			name="Landing_Red_16_pos";
		};
		class Landing_Red_17: Landing_Red_01
		{
			name="Landing_Red_17_pos";
		};
		class Landing_Red_18: Landing_Red_01
		{
			name="Landing_Red_18_pos";
		};
		class Landing_Red_19: Landing_Red_01
		{
			name="Landing_Red_19_pos";
		};
		class Landing_Blue_01: M_blue_base
		{
			name="Landing_Blue_01_pos";
			activeLight = 0;
			drawLightSize=0.3;
			drawLightCenterSize=0.3;
			flaresize=0.2;
		};
		class Landing_Blue_02: Landing_Blue_01
		{
			name="Landing_Blue_02_pos";
		};
		class Landing_Blue_03: Landing_Blue_01
		{
			name="Landing_Blue_03_pos";
		};
		class Landing_Blue_04: Landing_Blue_01
		{
			name="Landing_Blue_04_pos";
		};
		class Landing_Blue_05: Landing_Blue_01
		{
			name="Landing_Blue_05_pos";
		};
		class Landing_Blue_06: Landing_Blue_01
		{
			name="Landing_Blue_06_pos";
		};
		class Landing_Blue_07: Landing_Blue_01
		{
			name="Landing_Blue_07_pos";
		};
		class Landing_Blue_08: Landing_Blue_01
		{
			name="Landing_Blue_08_pos";
		};
		class Landing_Blue_09: Landing_Blue_01
		{
			name="Landing_Blue_09_pos";
		};
		class Landing_Blue_10: Landing_Blue_01
		{
			name="Landing_Blue_10_pos";
		};
		class Landing_Blue_11: Landing_Blue_01
		{
			name="Landing_Blue_11_pos";
		};
		class Landing_Blue_12: Landing_Blue_01
		{
			name="Landing_Blue_12_pos";
		};
		class Landing_Blue_13: Landing_Blue_01
		{
			name="Landing_Blue_13_pos";
		};
		class Landing_Blue_14: Landing_Blue_01
		{
			name="Landing_Blue_14_pos";
		};
		class Landing_Blue_15: Landing_Blue_01
		{
			name="Landing_Blue_15_pos";
		};
		class Landing_Blue_16: Landing_Blue_01
		{
			name="Landing_Blue_16_pos";
		};
	};
};