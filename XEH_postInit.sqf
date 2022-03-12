if !(hasInterface) exitWith {};

["AAE_Init",AAE_fnc_Init] call CBA_fnc_addEventHandler;
["AAE_Init",[]] call CBA_fnc_localEvent;
/* //whether is Server
if ((isServer && hasInterface) or isDedicated) then {
  ["AAE_Init",[]] call CBA_fnc_globalEvent;
};

if (!isServer && hasInterface) then {
  ["AAE_Init",[]] call CBA_fnc_localEvent;
}; */
