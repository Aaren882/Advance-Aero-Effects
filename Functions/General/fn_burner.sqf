params[["_plane",objNull],"_Exhausts_count","_Exhausts_POS"];

//Sound
_AB_Sound = getText (configFile >> "CfgVehicles" >> typeOf _plane >> "AAE_AB_Sound");

if ((Cameraon isKindOf "Plane") and (cameraView == "INTERNAL") and (_plane == cameraOn)) then {
  ["AAE_PlaySound",[_AB_Sound]] call CBA_fnc_localEvent;
};

_offset = _plane getVariable ["AAE_Burner_Offset",[0,-0.3,0]];

//Array
_result_Light = [];
_result_Particle = [];

//Burner Lights
_source_Light = "AAE_AfterBurner_Reflector";
_source_Particle = "#particlesource";
if (!(player in _plane) and (burner_flare_fn)) then {
  _source_Light = "AAE_AfterBurner_Reflector_Flare";
};

//Direction
_dir = _plane getVariable ["AAE_Exhaust_Direction",[[0,0,0],[0,0,0]]];

//Create Object
for "_i" from 0 to (_Exhausts_count - 1) step 1 do {
  _velocity = velocity _plane;

  //light Sources
  _light_source = _source_Light createVehicleLocal [0,0,0];
  _light_source hideObject true;

  _Engine = _Exhausts_POS # _i;
  _Direction = _dir # _i;

  //Attach
  _Attach = [_plane, _offset, _Engine];
  _light_source attachTo _Attach;

  //Rotation
  _light_source setVectorDirAndUp _Direction;

  //Return
  _result_Light pushBack _light_source;
  _plane setVariable ["AAE_Burner_Sources",_result_Light];

  //Particle Effect
  if !(isTouchingGround _plane) then {
    _Particle_source = _source_Particle createVehicleLocal [0,0,0];
    _Particle_source attachTo _Attach;

    _Particle_source setParticleParams [
    ["\A3\data_f\ParticleEffects\Universal\Universal_02", 8, 0, 40, 1], "", "Billboard",
  	1, 3, [0,0,0], [(_velocity # 0) * 0.01, (_velocity # 1) * 0.01, (_velocity # 2) * 0.05], 1, 1.4, 1, 0.1, [1,2,4,6,8],
  	[[0.06,0.06,0.06,0.05],[0.06,0.06,0.06,0.1],[0.1,0.1,0.1,0.04],[0.2,0.2,0.2,0.01],[0.3,0.3,0.3,0.001]],
  	[2,1], 0.1, 0.25, "", "", _Particle_source];
    _Particle_source setDropInterval 0.005;
    _Particle_source setParticleRandom [1, [0.4, 0.4, 0.4], [1, 1, 1], 20, 0.3, [0, 0, 0, 0.04], 0.1, 0.05, 0];

    _result_Particle pushBack _Particle_source;
    _plane setVariable ["AAE_Exhaust_Particle_Sources",_result_Particle];
  };
};

_Burner_sources = _plane getVariable ["AAE_Burner_Sources",[]];
_Particle_sources = _plane getVariable ["AAE_Exhaust_Particle_Sources",[]];

//Unhide Lights
sleep 0.1;
{_x hideObject false} foreach _Burner_sources;

_Particle_sources spawn {
  sleep 0.3;
  {deleteVehicle _x} foreach _this;
};

waituntil{
  !(_plane getVariable ["AAE_BurnerActived",false])
};

//Delete Objects
{hideObject _x} foreach _Burner_sources;
sleep 0.02;

{deleteVehicle _x} foreach _Burner_sources;
_plane setVariable ["AAE_Burner_Sources",[]];
