class RHS_UH60_Base;
class RHS_UH60M_base: RHS_UH60_Base
{
	class MarkerLights
	{
		class WhiteStill
		{
			color[]={1,1,1};
			ambient[]={0.1,0.1,0.1};
			blinking=1;
			intensity=150;
			blinkingPattern[]={0.1,0.9};
			blinkingPatternGuarantee=0;
			drawLightSize=0.25;
			drawLightCenterSize=0.04;
			activeLight=1;
			dayLight=1;
			useFlare=1;
		};
		class RedStill
		{
			color[]={0.8,0,0};
			ambient[]={0.8,0,0};
			intensity=75;
			drawLight=1;
			drawLightSize=0.21;
			drawLightCenterSize=0.1;
			blinking=0;
			activeLight=1;
			dayLight=1;
			useFlare=0;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 10;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 8;
			};
		};
		class GreenStill: RedStill
		{
			color[]={0,0.8,0};
			ambient[]={0,0.8,0};
			intensity=60;
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
			activeLight=1;
			dayLight=1;
			useFlare=1;
		};
		class WhiteBlinking: RedBlinking
		{
			blinkingPattern[]={0.2,1.3};
			drawLightSize=0.25;
			drawLightCenterSize=0.08;
		};
	};
};