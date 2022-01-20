params ["_plane","_Exhausts_count","_Exhausts_POS"];

_Exhausts_POS params [["_engine_LOD_0",0],["_engine_LOD_1",0],["_engine_LOD_2",0],["_engine_LOD_3",0]];

switch (_Exhausts_count) do
{
  case 1: {
    _plane_direction0 = _plane selectionVectorDirAndUp [_engine_LOD_0, "Memory"];
    _plane_direction0 = [((_plane_direction0 # 0) vectorMultiply -1), ((_plane_direction0 # 1) vectorMultiply -1)];

    _plane setVariable ["AAE_Exhaust_Direction",[_plane_direction0]];
  };
  case 2: {
    _plane_direction0 = _plane selectionVectorDirAndUp [_engine_LOD_0, "Memory"];
    _plane_direction0 = [((_plane_direction0 # 0) vectorMultiply -1), ((_plane_direction0 # 1) vectorMultiply -1)];

    _plane_direction1 = _plane selectionVectorDirAndUp [_engine_LOD_1, "Memory"];
    _plane_direction1 = [((_plane_direction1 # 0) vectorMultiply -1), ((_plane_direction1 # 1) vectorMultiply -1)];

    _plane setVariable ["AAE_Exhaust_Direction",[_plane_direction0,_plane_direction1]];
  };
  case 3: {
    _plane_direction0 = _plane selectionVectorDirAndUp [_engine_LOD_0, "Memory"];
    _plane_direction0 = [((_plane_direction0 # 0) vectorMultiply -1), ((_plane_direction0 # 1) vectorMultiply -1)];

    _plane_direction1 = _plane selectionVectorDirAndUp [_engine_LOD_1, "Memory"];
    _plane_direction1 = [((_plane_direction1 # 0) vectorMultiply -1), ((_plane_direction1 # 1) vectorMultiply -1)];

    _plane_direction2 = _plane selectionVectorDirAndUp [_engine_LOD_2, "Memory"];
    _plane_direction2 = [((_plane_direction2 # 0) vectorMultiply -1), ((_plane_direction2 # 1) vectorMultiply -1)];

    _plane setVariable ["AAE_Exhaust_Direction",[_plane_direction0,_plane_direction1,_plane_direction2]];
  };
  case 4: {
    _plane_direction0 = _plane selectionVectorDirAndUp [_engine_LOD_0, "Memory"];
    _plane_direction0 = [((_plane_direction0 # 0) vectorMultiply -1), ((_plane_direction0 # 1) vectorMultiply -1)];

    _plane_direction1 = _plane selectionVectorDirAndUp [_engine_LOD_1, "Memory"];
    _plane_direction1 = [((_plane_direction1 # 0) vectorMultiply -1), ((_plane_direction1 # 1) vectorMultiply -1)];

    _plane_direction2 = _plane selectionVectorDirAndUp [_engine_LOD_2, "Memory"];
    _plane_direction2 = [((_plane_direction2 # 0) vectorMultiply -1), ((_plane_direction2 # 1) vectorMultiply -1)];

    _plane_direction3 = _plane selectionVectorDirAndUp [_engine_LOD_3, "Memory"];
    _plane_direction3 = [((_plane_direction3 # 0) vectorMultiply -1), ((_plane_direction3 # 1) vectorMultiply -1)];

    _plane setVariable ["AAE_Exhaust_Direction",[_plane_direction0,_plane_direction1,_plane_direction2,_plane_direction3]];
  };
};
