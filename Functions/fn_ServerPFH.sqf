_idEH = addMissionEventHandler ["EachFrame", {
  private _AAE_UnitList = missionNamespace getVariable ["AAE_UnitList", []];
  if (count _AAE_UnitList != 0) then {
    _planePlayer = cameraOn;
    _planePlayer_class = typeof _planePlayer;

    _AAE_UnitList apply {
      if !(isGamePaused) then {
        call AAE_fnc_Main_process;
      };
    };
  };

  //-List Update
  if (time > (AAE_UnitList_LastUpdate + 1)) then {
    AAE_UnitList_LastUpdate = time;
    missionNamespace setVariable ["AAE_UnitList", vehicles select {
      (_x iskindof "plane") && (isEngineOn _x) && ((typeOf _x) in (localNamespace getVariable "AAE_Basic_Cache"))
    }, true];
  };

  //-Remove Client Side Handler If Have Multiple Handlers
  private _EH = player getVariable ["AAE_EachFrame_EH",-1];
  private _AAE_list = (allPlayers select {_x getVariable ["Have_AAE_Loaded",false]}) apply {str _x};
  _AAE_list sort true;

  if ((({(_x getVariable ["AAE_EachFrame_EH",-1]) != -1} count allPlayers) > 1) && !((_AAE_list # 0) == str player)) then {
    call AAE_fnc_ClientPFH;
    removeMissionEventHandler ["EachFrame", _EH];
    player setVariable ["AAE_EachFrame_EH",-1,true];
  };
}];

player setVariable ["AAE_EachFrame_EH",_idEH,true];
