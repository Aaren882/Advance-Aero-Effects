private ["_offset","_OffsetF","_selection","_AV8","_GearsArray","_lifetime","_size","_mass","_Hvar","_HvarR"];

_offset = 0;
_OffsetF = 0;

_selection = getArray (_config >> "driveOnComponent");

if (_selection isEqualTo  []) then {

  _selection = getArray (_config >> "AAE_WheelsContact");

  if (_selection isEqualTo  []) then {

    _selection = call {
      private _Mem = _plane selectionNames "LandContact";

      //Others
      if (_plane isKindOf "Plane_Fighter_01_Base_F") exitwith {
        _OffsetF = -1;
        ["gear_f" , _Mem # 1, _Mem # 2]
      };
      if (_plane isKindOf "VTOL_01_base_F") exitwith {
        ["wheel_1_1" , "wheel_2_2", "wheel_3_2"]
      };
      if (_plane isKindOf "Plane_Fighter_03_base_F") exitwith {
        ["wheel_1_axis" , "wheel_2_axis", "wheel_3_axis"]
      };
      if (_plane isKindOf "USAF_C130J_Base") exitwith {
        _offset = -0.5;
        ["wheel_1_1", "wheel_2_1", "wheel_2_2"]
      };
      if (_plane isKindOf "rhsusf_f22") exitwith {
        ["gear_f1", "wheel_2_rim", "wheel_3_rim"]
      };
      if (_plane isKindOf "RHS_C130J_Base") exitwith {
        ["wheel_1_1", "wheel_2_1", "wheel_2_2"]
      };
      if (_plane isKindOf "rhs_mig29s_base") exitwith {
        ["wheel_f_axis", "wheel_l_axis", "wheel_r_axis"]
      };
      if (_plane isKindOf "RHS_T50_base") exitwith {
        ["wheel_f_axis", "wheel_2_rim", "wheel_3_rim"]
      };
      if (_plane isKindOf "RHS_TU95MS_base") exitwith {
        ["gear_f1", "gear_l1", "gear_r1"]
      };
      if (_plane isKindOf "RHSGREF_A29_Base") exitwith {
        ["nosegearwheel", "maingearleftwheel", "maingearrightwheel"]
      };
      if (_plane isKindOf "UAV_02_base_F") exitwith {
        ["wheel_1", "wheel_2", "wheel_3"]
      };

      _Mem
    };
    
  };
};

if (_selection isEqualTo []) exitWith {};

//_AV8 = (_plane isKindOf "FIR_AV8B_Base") || (_plane isKindOf "FIR_AV8B_NA_Base") || (_plane isKindOf "FIR_AV8B_GR7_Base") || (_plane isKindOf "CUP_AV8B_Base");

_GearsArray = _selection apply {
  _plane selectionPosition _x;
};

_lifetime = 3;
_size = [2,4,6,10,12];

//Mass
_mass = getMass _plane;

//Vehicle Detail
if ((driver _plane) != player) then {
  if (_mass >= 100000) then {
      _lifetime = 5;
      _size = [2,5,8,10,12];
  } else {
    if (_mass <= 1500) then {
      _lifetime = 3;
    };
    if (_mass >= 10000) then {
      _lifetime = 3;
    };
    if (_mass >= 16200) then {
      _lifetime = 3;
    };
    if (_mass >= 20000) then {
      _lifetime = 3;
      _size = [2,4,6,10,12];
    };
  };
} else {
  if (_mass >= 100000) then {
      _lifetime = 5;
      _size = [2,5,8,10,12];
  } else {
    if (_mass <= 1500) then {
      _lifetime = 3;
    };
    if (_mass >= 10000) then {
      _lifetime = 3;
    };
    if (_mass >= 16200) then {
      _lifetime = 3;
    };
    if (_mass >= 20000) then {
      _lifetime = 3;
      _size = [2,4,6,10,12];
    };
  };
};

_LocalCache set ["AAE_Wheels_Selections", [_lifetime,_size,_GearsArray,_offset,_OffsetF]];