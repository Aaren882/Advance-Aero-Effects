params ["_plane","_Exhausts_count","_engine_offsets","_planePlayer"];

_engine_offsets params [["_engine1",[0,0,0]],["_engine2",[0,0,0]],["_engine3",[0,0,0]],["_engine4",[0,0,0]]];

_Result = switch (_Exhausts_count) do
{
  //Turbulent Effect
  case 1: {
    _source00 = _plane modelToWorldVisual [(_engine1 # 0), (_engine1 # 1)+(-10-turbulent_sdr),(_engine1 # 2)];

    _dis0 = _planePlayer distance _source00;

    [
      [_source00],
      [_dis0]
    ]
  };
  case 2: {
    _source00 = _plane modelToWorldVisual [(_engine1 # 0), (_engine1 # 1)+(-10-turbulent_sdr),(_engine1 # 2)];
    _source01 = _plane modelToWorldVisual [(_engine2 # 0), (_engine2 # 1)+(-10-turbulent_sdr),(_engine2 # 2)];

    _dis0 = _planePlayer distance _source00;
    _dis1 = _planePlayer distance _source01;

    [
      [_source00,_source01],
      [_dis0,_dis1]
    ]
  };
  case 3: {
    _source00 = _plane modelToWorldVisual [(_engine1 # 0), (_engine1 # 1)+(-10-turbulent_sdr),(_engine1 # 2)];
    _source01 = _plane modelToWorldVisual [(_engine2 # 0), (_engine2 # 1)+(-10-turbulent_sdr),(_engine2 # 2)];
    _source02 = _plane modelToWorldVisual [(_engine3 # 0), (_engine3 # 1)+(-10-turbulent_sdr),(_engine3 # 2)];

    _dis0 = _planePlayer distance _source00;
    _dis1 = _planePlayer distance _source01;
    _dis2 = _planePlayer distance _source02;

    [
      [_source00,_source01,_source02],
      [_dis0,_dis1,_dis2]
    ]
  };
  case 4: {
    _source00 = _plane modelToWorldVisual [(_engine1 # 0), (_engine1 # 1)+(-10-turbulent_sdr),(_engine1 # 2)];
    _source01 = _plane modelToWorldVisual [(_engine2 # 0), (_engine2 # 1)+(-10-turbulent_sdr),(_engine2 # 2)];
    _source02 = _plane modelToWorldVisual [(_engine3 # 0), (_engine3 # 1)+(-10-turbulent_sdr),(_engine3 # 2)];
    _source03 = _plane modelToWorldVisual [(_engine4 # 0), (_engine4 # 1)+(-10-turbulent_sdr),(_engine4 # 2)];
    _plane setVariable ["AAE_Turbulent_Sources",[_source00,_source01,_source02,_source03]];

    _dis0 = _planePlayer distance _source00;
    _dis1 = _planePlayer distance _source01;
    _dis2 = _planePlayer distance _source02;
    _dis3 = _planePlayer distance _source03;

    [
      [_source00,_source01,_source02,_source03],
      [_dis0,_dis1,_dis2,_dis3]
    ]
  };
};
_plane setVariable ["AAE_Turbulent_Sources",_Result # 0];
_planePlayer setVariable ["AAE_Turbulent_Source_Distance",_Result # 1];
_planePlayer setVariable ["AAE_Turbulent_Source_Distance_Found",true];
