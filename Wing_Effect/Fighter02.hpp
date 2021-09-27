class To201_FuselageVapour_FighterJet
{
	class FX_Plane_BodyTrail_low
	{
		simulation = "particles";
		type = "FX_BodyTrail_FighterJet";
		qualityLevel = 0;
		enabled = "accelY interpolate [59.99,60,-1,1]";
	};
	class FX_Plane_BodyTrail_medium
	{
		simulation = "particles";
		type = "FX_BodyTrail_FighterJet";
		qualityLevel = 1;
		enabled = "accelY interpolate [59.99,60,-1,1]";
	};
	class FX_Plane_BodyTrail_high
	{
		simulation = "particles";
		type = "FX_BodyTrail_FighterJet";
		qualityLevel = 2;
		enabled = "accelY interpolate [59.99,60,-1,1]";
	};
	
	//LWing
	//1
	class 1FX_Plane_WingTrail_lowL
	{
		simulation = "particles";
		type = "AAE_BodyTrail_FighterJet";
		position[] = {-1,0.2,-2};
		qualityLevel = 0;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 1FX_Plane_WingTrail_mediumL: 1FX_Plane_WingTrail_lowL
	{
		qualityLevel = 1;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 1FX_Plane_WingTrail_highL: 1FX_Plane_WingTrail_lowL
	{
		qualityLevel = 2;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	//2
	class 2FX_Plane_WingTrail_lowL: 1FX_Plane_WingTrail_lowL
	{
		position[] = {-2,0.2,-3};
		qualityLevel = 0;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 2FX_Plane_WingTrail_mediumL: 2FX_Plane_WingTrail_lowL
	{
		qualityLevel = 1;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 2FX_Plane_WingTrail_highL: 2FX_Plane_WingTrail_lowL
	{
		qualityLevel = 2;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	//3
	class 3FX_Plane_WingTrail_lowL: 1FX_Plane_WingTrail_lowL
	{
		position[] = {-3,0.2,-4};
		qualityLevel = 0;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 3FX_Plane_WingTrail_mediumL: 3FX_Plane_WingTrail_lowL
	{
		qualityLevel = 1;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 3FX_Plane_WingTrail_highL: 3FX_Plane_WingTrail_lowL
	{
		qualityLevel = 2;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	//4
	class 4FX_Plane_WingTrail_lowL: 1FX_Plane_WingTrail_lowL
	{
		type = "AAE_BodyTrail_FighterJet_Short";
		position[] = {-4,0.2,-5};
		qualityLevel = 0;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 4FX_Plane_WingTrail_mediumLL: 4FX_Plane_WingTrail_lowL
	{
		qualityLevel = 1;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 4FX_Plane_WingTrail_highL: 4FX_Plane_WingTrail_lowL
	{
		qualityLevel = 2;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	
	//RWing
	//1
	class 1FX_Plane_WingTrail_lowR
	{
		simulation = "particles";
		type = "AAE_BodyTrail_FighterJet";
		position[] = {1,0.2,-2};
		qualityLevel = 0;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 1FX_Plane_WingTrail_mediumR: 1FX_Plane_WingTrail_lowR
	{
		qualityLevel = 1;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 1FX_Plane_WingTrail_highR: 1FX_Plane_WingTrail_lowR
	{
		qualityLevel = 2;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	//2
	class 2FX_Plane_WingTrail_lowR: 1FX_Plane_WingTrail_lowR
	{
		position[] = {2,0.2,-3};
		qualityLevel = 0;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 2FX_Plane_WingTrail_mediumR: 2FX_Plane_WingTrail_lowR
	{
		qualityLevel = 1;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 2FX_Plane_WingTrail_highR: 2FX_Plane_WingTrail_lowR
	{
		qualityLevel = 2;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	//3
	class 3FX_Plane_WingTrail_lowR: 1FX_Plane_WingTrail_lowR
	{
		type = "AAE_BodyTrail_FighterJet_Short";
		position[] = {3,0.2,-4};
		qualityLevel = 0;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 3FX_Plane_WingTrail_mediumR: 3FX_Plane_WingTrail_lowR
	{
		qualityLevel = 1;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 3FX_Plane_WingTrail_highR: 3FX_Plane_WingTrail_lowR
	{
		qualityLevel = 2;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	//4
	class 4FX_Plane_WingTrail_lowR: 1FX_Plane_WingTrail_lowR
	{
		type = "AAE_BodyTrail_FighterJet_Short";
		position[] = {4,0.2,-5};
		qualityLevel = 0;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 4FX_Plane_WingTrail_mediumR: 4FX_Plane_WingTrail_lowR
	{
		qualityLevel = 1;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
	class 4FX_Plane_WingTrail_highR: 4FX_Plane_WingTrail_lowR
	{
		qualityLevel = 2;
		enabled = "accelY interpolate [79.99,80,-1,1]";
	};
};