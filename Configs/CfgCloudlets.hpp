//WingTrails FX
class CfgCloudlets
{
	class Default;
	class FX_WingTrail_FighterJet: Default
	{
		lifeTime = "0.2 + (accelY interpolate [70,200,0,0.2])";
		color[] = {{1,1,1,0.05},{1,1,1,0.1},{1,1,1,0.2},{1,1,1,0.2},{1,1,1,0.1},{1,1,1,0}};
	};
	class FX_WingTrail_FighterJet_Slow : FX_WingTrail_FighterJet
	{
		randomDirectionPeriod = 2;
		randomDirectionIntensity = 1;
		color[] = {{1,1,1,0},{1,1,1,0},{1,1,1,0.1},{1,1,1,0.2},{1,1,1,0.2},{1,1,1,0.1},{1,1,1,0}};
		colorCoef[] = {1,1,1,"(speed interpolate [62.5,83,0.3,0]) * ((altitude*altitude) interpolate [400,40000,1.2,0.5])"};
		rotationVelocity = 0;
		rotationVelocityVar = 0;
	};
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
	class FX_BodyTrail_FighterJet: Default
	{
		size[] = {0.5,0.8,1.2,1.2,1.8};
		colorCoef[] = 
		{
			1,
			1,
			1,
			"(accelY interpolate [70,250,0,0.2]) * ((altitude*altitude) interpolate [400,40000,2,0.5])"
		};
	};
	
	//Wing
	class AAE_BodyTrail_FighterJet: Default
	{
		interval = "0.0001 * (speed interpolate [70,70.0001,-1,1])";
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
		lifeTimeVar = 0.1;
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
			"(accelY interpolate [75,100,0,0.045]) * ((altitude*altitude) interpolate [400,40000,1,0.5])"
		};
		animationSpeed[] = {1000};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
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
		color[] = {{1,1,1,0.5},{1,1,1,0.3},{1,1,1,0.2},{1,1,1,0.2},{1,1,1,0.2},{1,1,1,0.2},{1,1,1,0.1},{1,1,1,0},{1,1,1,0},{1,1,1,0}};
		lifeTime = 0.008;
		lifeTimeVar = 0.03;
		colorCoef[]=
		{
			1,
			1,
			1,
			"(accelY interpolate [75,100,0,0.002])"
		};
	};
	//Vanilla
	class AAE_BodyTrail_FighterJet_A164: FX_BodyTrail_FighterJet
	{
		color[] = {{1,1,1,0.5},{1,1,1,0.3},{1,1,1,0.2},{1,1,1,0.2},{1,1,1,0.2},{1,1,1,0.2},{1,1,1,0.1},{1,1,1,0},{1,1,1,0},{1,1,1,0}};
		
		size[] = {1.2};
		sizeCoef = 1;
		
		lifeTime = 0.008;
		lifeTimeVar = 0.03;
		
		colorCoef[]=
		{
			1,
			1,
			1,
			"(accelY interpolate [30,100,0,0.003])"
		};
	};
	class AAE_BodyTrail_FighterJet_Mid: FX_BodyTrail_FighterJet
	{
		color[] = {{1,1,1,0.2},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0}};
		
		size[] = {1.2};
		sizeCoef = 1;
		
		colorCoef[]=
		{
			1,
			1,
			1,
			"(accelY interpolate [50,100,0,0.01])"
		};
	};
	class AAE_BodyTrail_FighterJet_Short_Vanilla: AAE_BodyTrail_FighterJet_A164
	{
		lifeTime = 0.025;
		lifeTimeVar = 0;
		
		colorCoef[]=
		{
			1,
			1,
			1,
			"(accelY interpolate [30,250,0,0.02])"
		};
	};
	class ExpSparks1;
	class AAE_TailHook_Landed_Spark: ExpSparks1
	{
		animationSpeed[] = {-2};
		size[]={0.1};
		sizeVar=0.5;
		interval = 0.01;
		rubbing=0.15;
		moveVelocity[]={0,0,2};
		moveVelocityVar[] = {3,3,3};
		
		position[]={0,0,0};
		positionVar[]={0,0,0};
		
		angleVar = 360;
		
		color[]=
		{
			{0.8,0.6,0.16,-1},
			{0.8,0.6,0.16,0}
		};
		
		colorVar[] = {0.05,0.05,0.05,0};
		
		rotationVelocity = 1;
		lifeTime=3;
		lifeTimeVar=0.2;
		
		randomDirectionPeriod=0.2;
		randomDirectionIntensity=0.2;
		
		bounceOnSurface = 0.1;
		bounceOnSurfaceVar = 0.12;
		
		weight=1.8;
		volume=1;
		
		emissiveColor[]=
		{
			{10000,6000,1600,0.5}
		};
		particleEffects="AAE_TailHook_Sprak";
	};
	/////////////////////////////////////////////////////////////
	//Super Hornet
	class FX_FA18_BodyTrail: Default
	{
		interval = 0.0003;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 13;
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
		color[] = {{1,1,1,0.1},{1,1,1,0.2},{1,1,1,0.1},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0}};
		colorCoef[]=
		{
			1,
			1,
			1,
			"(accelY interpolate [50,250,0,1]) * ((altitude*altitude) interpolate [400,40000,1.2,0.5])"
		};
		animationSpeed[] = {1000};
		animationSpeedCoef = 0.01;
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.2;
		position[] = {"positionX","positionY","positionZ"};
		positionVar[] = {0,0,0};
		MoveVelocityVar[] = {0,0,0};
		rotationVelocityVar = 0;
		sizeVar = 0.5;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class FX_FA18_BodyTrail2: Default
	{
		interval = 0.0003;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 13;
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
		color[] = {{1,1,1,0.1},{1,1,1,0.2},{1,1,1,0.1},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0},{1,1,1,0}};
		colorCoef[]=
		{
			1,
			1,
			1,
			"(accelY interpolate [50,250,0,1]) * ((altitude*altitude) interpolate [400,40000,1.2,0.5])"
		};
		animationSpeed[] = {1000};
		animationSpeedCoef = 0.01;
		randomDirectionPeriod = 0;
		randomDirectionIntensity = 0;
		onTimerScript = "";
		beforeDestroyScript = "";
		lifeTimeVar = 0.2;
		position[] = {"positionX","positionY","positionZ"};
		positionVar[] = {0,0,0};
		MoveVelocityVar[] = {0,0,0};
		rotationVelocityVar = 0;
		sizeVar = 0.5;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
	};
	class FX_FA18_WingOverVapour: Default
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
		color[] = {{1,1,1,0.01},{1,1,1,0}};
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
	class FX_FA18_WingTrail: Default
	{
		interval = 0.0003;
		colorCoef[]=
		{
			1,
			1,
			1,
			"(accelY interpolate [50,250,0,1]) * ((altitude*altitude) interpolate [400,40000,2,0.5])"
		};
	};
	/////////////////////////////////////////////////////////////
	//FIR
	class AAE_WingTrail_FighterJet_FIR: AAE_BodyTrail_FighterJet
	{
		lifeTime = 0.008;
		lifeTimeVar = 0.1;
		colorCoef[]=
		{
			1,
			1,
			1,
			"(accelY interpolate [80,100,0,0.08]) * ((altitude*altitude) interpolate [400,40000,1,0.5])"
		};
	};
	//Exhaust Effects
	/*class ExhaustSmoke1PlaneHP: Default
	{
		color[] = {{0.06,0.06,0.06,0.2},{0.1,0.1,0.1,0.04},{0.2,0.2,0.2,0.01},{0.3,0.3,0.3,0.001}};
		colorCoef[] = {"15","15","15","intensity/2 * (engineDamage interpolate [0.3,0.4,1,6]))"};
		size[] = {0.5,3};
	};*/
	class ExhaustSmokeRefractPlane: Default
	{
		interval = 0.1;
		colorCoef[] = {1,1,1,"(vehicleSpeedSize interpolate [0,60,0.2,1])*(vehicleSpeedSize interpolate [60,150,1,0])"};
		moveVelocity[] = {"speedX * 0.1","speedY * 0.1","speedZ * 0.1"};
		MoveVelocityVar[] = {1,1,1};
		size[] = {0.3,5,12,20,25,25,25};
		lifeTime = 5;
		weight = 1.8;
		volume = 1.1;
		//color[] = {{0.06,0.06,0.06,0.8},{0.3,0.3,0.3,0.7},{0.3,0.3,0.3,0.6},{0.3,0.3,0.3,0.65},{0.3,0.3,0.3,0.5},{0.3,0.3,0.3,0.4},{0.3,0.3,0.3,0}};
		color[] = {{0.3,0.3,0.3,0.8},{0.3,0.3,0.3,0.5},{0.3,0.3,0.3,0.3},{0.3,0.3,0.3,0.3},{0.3,0.3,0.3,0.25},{0.3,0.3,0.3,0.2},{0.3,0.3,0.3,0.16},{0.3,0.3,0.3,0.08},{0.3,0.3,0.3,0.02},{0.3,0.3,0.3,0}};
		bounceOnSurface = 0.1;
		bounceOnSurfaceVar = 0.01;
		rotationVelocity = 20;
	};
	//Weapons
	class MachineGun1: Default
	{
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 0;
		size[] = {2.4,3};
		rubbing = 0.01;
		color[] = {{0.85,0.85,0.85,0.15},{0.88,0.88,0.88,0.1},{0.9,0.9,0.9,0.08},{0.9,0.9,0.9,0.07},{0.9,0.9,0.9,0}};
		lifeTime = 3;
		sizeVar = 0.2;
		interval = "0.01/(vehicleSpeedSize interpolate [0,250,1,3])";
		animationSpeed[] = {1000};
		angleVar = 1;
		position[] = {"positionX","positionY","positionZ"};
		moveVelocity[]=
		{
			"directionX",
			"directionY",
			"directionZ"
		};
		positionVar[]=
		{
			0.1,
			0.1,
			0.1
		};
		MoveVelocityVar[]=
		{
			0,
			0,
			0
		};
		rotationVelocity = 1;
		rotationVelocityVar = 20;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
		sizeCoef = 1;
		colorCoef[] = {1,1,1,0.75};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.1;
	};
	class MachineGun2: Default
	{
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 0;
		size[] = {2.4,3};
		rubbing = 0.45;
		color[] = {{1,1,1,0.15},{1,1,1,0.06},{1,1,1,0.02},{1,1,1,0}};
		sizeCoef = 1;
		lifeTime = 3;
		sizeVar = 0.15;
		interval = 0.003;
		animationSpeed[] = {1000};
		moveVelocity[]=
		{
			"directionX",
			"directionY",
			"directionZ"
		};
		positionVar[]=
		{
			{0,0,0}
		};
		MoveVelocityVar[]=
		{
			{0,0,0}
		};
		rotationVelocity = 1;
		rotationVelocityVar = 20;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
		colorCoef[] = {1,1,1,0.75};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.1;
	};
	class MachineGun3: Default
	{
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 0;
		size[] = {2.4,3};
		rubbing = 0.01;
		color[] = {{0.85,0.85,0.85,0.15},{0.88,0.88,0.88,0.1},{0.9,0.9,0.9,0.08},{0.9,0.9,0.9,0.07},{0.9,0.9,0.9,0}};
		lifeTime = 3;
		sizeVar = 0.2;
		//interval = 0.0003;
		interval = "0.01/(vehicleSpeedSize interpolate [0,250,1,3])";
		animationSpeed[] = {1000};
		angleVar = 1;
		position[] = {"positionX","positionY","positionZ"};
		moveVelocity[]=
		{
			"directionX",
			"directionY",
			"directionZ"
		};
		positionVar[]=
		{
			0.1,
			0.1,
			0.1
		};
		MoveVelocityVar[]=
		{
			0,
			0,
			0
		};
		rotationVelocity = 1;
		rotationVelocityVar = 20;
		colorVar[] = {0,0,0,0};
		randomDirectionPeriodVar = 0;
		randomDirectionIntensityVar = 0;
		sizeCoef = 1;
		colorCoef[] = {1,1,1,0.75};
		animationSpeedCoef = 1;
		randomDirectionPeriod = 0.1;
		randomDirectionIntensity = 0.1;
	};
	
	//SAM
	class FX_MissileTrail_SAM_LongRange: Default
	{
		interval = 0.002;
		lifeTime = 12;
		size[] = {3,18,20,21,22,23,24,25,30,40};
		color[] = {{0.5,0.5,0.5,0.5},{0.6,0.6,0.6,0.3},{0.7,0.7,0.7,0.1},{0.8,0.8,0.8,0.04},{0.9,0.9,0.9,0.01},{0.9,0.9,0.9,0}};
		positionVarConst[] = {0.5,0.5,0.5};
		MoveVelocityVar[] = {0.4,0.4,0.4};
		rotationVelocity = 20;
		
		particleFSFrameCount=8;
	};
	
	//Missile
	class Missile3: Default
	{
		interval = 0.002;
		circleRadius = 0;
		circleVelocity[] = {0,0,0};
		angleVar = 1;
		
		particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
		particleFSNtieth = 16;
		particleFSIndex = 12;
		particleFSFrameCount = 8;
		particleFSLoop = 0;
		
		animationName = "";
		particleType = "Billboard";
		timerPeriod = 1;
		lifeTime = 5;
		moveVelocity[] = {0,0,0};
		rotationVelocity = 1;
		weight = 1;
		volume = 0.8;
		rubbing = 0.5;
		size[] = {2.8,4,6,8,12,15,25};
		color[] = 
		{
			{0.9,0.9,0.9,0.003},
			{0.5,0.5,0.5,0.04},
			{0.6,0.6,0.6,0.1},
			{0.7,0.7,0.7,0.05},
			{0.7,0.7,0.7,0.01},
			{0.8,0.8,0.8,0}
		};
		animationSpeed[] = {1};
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
	class AAE_Short_Missile: Missile3
	{
		lifeTime = 3;
	};
	class Missile4: Default
	{
		lifeTime = 4;
		size[] = {0.8,1.5,2,3};
		color[] = 
		{
			{0.9,0.9,0.9,0.003},
			{0.5,0.5,0.5,0.04},
			{0.7,0.7,0.7,0.08},
			{0.7,0.7,0.7,0.03},
			{0.7,0.7,0.7,0.01},
			{0.8,0.8,0.8,0}
		};
		rotationVelocityVar = 20;
	};
	
	//AAE
	/*class AAE_Vapor_Trail: Default
	{
		interval=0.025;
		particleShape="\A3\Data_F\ParticleEffects\Universal\Universal";
		particleFSNtieth=16;
		particleFSIndex=12;
		particleFSFrameCount=8;
		particleFSLoop=0;
		particleType="Billboard";
		animationName="";
		animationSpeed[]={1000};
		timerPeriod=0;
		lifeTime=20;
		position[]={0,0,-5};
		moveVelocity[]={0,0,0};
		rotationVelocity=1;
		weight=1.25;
		volume=1;
		rubbing=0.01;
		size[]={6,15,25,30,40};
		color[]=
		{
			{0.7,0.8,1,0},
			{0.7,0.8,1,0.3},
			{0.7,0.8,1,0.5},
			{0.7,0.8,1,0.3},
			{0.7,0.8,1,0.2},
			{0.7,0.8,1,0.1},
			{0.7,0.8,1,0}
		};
		lifeTimeVar=2;
		positionVar[]={2,0.5,2};
		positionVarConst[]={1,0.1,1};
		MoveVelocityVar[]={0.4,0.4,0.4};
		sizeVar=0.5;
		MoveVelocityVarConst[]={0,0,0};
		randomDirectionPeriod=0;
		randomDirectionIntensity=0;
		angleVar=1;
	};*/
};