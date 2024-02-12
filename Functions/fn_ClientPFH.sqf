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

  //-Take Client Side Handler
  private _EH = player getVariable ["AAE_EachFrame_EH_Client",-1];
  private _AAE_list = (allPlayers select {_x getVariable ["Have_AAE_Loaded",false]}) apply {str _x};
  _AAE_list sort true;

  if ((({(_x getVariable ["AAE_EachFrame_EH",-1]) != -1} count allPlayers) == 0) && ((_AAE_list # 0) == str player)) then {
    call AAE_fnc_ServerPFH;
    player setVariable ["AAE_EachFrame_EH_Client",-1];
    removeMissionEventHandler ["EachFrame", _EH];
  };
}];
player setVariable ["AAE_EachFrame_EH_Client",_idEH];
