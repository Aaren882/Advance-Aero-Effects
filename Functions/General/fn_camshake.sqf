if ((_plane iskindof "UAV_02_base_F") or (_plane iskindof "UAV_04_base_F")) exitWith {};

_Distance = player distance _plane;

if ((_Distance > 5) and (_Distance <= camshake_sdr)) then {
	addCamShake [3, 2, 10];
};
