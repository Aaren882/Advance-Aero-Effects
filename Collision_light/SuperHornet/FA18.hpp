class MarkerLights
{
	class Red_Still_R
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		brightness=1;
		blinking=0;
		activeLight = 1;
		dayLight = 1;
		useFlare = 1;
		FlareSize = 0.3;
		intensity = 50;
		drawLight = 1;
		drawLightSize = 0.25;
		drawLightCenterSize = 0.05;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 5;
			quadratic = 1;
			hardLimitStart = 0.05;
			hardLimitEnd = 6;
		};
	};
	class Green_Still_L: Red_Still_R
	{
		color[] = {0,10,0};
		ambient[] = {0,0.8,0};
		brightness=1;
		blinking=0;
	};
	class White_Still_L: Red_Still_R
	{
		color[] = {10,10,10};
		ambient[] = {0.1,0.1,0.1};
		brightness=1;
		blinking=0;
		FlareSize = 0.5;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 5;
			quadratic = 3;
			hardLimitStart = 0.01;
			hardLimitEnd = 3;
		};
	};
	class White_Still_R: White_Still_L
	{
		color[] = {10,10,10};
		ambient[] = {0.1,0.1,0.1};
		brightness=1;
		blinking=0;
		FlareSize = 0.5;
	};
	delete Red_blinking_L;
	class Red_blinking_R
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		intensity = 150;
		brightness=1;
		blinking=1;
		activeLight = 1;
		dayLight = 1;
		useFlare = 1;
		FlareSize = 1;
		drawLight = 1;
		drawLightSize = 0.35;
		drawLightCenterSize = 0.2;
		blinkingPattern[] = {0.1,0.9};
		blinkingStartsOn = 1;
		blinkingPatternGuarantee = 1;
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