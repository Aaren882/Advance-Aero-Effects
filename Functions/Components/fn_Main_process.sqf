_plane = _x;
_planePlayer = cameraOn;

_plane setVariable ["AAE_Actived", true];
_isServer = (player getVariable ["AAE_EachFrame_EH", -1]) != -1;

//Engine
_Engine_Offsets = _plane getVariable "AAE_veh_Engine_Offset";
_Exhausts_count = _plane getVariable "AAE_Exhausts_Count";
_Exhausts_POS = _plane getVariable "AAE_Exhaust_POS";

//Wingspan
_Wingspan = _plane getVariable "AAE_Wingspan";

//POS
_AGL_POS = getPos _plane;
_ASL_POS = getPosASL _plane;
_ATL_POS = getPosATL _plane;
_ASLW_POS = getPosASLW _plane;

//Speeds
_velocity = velocity _plane;
_speed = speed _plane;
_speed_Player = speed _planePlayer;

//Temperature
_air_Temp = ambientTemperature # 0;

//Vapor
if (vapor_sim_fn) then {
  Vapor_sim = (_air_Temp - (((_ASL_POS # 2) / 100) * 0.98)) <= -20;
};

//-Sonic Settings
if (sonicboom_tmp_fn) then {
  AAE_SpeedSet = (331+(0.6*_air_Temp))*3.6; // 1195 as Default
  AAE_sonicboom_speed_01 = AAE_SpeedSet - 20;
  AAE_sonicboom_speed_02 = AAE_SpeedSet - 10;
  AAE_sonicboom_speed_03 = AAE_SpeedSet + 10;
};

//Vapor
_Vapor_Activated = _plane getVariable ["AAE_Vapor_Activated", false];

//Ground
_Ground_Activated = _plane getVariable ["AAE_Ground_Activated", false];
_pitchBank = _plane call BIS_fnc_getPitchBank;

//Burner
_Burner_Activated = _plane getVariable ["AAE_BurnerActived",false];

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
    if (!(isTouchingGround _plane) && (gear_fn)) then {
      [_planePlayer,_speed_Player] call AAE_fnc_gearFactor;
    };

    //It's Flying
    if !(isTouchingGround _planePlayer) then {
      //Turbulence Plane
      if ((_speed_Player > 200) && (turbulentP_fn) && (_turbulent_Distance_Found)) then {
        [_planePlayer,_Exhausts_count] call AAE_fnc_turbulence;
      };

      //Turbulence World
      if (turbulentS_fn) then {
        [_planePlayer,((getpos _planePlayer) # 2),_speed_Player] call AAE_fnc_turbulenceW;
      };
    };

    //Taxing
    if ((isTouchingGround _planePlayer) && (taxiing_fn)) then {
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


if (isEngineOn _plane) then {
  //Camshake
  if ((isTouchingGround player) && (_speed >= 150) && !(player in _plane) && (camshake_fn)) then {
    _plane call AAE_fnc_camshake;
  };

  //Sonic
  if (sonicboom_fn) then {
    call AAE_fnc_sonicboom;
  };

  //Vapor Trail
  if ((_ASL_POS # 2 > (_plane getVariable "AAE_Vapor_toggle")) && (Vapor_sim) && (vapor_fn)) then {
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
  if (!(isTouchingGround _plane) && ((_AGL_POS # 2) < _ground_result) && (ground_fn) && !("Concrete" in (surfaceType (getPos _plane)))) then {
    if !(_Ground_Activated) then {
      _plane call AAE_fnc_ground;
      _plane setVariable ["AAE_Ground_Activated", true];
    };
  } else {
    _plane setVariable ["AAE_Ground_Activated", false];
  };

  //Have Burner
  _have_AB = _plane getVariable ["AAE_Have_AB",false];

  //Burner Source
  _plane_thrust = if (_plane getVariable ["AAE_Have_AB_Source",false]) then {
    (
      _plane animationSourcePhase (_plane getVariable "AAE_AB_Source") > 0.9 or
      _plane animationphase (_plane getVariable "AAE_AB_Source") > 0.9
    );
  } else {
    (_plane getSoundController "thrust") > 0.9;
  };

  _Burner_sources = _plane getVariable ["AAE_Burner_Sources",[]];

  //After Burner      #-Else included
  if ((burner_fn) && (_plane_thrust) && (_have_AB)) then {
    if !(_Burner_Activated) then {
      [_plane,_Exhausts_count,_Exhausts_POS,_isServer] spawn AAE_fnc_burner;
      _plane setVariable ["AAE_BurnerActived",true];
    };
  } else {
    _plane setVariable ["AAE_BurnerActived",false];
  };
} else {
  _plane setVariable ["AAE_Ground_Activated", false];
};
