class RHS_L159_base: Plane_Fighter_03_base_F
{
	class MarkerLights
	{
		class PositionRed
		{
			color[] = {1,0,0};
			ambient[] = {0.1,0,0};
			intensity = 75;
			drawLight = 1;
			drawLightSize = 0.15;
			drawLightCenterSize = 0.04;
			blinking = 0;
			FlareSize = 0.3;
			useFlare = 1;
			activeLight = 1;
			dayLight = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 8;
			};
		};
		class PositionGreen: PositionRed
		{
			color[] = {0,1,0};
			ambient[] = {0,0.1,0};
		};
		class PositionWhite: PositionRed
		{
			color[] = {1,1,1};
			ambient[] = {0.1,0.1,0.1};
		};
	};
};