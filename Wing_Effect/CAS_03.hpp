//LWing
class A143_FuselageVapour_FighterJet_L
{
	class FX_Plane_BodyTrail
	{
		simulation = "particles";
		type = "BodyTrail";
		enabled = "accelY interpolate [29.99,30,-1,1]";
	};
	
	//1
	class 1FX_Plane_WingTrail
	{
		simulation = "particles";
		type = "AAE_BodyTrail_FighterJet_A164";
		position[] = {-0.5,0.15,-0.03};
		enabled = "accelY interpolate [34.99,35,-1,1]";
		qualityLevel = 2;
	};
	//2
	class 2FX_Plane_WingTrail: 1FX_Plane_WingTrail
	{
		type = "AAE_BodyTrail_FighterJet_Short_Vanilla";
		position[] = {-1,0.15,-0.03};
	};
	//3
	class 3FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		position[] = {-1.5,0.13,-0.1};
	};
	//4
	class 4FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		position[] = {-2,0.15,-0.15};
	};
	//5
	class 5FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		
		position[] = {-2.5,0.12,-0.2};
	};
	//6
	class 6FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		position[] = {-3,0.1,-0.25};
	};
};
//RWing
class A143_FuselageVapour_FighterJet_R
{
	class FX_Plane_BodyTrail
	{
		simulation = "particles";
		type = "BodyTrail";
		enabled = "accelY interpolate [29.99,30,-1,1]";
	};
	
	//1
	class 1FX_Plane_WingTrail
	{
		simulation = "particles";
		type = "AAE_BodyTrail_FighterJet_A164";
		position[] = {0.5,0.15,-0.03};
		enabled = "accelY interpolate [34.99,35,-1,1]";
		qualityLevel = 2;
	};
	//2
	class 2FX_Plane_WingTrail: 1FX_Plane_WingTrail
	{
		type = "AAE_BodyTrail_FighterJet_Short_Vanilla";
		position[] = {1,0.15,-0.03};
	};
	//3
	class 3FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		position[] = {1.5,0.13,-0.1};
	};
	//4
	class 4FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		position[] = {2,0.15,-0.15};
	};
	//5
	class 5FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		
		position[] = {2.5,0.12,-0.2};
	};
	//6
	class 6FX_Plane_WingTrail: 2FX_Plane_WingTrail
	{
		position[] = {3,0.1,-0.25};
	};
};