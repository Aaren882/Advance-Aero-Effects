params ["_plane"];

_GearsArray = [];
_offset = 0;
_OffsetF = 0;

_config = configFile >> "CfgVehicles" >> typeOf _plane;

_selection = getArray (_config >> "driveOnComponent");

if (_selection isEqualTo  []) then {

  _selection = getArray (_config >> "AAE_WheelsContact");

  if (_selection isEqualTo  []) then {

    _selection = _plane selectionNames "LandContact";

    //Others
    if (_plane isKindOf "Plane_Fighter_01_Base_F") then {
      _selection = ["gear_f" , _selection # 1, _selection # 2];
      _OffsetF = -1;
    };
    if (_plane isKindOf "VTOL_01_base_F") then {
      _selection = ["wheel_1_1" , "wheel_2_2", "wheel_3_2"];
    };
    if (_plane isKindOf "Plane_Fighter_03_base_F") then {
      _selection = ["wheel_1_axis" , "wheel_2_axis", "wheel_3_axis"];
    };
    if (_plane isKindOf "USAF_C130J_Base") then {
      _selection = ["wheel_1_1", "wheel_2_1", "wheel_2_2"];
      _offset = -0.5;
    };
    if (_plane isKindOf "rhsusf_f22") then {
      _selection = ["gear_f1", "wheel_2_rim", "wheel_3_rim"];
    };
    if (_plane isKindOf "RHS_C130J_Base") then {
      _selection = ["wheel_1_1", "wheel_2_1", "wheel_2_2"];
    };
    if (_plane isKindOf "rhs_mig29s_base") then {
      _selection = ["wheel_f_axis", "wheel_l_axis", "wheel_r_axis"];
    };
    if (_plane isKindOf "RHS_T50_base") then {
      _selection = ["wheel_f_axis", "wheel_2_rim", "wheel_3_rim"];
    };
    if (_plane isKindOf "RHS_TU95MS_base") then {
      _selection = ["gear_f1", "gear_l1", "gear_r1"];
    };
    if (_plane isKindOf "RHSGREF_A29_Base") then {
      _selection = ["nosegearwheel", "maingearleftwheel", "maingearrightwheel"];
    };
    if (_plane isKindOf "UAV_02_base_F") then {
      _selection = ["wheel_1", "wheel_2", "wheel_3"];
    };
  };
};

if (_selection isEqualTo []) exitWith {};

_AV8 = (_plane isKindOf "FIR_AV8B_Base") or (_plane isKindOf "FIR_AV8B_NA_Base") or (_plane isKindOf "FIR_AV8B_GR7_Base") or (_plane isKindOf "CUP_AV8B_Base");

/* _gearF = _selection # 0;
_gearL = _selection # 1;
_gearR = _selection # 2;
_gearA = "";

_gear0 = _plane selectionPosition _gearF;
_gear1 = _plane selectionPosition _gearL;
_gear2 = _plane selectionPosition _gearR;
_gear3 = [0,0,0];

if (_AV8) then {
  _gearA = _selection # 3;
  _gear3 = _plane selectionPosition _gearA;
}; */

for "_i" from 0 to (count _selection - 1) do {
  _gear = _selection # _i;
  _Selection_Offset = _plane selectionPosition _gear;
  _GearsArray pushBack _Selection_Offset;
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

_Hvar = 0.84;
_HvarR = 0.84;

_returns = [_plane,_AV8,_lifetime,_size,_Hvar,_HvarR,_GearsArray,_offset,_OffsetF];

_returns
