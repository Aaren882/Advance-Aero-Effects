params ["_plane","_velocity","_speed"];

_velocityFX = [(0.8*(_velocity select 0)),(0.8*(_velocity select 1)),(0.8*(_velocity select 2))];
_color = [[1, 1, 1, 0],[1, 1, 1, 0.75]];

//Vars
_Sonic_MC = _plane getVariable ["AAE_SonicBoom_Main_Activated", false];
_Sonic_SC = _plane getVariable ["AAE_SonicBoom_Small_Activated", false];

////FAKE Particle Sources
_source00 = _plane getVariable ["AAE_SonicBoom_Small_Particle",objNull];
_source01 = _plane getVariable ["AAE_SonicBoom_Main_Particle",objNull];

/* _effect = {
  params ["_plane","_velocityFX","_Statement","_Sonic_MC","_Sonic_SC"];
  _color = [[1, 1, 1, 0],[1, 1, 1, 0.75]];
  if (_Statement == 0) then {
    source00_Sonic = "#particlesource" createVehicleLocal [0,0,0];
    source00_Sonic attachto [_plane,[0,0,0]];

    source00_Sonic setParticleParams ["\A3\data_f\cl_basic", "", "Billboard",
     1, 0.05,[0,5,-1], _velocityFX, 0, 0.0052, 0, 0,[0,5],
    _color,
    [0,1], 0.003,15, "", "", _plane];
    source00_Sonic setDropInterval 0.001;
    Sonic_Paricles pushback source00_Sonic;
    hintsilent str [source00_Sonic,count Sonic_Paricles,time];
  };
  if (_Statement == 1) then {
    //All
    source01_Sonic = "#particlesource" createVehicleLocal [0,0,0];
    source01_Sonic attachto [_plane,[0,0,0]];

    source01_Sonic setParticleParams ["\A3\data_f\cl_basic", "", "Billboard",
     1, 0.08,[0,-5,-1], _velocityFX, 0, 0.0052, 0, 0,[0,20],
    _color,
    [0,1], 0.003,50, "", "", _plane];
    source01_Sonic setDropInterval 0.001;
    Sonic_Paricles pushback source01_Sonic;
  };
  waitUntil {
    !_Sonic_SC and !_Sonic_MC
  };
  if (count Sonic_Paricles > 0) then {
    {deleteVehicle _x;} foreach Sonic_Paricles;
    Sonic_Paricles = [];
  };
}; */

_sonicboom_00 = {
  params ["_plane","_velocityFX","_color"];
  _source00 = "#particlesource" createVehicleLocal [0,0,0];
  _plane setVariable ["AAE_SonicBoom_Small_Particle",_source00];
  _source00 attachto [_plane,[0,0,0]];

  _source00 setParticleParams ["\A3\data_f\cl_basic", "", "Billboard",
   1, 0.08,[0,0,-1], _velocityFX, 0, 0.0052, 0, 0,[5],
  _color,
  [0,1], 0.003,50, "", "", _plane];
  _source00 setDropInterval 0.001;
  waitUntil {
    !(_plane getVariable ["AAE_SonicBoom_Small_Activated", false])
  };
  _plane setVariable ["AAE_SonicBoom_Small_Particle",objNull];
  deleteVehicle _source00;
};

_sonicboom_01 = {
  params ["_plane","_velocityFX","_color"];
  _source01 = "#particlesource" createVehicleLocal [0,0,0];
  _plane setVariable ["AAE_SonicBoom_Main_Particle",_source01];
  _source01 attachto [_plane,[0,0,0]];

  _source01 setParticleParams ["\A3\data_f\cl_basic", "", "Billboard",
   1, 0.08,[0,-5,-1], _velocityFX, 0, 0.0052, 0, 0,[20],
  _color,
  [0,1], 0.003,50, "", "", _plane];
  _source01 setDropInterval 0.001;
  waitUntil {
    !(_plane getVariable ["AAE_SonicBoom_Main_Activated", false])
  };
  _plane setVariable ["AAE_SonicBoom_Main_Particle",objNull];
  deleteVehicle _source01;
};

if !(isNull _plane) then {
  if ((_speed >= AAE_sonicboom_speed_01) and (_speed <= AAE_sonicboom_speed_02)) then {
    if !(_Sonic_SC) then {
      [_plane,_velocityFX,_color] Spawn _sonicboom_00;
      _plane setVariable ["AAE_SonicBoom_Small_Activated", true];
    };
  } else {
    _plane setVariable ["AAE_SonicBoom_Small_Activated", false];
  };

  if ((_speed > AAE_sonicboom_speed_02) and (_speed <= AAE_sonicboom_speed_03)) then {
    if (!_Sonic_MC) then {
      [_plane,_velocityFX,_color] Spawn _sonicboom_01;
      _plane setVariable ["AAE_SonicBoom_Main_Activated", true];
    };
  } else {
    _plane setVariable ["AAE_SonicBoom_Main_Activated", false];
  };
} else {
  _plane setVariable ["AAE_SonicBoom_Small_Activated", false];
  _plane setVariable ["AAE_SonicBoom_Main_Activated", false];
};
