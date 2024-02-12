/*///////////////////////////////////////////////////////////////////////
Find Engine Exhaust POS LODs etc

By: Aaren
/*///////////////////////////////////////////////////////////////////////

//Classes Directory
_Exhausts = "true" configClasses (_config >> "Exhausts");

//Vars
_Exhausts_count = count _Exhausts;
_Exhausts_POS = [];
_Engine_Offset= [];
_Exhaust_Dir = [];

//Find Engine Exhaust POS and Pushback
for "_i" from 0 to (_Exhausts_count - 1) step 1 do {
  private ["_Engine","_pos","_offset","_Dir","_Back_Dir"];
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
_LocalCache set ["AAE_Exhausts_Count",_Exhausts_count];
_LocalCache set ["AAE_Exhaust_POS",_Exhausts_POS];
_LocalCache set ["AAE_veh_Engine_Offset",_Engine_Offset];
_LocalCache set ["AAE_Exhaust_Direction",_Exhaust_Dir];
_LocalCache set ["AAE_Find_Engine",true];
