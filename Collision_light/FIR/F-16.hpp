class MarkerLights 
{
	class Red_Still_R 
	{
		color[] = {0.8,0,0};
		ambient[] = {0.8,0,0};
		intensity = 85;
		drawLight = 1;
		drawLightSize = 0.5;
		drawLightCenterSize = 0.2;
		activeLight = 1;
		brightness = 1;
		blinking = 1;
		dayLight = 1;
		useFlare = 1;
		FlareSize = 1;
		blinkingPattern[] = {0.1,0.9};
		blinkingPatternGuarantee = 0;
	};
	class Green_Still_L: Red_Still_R
	{
		color[]	= {0,0.8,0};
		ambient[] = {0,0.8,0};
		blinking = 1;
		brightness = 1;
	};
	class Red_Still_R2: Red_Still_R
	{
		color[] = {0.8,0,0};
		ambient[] = {0.8,0,0};
		intensity = 50;
		blinking = 0;
		brightness = 1;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 1;
			quadratic = 1;
			hardLimitStart = 0.05;
			hardLimitEnd = 0.5;
		};
	};
	class Green_Still_L2: Red_Still_R2
	{
		color[] = {0,0.8,0};
		ambient[] = {0,0.8,0};
		blinking = 0;
		brightness = 1;
	};
	class Red_Still_R3: Red_Still_R2
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		blinking = 0;
		brightness = 1;
		activeLight = 0;
		drawLight = 0;
		FlareSize = 0.4;
	};
	class Green_Still_L3: Red_Still_R3
	{
		color[] = {0,10,0};
		ambient[] = {0,0.8,0};
		blinking = 0;
		brightness = 1;
	};
	class White_blink_C: Red_Still_R
	{
		color[] = {1,1,1};
		ambient[] = {0.1,0.1,0.1};
		brightness = 1;
		blinkingPattern[] = {0.2,1.3};
		FlareSize = 1;
		drawLightSize = 0.45;
		drawLightCenterSize	= 0.24;
	};
};