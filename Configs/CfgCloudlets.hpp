//WingTrails FX
class CfgCloudlets
{
	class FX_WingTrail_FighterJet;
	class FX_WingTrail_FighterJet_Slow : FX_WingTrail_FighterJet
	{
		randomDirectionPeriod = 2;
		randomDirectionIntensity = 1;
		color[] = {{1,1,1,0},{1,1,1,0},{1,1,1,0.1},{1,1,1,0.2},{1,1,1,0.2},{1,1,1,0.1},{1,1,1,0}};
		colorCoef[] = {1,1,1,"(speed interpolate [62.5,83,0.3,0]) * ((altitude*altitude) interpolate [400,40000,1.2,0.5])"};
		rotationVelocity = 0;
		rotationVelocityVar = 0;
	};
	class Default;
	class WingTrail: Default
	{
		interval = 0.0003;
		colorCoef[] = {1,1,1,"(accelY interpolate [20,85,0,1]) * ((altitude*altitude) interpolate [400,40000,1.2,0.5])"};
	};
	class WingTrailMed: Default
	{
		interval = 0.0003;
		colorCoef[] = {1,1,1,"(accelY interpolate [20,85,0,1]) * ((altitude*altitude) interpolate [400,40000,1.2,0.5])"};
	};
	
	class BodyTrail: Default
	{
		interval = 0.0003;
		colorCoef[] = {1,1,1,"(accelY interpolate [30,250,0,1]) * ((altitude*altitude) interpolate [400,40000,2,0.5])"};
		size[] = {0.1,0.8,1.2};
	};
	class BodyTrailMed: Default
	{
		interval = 0.0003;
		colorCoef[] = {1,1,1,"(accelY interpolate [30,250,0,1]) * ((altitude*altitude) interpolate [400,40000,2,0.5])"};
	};
	
	//Wing
	class AAE_BodyTrail_FighterJet: Default
	{
		interval = 0.0003;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 16;
		particleFSLoop = 0;
		angleVar = 360;
		ignoreWind = 1;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 0.01;
		moveVelocity[] = {0,0,0};
		rotationVelocity = 1;
		weight = 1.274;
		volume = 1;
		rubbing = 0.18;
		size[] = {1.2};
		sizeCoef = 1;
		color[] = {{1,1,1,0.01},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0}};
		colorCoef[]=
		{
			1,
			1,
			1,
			"(accelY interpolate [60,250,0,1]) * ((altitude*altitude) interpolate [400,40000,1,0.5])"
		};
		animationSpeed[] = {1000};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.2;
		position[] = {"positionX","positionY","positionZ"};
		positionVar[] = {0,0,0};
		MoveVelocityVar[] = {0,0,0};
		rotationVelocityVar = 0;
		sizeVar = 0.25;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class AAE_BodyTrail_FighterJet_Short: AAE_BodyTrail_FighterJet
	{
		color[] = {{1,1,1,0.2},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0}};
		lifeTime = 0.005;
		lifeTimeVar = 0;
	};
	//Weapons
	class MachineGun2: Default
	{
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 1;
		size[] = {1,1.5};
		rubbing = 0.45;
		color[] = {{1,1,1,0.08},{1,1,1,0.1},{1,1,1,0.15},{1,1,1,0.07},{1,1,1,0.04}};
		sizeCoef = 1;
		lifeTime = 3;
		sizeVar = 0.15;
		interval = 0.003;
		moveVelocity[]=
		{
			"directionX + vehicleSpeedLocalX",
			"directionY + vehicleSpeedLocalY",
			"directionZ + vehicleSpeedLocalZ"
		};
		positionVar[]=
		{
			"0.1*(vehicleSpeedSize interpolate [0,250,1,5])",
			"0.1*(vehicleSpeedSize interpolate [0,250,1,5])",
			"0.1*(vehicleSpeedSize interpolate [0,250,1,5])"
		};
		MoveVelocityVar[]=
		{
			"1*(vehicleSpeedSize interpolate [0,250,1,5])",
			"1*(vehicleSpeedSize interpolate [0,250,1,5])",
			"1*(vehicleSpeedSize interpolate [0,250,1,5])"
		};
	};
	class MachineGun3: Default
	{
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 1;
		size[] = {1,1.5};
		rubbing = 0.45;
		color[] = {{1,1,1,0.07},{1,1,1,0.1},{1,1,1,0.06},{1,1,1,0.04}};
		lifeTime = 3;
		sizeVar = 0.15;
		interval = 0.0003;
		moveVelocity[]=
		{
			"directionX + vehicleSpeedLocalX",
			"directionY + vehicleSpeedLocalY",
			"directionZ + vehicleSpeedLocalZ"
		};
		positionVar[]=
		{
			"0.1*(vehicleSpeedSize interpolate [0,250,1,5])",
			"0.1*(vehicleSpeedSize interpolate [0,250,1,5])",
			"0.1*(vehicleSpeedSize interpolate [0,250,1,5])"
		};
		MoveVelocityVar[]=
		{
			"1*(vehicleSpeedSize interpolate [0,250,1,5])",
			"1*(vehicleSpeedSize interpolate [0,250,1,5])",
			"1*(vehicleSpeedSize interpolate [0,250,1,5])"
		};
	};
	
	//Missile
	class Missile3: Default
	{
		interval = 0.001;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		angleVar = 1;
		particleFSLoop = 0;
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 5;
		moveVelocity[] = {0,0,0};
		rotationVelocity = 1;
		weight = 1;
		volume = 0.8;
		rubbing = 0.5;
		size[] = {1,2,2.8};
		color[] = {{0.5,0.5,0.5,0.1},{0.6,0.6,0.6,0.05},{0.7,0.7,0.7,0.02},{0.8,0.8,0.8,0.005},{0.9,0.9,0.9,0.003}};
		animationSpeed[] = {1000};
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.1;
		onTimerScript = "";
		beforeDestroyScript = "";
		blockAIVisibility = 0;
		lifeTimeVar = 0.2;
		positionVar[] = {0.3,0.3,0.3};
		MoveVelocityVar[] = {0.4,0.4,0.4};
		rotationVelocityVar = 20;
		sizeVar = 0.15;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	
	//AAE
	class AAE_Vapor_Trail: Default
	{
		interval=0.003;
		particleShape="\A3\Data_F\ParticleEffects\Universal\Universal";
		particleFSNtieth=16;
		particleFSIndex=12;
		particleFSFrameCount=8;
		particleFSLoop=0;
		particleType="Billboard";
		animationName="";
		animationSpeed[]={1000};
		timerPeriod=0;
		lifeTime=10;
		position[]={0,0,-5};
		moveVelocity[]={0,0,0};
		rotationVelocity=1;
		weight=1.25;
		volume=1;
		rubbing=0.0099999998;
		size[]={4,8};
		color[]=
		{
			{0.69999999,0.80000001,1,0},
			{0.69999999,0.80000001,1,0.029999999},
			{0.69999999,0.80000001,1,0.059999999},
			{0.69999999,0.80000001,1,0.1},
			{0.69999999,0.80000001,1,0.050000001},
			{0.69999999,0.80000001,1,0.0099999998},
			{0.69999999,0.80000001,1,0}
		};
		lifeTimeVar=2;
		positionVar[]={3,0.1,3};
		positionVarConst[]={3,0.1,3};
		MoveVelocityVar[]={0.40000001,0.40000001,0.40000001};
		sizeVar=1;
		MoveVelocityVarConst[]={0,0,0};
		randomDirectionPeriod=0;
		randomDirectionIntensity=0;
		angleVar=1;
	};
	//For Scripts
	class HDust1;
	class AAE_Dust01: HDust1
	{
		interval = 0.01;
		particleEffects = "AAE_Dust";
		color[]={{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0.02},{1,1,0.8,0.06},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0}};
	};
	class HDust1M;
	class AAE_Dust02: HDust1M
	{
		interval = 0.02;
		color[]={{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0.02},{1,1,0.8,0.06},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0}};
	};
	class HDust1L;
	class AAE_Dust03: HDust1L
	{
		interval = 0.03;
		color[]={{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0.02},{1,1,0.8,0.06},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0}};
	};
	class HDust1LongBig;
	class AAE_Dust04: HDust1LongBig
	{
		interval = 0.05;
		color[]={{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0.02},{1,1,0.8,0.06},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0}};
	};
	class HDust1LongBigM;
	class AAE_Dust05: HDust1LongBigM
	{
		interval = 0.05;
		color[]={{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0.02},{1,1,0.8,0.06},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0},{1,1,0.8,0}};
	};
	//Water
	class HWater1;
	class AAE_Water01: HWater1
	{
		color[]={{0.7,0.8,1,0},{0.7,0.8,1,0},{0.7,0.8,1,0.02},{0.7,0.8,1,0.06},{0.7,0.8,1,0},{0.7,0.8,1,0},{0.7,0.8,1,0},{0.7,0.8,1,0},{0.7,0.8,1,0},{0.7,0.8,1,0},{0.7,0.8,1,0},{0.7,0.8,1,0}};
	};
};