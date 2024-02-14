params ["_plane","_Engine_State"];

if (!(alive _plane) || !_Engine_State) exitwith {_plane call AAE_fnc_DeleteEH};

_plane setvariable ["AAE_Vapor_toggle",vapor_sdr + random 20];

//- Setup Filter
#if __has_include("\z\ace\addons\gforces\config.bin")
  #define GFORCES (Gforces_fn && (ace_gforces_enabledfor == 0))
#else
  #define GFORCES Gforces_fn
#endif

if !(GFORCES) exitWith {};
if !(isNil{AAE_GForces_Filter}) exitWith {};

AAE_GForces_Filter = ppEffectCreate ["ColorCorrections", 6500];
AAE_GForces_Filter ppEffectForceInNVG true;
AAE_GForces_Filter ppEffectAdjust [1,1,0,[0,0,0,0],[0,0,0,0],[1,1,1,1],[10,10,0,0,0,0.1,0.5]];
AAE_GForces_Filter ppEffectCommit 0.4;
AAE_GForces_Filter ppEffectEnable true;
