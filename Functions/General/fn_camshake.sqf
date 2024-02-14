if ((_plane iskindof "UAV_02_base_F") || (_plane iskindof "UAV_04_base_F")) exitWith {};

private _Distance = player distance _plane;
if (_Distance < camshake_sdr) then {
	addCamShake [
		linearConversion [5, camshake_sdr,_Distance, 10,1,true],
		1, 
		linearConversion [50, camshake_sdr,_Distance, 20,10,true]
	];
};
