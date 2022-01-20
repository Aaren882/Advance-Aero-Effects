_Burner_Activated = _plane getVariable ["AAE_BurnerActived",false];
_plane_thrust = _plane getSoundController "thrust";

//After Burner
if (burner_fn and (_plane_thrust > 0.9) and (_have_AB) and !(isNull _plane)) then {
  [_plane,_Exhausts_count,_Exhausts_POS] call AAE_fnc_exhaust_dir;
  if !(_Burner_Activated) then {
    [_plane,_Exhausts_count,_engine_offsets] Spawn AAE_fnc_burner;
    _plane setVariable ["AAE_BurnerActived",true];
  };
} else {
  _plane setVariable ["AAE_BurnerActived",false];
};
