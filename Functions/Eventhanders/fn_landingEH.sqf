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

if !(landingVEF_fn) exitWith {};
//Gear POS
_vars = _plane getvariable "AAE_Wheels_Selections";

_vars params [
  "_plane",["_AV8",false],["_lifetime",10],["_vol",[2,2]],
  ["_Hvar",0.84],["_HvarR",0.84],
  ["_gear0",[0,0,0]],["_gear1",[0,0,0]],["_gear2",[0,0,0]],["_gear3",[0,0,0]],
  ["_offset",0],["_OffsetF",0]
];

_POS = [0,0,0];

//Particle Sources
_effect00 = "#particlesource" createVehicleLocal _POS;
_effect00 attachTo [_plane, _gear0];

_effect01 = "#particlesource" createVehicleLocal _POS;
_effect01 attachTo [_plane, _gear1];

_effect02 = "#particlesource" createVehicleLocal _POS;
_effect02 attachTo [_plane, _gear2];

_effect03 = objNull;

if (_AV8) then {
  _effect03 = "#particlesource" createVehicleLocal _POS;
  _effect03 attachTo [_plane, _gear3];
};

_plane setVariable ["AAE_Landed_Sources",[_effect00,_effect01,_effect02,_effect03]];
_plane setvariable ["AAE_Landed_Counter",true];

AAE_Langed_handler = addMissionEventHandler ["EachFrame", {
  if !(isGamePaused) then {
    //Get Variables
    _plane = _thisArgs # 0;
    _vars = _thisArgs # 1;
    _objects_vars = _thisArgs # 2;

    _plane setVariable ["AAE_Landed_Handler", AAE_Langed_handler];

    //Handler
    _execution = _plane getvariable "AAE_Landed_Counter";

    //Vars
    _Landing_Activated = _plane getVariable ["AAE_Landing_Activated", false];

    if (_execution and landingVEF_fn) then {
      if !(_Landing_Activated) then {
        [_vars,_objects_vars,_execution] Spawn AAE_fnc_landed;
        _plane setVariable ["AAE_Landing_Activated", true];
      };
    } else {
      _plane setVariable ["AAE_Landing_Activated", false];
    };
  };
},[
    _plane,
    _vars,
    (_plane getVariable "AAE_Landed_Sources")
  ]
];
//Cut Off Handler
[_plane] Spawn AAE_fnc_execution;
