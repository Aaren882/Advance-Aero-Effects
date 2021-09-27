params ["_plane","_velocity"];

_velocityFX = [(0.8*(_velocity select 0)),(0.8*(_velocity select 1)),(0.8*(_velocity select 2))];
_color = [[1, 1, 1, 0],[1, 1, 1, 0.75]];

_source00 = "#particlesource" createVehicleLocal [0,0,0];
_source00 attachto [_plane,[0,0,0]];
_source00 setParticleParams ["\A3\data_f\cl_basic", "", "Billboard",
 1, 0.08,[0,-5,-1], _velocityFX, 0, 0.0052, 0, 0,[0,20],
_color,
[0,1], 0.003,50, "", "", _plane];
_source00 setDropInterval 0.001;

waitUntil {!(_plane getVariable ["SonicBoom_Main_Activated", false])};

deleteVehicle _source00;
