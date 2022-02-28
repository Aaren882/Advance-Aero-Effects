/*///////////////////////////////////////////////////////////////////////
Find Engine Exhaust POS LODs etc

By: Aaren
/*///////////////////////////////////////////////////////////////////////
params["_plane"];

//Classes Directory
_Exhausts = "true" configClasses (configFile >> "CfgVehicles" >> typeOf _plane >> "Exhausts");

//Vars
_Exhausts_count = _plane getVariable ["AAE_Exhausts_Count",count _Exhausts];
_Exhausts_POS = _plane getVariable ["AAE_Exhaust_POS",[]];
_Engine_Offset= _plane getVariable ["AAE_veh_Engine_Offset",[]];
_Exhaust_Dir = _plane getVariable ["AAE_Exhaust_Direction",[]];

_plane setVariable ["AAE_Exhausts_Count",count _Exhausts];

//Find Engine Exhaust POS and Pushback
for "_i" from 0 to (_Exhausts_count - 1) step 1 do
{
  _Engine = _Exhausts # _i;

  _pos = getText (_Engine >> "position");

  _Exhausts_POS pushback _pos;

  //Get LODs offset
  _offset = _plane selectionPosition _pos;
  _Engine_Offset pushback _offset;

  //Get Direction (Back)
  _Dir = _plane selectionVectorDirAndUp [_pos, "Memory"];
  _Back_Dir = [((_Dir # 0) vectorMultiply -1), ((_Dir # 1) vectorMultiply -1)];
  _Exhaust_Dir pushback _Back_Dir;
};

//Set Variables
_plane setVariable ["AAE_Exhaust_POS",_Exhausts_POS];
_plane setVariable ["AAE_veh_Engine_Offset",_Engine_Offset];
_plane setVariable ["AAE_Exhaust_Direction",_Exhaust_Dir];
_plane setVariable ["AAE_Find_Engine",true];
