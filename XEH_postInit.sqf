if (!hasInterface) exitWith {};

#include "CBA_Setting.hpp"

["AAE_Init",AAE_fnc_init] call CBA_fnc_addEventHandler;

//whether is Server
if ((isServer && hasInterface) or isDedicated) then {
  ["AAE_Init",[]] call CBA_fnc_globalEvent;
};

if (!isServer && hasInterface) then {
  ["AAE_Init",[]] call CBA_fnc_localEvent;
};
