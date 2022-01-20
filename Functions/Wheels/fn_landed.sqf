params ["_array1","_array2","_execution"];
/////////////////////////////////////////Arrays//////////////////////////////////////////////////////
_array1 params [
  "_plane",["_AV8",false],["_lifetime",10],["_size",[2,2]],
  ["_Hvar",0.84],["_HvarR",0.84],
  ["_gear0",[0,0,0]],["_gear1",[0,0,0]],["_gear2",[0,0,0]],["_gear3",[0,0,0]],
  ["_offset",0],["_OffsetF",0]
];
_array2 params ["_effect00","_effect01","_effect02",["_effect03",objNull]];
////////////////////////////////////////////////////////////////////////////////////////////////////////

_color = [[0.7,0.8,1,0.8],[0.7,0.8,1,0.5],[0.7,0.8,1,0.3],[0.7,0.8,1,0.15],[0.7,0.8,1,0.05],[0.7,0.8,1,0.01],[0.7,0.8,1,0.0]];
_velocity = velocity _plane;
_VelocityFX = [0.4*(_Velocity select 0),0.4*(_Velocity select 1), 0];

//Water Surface
if (surfaceIsWater (getpos _plane)) then {
  _Hvar = 24.8;
  _HvarR = 24.8;
  _gearoffsetF = 0;
  _gearoffsetRR = 0;
  _gearoffsetRL = 0;
};

if (((getpos _effect01) # 2) <= _HvarR) then {

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
};

waitUntil {
  (((getpos _effect00) # 2) <= _Hvar)
};

if (speed _plane > (190 + random 5)) then {

  _effect00 setParticleParams [
  ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 16, 0], "", "Billboard",
  0, _lifetime, [0, _offset, _OffsetF], _VelocityFX, 1.25, 1.2, 1, 0, _size,
  _color,
  [0], 0.5, 0, "", "", _effect00];
  _effect00 setDropInterval 0.01;
  _effect00 setParticleRandom [0.5, [0, 0, 0], [4.5,1,0.01], 0.5, 0.5, [0, 0, 0, 0], 0.1, 0.02, 90];
};
