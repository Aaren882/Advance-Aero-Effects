class rhs_uh1h_base: Helicopter_Base_H
{
	class MarkerLights
	{
		class CollisionLight_Red
		{
			color[] = {0.9,0.15,0.1};
			ambient[] = {0.9,0.15,0.1};
			intensity = 75;
			blinking = 1;
			blinkingPattern[] = {0.1,0.9};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.2;
			drawLightCenterSize = 0.04;
			FlareSize = 0.3;
			useFlare = 1;
			activeLight = 1;
			dayLight = 1;
			class Attenuation
			{
				start = 0;
				constant = 0;
				linear = 5;
				quadratic = 1;
				hardLimitStart = 1;
				hardLimitEnd = 8;
			};
		};
		class Red_Interior: CollisionLight_Red
		{
			color[] = {0.9,0.15,0.1};
			ambient[] = {0.9,0.15,0.1};
			intensity = 800;
			blinking = 0;
			drawLightSize = 0;
			drawLightCenterSize = 0;
			useFlare = 0;
			activeLight = 0;
			dayLight = 0;
		};
		class Red_Top_Position: CollisionLight_Red
		{
			color[] = {0.9,0.15,0.1};
			ambient[] = {0.9,0.15,0.1};
			intensity = 150;
			blinking = 1;
			blinkingPattern[] = {0.5,0.5};
			blinkingPatternGuarantee = 0;
			drawLightSize = 0.2;
			drawLightCenterSize = 0.04;
			FlareSize = 1;
			delete Attenuation;
		};
		class Green_Position: CollisionLight_Red
		{
			color[] = {0.4,1,0.5};
			ambient[] = {0.4,1,0.5};
		};
	};
};