class RHS_A10: Plane_CAS_01_base_F
{
	class MarkerLights
	{
		class CollisionRed
		{
			color[] = {0.8,0,0};
			ambient[] = {0.8,0,0};
			intensity = 300;
			drawLight = 1;
			drawLightSize = 0.25;
			drawLightCenterSize = 0.05;
			activeLight = 1;
			blinking = 1;
			dayLight = 0;
			useFlare = 1;
			blinkingPattern[] = {0.2,1.3};
			blinkingPatternGuarantee = 0;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 1;
				quadratic = 2;
				hardLimitStart = 1;
				hardLimitEnd = 20;
			};
		};
		class CollisionGreen: CollisionRed
		{
			color[] ={0,0.8,0};
			ambient[] ={0,0.08,0};
			blinkingPattern[] = {0.2,1.3};
		};
		class PositionWhiteTop: CollisionRed
		{
			color[] ={1,1,1};
			ambient[] ={0.1,0.1,0.1};
			drawLightSize =0.2;
			blinking = 0;
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
		class CollisionWhiteRear: CollisionRed
		{
			color[] ={1,1,1};
			ambient[] ={0.1,0.1,0.1};
			blinkingPatternGuarantee =0;
			drawLightSize =0.25;
			drawLightCenterSize =0.04;
			blinkingPattern[] = {0.2,1.5};
		};
	};
};