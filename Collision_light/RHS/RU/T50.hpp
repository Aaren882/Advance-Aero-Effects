class RHS_T50_base: Plane_Base_F
{
	class MarkerLights
	{
		class PositionRed
		{
			color[] = {0.8,0,0};
			ambient[] = {0.8,0,0};
			intensity = 150;
			drawLight = 1.5;
			drawLightSize = 0.25;
			drawLightCenterSize = 04;
			blinking = 0;
			flareSize=0.3;
			dayLight = 1;
			useFlare = 1;
			activeLight = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 50;
			};
		};
		class PositionGreen: PositionRed
		{
			color[] = {0,0.8,0};
			ambient[] = {0,0.8,0};
		};
	};
};