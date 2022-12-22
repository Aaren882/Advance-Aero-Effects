//Water
if (surfaceIsWater _Depos) then {
  _plane setVariable ["AAE_Ground_Type","Water"];
} else {
  //Beach
  if ((surfaceType _Depos == "#GdtBeach")) then {
    _plane setVariable ["AAE_Ground_Type","Beach"];
  };
  //Dust
  if ((surfaceType _Depos != "#GdtStratisConcrete") and (surfaceType _Depos != "#GdtConcrete") and (surfaceType _Depos != "#GdtSeabed") and (surfaceType _Depos != "#GdtBeach")) then {
    _plane setVariable ["AAE_Ground_Type","Dust"];
  };
};

//Return Value : Bool ("AAE_Ground_Type_Changed")
_plane setVariable ["AAE_Ground_Type_Changed",false];
if ((_plane getVariable ["AAE_Ground_Type","Default"]) != _Particle_Pick) then {
  _plane setVariable ["AAE_Ground_Type_Changed",true];
  //-exit ground particles
  _plane setVariable ["AAE_Ground_Activated", false];
};
