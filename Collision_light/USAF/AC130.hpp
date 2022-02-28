class MarkerLights
{
	class PositionRed
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
		FlareSize = 0.6;
		blinking = 0;
	};
	class PositionRed2: PositionRed
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		intensity = 50;
		FlareSize = 0.3;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 5;
			quadratic = 5;
			hardLimitStart = 1;
			hardLimitEnd = 8;
		};
	};
	class PositionRed3: PositionRed
	{
		activeLight = 1;
		FlareSize = 0.3;
	};
	class PositionGreen: PositionRed
	{
		color[] = {0,10,0};
		ambient[] = {0,0.1,0};
	};
	class PositionWhite: PositionRed
	{
		color[] = {1,1,1};
		ambient[] = {0.1,0.1,0.1};
		activeLight = 1;
	};
	class PositionWhite2: PositionWhite
	{
		activeLight = 1;
	};
	class CollisionWhite: PositionRed
	{
		color[] = {10,10,10};
		ambient[] = {0.1,0.1,0.1};
		intensity = 85;
		blinking = 1;
		FlareSize = 1;
		drawLightSize = 0.4;
		drawLightCenterSize = 0.15;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 5;
			quadratic = 3;
			hardLimitStart = 0.5;
			hardLimitEnd = 4;
		};
	};
	class CollisionWhite2: CollisionWhite
	{
		activeLight = 1;
		class Attenuation
		{
			start = 3;
			constant = 0;
			linear = 5;
			quadratic = 1;
			hardLimitStart = 3;
			hardLimitEnd = 20;
		};
	};
};