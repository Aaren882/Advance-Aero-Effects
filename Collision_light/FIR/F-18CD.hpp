class MarkerLights	
{
	class RedStill
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		intensity = 50;
		drawLight = 1;
		drawLightSize = 0.25;
		drawLightCenterSize = 0.1;
		activeLight = 1;
		brightness = 1;
		dayLight = 1;
		useFlare = 1;
		FlareSize = 0.15;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 10;
			quadratic = 10;
			hardLimitStart = 1;
			hardLimitEnd = 8;
		};
	};
	class RedStill2: RedStill
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		brightness = 1;
	};
	class GreenStill1: RedStill
	{
		color[] = {0,5,0};
		ambient[] = {0,0.1,0};
		brightness = 1;
	};
	class GreenStill2: RedStill
	{
		color[] = {0,5,0};
		ambient[] = {0,0.1,0};
		brightness = 1;
	};			
	class WhiteCollision: RedStill
	{
		color[] = {1,1,1};
		ambient[] = {0.1,0.1,0.1};
		intensity = 85;
		brightness = 1;
		blinkingPattern[] = {0.2,1.3};
		FlareSize = 1;
		drawLightSize = 0.4;
		drawLightCenterSize = 0.15;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 5;
			quadratic = 1;
			hardLimitStart = 1;
			hardLimitEnd = 20;
		};
	};
};