class Heli_Transport_01_base_F: Helicopter_Base_H
{
	class UserActions
	{
		class DoorL1_Open
		{
			userActionID = 50;
			displayName = "$STR_A3_CfgVehicles_UserActions_OpenLdoor0";
			displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			radius = 2.5;
			radiusView = 0.2;
			showIn3D = 17;
			available = 0;
			priority = 0.5;
			position = "door_L";
			showWindow = 1;
			onlyForPlayer = 1;
			shortcut = "";
			condition = "this doorPhase 'door_L' < 0.5 AND Alive(this) && player in this";
			statement = "this animateDoor ['door_L', 1]";
		};
		class DoorR1_Open: DoorL1_Open
		{
			userActionID = 51;
			displayName = "$STR_A3_CfgVehicles_UserActions_OpenRdoor0";
			position = "door_R";
			condition = "this doorPhase 'door_R' < 0.5 AND Alive(this) && player in this";
			statement = "this animateDoor ['door_R', 1]";
		};
		class DoorL1_Close: DoorL1_Open
		{
			userActionID = 53;
			displayName = "$STR_A3_CfgVehicles_UserActions_CloseLdoor0";
			condition = "this doorPhase 'door_L' > 0.5 AND Alive(this) && player in this";
			statement = "this animateDoor ['door_L', 0]";
		};
		class DoorR1_Close: DoorL1_Close
		{
			userActionID = 54;
			displayName = "$STR_A3_CfgVehicles_UserActions_CloseRdoor0";
			position = "door_R";
			condition = "this doorPhase 'door_R' > 0.5 AND Alive(this) && player in this";
			statement = "this animateDoor ['door_R', 0]";
		};
	};
};
class Heli_Transport_03_base_F: Helicopter_Base_H
{
	waterLeakiness = 0.1;
	class UserActions
	{
		class Ramp_Open
		{
			userActionID = 60;
			displayName = "$STR_ACTION_RAMP_OPEN0";
			textToolTip = "$STR_ACTION_RAMP_OPEN0";
			displayNameDefault = "<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2.5' />";
			position = "";
			condition = "this doorPhase 'Door_rear_source' < 0.5 AND Alive(this) && {(player in [driver this, this turretUnit [0], this turretUnit [3], this turretUnit [4]])} && {((this getVariable ['bis_disabled_Ramp',0]) isEqualTo 0)}";
			statement = "this animateDoor ['Door_rear_source', 1]";
			priority = 1.5;
			radius = 1.5;
			radiusView = 0.2;
			showIn3D = 17;
			available = 0;
			showWindow = 0;
			onlyForPlayer = 1;
			shortcut = "";
		};
		class Ramp_Close: Ramp_Open
		{
			userActionID = 61;
			displayName = "$STR_ACTION_RAMP_CLOSE0";
			textToolTip = "$STR_ACTION_RAMP_CLOSE0";
			condition = "this doorPhase 'Door_rear_source' > 0.5 AND Alive(this) && {(player in [driver this, this turretUnit [0], this turretUnit [3], this turretUnit [4]])} && {((this getVariable ['bis_disabled_Ramp',0]) isEqualTo 0)}";
			statement = "this animateDoor ['Door_rear_source', 0]";
		};
		
		class Right_Door_Open: Ramp_Open
		{
			displayName = "$STR_A3_CfgVehicles_UserActions_OpenRdoor0";
			textToolTip = "$STR_A3_CfgVehicles_UserActions_OpenRdoor0";
			condition = "this doorPhase 'Door_R_source' < 0.5 AND Alive(this) && {(player in [driver this, this turretUnit [0], this turretUnit [1], this turretUnit [2]])} && {((this getVariable ['bis_disabled_Ramp',0]) isEqualTo 0)}";
			statement = "this animateDoor ['Door_R_source', 1]";
		};
		class Right_Door_Colse: Ramp_Close
		{
			displayName = "$STR_A3_CfgVehicles_UserActions_CloseRdoor0";
			textToolTip = "$STR_A3_CfgVehicles_UserActions_CloseRdoor0";
			condition = "this doorPhase 'Door_R_source' > 0.5 AND Alive(this) && {(player in [driver this, this turretUnit [0], this turretUnit [1], this turretUnit [2]])} && {((this getVariable ['bis_disabled_Ramp',0]) isEqualTo 0)}";
			statement = "this animateDoor ['Door_R_source', 0]";
		};
		
		class Left_Door_Open: Ramp_Open
		{
			displayName = "$STR_A3_CfgVehicles_UserActions_OpenLdoor0";
			textToolTip = "$STR_A3_CfgVehicles_UserActions_OpenLdoor0";
			condition = "this doorPhase 'Door_L_source' < 0.5 AND Alive(this) && {(player in [driver this, this turretUnit [0], this turretUnit [1], this turretUnit [2]])} && {((this getVariable ['bis_disabled_Ramp',0]) isEqualTo 0)}";
			statement = "this animateDoor ['Door_L_source', 1]";
		};
		class Left_Door_Colse: Ramp_Close
		{
			displayName = "$STR_A3_CfgVehicles_UserActions_CloseLdoor0";
			textToolTip = "$STR_A3_CfgVehicles_UserActions_CloseLdoor0";
			condition = "this doorPhase 'Door_L_source' > 0.5 AND Alive(this) && {(player in [driver this, this turretUnit [0], this turretUnit [1], this turretUnit [2]])} && {((this getVariable ['bis_disabled_Ramp',0]) isEqualTo 0)}";
			statement = "this animateDoor ['Door_L_source', 0]";
		};
	};
};
//-RHSUSAF
#if __has_include("\rhsusf\addons\rhsusf_main\config.bin")
	class Heli_Transport_02_base_F;
	class RHS_CH_47F_base: Heli_Transport_02_base_F
	{
		waterLeakiness = 0.1;
	};
#endif

//H-60
#if __has_include("\z\vtx\addons\uh60_config\config.bin")
	class vtx_H60_base: Heli_Transport_01_base_F
	{
		class UserActions: UserActions
		{
			class DoorL1_Open: DoorL1_Open
			{
				condition = "false";
			};
			class DoorR1_Open: DoorR1_Open
			{
				condition = "false";
			};
			class DoorL1_Close: DoorL1_Close
			{
				condition = "false";
			};
			class DoorR1_Close: DoorR1_Close
			{
				condition = "false";
			};
		};
	};
#endif