class CfgWeapons
{
	class CannonCore;
	class weapon_Fighter_Gun20mm_AA: CannonCore
	{
		class GunParticles
		{
			class Effect
			{
				effectName = "MachineGun3";
				positionName = "pos_nosegun";
				directionName = "pos_nosegun_dir";
			};
		};
	};
	class weapon_Fighter_Gun_30mm: CannonCore
	{
		class GunParticles
		{
			class Effect
			{
				effectName = "MachineGun3";
				positionName = "nosegun";
				directionName = "nosegun_dir";
			};
		};
	};
};