_idEH = addMissionEventHandler ["EachFrame", {
  private _AAE_UnitList = missionNamespace getVariable ["AAE_UnitList", []];

  if (count _AAE_UnitList != 0) then {
    _AAE_UnitList apply {
      if !(isGamePaused) then {
        call AAE_fnc_Main_process;
      };
    };
  };

  //-List Update
  if (time > (AAE_UnitList_LastUpdate + 0.1)) then {
    AAE_UnitList_LastUpdate = time;
    missionNamespace setVariable ["AAE_UnitList", vehicles select {(_x iskindof "plane") && (isEngineOn _x) && (_x getVariable ["AAE_Find_Engine",false])}, true];
  };

  //-Remove Client Side Handler If Have Multiple Handlers
  private _EH = player getVariable ["Have_AAE_Loaded",-1];
  private _AAE_list = (allPlayers select {_x getVariable ["Have_AAE_Loaded",false]}) apply {str _x};
  _AAE_list sort true;

  if ((({(_x getVariable ["AAE_EachFrame_EH",-1]) != -1} count allPlayers) > 1) && !((_AAE_list # 0) == str player)) then {
    call AAE_fnc_ClientPFH;
    player setVariable ["AAE_EachFrame_EH",-1,true];
    removeMissionEventHandler ["EachFrame", _EH];
  };
}];

player setVariable ["AAE_EachFrame_EH",_idEH,true];
