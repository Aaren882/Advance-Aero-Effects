class RHS_AH1Z_base: Heli_Attack_01_base_F{};
class RHS_AH1Z: RHS_AH1Z_base
{
	class MarkerLights
	{
		class WhiteStill
		{
			color[]={1,1,1};
			ambient[]={0.1,0.1,0.1};
			blinking=1;
			intensity=75;
			blinkingPattern[]={0.1,0.9};
			blinkingPatternGuarantee=0;
			drawLight = 1;
			drawLightSize = 0.1;
			drawLightCenterSize = 0.02;
			useFlare=1;
			activeLight=1;
			brightness = 1;
		};
		class RedStill
		{
			color[] = {10,0,0};
			ambient[] = {0.1,0,0};
			intensity = 10;
			drawLight = 1;
			drawLightSize = 0.15;
			drawLightCenterSize = 0.04;
			FlareSize = 0.3;
			activeLight = 1;
			blinking = 0;
			dayLight = 1;
			useFlare = 1;
			brightness = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 0.5;
				hardLimitEnd = 3;
			};
		};
		class GreenStill: RedStill
		{
			color[] = {0,10,0};
			ambient[] = {0,0.1,0};
		};
		class RedBlinking
		{
			color[]={0.9,0.15,0.1};
			ambient[]={0.9,0.15,0.1};
			intensity=75;
			blinking=1;
			blinkingPattern[]={0.1,0.9};
			blinkingPatternGuarantee=0;
			drawLightSize=0.2;
			drawLightCenterSize=0.04;
			useFlare=1;
			activeLight=1;
			brightness = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 10;
				quadratic = 10;
				hardLimitStart = 1;
				hardLimitEnd = 2;
			};
		};
		class WhiteBlinking: RedBlinking
		{
			color[]={0.9,0.15,0.1};
			ambient[]={0.9,0.15,0.1};
			blinkingPattern[]={0.2,1.3};
			drawLightSize=0.25;
			drawLightCenterSize=0.08;
			useFlare=1;
			activeLight=1;
			brightness = 1;
		};
	};
};