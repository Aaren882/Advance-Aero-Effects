class MarkerLights 
{
	class Red_Still_R
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
		FlareSize = 0.3;
		blinking = 0;
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
	
	class Green_Still_L: Red_Still_R
	{
		color[] = {0,5,0};
		ambient[] = {0,0.1,0};
		brightness = 1;
		blinking = 0;
	};
};