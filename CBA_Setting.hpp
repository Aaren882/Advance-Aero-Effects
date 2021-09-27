/*[
	"server_fn","CHECKBOX",
	["[AS Server Settings]","Need to Restart"],
	["Advance Aero Effects", "Ganeral"],
	false,
	true,
	{
		if (server_fn) then {
			AAE_server = 0;
		} else {
			AAE_server = 0;
		};
		hint "Need to Restart!!";
	},
	true
] call CBA_fnc_addSetting;*/

[
	"ground_fn","CHECKBOX",
	["Ground Effect (CBA Slider)","Spawn Ground Effect at 100m or lower"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

[
	"vapor_fn","CHECKBOX",
	["Vapor Trail Effect (CBA Slider)","Spawn Vapor Trail"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

[
	"gear_fn","CHECKBOX",
	["Gear Factor Effect","Spawn Cam Shake"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

[
	"taxing_fn","CHECKBOX",
	["Taxing Cam Shake Effect"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

[
	"Gforces_fn","CHECKBOX",
	["G-Forces Effect (Without ACE Installed)","Except For the Breathing Sound"],
	["Advance Aero Effects", "G-Forces"],
	false
] call CBA_fnc_addSetting;

[
	"sonicboom_fn","CHECKBOX",
	["SonicBoom Effect","Spawn Sonic Boom Effect at 1185km/hr ~ 1205km/hr"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

[
	"camshake_fn","CHECKBOX",
	["Cam-Shake Effect (CBA Slider)","Trigger Cam-Shaking Effect at Distance 5m ~ 200m (For Troopers on The Ground)"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

[
	"landingVEF_fn","CHECKBOX",
	["Landing Smoke Effect","Spawn Landing Effect on the Gears"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

[
	"landingCam_fn","CHECKBOX",
	["Taxing CamShake Effect","Trigger CamShaking Effect While TouchDown"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

[
	"turbulentP_fn","CHECKBOX",
	["Turbulent Effect (Exhaust - CBA Slider)","Spawn Turbulent Effect at Rear of the Engines"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

[
	"turbulentS_fn","CHECKBOX",
	["Turbulent Effect Speed (World)","Spawn Turbulent Effect at Low Speed and Under 1000m"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

[
	"turbulentH_fn","CHECKBOX",
	["Turbulent Effect Height (World - CBA Slider)","Spawn Turbulent Effect at Low Altitude and Speed Over 700 km/hr"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

//Sounds
[
	"gBreathe_sound_fn","CHECKBOX",
	["Breathing Sound Effect"],
	["Advance Aero Effects", "G-Forces"],
	false
] call CBA_fnc_addSetting;

[
	"turbulent_snd_rum_fn","CHECKBOX",
	["Turbulent Rumbling Sound Effect","Trigger Rumbling Sound Effect"],
	["Advance Aero Effects", "Rumbling Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"gear_snd_rum_fn","CHECKBOX",
	["Gear Rumbling Sound Effect","Trigger Rumbling Sound Effect"],
	["Advance Aero Effects", "Rumbling Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"turbulent_snd_alarm_fn","CHECKBOX",
	["Turbulent Alarm Sound Effect","Trigger Alarm Sound Effect"],
	["Advance Aero Effects", "Alarm Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"gear_snd_alarm_fn","CHECKBOX",
	["Gear Alarm Sound Effect","Trigger Alarm Sound Effect"],
	["Advance Aero Effects", "Alarm Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"turbulentS_snd_alarm_fn","CHECKBOX",
	["Speed Alarm Sound Effect","Trigger Alarm Sound Effect"],
	["Advance Aero Effects", "Alarm Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"turbulentH_snd_alarm_fn","CHECKBOX",
	["Elevation Alarm Sound Effect","Trigger Alarm Sound Effect"],
	["Advance Aero Effects", "Alarm Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"TDSound_fn","CHECKBOX",
	["TouchDown Sound Effect","Trigger TouchDown Sound Effect"],
	["Advance Aero Effects", "Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"Taxing_sound_fn","CHECKBOX",
	["Taxing Sound Effect","Trigger Taxing Sound Effect"],
	["Advance Aero Effects", "Sound Effects"],
	false
] call CBA_fnc_addSetting;

//Sliders
[
	"vapor_sdr", "SLIDER",
	["Vapor Trail Active Range Slider","The Active Height of Vapor Trail"],
	["Advance Aero Effects", "Settings"],
	[2000, 10000, 3000, 0]
] call CBA_fnc_addSetting;

[
	"groundP_sdr", "SLIDER",
	["Ground Effects Active Range Slider","The Active Height of Ground Effects (5m~)"],
	["Advance Aero Effects", "Settings"],
	[2, 250, 50, 0]
] call CBA_fnc_addSetting;

[
	"camshake_sdr", "SLIDER",
	["Cam-Shake Effect Active Range Slider","The Active Range of Cam-Shake"],
	["Advance Aero Effects", "Settings"],
	[5, 500, 200, 0]
] call CBA_fnc_addSetting;

[
	"gearP_sdr", "SLIDER",
	["Speed Adjustment for Gear Factor (km/hr)"],
	["Advance Aero Effects", "Settings"],
	[150, 1000, 600, 0]
] call CBA_fnc_addSetting;

[
	"turbulent_sdr", "SLIDER",
	["Turbulent Effect Active Scale Slider (Plane)","The Active Scale of Turbulent Effect (Plane)"],
	["Advance Aero Effects", "Settings"],
	[0, 15, 10, 0]
] call CBA_fnc_addSetting;

[
	"turbulentT_sdr", "SLIDER",
	["Turbulent Effect Active Height Slider (World)","The Active Height of Turbulent Effect (World)"],
	["Advance Aero Effects", "Settings"],
	[10, 200, 50, 0]
] call CBA_fnc_addSetting;

[
	"gforces_sdr", "SLIDER",
	["Adjustment for G-Forces Slider"],
	["Advance Aero Effects", "G-Forces"],
	[0, 1, 1, 1]
] call CBA_fnc_addSetting;