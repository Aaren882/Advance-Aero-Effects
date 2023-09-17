[
	"ground_fn","CHECKBOX",
	["Ground Effect (CBA Slider)","Spawn Ground Effect at 250m or lower"],
	["Advance Aero Effects", "Ground Effect"],
	false
] call CBA_fnc_addSetting;

[
	"wingspan_fn","CHECKBOX",
	["Auto Detection","Auto Detects Trigger Height by Wingspan"],
	["Advance Aero Effects", "Ground Effect"],
	true
] call CBA_fnc_addSetting;

[
	"burner_fn","CHECKBOX",
	["AfterBurner Effect","Add AfterBurner Light"],
	["Advance Aero Effects", "AfterBurner Effect Settings"],
	true
] call CBA_fnc_addSetting;

[
	"burner_flare_fn","CHECKBOX",
	["AfterBurner Flare Effect","Active AfterBurner Light Flare"],
	["Advance Aero Effects", "AfterBurner Effect Settings"],
	false
] call CBA_fnc_addSetting;

[
	"wingspan_fn","CHECKBOX",
	["Auto Detection","Auto Detects Trigger Height by Wingspan"],
	["Advance Aero Effects", "Ground Effect"],
	true
] call CBA_fnc_addSetting;

[
	"vapor_fn","CHECKBOX",
	["Vapor Trail Effect (CBA Slider)","Spawn Vapor Trail"],
	["Advance Aero Effects", "Vapor Trail Effect"],
	false
] call CBA_fnc_addSetting;

[
	"vapor_sim_fn","CHECKBOX",
	["Affect By Amibient Factor (reach -20°C ,-4°F)","Temp - ((ASL / 100) * 0.98) reach Active altitude (Slider)"],
	["Advance Aero Effects", "Vapor Trail Effect"],
	false,0,
	{
		if !(_this) then {
			Vapor_sim = true;
		};
	}
] call CBA_fnc_addSetting;

[
	"gear_fn","CHECKBOX",
	["Gear Factor Effect","Spawn Cam Shake"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

[
	"taxiing_fn","CHECKBOX",
	["Taxiing Cam Shake Effect"],
	["Advance Aero Effects", "Taxiing Settings"],
	false
] call CBA_fnc_addSetting;

[
	"Gforces_fn","CHECKBOX",
	["G-Forces Effect (Without ACE Installed)","Except For the Breathing Sound"],
	["Advance Aero Effects", "G-Forces"],
	false
] call CBA_fnc_addSetting;

[
	"Gforces_Vol_fn","CHECKBOX",
	["Lower Ambient Volume","Lower Ambient Sound Effects"],
	["Advance Aero Effects", "G-Forces"],
	true
] call CBA_fnc_addSetting;

[
	"sonicboom_fn","CHECKBOX",
	["SonicBoom Effect","Spawn Sonic Boom Vapor Effect"],
	["Advance Aero Effects", "Sonic Boom Effect"],
	false
] call CBA_fnc_addSetting;

[
	"sonicboom_tmp_fn","CHECKBOX",
	["SonicBoom Ambient Factor","Affect by air temperture: 331 + (0.6 * Temp)"],
	["Advance Aero Effects", "Sonic Boom Effect"],
	false,0,
	{
		if !(_this) then {
			AAE_SpeedSet = 1195;
			AAE_sonicboom_speed_01 = AAE_SpeedSet - 20;//1175
			AAE_sonicboom_speed_02 = AAE_SpeedSet - 10;//1185
			AAE_sonicboom_speed_03 = AAE_SpeedSet + 10;//1205
		};
	}
] call CBA_fnc_addSetting;

[
	"camshake_fn","CHECKBOX",
	["Cam-Shake Effect (CBA Slider)","Cam-Shaking Effect at Distance 5m ~ 200m (For Troopers on The Ground)"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

[
	"landingVEF_fn","CHECKBOX",
	["Landing Smoke Effect","Spawn Landing Effect on the Gears"],
	["Advance Aero Effects", "Ganeral"],
	false
] call CBA_fnc_addSetting;

// [
// 	"landingCam_fn","CHECKBOX",
// 	["Taxiing CamShake Effect","CamShaking Effect While TouchDown"],
// 	["Advance Aero Effects", "Ganeral"],
// 	false
// ] call CBA_fnc_addSetting;

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

//Crash Cam Shake
[
	"crashShake_fn","CHECKBOX",
	"CamShake Effect When Crashes",
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
	["Turbulent Rumbling Sound Effect","Rumbling Sound Effect"],
	["Advance Aero Effects", "Rumbling Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"gear_snd_rum_fn","CHECKBOX",
	["Gear Rumbling Sound Effect","Rumbling Sound Effect"],
	["Advance Aero Effects", "Rumbling Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"Taxing_sound_fn","CHECKBOX",
	["Gear Rumbling Sound Effect","Rumbling Sound Effect"],
	["Advance Aero Effects", "Taxiing Settings"],
	false
] call CBA_fnc_addSetting;

[
	"turbulent_snd_alarm_fn","CHECKBOX",
	["Turbulent Alarm Sound Effect","Alarm Sound Effect"],
	["Advance Aero Effects", "Alarm Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"gear_snd_alarm_fn","CHECKBOX",
	["Gear Alarm Sound Effect","Alarm Sound Effect"],
	["Advance Aero Effects", "Alarm Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"turbulentS_snd_alarm_fn","CHECKBOX",
	["Speed Alarm Sound Effect","Alarm Sound Effect"],
	["Advance Aero Effects", "Alarm Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"turbulentH_snd_alarm_fn","CHECKBOX",
	["Elevation Alarm Sound Effect","Alarm Sound Effect"],
	["Advance Aero Effects", "Alarm Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"TDSound_fn","CHECKBOX",
	["TouchDown Sound Effect","TouchDown Sound Effect"],
	["Advance Aero Effects", "Sound Effects"],
	false
] call CBA_fnc_addSetting;

[
	"Taxiing_sound_fn","CHECKBOX",
	["Taxiing Sound Effect","Taxiing Sound Effect"],
	["Advance Aero Effects", "Sound Effects"],
	false
] call CBA_fnc_addSetting;

//Sliders
[
	"vapor_sdr", "SLIDER",
	["Vapor Trail Active Range Slider","The Active Height of Vapor Trail"],
	["Advance Aero Effects", "Vapor Trail Effect"],
	[2000, 10000, 3000, 0]
] call CBA_fnc_addSetting;

[
	"groundP_sdr", "SLIDER",
	["Ground Effects Active Range Slider","The Active Height of Ground Effects (5m~)"],
	["Advance Aero Effects", "Ground Effect"],
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

[
	"gforces_Vol_sdr", "SLIDER",
	["Adjustment for volume Slider (%)"],
	["Advance Aero Effects", "G-Forces"],
	[0, 100, 30, 0]
] call CBA_fnc_addSetting;
