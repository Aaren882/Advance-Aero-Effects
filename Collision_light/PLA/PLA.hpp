class MarkerLights
{
	class CollisionLight_wingtip_red
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		intensity = 50;
		drawLightSize = 0.15;
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
			hardLimitEnd = 5;
		};
	};
	class CollisionLight_wingtip_green: CollisionLight_wingtip_red
	{
		color[] = {0,10,0};
		ambient[] = {0,0.8,0};
	};
	class CollisionLightWhite1
	{
		color[] = {50,50,50};
		ambient[] = {0.1,0.1,0.1};
		blinking = 1;
		FlareSize = 1;
		intensity = 100;
		activeLight = 1;
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
	class CollisionLightWhite2: CollisionLightWhite1
	{
		activeLight = 0;
	};
};