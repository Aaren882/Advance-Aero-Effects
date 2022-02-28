class MarkerLights	
{
	class RedStill
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		intensity = 50;
		drawLight = 1;
		drawLightSize = 0.15;
		drawLightCenterSize = 0.1;
		activeLight = 1;
		brightness = 1;
		useFlare = 1;
		FlareSize = 0.25;
		blinking = 0;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 5;
			quadratic = 5;
			hardLimitStart = 1;
			hardLimitEnd = 3;
		};
	};
	delete RedStill2;
	class GreenStill: RedStill
	{
		name = "PositionLight_red2";
		color[] = {0,5,0};
		ambient[] = {0,0.1,0};
		brightness = 1;
	};
	class RedStill3: RedStill
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		brightness = 1;
		drawLightSize = 0.2;
		drawLightCenterSize = 0.12;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 10;
			quadratic = 10;
			hardLimitStart = 0.2;
			hardLimitEnd = 1;
		};
	};
	class GreenStill2: RedStill3
	{
		color[] = {0,5,0};
		ambient[] = {0,0.1,0};
		brightness = 1;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 10;
			quadratic = 10;
			hardLimitStart = 0.2;
			hardLimitEnd = 1;
		};
	};
	delete BlueStill;
	delete BlueStill2;
	class GreenRight: RedStill
	{
		color[] = {0,5,0};
		ambient[] = {0,0.1,0};
		brightness = 1;
	};
	class RedLeft: RedStill
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		brightness = 1;
	};
	delete GreenWingRight;
	delete RedWingLeft;
	delete WhiteCollision;
	class WhiteCollision2: RedStill
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
			quadratic = 3;
			hardLimitStart = 1;
			hardLimitEnd = 12;
		};
	};
};