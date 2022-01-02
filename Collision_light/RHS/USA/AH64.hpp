class RHS_AH64_base: Heli_Attack_01_base_F{};
class RHS_AH64D: RHS_AH64_base
{
	class MarkerLights
	{
		class WhiteStill
		{
			color[] = {1,1,1};
			ambient[] = {0.1,0.1,0.1};
			blinking = 1;
			intensity = 75;
			activeLight = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.45;
			drawLightCenterSize = 0.24;
			useFlare = 1;
			brightness = 1;
		};
		class RedStill
		{
			color[] = {0.8,0,0};
			ambient[] = {0.8,0,0};
			intensity = 85;
			drawLight = 1;
			drawLightSize = 0.45;
			drawLightCenterSize	= 0.24;
			activeLight = 1;
			blinking = 0;
			dayLight = 1;
			useFlare = 1;
			brightness = 1;
		};
		class GreenStill: RedStill
		{
			color[]	 = {0,0.8,0};
			ambient[] = {0,0.8,0};
		};
		class RedBlinking
		{
			color[] = {0.9,0.15,0.1};
			ambient[] = {0.9,0.15,0.1};
			intensity = 150;
			blinking = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.45;
			drawLightCenterSize	= 0.24;
			activeLight = 1;
			useFlare = 1;
			brightness = 1;
		};
		class WhiteBlinking
		{
			color[] = {0.9,0.15,0.1};
			intensity = 150;
			ambient[] = {0.9,0.15,0.1};
			blinking = 1;
			blinkingPattern[] = {0.2,1.3};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.45;
			drawLightCenterSize = 0.24;
			activeLight = 1;
			useFlare = 1;
			brightness = 1;
		};
	};
};