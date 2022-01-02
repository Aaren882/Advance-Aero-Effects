//Arrays
_array1 = _this # 0;
_array2 = _this # 1;

//Array1
_plane = _array1 # 0;
_AV8 = _array1 # 1;
_lifetime = _array1 # 2;
_vol = _array1 # 3;
_Hvar = _array1 # 4;
_HvarR = _array1 # 5;
_gear0 = _array1 # 6;
_gear1 = _array1 # 7;
_gear2 = _array1 # 8;
_gear3 = _array1 # 9;
_offset = _array1 # 10;

//Array2
_effect00 = _array2 # 0;
_effect01 = _array2 # 1;
_effect02 = _array2 # 2;
_effect03 = _array2 # 3;

_color = [[0.7,0.8,1,0.0],[0.7,0.8,1,0.01],[0.7,0.8,1,0.05],[0.7,0.8,1,0.01],[0.7,0.8,1,0.0]];
_velocity = velocity _plane;
_VelocityFX = [0.8*(_Velocity select 0),0.8*(_Velocity select 1), 0];

_OffsetF = 0;
if (_plane isKindOf "Plane_Fighter_01_Base_F") then {
  _OffsetF = -1;
};

if (((getpos _effect01) # 2) <= _HvarR) then {

  _effect01 setParticleParams [
  ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 16, 0], "", "Billboard",
  0, _lifetime, [0, 0, 0], _VelocityFX, 0.5, 1.25, 1, 0.01, _vol,
  _color,
  [0], 0.5, 0, "", "", _effect01];
  _effect01 setDropInterval 0.003;
  _effect01 setParticleRandom [0.2, [0.2, 0.2, 0], [1,1,0.15], 0.5, 0.5, [0, 0, 0, 0], 0.1, 0.02, 90];
};
if (((getpos _effect02) # 2) <= _HvarR) then {

  _effect02 setParticleParams [
  ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 16, 0], "", "Billboard",
  0, _lifetime, [0, 0, 0], _VelocityFX, 0.5, 1.25, 1, 0.01, _vol,
  _color,
  [0], 0.5, 0, "", "", _effect02];
  _effect02 setDropInterval 0.003;
  _effect02 setParticleRandom [0.2, [0.2, 0.2, 0], [1,1,0.15], 0.5, 0.5, [0, 0, 0, 0], 0.1, 0.02, 90];
  if (_AV8) then {

    _effect03 setParticleParams [
    ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 16, 0], "", "Billboard",
    0, _lifetime, [0, _offset, 0], _VelocityFX, 0.5, 1.25, 1, 0.01, _vol,
    _color,
    [0], 0.5, 0, "", "", _effect03];
    _effect03 setDropInterval 0.003;
    _effect03 setParticleRandom [0.2, [0.2, 0.2, 0], [1,1,0.15], 0.5, 0.5, [0, 0, 0, 0], 0.1, 0.02, 90];
  };
};
if (((getpos _effect00) # 2) <= _Hvar) then {

  _effect00 setParticleParams [
  ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 16, 0], "", "Billboard",
  0, _lifetime, [0, _offset, _OffsetF], _VelocityFX, 0.5, 1.25, 1, 0.01, _vol,
  _color,
  [0], 0.5, 0, "", "", _effect00];
  _effect00 setDropInterval 0.003;
  _effect00 setParticleRandom [0.2, [0.2, 0.2, 0], [1,1,0.15], 0.5, 0.5, [0, 0, 0, 0], 0.1, 0.02, 90];
};
waitUntil {!execution};

deleteVehicle _effect00;
deleteVehicle _effect01;
deleteVehicle _effect02;
if (_AV8) then {
  deleteVehicle _effect03;
};
//End loop
removeMissionEventHandler ["EachFrame", AAE_Langing_handler];
