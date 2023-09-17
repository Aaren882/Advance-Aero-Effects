//FIR
#if __has_include("\FIR_AirWeaponSystem_US_cfg\config.bin")
	class FIR_A10A_Base : Plane_CAS_01_base_F
	{
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_A10C_Base : Plane_CAS_01_base_F
	{
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_A10U_Base : Plane_CAS_01_base_F
	{
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_F14D_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 19.54;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_F16_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 9.96;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_F35B_Armaverse_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 10.7;
		class ABSystem
		{
			AB_Source = "afterburner_strech";
		};
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_AV8B_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 9.25;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_AV8B_NA_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 9.25;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_AV8B_GR7_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 9.25;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_F15_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 13.03;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_F15A_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 13.03;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_F15B_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 13.03;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_F15E_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 13.03;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_F15E_Demo_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 13.03;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_F15B_Civ_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 13.03;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_F15D_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 13.03;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_F15SE_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 13.03;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_FA18_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 13.62;
		class ABSystem
		{
			AB_Source = "ab_l_hide";
		};
	};
	class FIR_F22_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 13.56;
		class EventHandlers: EventHandlers
		{};
	};
	class FIR_F23A_Base : Plane_Fighter_03_base_F
	{
		Aircraft_Wingspan = 13.3;
		class EventHandlers: EventHandlers
		{};
	};
	class Tornado_AWS_BASE: Plane_Fighter_03_base_F
	{
		class ABSystem
		{
			AB_Source = "burner_fire_1_left";
		};
		class EventHandlers: EventHandlers
		{};
	};
#endif

//F/A-18 Super Hornets
#if __has_include("\js_jc_fa18\config.bin")
	class JS_JC_FA18E: Plane_Base_F
	{
		Aircraft_Wingspan = 13.62;
		AB_Source = "ab_switch";
		class WingVortices
		{
			class WingTipLeft
			{
				effectName = "FX_FA18_WingVortices";
			};
			class WingTipRight
			{
				effectName = "FX_FA18_WingVortices";
			};
		};
		class Exhausts
		{
			class Exhaust_left
			{
				effect = "ExhaustsEffectPlaneHP";
			};
			class Exhaust_right
			{
				effect = "ExhaustsEffectPlaneHP";
			};
		};
	};
	class JS_JC_FA18F: Plane_Base_F
	{
		Aircraft_Wingspan = 13.62;
		AB_Source = "ab_switch";
		class WingVortices
		{
			class WingTipLeft
			{
				effectName = "FX_FA18_WingVortices";
			};
			class WingTipRight
			{
				effectName = "FX_FA18_WingVortices";
			};
		};
		class Exhausts
		{
			class Exhaust_left
			{
				effect = "ExhaustsEffectPlaneHP";
			};
			class Exhaust_right
			{
				effect = "ExhaustsEffectPlaneHP";
			};
		};
	};
#endif

//RHS
class rhsusf_f22: Plane_Fighter_03_base_F
{
	AB_Source = "afterburner_source";
};
class rhs_mig29s_base: Plane_Base_F
{
	AB_Source = "afterburner_l_translate";
};
class RHS_T50_base: Plane_Base_F
{
	AB_Source = "afterburner_l_translate";
};

//USAF
#if __has_include("\usaf_main\config.bin")
	//-Utility
	class USAF_MQ9: UAV
	{
		class WingVortices
		{
			class WingTipLeft
			{
				effectName = "WingVortices";
				position = "light_strobe_L";
			};
			class WingTipRight
			{
				effectName = "WingVortices";
				position = "light_strobe_R";
			};
		};
	};
	class USAF_C130J_Base: Plane_Base_F
	{
		class WingVortices
		{
			class WingTipLeft
			{
				effectName = "WingVortices";
				position = "PositionLight_red_1_pos";
			};
			class WingTipRight
			{
				effectName = "WingVortices";
				position = "PositionLight_green_1_pos";
			};
		};
	};
	
	//-AC-130
	class USAF_AC130U_base: Plane_Base_F{};
	class USAF_AC130U: USAF_AC130U_base
	{
		AAE_WheelsContact[] = {"wheel_1_1","wheel_2_1","wheel_2_2"};
		class WingVortices
		{
			class WingTipLeft
			{
				effectName = "WingVortices";
				position = "navigationlight red1";
			};
			class WingTipRight
			{
				effectName = "WingVortices";
				position = "navigationlight green1";
			};
		};
	};
#endif

//SOG
class vn_air_f4_base: Plane_Base_F
{
	Aircraft_Wingspan = 11.7;
	//AAE_Have_AB = 1;
};

/*//Sab Military
class sab_militaryaviation_baseplane: Plane_Base_F
{
	class EventHandlers: EventHandlers
	{};
};

//Unsung
class uns_plane: Plane_Base_F
{
	class EventHandlers: EventHandlers
	{};
};*/