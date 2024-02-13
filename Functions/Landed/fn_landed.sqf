params ["_plane","_vars","_effect","_behind","_tailhook_init"];

/////////////////////////////////////////Arrays//////////////////////////////////////////////////////
_vars params [
  "_lifetime","_size",
  "",
  "_offset","_OffsetF"
];
////////////////////////////////////////////////////////////////////////////////////////////////////////

_color = [[0.7,0.8,1,0.8],[0.7,0.8,1,0.5],[0.7,0.8,1,0.3],[0.7,0.8,1,0.15],[0.7,0.8,1,0.05],[0.7,0.8,1,0.01],[0.7,0.8,1,0.0]];
_pos_Var = [4.5,1,0.01];

if !(_behind) then {
  _size = [1,3,6,20];
  _pos_Var = [2,1,0.01];
};

_Dir = vectorDirVisual _plane;
_VelocityFX = [_Dir # 0,_Dir # 1, 0];

_effect setParticleParams [
  ["\A3\Data_F\ParticleEffects\Universal\Universal", 16, 12, 16, 0], "", "Billboard",
  0, _lifetime, [0, 0, -0.8 * ((getPos _effect) # 2)], _VelocityFX, 1.25, 1.2, 1, 0, _size,
  _color,
  [0], 0.5, 0, "", "", _effect
];
_effect setDropInterval 0.01;
_effect setParticleRandom [0.5, [0, 0, 0], _pos_Var, 0.5, 0.5, [0, 0, 0, 0], 0.1, 0.02, 90];

_Hook = _plane getVariable ["AAE_Hook_Sparks",false];

_Hook_Active = (
  (_plane animationPhase "tailhook" != _tailhook_init) &&
  !(_Hook) &&
  (_behind)
);

//TailHook Sparks
if (_Hook_Active) then {
  _plane spawn {
    params ["_plane"];
    _config = configOf _plane;
    _hook_effect = "#particlesource" createVehicleLocal [0,0,0];
    _hook_effect attachTo [_plane, [0,0,0], getText(_config >> "CarrierOpsCompatability" >> "ArrestHookMemoryPoint")];
    _hook_effect setParticleClass "AAE_TailHook_Landed_Spark";
    _plane setVariable ["AAE_Hook_Sparks",true];

    uisleep 0.25;

    deleteVehicle _hook_effect;
    _plane setVariable ["AAE_Hook_Sparks",false];
  };
};

//Delete Particles
uisleep 0.25;
deleteVehicle _effect;