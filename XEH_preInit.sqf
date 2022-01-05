#include "CBA_Setting.hpp"

//-ACE Detection
HaveACE = isClass (configFile >> "CfgPatches" >> "ace_main");

// -Basic Definitions
//-Sonic Settings
AAE_SpeedSet = 1195;
AAE_sonicboom_speed_01 = AAE_SpeedSet - 20;//1175
AAE_sonicboom_speed_02 = AAE_SpeedSet - 10;//1185
AAE_sonicboom_speed_03 = AAE_SpeedSet + 10;//1205

//-ACE Vars
GForces = [];
GForces resize 30;
GForces = GForces apply {1};
GForces_Index = 0;
lastUpdateTime = 0;
oldVel = [0,0,0];
