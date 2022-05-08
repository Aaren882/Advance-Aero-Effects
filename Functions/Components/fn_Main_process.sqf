//Vapor
_Vapor_Activated = _plane getVariable ["AAE_Vapor_Activated", false];

//Ground
_Ground_Activated = _plane getVariable ["AAE_Ground_Activated", false];
_pitchBank = _plane call BIS_fnc_getPitchBank;

//Burner
_Burner_Activated = _plane getVariable ["AAE_BurnerActived",false];

/*/////////////////////////////////////////////////////////////////////////
//Player only
if (_planePlayer isKindOf "plane") then {
  _turbulent_Distance_Found = _planePlayer getVariable ["AAE_Turbulent_Source_Distance_Found",false];

  //GForces
  if !(isTouchingGround _planePlayer) then {
    _planePlayer call AAE_fnc_gforces;
  };

  if (cameraView == "internal") then {

    //Turbulence Settings
    [_plane,_Exhausts_count,_engine_offsets,_planePlayer] call AAE_fnc_Exhaust_Offsets;

    //Gear Factor
    if (!(isTouchingGround _plane) and (gear_fn)) then {
      [_planePlayer,_speed_Player] call AAE_fnc_gearFactor;
    };

    //It's Flying
    if !(isTouchingGround _planePlayer) then {
      //Turbulence Plane
      if ((_speed_Player > 200) and (turbulentP_fn) and (_turbulent_Distance_Found)) then {
        [_planePlayer,_Exhausts_count] Spawn AAE_fnc_turbulence;
      };

      //Turbulence World
      if (turbulentS_fn) then {
        [_planePlayer,((getpos _planePlayer) # 2),_speed_Player] call AAE_fnc_turbulenceW;
      };
    };

    //Taxing
    if ((isTouchingGround _planePlayer) and (taxiing_fn)) then {
      [_planePlayer,_speed_Player] call AAE_fnc_taxiing;
    };

    if (Gforces_Vol_fn) then {
      //Volume Changed
      call AAE_fnc_VolumeChangedEH;

      //Volume fade out
      call AAE_fnc_ChangeVolume;
    };
  };
};
 */

//Player only
if (player in _plane) then {
  _turbulent_Distance_Found = _planePlayer getVariable ["AAE_Turbulent_Source_Distance_Found",false];

  //GForces
  if !(isTouchingGround _planePlayer) then {
    _planePlayer call AAE_fnc_gforces;
  };

  if (cameraView == "internal") then {

    //Turbulence Settings
    [_plane,_Exhausts_count,_engine_offsets,_planePlayer] call AAE_fnc_Exhaust_Offsets;

    //Gear Factor
    if (!(isTouchingGround _plane) and (gear_fn)) then {
      [_planePlayer,_speed_Player] call AAE_fnc_gearFactor;
    };

    //It's Flying
    if !(isTouchingGround _planePlayer) then {
      //Turbulence Plane
      if ((_speed_Player > 200) and (turbulentP_fn) and (_turbulent_Distance_Found)) then {
        [_planePlayer,_Exhausts_count] call AAE_fnc_turbulence;
      };

      //Turbulence World
      if (turbulentS_fn) then {
        [_planePlayer,((getpos _planePlayer) # 2),_speed_Player] call AAE_fnc_turbulenceW;
      };
    };

    //Taxing
    if ((isTouchingGround _planePlayer) and (taxiing_fn)) then {
      [_planePlayer,_speed_Player] call AAE_fnc_taxiing;
    };

    if (Gforces_Vol_fn) then {
      //Volume Changed
      call AAE_fnc_VolumeChangedEH;

      //Volume fade out
      call AAE_fnc_ChangeVolume;
    };
  };
};
if !(isNull _plane) then {
  //Camshake
  if ((isTouchingGround player) and (_speed >= 150) and !(player in _plane) and (camshake_fn)) then {
    _plane call AAE_fnc_camshake;
  };

  //Sonic
  if (sonicboom_fn) then {
    call AAE_fnc_sonicboom;
  };

  //Vapor Trail
  if ((_ASL_POS # 2 > (_plane getVariable "AAE_Vapor_toggle")) and (Vapor_sim) and (vapor_fn)) then {
    if !(_Vapor_Activated) then {
      [_plane,_Exhausts_count,_Exhausts_POS] Spawn AAE_fnc_vapor;
      _plane setVariable ["AAE_Vapor_Activated", true];
    };
  } else {
    _plane setVariable ["AAE_Vapor_Activated", false];
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
  _ground_result_var = 0.5 * _pitch * _ground_speed_var;
  _ground_result = groundP_sdr + _ground_result_var;
  if (Wingspan_fn) then {
    _ground_result = _Wingspan + _ground_result_var;
  };
  //https://www.desmos.com/calculator/f8zvnybbwk
  //////////////////////////////////////////////////////////////////////////////////////////////////////////

  //Ground
  if (!(isTouchingGround _plane) and ((_AGL_POS # 2) < _ground_result) and (ground_fn) and !("Concrete" in (surfaceType (getPos _plane)))) then {
    if !(_Ground_Activated) then {
      _plane Spawn AAE_fnc_ground;
    };
    _plane setVariable ["AAE_Ground_Activated", true];
  } else {
    _plane setVariable ["AAE_Ground_Activated", false];
  };

  //After Burner      //Else included
  if ((burner_fn) and (_plane_thrust) and (_have_AB)) then {
    if !(_Burner_Activated) then {
      [_plane,_Exhausts_count,_Exhausts_POS] Spawn AAE_fnc_burner;
      _plane setVariable ["AAE_BurnerActived",true];
    };
  } else {
    _plane setVariable ["AAE_BurnerActived",false];
  };
} else {
  _plane setVariable ["AAE_Vapor_Activated", false];
  _plane setVariable ["AAE_Ground_Activated", false];
  _plane setVariable ["AAE_BurnerActived",false];
};
