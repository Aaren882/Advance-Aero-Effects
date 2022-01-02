class RHS_TU95MS_base: Plane_Base_F
{
	class MarkerLights
	{
		class PositionRed1
		{
			color[] = {0.8,0,0};
			ambient[] = {0.8,0,0};
			intensity = 300;
			drawLight = 2.5;
			drawLightSize = 0.35;
			drawLightCenterSize = 0.14;
			blinking = 0;
			FlareSize = 0.3;
			activeLight = 1;
			dayLight = 1;
			useFlare = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 100;
			};
		};
		class PositionRed2: PositionRed1{};
		class PositionGreen1: PositionRed1
		{
			color[] = {0,0.8,0};
			ambient[] = {0,0.8,0};
		};

		class PositionGreen2: PositionGreen1{};
		class PositionWhite1: PositionGreen2
		{
			color[]={1,1,1};
			ambient[]={0.1,0.1,0.1};
		};
		class PositionWhite2: PositionWhite1{};
		class CollisionWhite1: PositionRed1
		{
			color[]={1,1,1};
			ambient[]={0.1,0.1,0.1};
			intensity = 500;
			blinking=1;
			blinkingPattern[]={0.1,0.9};
			blinkingPatternGuarantee=0;
			drawLightSize=0.7;
			drawLightCenterSize=0.7;
			FlareSize=1;
			delete Attenuation;
		};
		class CollisionWhite2: CollisionWhite1{};
	};
};