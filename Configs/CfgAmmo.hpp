class CfgAmmo
{
	//AA
	class MissileBase;
	class ammo_Missile_MediumRangeAABase: MissileBase
	{
		initTime = 0.3;
		thrust = 400;
	};
	class ammo_Missile_ShortRangeAABase: MissileBase
	{
		effectsMissile = "AAE_Missile_AA_Short";
	};
	class Missile_AGM_02_F: MissileBase
	{
		effectsMissile = "FX_Missile_AG";
	};
	class CMflare_Chaff_Ammo;
	class FIR_CMFlare_Chaff_Ammo: CMflare_Chaff_Ammo
	{
		delete effectsSmoke;
		delete model;
		delete airFriction;
		delete thrustTime;
	};
};