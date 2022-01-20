//params ["_plane","_engine_offsets","_Exhausts_count","_Exhausts_POS","_Wingspan"];

//Player only
if (_planePlayer isKindOf "plane") then {
  _turbulent_Distance_Found = _planePlayer getVariable ["AAE_Turbulent_Source_Distance_Found",false];
  if (cameraView == "internal") then {

    //Turbulent Settings
    [_plane,_Exhausts_count,_engine_offsets,_planePlayer] call AAE_fnc_Exhaust_Offsets;

    //Gear Factor
    if (!(isTouchingGround _plane) and (gear_fn)) then {
      [_planePlayer,_speed_Player] Spawn AAE_fnc_gearFactor;
    };

    //Turbulent Plane       //It's Flying
    if ((_speed_Player > 200) and !(isTouchingGround _planePlayer) and (turbulentP_fn) and (_turbulent_Distance_Found)) then {
      [_planePlayer,_Exhausts_count] Spawn AAE_fnc_turbulent;
    };

    //Turbulent World
    if (!(isTouchingGround _planePlayer) and (turbulentS_fn)) then {
      [_planePlayer,((getpos _planePlayer) # 2),_speed_Player] Spawn AAE_fnc_turbulentW;
    };

    //Taxing
    if ((isTouchingGround _planePlayer) and (taxing_fn)) then {
      [_planePlayer,_speed_Player] Spawn AAE_fnc_taxing;
    };
  };
  //GForces
  if !(isTouchingGround _planePlayer) then {
    [_planePlayer] Spawn AAE_fnc_gforces;
  };
};

//Sonic
if (sonicboom_fn) then {
  [_plane,_velocity,_speed] Spawn AAE_fnc_sonicboom;
};

//Vapor Trail
if ((_ASL_POS # 2 > (_plane getVariable "AAE_Vapor_toggle")) and (vapor_fn)) then {
  if !(_Vapor_Activated) then {
    [_plane,_Exhausts_count,_engine_offsets] Spawn AAE_fnc_vapor;
    _plane setVariable ["AAE_Vapor_Activated", true];
  };
} else {
  _plane setVariable ["AAE_Vapor_Activated", false];
};

if !(isNull _plane) then {
  //Camshake
  if ((isTouchingGround player) and (_speed >= 150) and !(player in _plane) and (camshake_fn)) then {
    _plane Spawn AAE_fnc_camshake;
  };

  //////////////////////////////////////Vars for ground effect//////////////////////////////////////////////
  //offset variables setup
  // Pitch
  _pitch = _pitchbank # 0;
  if (_pitch > 90) then {
    _pitch = 90;
  };
  if (_pitch < 0) then {
    _pitch = 0;
  };
  // Speed
  _ground_speed_var = (0.1 * _speed) + 1;
  if (_ground_speed_var > 2) then {
    _ground_speed_var = 2;
  };
  //Result
  _ground_result_var = 0.7 *_pitch * _ground_speed_var;
  _ground_result = groundP_sdr + _ground_result_var;
  if (Wingspan_fn) then {
    _ground_result = _Wingspan + _ground_result_var;
  };
  //https://www.desmos.com/calculator/f8zvnybbwk
  //////////////////////////////////////////////////////////////////////////////////////////////////////////

  //Ground
  if (!(isTouchingGround _plane) and ((_AGL_POS # 2) < _ground_result) and (ground_fn)) then {
    _type = _plane getVariable ["AAE_Ground_Type","Default"];
    [_plane,_engine1,_engine2,_AGL_POS,_ASL_POS,_ATL_POS,_ASLW_POS,_velocity,_speed,_type] Spawn AAE_fnc_ground;
    _plane setVariable ["AAE_Ground_Activated", true];
  } else {
    _plane setVariable ["AAE_Ground_Activated", false];
  };
} else {
  _plane setVariable ["AAE_Vapor_Activated", false];
  _plane setVariable ["AAE_Ground_Activated", false];
};
