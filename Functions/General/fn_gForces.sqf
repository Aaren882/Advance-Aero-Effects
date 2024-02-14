//////////////////////////////////////////////////////////////////////////////////////////////////////////
//This Script is base on ACE3
//  Thanks for their hard working ~
//
//Changed:
//1. player wont be that easy to black out or red out
//2. maximum G-Forces "9G"
//3. wont passout
//4. Detect player wearing///
//5. G-Breathing Sound
//6. Sound Fade Out
//Edited by Aaren
//////////////////////////////////////////////////////////////////////////////////////////////////////////
params ["_plane","_config"];
private [
  "_sound","_sound_hold",
  "_INTERVAL","_MAXVIRTUALG","_MINVIRTUALG",
  "_var","_GForces","_Index","_oldVel",
  "_newVel","_accel","_currentGForce",
  "_average","_gBlackOut","_strength",
  "_Active"
];

_sound = getText (_config >> "AAE_GBreathe");
_sound_hold = getText (_config >> "AAE_GBreathe_Hold");

if (_sound == "") then {
  _sound = "AAE_GBreathe";
  _sound_hold = "AAE_GBreathe_Hold";
};

_INTERVAL= 0.2;
_MAXVIRTUALG = 5;
_MINVIRTUALG = 2.5;

_var = localNamespace getVariable "AAE_GForce_Var";
_lastUpdateTime = _var get "lastUpdateTime";

//Volume fade out
if (Gforces_Vol_fn) then {
  call AAE_fnc_ChangeVolume;
};

//- Below Update per 0.2 sec
if ((time - _lastUpdateTime) < _INTERVAL) exitWith {};
_var set ["lastUpdateTime", time];

_GForces = _var get "GForces";
_Index = _var get "Index";
_oldVel = _var get "oldVel";

//Thanks for ACE team
_newVel = velocity _plane;
_accel = (_newVel vectorDiff _oldVel) vectorMultiply (1 / _INTERVAL);
_currentGForce = (((_accel vectorDotProduct (vectorUp _plane)) / 11) max -10) min 10;

if (_currentGForce >= 7) then {
  _sound = _sound_hold;
};

_GForces set [_Index, _currentGForce * gforces_sdr];

_var set ["GForces", _GForces];
_var set ["Index" , (_Index + 1) % 30];
_var set ["oldVel", _newVel];

_average = 0;

{
  _average = _average + _x;
} count _GForces;

_average = _average / 30;

_gBlackOut = _MAXVIRTUALG / 0.55 + _MAXVIRTUALG / 1 - _MAXVIRTUALG;
_strength = ((_average - 0.30 * _gBlackOut) / (0.70 * _gBlackOut)) max 0;
localNamespace setVariable ["AAE_CurrentGForce",_strength];

if (isnil{AAE_GForces_Filter}) exitWith {};

if (_average > 0.30 * _gBlackOut) then {
  if (Gforces_fn) then {
    AAE_GForces_Filter ppEffectAdjust [1,1,0,[0,0,0,1],[0,0,0,0],[1,1,1,1],[2 * (1 - _strength),(1 - _strength),0,0,0,0.1,0.5]];
  };

  if ((_currentGForce >= 3) && (cameraView == "internal") && (gBreathe_sound_fn)) then {
    if ((_currentGForce >= 7) && ((_plane getVariable ["Breathing_execution_time", -1]) < time)) then {
      [_plane,_sound_Hold] call AAE_fnc_PlayBreathing;
    } else {
      if ((_plane getVariable ["Breathing_execution_time", -1]) < time) then {
        [_plane,_sound] call AAE_fnc_PlayBreathing;
      };
    };
  };
} else {
  private _gRedOut = _MINVIRTUALG / 0.55;

  if (_average < -0.30 * _gRedOut) then {
    if (Gforces_fn) then {
      _strength = ((abs _average - 0.30 * _gRedOut) / (0.70 * _gRedOut)) max 0;
      AAE_GForces_Filter ppEffectAdjust [1,1,0,[1,0.2,0.2,1],[0,0,0,0],[1,1,1,1],[2 * (1 - _strength),1 * (1 - _strength),0,0,0,0.1,0.5]];
    };

    if ((_currentGForce >= 3) && (cameraView == "internal") && (gBreathe_sound_fn) && ((_plane getVariable ["Breathing_execution_time", -1]) < time)) then {
      [_plane,_sound] call AAE_fnc_PlayBreathing;

      if ((_currentGForce >= 7) && ((_plane getVariable ["Breathing_execution_time", -1]) < time)) then {
        [_plane,_sound_Hold] call AAE_fnc_PlayBreathing;
      };
    };

  } else {
    AAE_GForces_Filter ppEffectAdjust [1,1,0,[0,0,0,1],[0,0,0,0],[1,1,1,1],[10,10,0,0,0,0.1,0.5]];
  };
};

AAE_GForces_Filter ppEffectCommit 0.6;

//- Update Varible
localNamespace setVariable ["AAE_GForce_Var", _var];