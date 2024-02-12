params ["_plane","_Engine_State"];

if (!(alive _plane) || !_Engine_State) exitwith {_plane call AAE_fnc_DeleteEH};


_plane setvariable ["AAE_Vapor_toggle",vapor_sdr + random 20];

AAE_GForces_Filter = ppEffectCreate ["ColorCorrections", 6500];
AAE_GForces_Filter ppEffectForceInNVG true;
AAE_GForces_Filter ppEffectAdjust [1,1,0,[0,0,0,0],[0,0,0,0],[1,1,1,1],[10,10,0,0,0,0.1,0.5]];
AAE_GForces_Filter ppEffectCommit 0.4;

if (_plane iskindof "Plane") then {
  AAE_GForces_Filter ppEffectEnable true;
};