params[["_plane",objNull],"_Exhausts_count","_engine_offsets"];

_engine_offsets params [["_engine1",[0,0,0]],["_engine2",[0,0,0]],["_engine3",[0,0,0]],["_engine4",[0,0,0]]];

_engine1 = _engine1 vectorAdd [0,-0.3,0];
_engine2 = _engine2 vectorAdd [0,-0.3,0];
_engine3 = _engine3 vectorAdd [0,-0.3,0];
_engine4 = _engine4 vectorAdd [0,-0.3,0];

//Burner Lights
_source = "AAE_AfterBurner_Reflector";
if (!(player in _plane) and (burner_flare_fn)) then {
  _source = "AAE_AfterBurner_Reflector_Flare";
};

//Direction
_dir = _plane getVariable ["AAE_Exhaust_Direction",[[0,0,0],[0,0,0]]];
_dir params [["_plane_direction0",[[0,0,0],[0,0,0]]],["_plane_direction1",[[0,0,0],[0,0,0]]],["_plane_direction2",[[0,0,0],[0,0,0]]],["_plane_direction3",[[0,0,0],[0,0,0]]]];

//Rotation Function
_Burner_Rotation = {
  _Burner_sources params ["_light_source00","_light_source01","_light_source02","_light_source03"];
  _dir params ["_plane_direction0","_plane_direction1","_plane_direction2","_plane_direction3"];

  switch (_Exhausts_count) do
  {
    case 1: {
      _light_source00 setVectorDirAndUp _plane_direction0;
    };
    case 2: {
      _light_source00 setVectorDirAndUp _plane_direction0;
      _light_source01 setVectorDirAndUp _plane_direction1;
    };
    case 3: {
      _light_source00 setVectorDirAndUp _plane_direction0;
      _light_source01 setVectorDirAndUp _plane_direction1;
      _light_source02 setVectorDirAndUp _plane_direction2;
    };
    case 4: {
      _light_source00 setVectorDirAndUp _plane_direction0;
      _light_source01 setVectorDirAndUp _plane_direction1;
      _light_source02 setVectorDirAndUp _plane_direction2;
      _light_source03 setVectorDirAndUp _plane_direction3;
    };
  };
};

//Create Object
switch (_Exhausts_count) do
{
  case 1: {
    _light_source00 = _source createVehicleLocal [0,0,0];
    //Rotation
    _light_source00 setVectorDirAndUp _plane_direction0;

    sleep 0.02;
    _light_source00 attachTo [_plane, _engine1];

    _plane setVariable ["AAE_Burner_Sources",[_light_source00]];
  };
  case 2: {
    _light_source00 = _source createVehicleLocal [0,0,0];
    _light_source01 = _source createVehicleLocal [0,0,0];
    //Rotation
    _light_source00 setVectorDirAndUp _plane_direction0;
    _light_source01 setVectorDirAndUp _plane_direction1;

    sleep 0.02;
    _light_source00 attachTo [_plane, _engine1];
    _light_source01 attachTo [_plane, _engine2];

    _plane setVariable ["AAE_Burner_Sources",[_light_source00,_light_source01]];
  };
  case 3: {
    _light_source00 = _source createVehicleLocal [0,0,0];
    _light_source01 = _source createVehicleLocal [0,0,0];
    _light_source02 = _source createVehicleLocal [0,0,0];
    //Rotation
    _light_source00 setVectorDirAndUp _plane_direction0;
    _light_source01 setVectorDirAndUp _plane_direction1;
    _light_source02 setVectorDirAndUp _plane_direction2;

    sleep 0.02;
    _light_source00 attachTo [_plane, _engine1];
    _light_source01 attachTo [_plane, _engine2];
    _light_source02 attachTo [_plane, _engine3];

    _plane setVariable ["AAE_Burner_Sources",[_light_source00,_light_source01,_light_source02]];
  };
  case 4: {
    _light_source00 = _source createVehicleLocal [0,0,0];
    _light_source01 = _source createVehicleLocal [0,0,0];
    _light_source02 = _source createVehicleLocal [0,0,0];
    _light_source03 = _source createVehicleLocal [0,0,0];
    //Rotation
    _light_source00 setVectorDirAndUp _plane_direction0;
    _light_source01 setVectorDirAndUp _plane_direction1;
    _light_source02 setVectorDirAndUp _plane_direction2;
    _light_source03 setVectorDirAndUp _plane_direction3;

    sleep 0.02;
    _light_source00 attachTo [_plane, _engine1];
    _light_source01 attachTo [_plane, _engine2];
    _light_source02 attachTo [_plane, _engine3];
    _light_source03 attachTo [_plane, _engine4];

    _plane setVariable ["AAE_Burner_Sources",[_light_source00,_light_source01,_light_source02,_light_source03]];
  };
};
_Burner_sources = _plane getVariable ["AAE_Burner_Sources",[]];
waituntil{
  if !(isNull _plane) then {
    _dir = _plane getVariable "AAE_Exhaust_Direction";
    call _Burner_Rotation;
  };
  //Condition
  !(_plane getVariable ["AAE_BurnerActived",false])
};

{deleteVehicle _x} foreach _Burner_sources;
_plane setVariable ["AAE_Burner_Sources",[]];
