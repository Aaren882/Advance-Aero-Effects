class RHS_C130J_Base: Plane_Base_F
{
	class MarkerLights
	{
		class PositionRed
		{
			color[]={0.8,0,0};
			ambient[]={0.8,0,0};
			intensity=200;
			drawLight=1;
			drawLightSize=0.4;
			drawLightCenterSize=0.04;
			blinking=0;
			dayLight=1;
			useFlare=1;
			activeLight=1;
		};
		class PositionGreen: PositionRed
		{
			color[]={0,0.8,0};
			ambient[]={0,0.8,0};
		};
		class PositionWhite: PositionRed
		{
			color[]={1,1,1};
			ambient[]={0.1,0.1,0.1};
			drawLightSize=0.4;
		};
		class PositionWhite2: PositionRed
		{
			color[]={1,1,1};
			ambient[]={0.1,0.1,0.1};
			drawLightSize=0.4;
		};
		class PositionWhite3: PositionRed
		{
			color[]={1,1,1};
			ambient[]={0.1,0.1,0.1};
			drawLightSize=0.4;
		};
		class PositionWhite4: PositionRed
		{
			color[]={1,1,1};
			ambient[]={0.1,0.1,0.1};
			drawLightSize=0.4;
		};
		class CollisionRed: PositionRed
		{
			color[]={0.9,0.15,0.1};
			ambient[]={0.9,0.15,0.1};
			blinking=1;
			blinkingPattern[]={0.2,1.3};
			blinkingPatternGuarantee=0;
			drawLightSize=0.4;
			drawLightCenterSize=0.08;
		};
		class CollisionWhite: PositionRed
		{
			color[]={1,1,1};
			ambient[]={0.1,0.1,0.1};
			blinking=1;
			blinkingPattern[]={0.1,0.9};
			blinkingPatternGuarantee=0;
			drawLightSize=0.4;
			drawLightCenterSize=0.04;
		};
	};
	//Fix Wing Vortices
	class WingVortices{};
};