class RHS_CH_47F_base: Heli_Transport_02_base_F
{
	class MarkerLights
	{
		class RedStill
		{
			color[]={0.8,0,0};
			ambient[]={0.8,0,0};
			intensity=74;
			drawLight=1;
			drawLightSize=0.2;
			drawLightCenterSize=0.04;
			blinking=0;
			activeLight=1;
			dayLight=1;
			useFlare=1;
			FlareSize=0.3;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 15;
			};
		};
		class GreenStill: RedStill
		{
			color[]={0,0.8,0};
			ambient[]={0,0.8,0};
			intensity=50;
			drawLight=1;
			drawLightSize=0.2;
			drawLightCenterSize=0.04;
			blinking=0;
			activeLight=1;
			dayLight=1;
			useFlare=1;
			FlareSize=0.3;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 15;
			};
		};
	};
};