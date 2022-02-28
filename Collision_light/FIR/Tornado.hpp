class MarkerLights
{
	class PositionRed
	{
		name = "PositionLight_red_1_pos";
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		intensity = 50;
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
			quadratic = 5;
			hardLimitStart = 0.2;
			hardLimitEnd = 1;
		};
	};
	class PositionGreen: PositionRed
	{
		color[] = {0,5,0};
		ambient[] = {0,0.1,0};
		name = "PositionLight_green_1_pos";
	};
	class CollisionRed: PositionRed
	{
		name = "CollisionLight_red_1_pos";
		color[] = {9,1.5,1};
		ambient[] = {0.09,0.015,0.01};
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
		name = "CollisionLight_white_1_pos";
		color[] = {1,1,1};
		ambient[] = {0.1,0.1,0.1};
		intensity = 85;
		FlareSize = 1;
		blinking = 1;
		blinkingPattern[] = {0.1,0.9};
		blinkingPatternGuarantee = 0;
		drawLightSize = 0.2;
		drawLightCenterSize = 0.04;
		class Attenuation
		{
			start = 1;
			constant = 0;
			linear = 5;
			quadratic = 5;
			hardLimitStart = 1;
			hardLimitEnd = 20;
		};
	};
};