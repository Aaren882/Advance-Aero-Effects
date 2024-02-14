//Remove EachFrame EH
params ["_plane"];

//G Forces
if !(isnil {AAE_GForces_Filter}) then {
  AAE_GForces_Filter ppEffectEnable false;
  ppEffectDestroy AAE_GForces_Filter;
  AAE_GForces_Filter = nil;
};

//Vars
_Vapor_Paricles = _plane getVariable ["AAE_Vapor_Paricles",[]];
_Sonic_Paricles = _plane getVariable ["AAE_Sonic_Paricles",[]];
_Burner_sources = _plane getVariable ["AAE_Burner_Sources",[]];
_Ground_Paricles = _plane getVariable ["AAE_Ground_Particles",[]];
_landed_Particles = _plane getVariable ["AAE_Landed_Paricles",[]];

//Vapor
_plane setVariable ["AAE_Vapor_Activated", false];
if (count (_plane getVariable "AAE_Vapor_Paricles") > 0) then {
  {deleteVehicle _x} foreach _Vapor_Paricles;
  _plane setVariable ["AAE_Vapor_Paricles", nil];
};

//SonicBoom
_plane setVariable ["AAE_SonicBoom_Main_Activated", false];
_plane setVariable ["AAE_SonicBoom_Small_Activated", false];

//Burner
_plane setVariable ["AAE_BurnerActived",false];
if (count _Burner_sources > 0) then {
  {deleteVehicle _x} foreach _Burner_sources;
  _plane setVariable ["AAE_Burner_Sources", nil];
};

//Ground
_plane setVariable ["AAE_Ground_Type_Changed",false];

//Landed
if (count _landed_Particles > 0) then {
  {deleteVehicle _x} foreach _landed_Particles;
  _plane setVariable ["AAE_Landed_Paricles", []];
};