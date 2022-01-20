/*///////////////////////////////////////////////////////////////////////
Find Engine Exhaust POS

Returns: Boolean
By: Aaren
/*///////////////////////////////////////////////////////////////////////
params["_plane"];
//Classes Directory
_Exhausts = "true" configClasses (configFile >> "CfgVehicles" >> typeOf _plane >> "Exhausts");

//Vars
_Exhausts_count = _plane getVariable ["AAE_Exhausts_Count",count _Exhausts];
_Exhausts_POS = _plane getVariable ["AAE_Exhaust_POS",[]];
_Engine_Offset= _plane getVariable ["AAE_veh_Engine_Offset",[]];

_plane setVariable ["AAE_Exhausts_Count",count _Exhausts];

//Find Engine Exhaust POS and Pushback
for "_i" from 0 to (_Exhausts_count - 1) step 1 do
{
  _format = format["AAE_Engine_%1",_i];
  _plane setVariable [_format, _Exhausts # _i];
  _Engine = _plane getVariable _format;

  _pos = getText (_Engine >> "position");

  _plane setVariable [_format,_pos];
  _Exhausts_POS pushback _pos;
  _plane setVariable ["AAE_Exhaust_POS",_Exhausts_POS];

  //Get LODs offset
  _offset = _plane selectionPosition _pos;
  _Engine_Offset pushback _offset;
  _plane setVariable ["AAE_veh_Engine_Offset",_Engine_Offset];
};

/* _Exhausts_2 = _plane getVariable "AAE_Engine_2";
_Exhausts_3 = _plane getVariable "AAE_Engine_3";
_Exhausts_POS = _plane getVariable "AAE_Exhaust_POS";
_Engine_Offset = _plane getVariable "AAE_veh_Engine_Offset";
_Exhausts_count = _plane getVariable "AAE_Exhausts_Count";
hintSilent str [_Exhausts_2,_Exhausts_3,_Exhausts_POS,time]; */

_plane setVariable ["AAE_Find_Engine",true];

true
