//Fighter 01
class Plane_Fighter_01_Base_F: Plane_Base_F
{
	Aircraft_Wingspan = 13.56;
	AAE_Have_AB = 1;
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
		//Left
		class BodyLeft_inner_1
		{
			effectName = "F181_FuselageVapour_FighterJet_L";
			position = "pos_body_vapour_L_1";
		};
		class BodyLeft_inner_2
		{
			effectName = "FX_FuselageVapour_FighterJet";
			position = "pos_body_vapour_L_2";
		};
		class BodyLeft_inner_3: BodyLeft_inner_2
		{
			position = "pos_body_vapour_L_3";
		};
		//Right
		class BodyRight_inner_1
		{
			effectName = "F181_FuselageVapour_FighterJet_R";
			position = "pos_body_vapour_R_1";
		};
		class BodyRight_inner_2
		{
			effectName = "FX_FuselageVapour_FighterJet";
			position = "pos_body_vapour_R_2";
		};
		class BodyRight_inner_3: BodyRight_inner_2
		{
			position = "pos_body_vapour_R_3";
		};
	};
	class CarrierOpsCompatability
	{
		ArrestHookMemoryPoint = "tailhook";
	};
	//"hit_glass1"
	/*hiddenSelections[] = 
	{
		"Camo1",
		"Camo2",
		"glass1",
		"camo_cockpit_1",
		"camo_cockpit_2",
		"camo_cockpit_3",
		"camo_cockpit_5",
		"number_01",
		"number_02",
		"number_03",
		"canopy"
	};
	hiddenSelectionsTextures[] = 
	{
		"a3\air_f_jets\plane_fighter_01\data\fighter_01_fuselage_01_co.paa",
		"a3\air_f_jets\plane_fighter_01\data\fighter_01_fuselage_02_co.paa",
		"",
		"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_01_co.paa",
		"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_02_co.paa",
		"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_03_co.paa",
		"a3\air_f_jets\plane_fighter_01\data\fighter_01_cockpit_05_co.paa",
		"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_01_ca.paa",
		"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_00_ca.paa",
		"a3\air_f_jets\plane_fighter_01\data\Numbers\Fighter_01_01_ca.paa"
	};*/
};
//Fighter02
class Plane_Fighter_02_Base_F: Plane_Base_F
{
	Aircraft_Wingspan = 14.1;
	AAE_Have_AB = 1;
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
		//Left
		class BodyLeft_inner
		{
			effectName = "To201_FuselageVapour_FighterJet_L";
			position = "body_vapour_L_S";
		};
		class BodyLeft_outer: BodyLeft_inner
		{
			effectName = "FX_FuselageVapour_FighterJet";
			position = "body_vapour_L_E";
		};
		//Right
		class BodyRight_inner
		{
			effectName = "To201_FuselageVapour_FighterJet_R";
			position = "body_vapour_R_S";
		};
		class BodyRight_outer: BodyLeft_outer
		{
			effectName = "FX_FuselageVapour_FighterJet";
			position = "body_vapour_R_E";
		};
	};
};
//Fighter04
class Plane_Fighter_04_Base_F: Plane_Base_F
{
	Aircraft_Wingspan = 8.6;
	AAE_Have_AB = 1;
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
			effectName = "A149_FuselageVapour_FighterJet_L";
			position = "pos_body_vapour_L";
		};
		class BodyRight_inner_1
		{
			effectName = "A149_FuselageVapour_FighterJet_R";
			position = "pos_body_vapour_R";
		};
	};
};
//CAS_01
class Plane_CAS_01_base_F: Plane_Base_F
{
	Aircraft_Wingspan = 17.53;
	class WingVortices
	{
		class BodyLeft
		{
			effectName = "A164_FuselageVapour_FighterJet";
			position = "Vapour_body_left_pos";
		};
		class BodyRight
		{
			effectName = "A164_FuselageVapour_FighterJet";
			position = "Vapour_body_right_pos";
		};
		class WingTipLeft
		{
			effectName = "WingVortices";
			position = "Vapour_wintip_left_pos";
		};
		class WingTipRight
		{
			effectName = "WingVortices";
			position = "Vapour_wintip_right_pos";
		};
	};
	//hiddenSelections[] += {"glass_1","glass_2","glass_3"};
	//hiddenSelectionsTextures[] += {"a3\air_f_epc\plane_cas_01\data\plane_cas_01_glass_ca.paa","a3\air_f_jets\plane_fighter_01\data\fighter_01_glass_01_ca.paa","a3\air_f_jets\plane_fighter_01\data\fighter_01_glass_01_ca.paa"};
};
//CAS_02
class Plane_CAS_02_base_F: Plane_Base_F
{
	Aircraft_Wingspan = 13.62;
	class WingVortices
	{
		class BodyLeft
		{
			effectName = "To199_FuselageVapour_FighterJet_L";
			position = "Vapour_body_left_pos";
		};
		class BodyRight
		{
			effectName = "To199_FuselageVapour_FighterJet_R";
			position = "Vapour_body_right_pos";
		};

		class WingTipLeft
		{
			effectName = "WingVortices";
			position = "Vapour_wintip_left_pos";
		};
		class WingTipRight
		{
			effectName = "WingVortices";
			position = "Vapour_wintip_right_pos";
		};
	};
};
//Fighter_03 (A-143)
class Plane_Fighter_03_base_F: Plane_Base_F
{
	Aircraft_Wingspan = 9.46;
	class WingVortices
	{
		class BodyLeft
		{
			effectName = "A143_FuselageVapour_FighterJet_L";
			position = "body_vapour_L_S";
		};
		class BodyRight
		{
			effectName = "A143_FuselageVapour_FighterJet_R";
			position = "body_vapour_R_S";
		};
		class WingTipLeft
		{
			effectName = "WingVortices";
			position = "body_vapour_L_E";
		};
		class WingTipRight
		{
			effectName = "WingVortices";
			position = "body_vapour_R_E";
		};
	};
};