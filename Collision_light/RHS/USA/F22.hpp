class rhsusf_f22: Plane_Fighter_03_base_F
{
	class MarkerLights
	{
		class PositionLeft
		{
			color[]={0,0.8,0};
			ambient[]={0,0.8,0};
			intensity=50;
			drawLight=1;
			drawLightSize=0.25;
			drawLightCenterSize=0.08;
			activeLight=1;
			blinking=0;
			dayLight=1;
			useFlare=1;
			FlareSize=0.3;
			class Attenuation
			{
				start=0;
				constant=0;
				linear=5;
				quadratic=1;
				hardLimitStart=1;
				hardLimitEnd=50;
			};
		};
		class PositionRight: PositionLeft{}
		class CollisionLeft: PositionLeft
		{
			color[]={0.9,0.15,0.1};
			ambient[]={0.9,0.15,0.1};
			intensity=300;
			blinking=1;
			blinkingPattern[]={0.2,1.3};
			blinkingPatternGuarantee=0;
			drawLightSize=0.35;
			drawLightCenterSize=0.18;
			FlareSize=1;
			delete Attenuation;
		};
		class CollisionRight: CollisionLeft{}
	};
};