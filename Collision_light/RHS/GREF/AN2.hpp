class RHS_AN2_Base: Plane_Base_F
{
	class MarkerLights
	{
		class WhiteStill
		{
			color[] = {1,1,1};
			ambient[] = {0.1,0.1,0.1};
			intensity = 75;
			drawLight = 1;
			drawLightSize = 0.25;
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
				hardLimitStart = 0.2;
				hardLimitEnd = 8;
			};
		};
		class RedStill
		{
			color[] = {0.8,0,0};
			ambient[] = {0.8,0,0};
			intensity = 75;
			drawLight = 1;
			drawLightSize = 0.25;
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
		class GreenStill
		{
			color[] = {0,0.8,0};
			ambient[] = {0,0.8,0};
			intensity = 75;
			drawLight = 1;
			drawLightSize = 0.25;
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
		class RedBlinking
		{
			color[] = {0.9,0.15,0.1};
			ambient[] = {0.9,0.15,0.1};
			intensity = 75;
			blinking = 1;
			blinkingStartsOn = 0;
			blinkingPattern[] = {2.9,0.1};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.2;
			drawLightCenterSize = 0.04;
			useFlare = 1;
			activeLight = 1;
			dayLight = 1;
		};
		class WhiteBlinking1
		{
			color[] = {1.0, 1.0, 1.0};
			ambient[] = {0.1,0.1,0.1};
			intensity = 100;
			blinking = 1;
			blinkingPattern[] = {0.1, 2.9};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.35;
			drawLightCenterSize = 08;
			useFlare = 1;
			activeLight = 1;
			dayLight = 1;
		};
		class WhiteBlinking2 : WhiteBlinking1{};
		class WhiteBlinking3: WhiteBlinking1{};
	};
};