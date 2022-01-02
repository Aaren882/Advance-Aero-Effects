class RHS_Mi8_base:  Heli_Light_02_base_F
{
	class MarkerLights
	{
		class GreenStill
		{
			color[] = {0,0.8,0};
			ambient[] = {0,0.8,0};
			intensity = 75;
			blinking=0;
			brightness=1;
			flareSize=0.2;
			drawLight = 1;
			drawLightSize = 0.25;
			drawLightCenterSize = 0.08;
			useFlare=1;
			activeLight = 1;
			dayLight = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 0.2;
				hardLimitEnd = 1;
			};
		};
		class RedStill: GreenStill
		{
			color[] = {0.8,0,0};
			ambient[] = {0.8,0,0};
		};
		class WhiteStill: GreenStill
		{
			color[] = {1,1,1};
			ambient[] = {0.1,0.1,0.1};
		};
		class WhiteBlicking: GreenStill
		{
			color[] = {1,1,1};
			ambient[] = {0.1,0.1,0.1};
			blinking=1;
			intensity = 150;
			flareSize=1;
			delete Attenuation;
		};
		class RedBlinking: WhiteBlicking
		{
			color[] = {0.9,0.15,0.1};
			ambient[] = {0.9,0.15,0.1};
		};
	};
};