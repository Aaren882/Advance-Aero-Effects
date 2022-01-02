class A164_FuselageVapour_FighterJet
{
	class FX_Plane_BodyTrail_low
	{
		simulation = "particles";
		type = "BodyTrail";
		position[] = {0,-0.5,3};
		enabled = "accelY interpolate [29.99,30,-1,1]";
	};
	
	//RWing
	//1
	class 1FX_Plane_WingTrail_lowR
	{
		simulation = "particles";
		type = "AAE_BodyTrail_FighterJet_A164";
		position[] = {1,-0.5,3};
		enabled = "accelY interpolate [34.99,35,-1,1]";
	};
	//2
	class 2FX_Plane_WingTrail_lowR: 1FX_Plane_WingTrail_lowR
	{
		position[] = {2,-0.5,2.8};
	};
	//3
	class 3FX_Plane_WingTrail_lowR: 1FX_Plane_WingTrail_lowR
	{
		position[] = {3,-0.5,2.8};
	};
	//4
	class 4FX_Plane_WingTrail_lowR: 1FX_Plane_WingTrail_lowR
	{
		type = "AAE_BodyTrail_FighterJet_Short_Vanilla";
		position[] = {4,-0.5,2.76};
	};
	//5
	class 5FX_Plane_WingTrail_lowR: 4FX_Plane_WingTrail_lowR
	{
		position[] = {5,-0.5,2.76};
	};
	//6
	class 6FX_Plane_WingTrail_lowR: 4FX_Plane_WingTrail_lowR
	{
		position[] = {6,-0.35,2.65};
	};
	//7
	class 7FX_Plane_WingTrail_lowR: 4FX_Plane_WingTrail_lowR
	{
		position[] = {7,-0.35,2.65};
	};
	
	//LWing
	//1
	class 1FX_Plane_WingTrail_lowL
	{
		simulation = "particles";
		type = "AAE_BodyTrail_FighterJet_A164";
		position[] = {-1,-0.5,3};
		enabled = "accelY interpolate [34.99,35,-1,1]";
	};
	//2
	class 2FX_Plane_WingTrail_lowL: 1FX_Plane_WingTrail_lowL
	{
		position[] = {-2,-0.5,2.8};
	};
	//3
	class 3FX_Plane_WingTrail_lowL: 1FX_Plane_WingTrail_lowL
	{
		position[] = {-3,-0.5,2.8};
	};
	//4
	class 4FX_Plane_WingTrail_lowL: 1FX_Plane_WingTrail_lowL
	{
		type = "AAE_BodyTrail_FighterJet_Short_Vanilla";
		position[] = {-4,-0.5,2.76};
	};
	//5
	class 5FX_Plane_WingTrail_lowL: 4FX_Plane_WingTrail_lowL
	{
		position[] = {-5,-0.5,2.76};
	};
	//6
	class 6FX_Plane_WingTrail_lowL: 4FX_Plane_WingTrail_lowL
	{
		position[] = {-6,-0.35,2.65};
	};
	//7
	class 7FX_Plane_WingTrail_lowL: 4FX_Plane_WingTrail_lowL
	{
		position[] = {-7,-0.35,2.65};
	};
};