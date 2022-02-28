//Navigation
class Land_NavigLight: House
{
	class MarkerLights
	{
		class Light_1
		{
			color[] = {0.95,0.85,0.15};
			ambient[] = {0.95,0.85,0.15};
			intensity = 70;
			drawLight = 1;
			drawLightSize = 0.8;
			drawLightCenterSize = 0.4;
			activeLight = 1;
			blinking = 0;
			dayLight = 0;
			useFlare = 1;
			brightness = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 1;
				quadratic = 0.5;
				hardLimitStart = 100;
				hardLimitEnd = 1000;
			};
		};
	};
};
class Land_NavigLight_3_F: Land_NavigLight
{
	class MarkerLights: MarkerLights
	{
		class Light_1: Light_1
		{
			color[] = {0.9,0,0};
			ambient[] = {0.09,0,0};
		};
		class Light_2: Light_1
		{
			name = "Light_2_pos";
		};
		class Light_3: Light_1
		{
			name = "Light_3_pos";
		};
	};
};
class Land_Flush_Light_green_F: Land_NavigLight
{
	class MarkerLights: MarkerLights
	{
		class Light_1: Light_1
		{
			color[] = {0.05,0.65,0.05};
			ambient[] = {0.05,0.65,0.05};
			flareSize = 0.8;
			drawLightSize = 0.6;
			drawLightCenterSize = 0.3;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 1;
				quadratic = 1;
				hardLimitStart = 10;
				hardLimitEnd = 100;
			};
		};
	};
};
class Land_Flush_Light_red_F: Land_Flush_Light_green_F
{
	class MarkerLights: MarkerLights
	{
		class Light_1: Light_1
		{
			color[] = {5,0,0};
			ambient[] = {0.1,0,0};
		};
	};
};
class Land_Flush_Light_yellow_F: Land_Flush_Light_green_F
{
	class MarkerLights: MarkerLights
	{
		class Light_1: Light_1
		{
			color[] = {0.85,0.85,0.05};
			ambient[] = {0.85,0.85,0.05};
		};
	};
};
class Land_runway_edgelight: Land_NavigLight
{
	class MarkerLights: MarkerLights
	{
		class Light_1: Light_1
		{
			color[] = {1,0.95,0.85};
			ambient[] = {1,0.95,0.85};
			flareSize = 0.5;
			/*class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 1;
				quadratic = 0.5;
				hardLimitStart = 100;
				hardLimitEnd = 1000;
			};*/
		};
	};
};
class Land_runway_edgelight_blue_F: Land_runway_edgelight
{
	class MarkerLights: MarkerLights
	{
		class Light_1: Light_1
		{
			color[] = {0.1,0.1,0.65};
			ambient[] = {0.1,0.1,0.65};
		};
	};
};

//PAPI
class Land_VASICore;
class Land_Runway_PAPI: Land_VASICore
{
	class RedVasiLight
	{
		class Light_1
		{
			color[] = {95,15,15};
			ambient[] = {95,15,15};
			intensity = 60;
			name = "Light_red_pos";
			drawLight = 1;
			drawLightSize = 0.5;
			drawLightCenterSize = 0.4;
			activeLight = 1;
			blinking = 0;
			dayLight = 1;
			useFlare = 1;
		};
	};
	class WhiteVasiLight: RedVasiLight
	{
		class Light_1: Light_1
		{
			color[] = {95,95,95};
			ambient[] = {95,95,95};
			name = "Light_white_pos";
		};
	};
	class VasiLight
	{
		class Light_red
		{
			color[] = {95,15,15};
			ambient[] = {95,15,15};
			intensity = 60;
			name = "Light_red_pos";
			drawLight = 1;
			drawLightSize = 0.7;
			drawLightCenterSize = 0.3;
			cone = 15;
			slope = 5.4;
			angleLimitV[] = {-85,5.4};
			angleLimitH[] = {-85,85};
			activeLight = 1;
			blinking = 0;
			dayLight = 1;
			useFlare = 1;
		};
		class Light_white: Light_red
		{
			color[] = {95,95,95};
			ambient[] = {95,95,95};
			name = "Light_white_pos";
			angleLimitV[] = {5.4,85};
		};
	};
};