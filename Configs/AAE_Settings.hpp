AAE_Alarm_Int = "AAE_Alarm";
AAE_Rumble_Int = "AAE_Rumble";
AAE_GBreathe = "AAE_GBreathe";
AAE_GBreathe_Hold = "AAE_GBreathe_Hold";
AAE_AB_Sound = "AAE_AB_Active";
Taxiing = "AAE_RumbleG";
AAE_Touchdown_Int[] = {"MG8\AVDAVFX\snd\touchdown_int.ogg", 5, 1};
AAE_Touchdown_Ext[] = {"MG8\AVDAVFX\snd\touchdown.ogg", 1, 1, 1500};
AAE_Burner_Offset[] = {0,-0.3,0}; // {X,Y,Z} in Script Format
AAE_WheelsContact[] = {}; //Enter the LOD name
class AAE_Config_Handler
{
	//Particle Color Settings
	Beach[] = 
	{
		{1,1,0.46,0},
		{1,1,0.46,0.01},
		{1,1,0.46,0.02},
		{1,1,0.46,0.06},
		{1,1,0.46,0.05},
		{1,1,0.46,0.02},
		{1,1,0.46,0}
	};
	Dust[] =
	{
		{1,1,0.46,0},
		{1,1,0.46,0.01},
		{1,1,0.46,0.02},
		{1,1,0.46,0.06},
		{1,1,0.46,0.05},
		{1,1,0.46,0.02},
		{1,1,0.46,0}
	};
	Default[] =
	{
		{1,1,0.46,0},
		{1,1,0.46,0.01},
		{1,1,0.46,0.02},
		{1,1,0.46,0.06},
		{1,1,0.46,0.05},
		{1,1,0.46,0.02},
		{1,1,0.46,0}
	};
	Water[] =
	{
		{0.7,0.8,1,0},
		{0.7,0.8,1,0.05},
		{0.7,0.8,1,0.1},
		{0.7,0.8,1,0.12},
		{0.7,0.8,1,0.08},
		{0.7,0.8,1,0.04},
		{0.7,0.8,1,0.02},
		{0.85,0.9,1,0}
	};
};