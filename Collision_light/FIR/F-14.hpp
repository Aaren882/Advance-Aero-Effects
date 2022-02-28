class MarkerLights 
{
	class Green_Still_R
	{
		color[] = {0,0.8,0};
		ambient[] = {0,0.8,0};
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
			linear = 10;
			quadratic = 10;
			hardLimitStart = 1;
			hardLimitEnd = 3;
		};
	};
	class Green_Still_R_2: Green_Still_R
	{
		color[] = {0,0.8,0};
		ambient[] = {0,0.8,0};
		brightness = 1;
	};
	
	class Red_Still_L: Green_Still_R
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		brightness = 1;
	};
	class Red_Still_L_2: Green_Still_R
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		brightness = 1;
	};
	class Tail_Pos_Light: Green_Still_R
	{
		color[] = {10,6,0};
		ambient[] = {1,0.6,0};
		brightness = 1;
		intensity = 85;
		FlareSize = 0.6;
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
	class Tail_Pos_Light_1: Tail_Pos_Light
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		brightness = 1;
		drawLightSize = 0.2;
		drawLightCenterSize = 0.15;
		blinkingPattern[] = {0.2,1.3};
		class Attenuation: Attenuation
		{
			quadratic = 1;
			hardLimitEnd = 15;
		};
	};
	delete Tail_Pos_Light_2;
	delete Tail_Pos_Light_3;
	/*class Tail_Pos_Light_2: Tail_Pos_Light_1
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		brightness = 1;
	};
	class Tail_Pos_Light_3: Tail_Pos_Light_1
	{
		color[] = {10,0,0};
		ambient[] = {0.1,0,0};
		brightness = 1;
	};*/
};