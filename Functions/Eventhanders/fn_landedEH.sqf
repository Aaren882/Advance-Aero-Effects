params ["_plane"];

if ((_plane getVariable ["AAE_Landed_CoolDown",false]) && !(landingVEF_fn)) exitWith {};

//Sounds
_config = configOf _plane;
_config_int = getText (_config >> "AAE_Touchdown_Int");
_config_ext = getArray (_config >> "AAE_Touchdown_Ext");
_speed_limit = (getNumber (_config >> "landingSpeed") - (20 + random 10)) min 180;
_tailhook_init = getNumber(_config >> "AnimationSources" >> "TailHook" >> "initPhase");

_config_ext params ["_file_ext","_vol_ext","_pitch_ext","_range_ext"];

_speed = speed _plane;
if (_speed <= 100) exitWith {};

if (TDSound_fn) then {
  if (cameraView == "INTERNAL") then {
    playSound _config_int;
  } else {
    playSound3D [_file_ext, _plane, false, getPosASL _plane, _vol_ext, _pitch_ext, _range_ext];
  };
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if !(landingVEF_fn) exitWith {};

//Gear POS
_vars = (_plane call AAE_fnc_InitEH) get "AAE_Wheels_Selections";
_GearsArray = _vars # 2;
_average = 0;

_WheelH = _GearsArray apply {
  private _H = (_plane modelToWorldVisualWorld _x) # 2;
  _average = _average + _H;
  _H
};
_average = _average / count _GearsArray;

{
  private ["_H","_gear","_effect","_behind"];
  _H = _WheelH # _forEachIndex;

  //- Skip if -Speed lower than Limit- OR -Above average-
  if (_speed < _speed_limit || _H > _average) then {continue};
  _gear = _x;

  //Particle Sources
  _effect = "#particlesource" createVehicleLocal [0,0,0];
  _effect attachTo [_plane, _gear];
  
  _behind = false;
  if (_gear # 1 < 0) then {
    _behind = true;
  };

  //Spawn Effects
  [_plane,_vars,_effect,_behind,_tailhook_init] Spawn AAE_fnc_landed;
} forEach _GearsArray;

_plane setvariable ["AAE_Landed_Counter",true];

//Cut Off Handler
_plane Spawn AAE_fnc_CoolDown;
