class rhsusf_CH53E_USMC: Helicopter_Base_H
{
	class MarkerLights
	{
		class PositionRed
		{
			color[]={0.8,0,0};
			ambient[]={0.8,0,0};
			intensity=75;
			drawLight=1;
			drawLightSize=0.15;
			drawLightCenterSize=0.04;
			blinking=0;
			activeLight=1;
			dayLight=1;
			useFlare=1;
			FlareSize=0.5;
			class Attenuation
			{
				start=0;
				constant=0;
				linear=5;
				quadratic=1;
				hardLimitStart=1;
				hardLimitEnd=10;
			};
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
			drawLightSize=0.2;
		};
		class CollisionRed: PositionRed
		{
			color[]={0.9,0.15,0.1};
			ambient[]={0.9,0.15,0.1};
			blinking=1;
			blinkingPattern[]={0.2,1.3};
			blinkingPatternGuarantee=0;
			drawLightSize=0.25;
			drawLightCenterSize=0.08;
			FlareSize=1;
			intensity=150;
			class Attenuation: Attenuation
			{
				hardLimitEnd=20;
			};
		};
		class CollisionWhite: PositionRed
		{
			color[]={1,1,1};
			ambient[]={0.1,0.1,0.1};
			blinking=1;
			blinkingPattern[]={0.1,0.9};
			blinkingPatternGuarantee=0;
			drawLightSize=0.2;
			drawLightCenterSize=0.04;
			FlareSize=1;
		};
		class InteriorBlue
		{
			color[]={0.07,1,0.9};
			ambient[]={0.07,0.1,0.9};
			intensity=75;
			blinking=0;
			drawLightSize=0.25;
			drawLightCenterSize=0.08;
			class Attenuation
			{
				start=0;
				constant=0;
				linear=25;
				quadratic=50;
				hardLimitStart=2.25;
				hardLimitEnd=3;
			};
		};
	};
};