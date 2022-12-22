//LWing
class To199_FuselageVapour_FighterJet_L
{
	class FX_Plane_BodyTrail_1
	{
		simulation = "particles";
		type = "BodyTrail";
		enabled = "accelY interpolate [29.99,30,-1,1]";
	};
	class FX_Plane_BodyTrail_2
	{
		simulation = "particles";
		type = "BodyTrail";
		position[] = {0.8,0.2,1.8};
		enabled = "accelY interpolate [29.99,30,-1,1]";
	};
	
	//1
	class 1FX_Plane_WingTrail
	{
		simulation = "particles";
		type = "AAE_BodyTrail_FighterJet_A164";
		position[] = {-0.5,0,-0.3};
		enabled = "accelY interpolate [34.99,35,-1,1]";
		qualityLevel = 2;
	};
	//2
	class 2FX_Plane_WingTrail: 1FX_Plane_WingTrail
	{
		type = "AAE_BodyTrail_FighterJet_Short_Vanilla";
		position[] = {-1,0,-0.6};
	};
	//3
	class 3FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		position[] = {-1.5,0,-1};
	};
	//4
	class 4FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		position[] = {-2,0,-1.3};
	};
	//5
	class 5FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		
		position[] = {-2.5,0,-1.6};
	};
	//6
	class 6FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		position[] = {-3,-0.05,-1.9};
	};
};
//RWing
class To199_FuselageVapour_FighterJet_R
{
	class FX_Plane_BodyTrail_1
	{
		simulation = "particles";
		type = "BodyTrail";
		enabled = "accelY interpolate [29.99,30,-1,1]";
	};
	class FX_Plane_BodyTrail_2
	{
		simulation = "particles";
		type = "BodyTrail";
		position[] = {-0.8,0.2,1.8};
		enabled = "accelY interpolate [29.99,30,-1,1]";
	};
	
	//1
	class 1FX_Plane_WingTrail
	{
		simulation = "particles";
		type = "AAE_BodyTrail_FighterJet_A164";
		position[] = {0.5,0,-0.3};
		enabled = "accelY interpolate [34.99,35,-1,1]";
		qualityLevel = 2;
	};
	//2
	class 2FX_Plane_WingTrail: 1FX_Plane_WingTrail
	{
		position[] = {1,0,-0.6};
	};
	//3
	class 3FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		type = "AAE_BodyTrail_FighterJet_Short_Vanilla";
		position[] = {1.5,0,-1};
	};
	//4
	class 4FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		position[] = {2,0,-1.3};
	};
	//5
	class 5FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		position[] = {2.5,0,-1.6};
	};
	//6
	class 6FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		position[] = {3,-0.05,-1.9};
	};
};