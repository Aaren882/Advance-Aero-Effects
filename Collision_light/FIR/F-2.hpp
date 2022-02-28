class MarkerLights 
{
	class Red_Still_R
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		intensity = 50;
		drawLight = 1;
		drawLightSize = 0.2;
		drawLightCenterSize = 0.15;
		activeLight = 1;
		brightness = 1;
		useFlare = 1;
		FlareSize = 0.4;
		blinking = 0;
		class Attenuation
		{
			start = 0;
			constant = 0;
			linear = 5;
			quadratic = 10;
			hardLimitStart = 0.2;
			hardLimitEnd = 2;
		};
	};
	class Green_Still_L: Red_Still_R
	{
		color[] = {0,5,0};
		ambient[] = {0,0.1,0};
		brightness = 1;
		blinking = 0;
	};
	class Red_Still_R2: Red_Still_R
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		brightness = 1;
		blinking = 0;
	};
	class Green_Still_L2: Red_Still_R
	{
		color[] = {0,5,0};
		ambient[] = {0,0.1,0};
		brightness = 1;
		blinking = 0;
	};
	class Red_Still_R3: Red_Still_R
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		brightness = 1;
		blinking = 0;
	};
	class Green_Still_L3: Red_Still_R
	{
		color[] = {0,5,0};
		ambient[] = {0,0.1,0};
		brightness = 1;
		blinking = 0;
	};
	class White_blink_C: Red_Still_R
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