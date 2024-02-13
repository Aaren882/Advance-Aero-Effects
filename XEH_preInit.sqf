#include "CBA_Setting.hpp"

// -Basic Definitions
//-Sonic Settings
AAE_SpeedSet = 1195;
AAE_sonicboom_speed_01 = AAE_SpeedSet - 20;//1175
AAE_sonicboom_speed_02 = AAE_SpeedSet - 10;//1185
AAE_sonicboom_speed_03 = AAE_SpeedSet + 10;//1205

//-ACE Vars
_tempMap = createHashMap;
_temp = [];
_temp resize 30;

_tempMap set ["GForces", _temp apply {1}];
_tempMap set ["Index", 0];
_tempMap set ["lastUpdateTime", 0];
_tempMap set ["oldVel", [0,0,0]];

localNamespace setVariable [
  "AAE_GForce_Var",
  _tempMap
];
_temp = nil;

AAE_UnitList_LastUpdate = 0;
