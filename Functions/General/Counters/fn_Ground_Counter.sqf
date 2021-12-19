params["_plane"];
while {(alive _plane) and (_plane getVariable ["AAE_Actived", false])} do {
  if !(isGamePaused) then {
    sleep 5;
    if !(_plane getVariable ["AAE_Ground_Type_Changed",false]) then {
      _plane setVariable ["AAE_Ground_Particles_Refrash",true];
      sleep 0.0001;
      _plane setVariable ["AAE_Ground_Particles_Refrash",false];
    };
  };
};
