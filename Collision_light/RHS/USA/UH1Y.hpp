class RHS_UH1_Base: Heli_Light_03_base_F
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
			intensity=90;
			drawLight=1;
			drawLightSize=0.2;
			drawLightCenterSize=0.04;
			blinking=0;
			activeLight=1;
			dayLight=1;
			useFlare=0;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 10;
				quadratic = 3;
				hardLimitStart = 1;
				hardLimitEnd = 2;
			};
		};
		class GreenStill: RedStill
		{
			color[]={0,0.8,0};
			ambient[]={0,0.8,0};
			intensity=75;
		};
		class RedBlinking
		{
			color[]={0.9,0.15,0.1};
			ambient[]={0.9,0.15,0.1};
			intensity=40;
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
class RHS_UH1Y_US_base;
class RHS_UH1Y: RHS_UH1Y_US_base
{
	class MarkerLights
	{
		class WhiteStill
		{
			name = "bily pozicni";
			color[] = {1,1,1};
			ambient[] = {0.1,0.1,0.1};
			blinking = 1;
			intensity = 150;
			blinkingPattern[] = {0.1,0.9};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.25;
			drawLightCenterSize = 0.04;
			activeLight=1;
			dayLight=1;
			useFlare=1;
		};
		class RedStill
		{
			name = "cerveny pozicni";
			color[] = {0.8,0,0};
			ambient[] = {0.8,0,0};
			intensity = 90;
			drawLight = 1;
			drawLightSize = 0.15;
			drawLightCenterSize = 0.04;
			blinking = 0;
			activeLight=1;
			dayLight=1;
			useFlare=0;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 10;
				quadratic = 3;
				hardLimitStart = 1;
				hardLimitEnd = 2;
			};
		};
		class GreenStill: RedStill
		{
			name = "zeleny pozicni";
			color[] = {0,0.8,0};
			ambient[] = {0,0.8,0};
			intensity = 45;
		};
		class RedBlinking
		{
			name = "bily pozicni blik";
			color[] = {0.9,0.15,0.1};
			ambient[] = {0.09,0.015,0.01};
			intensity = 50;
			blinking = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.2;
			drawLightCenterSize = 0.04;
			activeLight=1;
			dayLight=1;
			useFlare=1;
		};
		class WhiteBlinking: RedBlinking
		{
			name = "cerveny pozicni blik";
			blinkingPattern[] = {0.2,1.3};
			drawLightSize = 0.25;
			drawLightCenterSize = 0.08;
		};
	};
};