params ["_array1","_effect","_Particle_Sources","_behind"];

/////////////////////////////////////////Arrays//////////////////////////////////////////////////////
_array1 params [
  "_plane","_AV8","_lifetime","_size",
  "_Hvar","_HvarR",
  "_GearsArray",
  "_offset","_OffsetF"
];
////////////////////////////////////////////////////////////////////////////////////////////////////////

_config = configFile >> "CfgVehicles" >> typeOf _plane;
_speed_limit = (getNumber (_config >> "landingSpeed") - (20 +  random 10));
if (_speed_limit > 180) then {_speed_limit = 180};

_color = [[0.7,0.8,1,0.8],[0.7,0.8,1,0.5],[0.7,0.8,1,0.3],[0.7,0.8,1,0.15],[0.7,0.8,1,0.05],[0.7,0.8,1,0.01],[0.7,0.8,1,0.0]];
_pos_Var = [4.5,1,0.01];

if !(_behind) then {
  _size = [1,3,6,20];
  _pos_Var = [2,1,0.01];
};

_tailhook_init = getNumber(_config >> "AnimationSources" >> "TailHook" >> "initPhase");

//Water Surface
if (surfaceIsWater (getpos _plane)) then {
  _Hvar = 24.8;
  _HvarR = 24.8;
  _gearoffsetF = 0;
  _gearoffsetRR = 0;
  _gearoffsetRL = 0;
};

_velocity = velocity _plane;
_VelocityFX = [0.4*(_Velocity select 0),0.4*(_Velocity select 1), 0];

waitUntil {
  (((getpos _effect) # 2) <= _Hvar)
};

if (speed _plane < _speed_limit) exitWith {};

_effect setParticleParams [
["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 16, 0], "", "Billboard",
0, _lifetime, [0, 0, 0], _VelocityFX, 1.25, 1.2, 1, 0, _size,
_color,
[0], 0.5, 0, "", "", _effect];
_effect setDropInterval 0.01;
_effect setParticleRandom [0.5, [0, 0, 0], _pos_Var, 0.5, 0.5, [0, 0, 0, 0], 0.1, 0.02, 90];

_Hook = _plane getVariable ["AAE_Hook_Sparks",false];
_Hook_Active = (
  (_plane animationPhase "tailhook" != _tailhook_init) and
  !(_Hook) and
  (_behind)
);

//TailHook Sparks
if (_Hook_Active) then {
  _hook_effect = "#particlesource" createVehicleLocal [0,0,0];
  _hook_effect attachTo [_plane, [0,0,0],(getText(_config >> "CarrierOpsCompatability" >> "ArrestHookMemoryPoint"))];
  _hook_effect setParticleClass "AAE_TailHook_Landed_Spark";
  _plane setVariable ["AAE_Hook_Sparks",true];

  sleep 0.25;

  deleteVehicle _hook_effect;
  _plane setVariable ["AAE_Hook_Sparks",false];
};


/* if (((getpos _effect01) # 2) <= _HvarR) then {

  _effect01 setParticleParams [
  ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 16, 0], "", "Billboard",
  0, _lifetime, [0, 0, 0], _VelocityFX, 1.25, 1.2, 1, 0, _size,
  _color,
  [0], 0.5, 0, "", "", _effect01];
  _effect01 setDropInterval 0.01;
  _effect01 setParticleRandom [0.5, [0, 0, 0], [4.5,1,0.01], 0.5, 0.5, [0, 0, 0, 0], 0.1, 0.02, 90];
};
if (((getpos _effect02) # 2) <= _HvarR) then {

  _effect02 setParticleParams [
  ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 16, 0], "", "Billboard",
  0, _lifetime, [0, 0, 0], _VelocityFX, 1.25, 1.2, 1, 0.3, _size,
  _color,
  [0], 0.5, 0, "", "", _effect02];
  _effect02 setDropInterval 0.01;
  _effect02 setParticleRandom [0.5, [0, 0, 0], [4.5,1,0.01], 0.5, 0.5, [0, 0, 0, 0], 0.1, 0.02, 90];

  if (_AV8) then {

    _effect03 setParticleParams [
    ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 16, 0], "", "Billboard",
    0, _lifetime, [0, _offset, 0], _VelocityFX, 1.25, 1.2, 1, 0, _size,
    _color,
    [0], 0.5, 0, "", "", _effect03];
    _effect03 setDropInterval 0.01;
    _effect03 setParticleRandom [0.5, [0, 0, 0], [4.5,1,0.01], 0.5, 0.5, [0, 0, 0, 0], 0.1, 0.02, 90];
  };
  //TailHook Sparks
  if (_plane animationPhase "tailhook" != _tailhook_init) then {
    _hook_effect = "#particlesource" createVehicleLocal [0,0,0];
    _hook_effect attachTo [_plane, [0,0,0],(getText(configFile >> "CfgVehicles" >> typeOf _plane >> "CarrierOpsCompatability" >> "ArrestHookMemoryPoint"))];
    _array2 pushback _hook_effect;
    _hook_effect setParticleClass "AAE_TailHook_Landed_Spark";
  };
};

waitUntil {
  (((getpos _effect00) # 2) <= _Hvar)
};

if (speed _plane > (180 + random 30)) then {

  _effect00 setParticleParams [
  ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 16, 0], "", "Billboard",
  0, _lifetime, [0, _offset, _OffsetF], _VelocityFX, 1.25, 1.2, 1, 0, _size,
  _color,
  [0], 0.5, 0, "", "", _effect00];
  _effect00 setDropInterval 0.01;
  _effect00 setParticleRandom [0.5, [0, 0, 0], [4.5,1,0.01], 0.5, 0.5, [0, 0, 0, 0], 0.1, 0.02, 90];
}; */
