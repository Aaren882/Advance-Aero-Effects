//Fighter 01
class Plane_Fighter_01_Base_F: Plane_Base_F
{
	class WingVortices
	{
		class WingTipLeft
		{
			effectName = "FX_WingVortices_FighterJet";
			position = "pos_wingtip_vapour_L";
		};
		class WingTipRight
		{
			effectName = "FX_WingVortices_FighterJet";
			position = "pos_wingtip_vapour_R";
		};
		class BodyLeft_inner_1
		{
			effectName = "F181_FuselageVapour_FighterJet";
			position = "pos_body_vapour_L_1";
		};
		class BodyLeft_inner_2
		{
			effectName = "F181_FuselageVapour_FighterJet";
			position = "pos_body_vapour_L_2";
		};
		class BodyLeft_inner_3
		{
			effectName = "F181_FuselageVapour_FighterJet";
			position = "pos_body_vapour_L_3";
		};
		class BodyRight_inner_1
		{
			effectName = "F181_FuselageVapour_FighterJet";
			position = "pos_body_vapour_R_1";
		};
		class BodyRight_inner_2
		{
			effectName = "F181_FuselageVapour_FighterJet";
			position = "pos_body_vapour_R_2";
		};
		class BodyRight_inner_3
		{
			effectName = "F181_FuselageVapour_FighterJet";
			position = "pos_body_vapour_R_3";
		};
	};
};
//Fighter02
class Plane_Fighter_02_Base_F: Plane_Base_F
{
	class WingVortices
	{
		class WingTipLeft
		{
			effectName = "FX_WingVortices_FighterJet";
			position = "wingtip_marker_light_green";
		};
		class WingTipRight: WingTipLeft
		{
			position = "wingtip_marker_light_red";
		};
		class BodyLeft_inner
		{
			effectName = "To201_FuselageVapour_FighterJet";
			position = "body_vapour_L_S";
		};
		class BodyLeft_outer: BodyLeft_inner
		{
			position = "body_vapour_L_E";
		};
		class BodyRight_inner: BodyLeft_inner
		{
			position = "body_vapour_R_S";
		};
		class BodyRight_outer: BodyLeft_inner
		{
			position = "body_vapour_R_E";
		};
	};
};
class Plane_Fighter_04_Base_F: Plane_Base_F
{
	class WingVortices
	{
		class WingTipLeft
		{
			effectName = "FX_WingVortices_FighterJet";
			position = "pos_wingtip_vapour_L";
		};
		class WingTipRight: WingTipLeft
		{
			position = "pos_wingtip_vapour_R";
		};
		class BodyLeft_inner_1
		{
			effectName = "A149_FuselageVapour_FighterJet";
			position = "pos_body_vapour_L";
		};
		class BodyRight_inner_1: BodyLeft_inner_1
		{
			position = "pos_body_vapour_R";
		};
	};
};