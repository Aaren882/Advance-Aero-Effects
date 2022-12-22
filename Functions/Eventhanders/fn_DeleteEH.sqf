//Remove EachFrame EH
params ["_plane"];
if (_plane getVariable ["AAE_Actived", false]) then {
  //Engine EH
  _plane setVariable ["AAE_Actived", false];

  //Loop Remove
  /* removeMissionEventHandler ["EachFrame", (_plane getVariable ["AAE_EachFrame_Engine", -1])];
  _plane setVariable ["AAE_EachFrame_Engine", -1]; */

  //G Forces
  AAE_GForces_Filter ppEffectEnable false;
  ppEffectDestroy AAE_GForces_Filter;

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
    _plane setVariable ["AAE_Vapor_Paricles", []];
  };

  //SonicBoom
  _plane setVariable ["AAE_SonicBoom_Main_Activated", false];
  _plane setVariable ["AAE_SonicBoom_Small_Activated", false];
  _Sonic_source00 = _plane getVariable ["AAE_SonicBoom_Small_Particle",objNull];
  _Sonic_source01 = _plane getVariable ["AAE_SonicBoom_Main_Particle",objNull];

  //Burner
  _plane setVariable ["AAE_BurnerActived",false];
  if (count _Burner_sources > 0) then {
    {deleteVehicle _x} foreach _Burner_sources;
    _plane setVariable ["AAE_Burner_Sources", []];
  };

  //Ground
  _plane setVariable ["AAE_Ground_Type_Changed",false];
  /* if (count _Ground_Paricles > 0) then {
    {deleteVehicle _x} foreach _Ground_Paricles;
    _plane setVariable ["AAE_Ground_Particles", []];
    _plane setVariable ["AAE_Ground_Activated", false];
  }; */

  //Landed
  if (count _landed_Particles > 0) then {
    {deleteVehicle _x} foreach _landed_Particles;
    _plane setVariable ["AAE_Landed_Paricles", []];
  };
};
