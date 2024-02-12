params ["_planePlayer"];
private ["_planes","_ASL","_Result","_requireAng"];

_planes = nearestObjects [_planePlayer, ["Plane"], turbulent_sdr + 30];
_ASL = getPosASLVisual _planePlayer;
_Result = [-1];
_requireAng = round (turbulent_ang_sdr / 2);

{
  if (_x != _planePlayer) then {
    private ["_plane","_engine_offsets","_planeDirOP"];
    _plane = _x;
    _engine_offsets = (_plane call AAE_fnc_InitEH) get "AAE_veh_Engine_Offset";
    _planeDirOP = (vectorDir _plane) vectorMultiply -1;

    //-Returning Range from other Engine to playerAC + angle
    _Result = _engine_offsets apply {
      private ["_source","_dis","_dir","_angV","_angH"];
      _source = _plane modelToWorldVisualWorld [(_x # 0), (_x # 1)-(turbulent_sdr/2),(_x # 2)];
      _dis = _ASL distance _source;

      _dir = _source vectorFromTo _ASL;
      _angV = abs round asin (_dir # 2);
      _angH = abs acos (_planeDirOP vectorCos _dir);

      if (
          (_angV > _requireAng) || 
          (_angH > _requireAng) ||
          (_dis > turbulent_sdr + 5)
      ) then {continuewith -1};
      
      _dis
    };
    _Result = _Result select {_x > 0};
  };
} forEach _planes;

[selectMin _Result, _planePlayer]