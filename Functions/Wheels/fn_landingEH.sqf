params ["_plane"];

//Sounds
_config_int = getArray (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Touchdown_Int");
_config_ext = getArray (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_Touchdown_Ext");
_file_int = _config_int # 0;
_file_ext = _config_ext # 0;

_vol_int = _config_int # 1;
_vol_ext = _config_ext # 1;

_pitch_int = _config_int # 2;
_pitch_ext = _config_ext # 2;

_range_ext = _config_ext # 3;

if (speed _plane <= 100) exitWith {};

if (TDSound_fn) then {
  playSound3D [_file_int, _plane, true, getPosASL _plane, _vol_int, _pitch_int, 2000];
  playSound3D [_file_ext, _plane, false, getPosASL _plane, _vol_ext, _pitch_ext, _range_ext];
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Handler
execution = false;

//Gear POS
_vars = [_plane] call AAE_fnc_wheels;

_AV8 = _vars # 1;

//Gears
_gear0 = _vars # 6;
_gear1 = _vars # 7;
_gear2 = _vars # 8;

//POS
_PlanePOS = getpos _plane;

//Objects
_effect00 = "#particlesource" createVehicleLocal _PlanePOS;
_effect00 attachTo [_plane, _gear0];

_effect01 = "#particlesource" createVehicleLocal _PlanePOS;
_effect01 attachTo [_plane, _gear1];

_effect02 = "#particlesource" createVehicleLocal _PlanePOS;
_effect02 attachTo [_plane, _gear2];

_effect03 = objNull;

if (_AV8) then {
  _gear3 = _vars # 9;
  _effect03 = "#particlesource" createVehicleLocal _PlanePOS;
  _effect03 attachTo [_plane, _gear3];
};

//Handler
[_plane] spawn AAE_fnc_execution;

AAE_Langing_handler = addMissionEventHandler ["EachFrame", {
  if !(isGamePaused) then {
    //Get Variables
    _Setting_vars = _thisArgs # 0;
    _objects_vars = _thisArgs # 1;

    _vars = _Setting_vars # 0;
    _plane = _vars # 0;

    //Vars
    _Landing_Activated = _plane getVariable ["AAE_Landing_Activated", false];

    if (execution and landingVEF_fn) then {
      if (!_Landing_Activated) then {
        [_vars,_objects_vars] spawn AAE_fnc_landed;
        _plane setVariable ["AAE_Landing_Activated", true];
      };
    } else {
      _plane setVariable ["AAE_Landing_Activated", false];
    };
  };
},[
    [_vars],
    [_effect00,_effect01,_effect02,_effect03]
  ]
];
