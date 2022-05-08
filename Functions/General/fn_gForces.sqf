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
_plane = _this;

_config = configFile >> "CfgVehicles" >> typeOf _plane;
_sound = getText (_config >> "AAE_GBreathe");
_sound_hold = getText (_config >> "AAE_GBreathe_Hold");

if (_sound isEqualTo "") then {
  _sound = "AAE_GBreathe";
  _sound_hold = "AAE_GBreathe_Hold";
};

_INTERVAL= 0.2;
_MAXVIRTUALG = 5;
_MINVIRTUALG = 2.5;

if ((time - lastUpdateTime) < _INTERVAL) exitWith {};
lastUpdateTime = time;

//Thanks for ACE team
_newVel = velocity _plane;
_accel = (_newVel vectorDiff oldVel) vectorMultiply (1 / _INTERVAL);
_currentGForce = (((_accel vectorDotProduct (vectorUp _plane)) / 11) max -10) min 10;

if (_currentGForce >= 7) then {
  _sound = _sound_hold;
};

GForces set [GForces_Index, _currentGForce * gforces_sdr];
GForces_Index = (GForces_Index + 1) % 30;

oldVel = _newVel;

_average = 0;

_count = {
  _average = _average + _x;
  true
} count GForces;

if (_count > 0) then {
  _average = _average / _count;
};

_gBlackOut = _MAXVIRTUALG / 0.55 + _MAXVIRTUALG / 1 - _MAXVIRTUALG;
_strength = ((_average - 0.30 * _gBlackOut) / (0.70 * _gBlackOut)) max 0;
_plane setVariable ["AAE_CurrentGForce",_strength];
if (_average > 0.30 * _gBlackOut) then {
  if ((Gforces_fn) and !(HaveACE)) then {
    _strength = ((_average - 0.30 * _gBlackOut) / (0.70 * _gBlackOut)) max 0;
    GForces_Filter ppEffectAdjust [1,1,0,[0,0,0,1],[0,0,0,0],[1,1,1,1],[2 * (1 - _strength),(1 - _strength),0,0,0,0.1,0.5]];
  };

  if ((_currentGForce >= 3) and (cameraView == "internal") and (gBreathe_sound_fn)) then {
    if ((_currentGForce >= 7) and ((_plane getVariable ["Breathing_execution_time", -1]) < time)) then {
      [_plane,_sound_Hold] call AAE_fnc_PlayBreathing;
    } else {
      if ((_plane getVariable ["Breathing_execution_time", -1]) < time) then {
        [_plane,_sound] call AAE_fnc_PlayBreathing;
      };
    };
  };
} else {
  _gRedOut = _MINVIRTUALG / 0.55;

  if (_average < -0.30 * _gRedOut) then {
    if ((Gforces_fn) and !(HaveACE)) then {
      _strength = ((abs _average - 0.30 * _gRedOut) / (0.70 * _gRedOut)) max 0;
      GForces_Filter ppEffectAdjust [1,1,0,[1,0.2,0.2,1],[0,0,0,0],[1,1,1,1],[2 * (1 - _strength),1 * (1 - _strength),0,0,0,0.1,0.5]];
    };

    if ((_currentGForce >= 3) and (cameraView == "internal") and (gBreathe_sound_fn) and ((_plane getVariable ["Breathing_execution_time", -1]) < time)) then {
      [_plane,_sound] call AAE_fnc_PlayBreathing;

      if ((_currentGForce >= 7) and ((_plane getVariable ["Breathing_execution_time", -1]) < time)) then {
        [_plane,_sound_Hold] call AAE_fnc_PlayBreathing;
      };
    };

  } else {
    GForces_Filter ppEffectAdjust [1,1,0,[0,0,0,1],[0,0,0,0],[1,1,1,1],[10,10,0,0,0,0.1,0.5]];
  };
};

GForces_Filter ppEffectCommit 0.6;
