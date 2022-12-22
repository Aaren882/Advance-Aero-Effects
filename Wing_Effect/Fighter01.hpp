//LWing
class F181_FuselageVapour_FighterJet_L: FX_FuselageVapour_FighterJet
{
	class FX_Plane_BodyTrail
	{
		simulation = "particles";
		type = "FX_BodyTrail_FighterJet";
		enabled = "accelY interpolate [69.99,70,-1,1]";
	};
	
	//1
	class 1FX_Plane_WingTrail
	{
		simulation = "particles";
		type = "AAE_BodyTrail_FighterJet";
		position[] = {-1,0.1,-3};
		enabled = "accelY interpolate [74.99,75,-1,1]";
		qualityLevel = 2;
	};
	//2
	class 2FX_Plane_WingTrail: 1FX_Plane_WingTrail
	{
		position[] = {-1.5,0,-3.5};
	};
	//3
	class 3FX_Plane_WingTrail: 1FX_Plane_WingTrail
	{
		type = "AAE_BodyTrail_FighterJet_Short";
		position[] = {-2,0,-4};
	};
	//4
	class 4FX_Plane_WingTrail: 3FX_Plane_WingTrail
	{
		position[] = {-2.5,-0.1,-4.4};
	};
	//5
	class 5FX_Plane_WingTrail: 3FX_Plane_WingTrail
	{
		position[] = {-3,-0.1,-4.8};
	};
	//6
	class 6FX_Plane_WingTrail: 3FX_Plane_WingTrail
	{
		position[] = {-3.5,-0.1,-5.3};
	};
	//7
	class 7FX_Plane_WingTrail: 3FX_Plane_WingTrail
	{
		position[] = {-4,-0.1,-5.3};
	};
};
//RWing
class F181_FuselageVapour_FighterJet_R
{
	//1
	class 1FX_Plane_WingTrail
	{
		simulation = "particles";
		type = "AAE_BodyTrail_FighterJet";
		position[] = {1,0.1,-3};
		enabled = "accelY interpolate [74.99,75,-1,1]";
		qualityLevel = 2;
	};
	//2
	class 2FX_Plane_WingTrail: 1FX_Plane_WingTrail
	{
		position[] = {1.5,0,-3.5};
	};
	//3
	class 3FX_Plane_WingTrail: 1FX_Plane_WingTrail
	{
		type = "AAE_BodyTrail_FighterJet_Short";
		position[] = {2,0,-4};
	};
	//4
	class 4FX_Plane_WingTrail: 3FX_Plane_WingTrail
	{
		position[] = {2.5,-0.1,-4.4};
	};
	//5
	class 5FX_Plane_WingTrail: 3FX_Plane_WingTrail
	{
		position[] = {3,-0.1,-4.8};
	};
	//6
	class 6FX_Plane_WingTrail: 3FX_Plane_WingTrail
	{
		position[] = {3.5,-0.1,-5.3};
	};
	//7
	class 7FX_Plane_WingTrail: 3FX_Plane_WingTrail
	{
		position[] = {4,-0.1,-5.3};
	};
};