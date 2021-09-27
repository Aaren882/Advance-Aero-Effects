//Destroryer
class Land_Destroyer_01_hull_base_F: House_F
{
	class MarkerLights
	{
		class M_light_base
		{
			name = "empty";
			color[] = {0.95,0.85,0.15};
			ambient[] = {0.0,0.0,0.0};
			intensity = 30;
			drawLight = 1;
			drawLightSize = 1.0;
			drawLightCenterSize = 0.1;
			activeLight = 1;
			blinking = 0;
			dayLight = 0;
			useFlare = 0;
		};
		class M_Ylow_base_strong: M_light_base
		{
			color[] = {9,9,0.5};
		};
		class M_Ylow_base_weak: M_light_base
		{
			color[] = {0.85,0.85,0.05};
		};
		class M_Red_base: M_light_base
		{
			color[] = {0.9,0.0,0.0};
		};
		class M_Green_base: M_light_base
		{
			color[] = {0.0,0.8,0.0};
		};
		class M_White_base: M_light_base
		{
			color[] = {1,1,1};
		};
		class M_blue_base: M_light_base
		{
			color[] = {0.0,0.0,0.9};
		};
		class M_interior_light_base
		{
			name = "empty";
			color[] = {0.2,1,0,1};
			ambient[] = {0,0,0,0};
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
				quadratic = 40;
			};
			position[] = {0,0.2,0};
			diffuse[] = {0.02,0.1,0};
		};
		class M_interior_light_White_base: M_interior_light_base
		{
			color[] = {1,1,1,1};
			diffuse[] = {1,1,1};
		};
		class M_interior_light_Green_base: M_interior_light_base
		{
			color[] = {0.2,1,0,1};
			diffuse[] = {0.02,0.1,0};
		};
		class M_interior_light_Red_base: M_interior_light_base
		{
			color[] = {1,0,0.025,1};
			diffuse[] = {0.1,0,0.0025};
		};
		class M_interior_light_Blue_base: M_interior_light_base
		{
			color[] = {0,0.6,1,1};
			diffuse[] = {0,0.6,1};
		};
	};
};