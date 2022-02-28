params["_plane","_type","_Depos"];

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
waitUntil {
  ((_plane getVariable ["AAE_Ground_Type","Default"]) != _type)
};
_plane setVariable ["AAE_Ground_Type_Changed",true];
