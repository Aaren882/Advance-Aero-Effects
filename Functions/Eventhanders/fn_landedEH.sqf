params ["_plane"];

if (_plane getVariable ["AAE_Landed_CoolDown",false] and (landingVEF_fn)) exitWith {};

_Wheels_Selections = _plane getVariable ["AAE_Wheels_Selections",[]];

//Wheels
if (_Wheels_Selections isEqualTo []) then {
  _wheels = call AAE_fnc_wheels;
  _plane setVariable ["AAE_Wheels_Selections",_wheels];
};

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

_GearsArray = _vars # 6;

_POS = [0,0,0];
_Particle_Sources = [];

for "_i" from 0 to (count _GearsArray) - 1 do {
  //Particle Sources
  _gear = _GearsArray # _i;
  _effect = "#particlesource" createVehicleLocal _POS;
  _effect attachTo [_plane, _gear];

  _behind = false;
  if (_gear # 1 < 0) then {
    _behind = true;
  };

  _Particle_Sources pushBack _effect;

  //Spawn Effects
  _Script = [_vars,_effect,_Particle_Sources,_behind] Spawn AAE_fnc_landed;

  //Delete Particles
  [_effect,_Particle_Sources,_plane,_Script] spawn {
    params ["_effect","_Particle_Sources","_plane","_Script"];
    _index = _Particle_Sources find _effect;

    waitUntil {
      scriptDone _Script
    };
    sleep 0.25;
    _Particle_Sources deleteAt _index;
    deleteVehicle _effect;
  };
};

_plane setvariable ["AAE_Landed_Counter",true];

//Cut Off Handler
_plane Spawn AAE_fnc_CoolDown;
