class rhs_mig29s_base: Plane_Base_F
{
	class MarkerLights
	{
		class PositionRed
		{
			color[]={0.8,0,0};
			ambient[]={0.8,0,0};
			intensity=150;
			drawLight=1.5;
			drawLightSize=0.25;
			drawLightCenterSize=0.04;
			blinking=0;
			FlareSize=0.3;
			useFlare=1;
			activeLight = 1;
			dayLight = 1;
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
		class PositionGreen: PositionRed
		{
			color[]={0,0.8,0};
			ambient[]={0,0.8,0};
		};
		class PositionWhite: PositionRed
		{
			color[]={1,1,1};
			ambient[]={0.8,0.8,0.8};
			FlareSize=0.8;
		};
	};
};