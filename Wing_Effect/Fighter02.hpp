class To201_FuselageVapour_FighterJet_L
{
	class FX_Plane_BodyTrail
	{
		simulation = "particles";
		type = "FX_BodyTrail_FighterJet";
		enabled = "accelY interpolate [69.99,70,-1,1]";
	};
	
	//LWing
	//1
	class 1FX_Plane_WingTrail
	{
		simulation = "particles";
		type = "AAE_BodyTrail_FighterJet";
		position[] = {-1,0.2,-2};
		enabled = "accelY interpolate [74.99,75,-1,1]";
		qualityLevel = 2;
	};
	//2
	class 2FX_Plane_WingTrail: 1FX_Plane_WingTrail
	{
		position[] = {-2,0.2,-3};
	};
	//3
	class 3FX_Plane_WingTrail: 1FX_Plane_WingTrail
	{
		type = "AAE_BodyTrail_FighterJet_Short";
		position[] = {-3,0.2,-4};
	};
	//4
	class 4FX_Plane_WingTrail: 3FX_Plane_WingTrail
	{
		position[] = {-4,0.2,-5};
	};
};
//RWing
class To201_FuselageVapour_FighterJet_R: To201_FuselageVapour_FighterJet_L
{
	//1
	class 1FX_Plane_WingTrail
	{
		simulation = "particles";
		type = "AAE_BodyTrail_FighterJet";
		position[] = {1,0.2,-2};
		enabled = "accelY interpolate [74.99,75,-1,1]";
		qualityLevel = 2;
	};
	//2
	class 2FX_Plane_WingTrail: 1FX_Plane_WingTrail
	{
		position[] = {2,0.2,-3};
	};
	//3
	class 3FX_Plane_WingTrail: 1FX_Plane_WingTrail
	{
		type = "AAE_BodyTrail_FighterJet_Short";
		position[] = {3,0.2,-4};
	};
	//4
	class 4FX_Plane_WingTrail: 3FX_Plane_WingTrail
	{
		position[] = {4,0.2,-5};
	};
};