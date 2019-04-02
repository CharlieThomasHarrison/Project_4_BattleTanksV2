BattleTanksV2
An Open terrain Tank V Tank game (Single player) made in Unreal Engine (V4.20.2 and above)
Project made along side a Udemy corse (The Unreal Engine Developer Course - Learn C++ & Make Games)

## Updates:
* BT01: Setup of SourceTree and Unreall engine Project
* BT02: Game Design Document (GDD)
* BT03: Seting up in GitHub "repo"
* BT04: Seting up Unreal Engine Project files
* BT05: Version 1 of the game terrain 
* BT06: Terrein Texture V1 applied Terrien made V1
* BT07: Import of Tank mesh and contruction of the Tank BluePrint
* BT08: V1 implment of spring arm camera and X & Y Camera controls/ V1 Default gamemode: free-for-all
* BT09: Camera V2: Changes and improvements to spring arm & added scene root
* BT10: Created a Aiming UI & updated Gamemode
* BT11: UI V1: Created basic meanmenu and fading background with minmal fuction
* BT12: UI V1.1: Finshed first pass at Meanmenu (Font, changeing buttons/backgrounds and interative buttons)
* BT13: Switch over core class to custume C++ code
* BT14: Make a AIController for tanks placed in worlf and find the players Pawn print to console
* BT15: Event Tick added to C++ PlayerController begining work stared on Aiming the Tank class at UI crosshair
* BT16: GetSightRayHitLocation consturcted
* BT17: C++ Crosshair location in pixel found and printed to log
* BT18: Forward diraction found and printed to log
* BT19: Raytraceing and print to log location hit
* BT20: Add AimAt fuction to Tank pawn for player/AI
* BT21: AimingComponent Added to Tank BP thorugh C++ and all items todo with aiming moveing to this Component
* BT22: Soft codeing of the barrel reference and well as print to log location of attached barral to its owner tank
* BT23: Lunch speed of tank cannon avaible in blueprint and printed out to log 
* BT24: SuggestProjectileVelocity implermented into code and socket add to barrel mode
* BT25: TankAimComponent printing to log the corret FRotator for aiming the tank barrel 
* BT26: Cration of the TankBarrel c++ class and conversion of other class to use TankBarrel
* BT27: Min/Max Elevation vaules add to barrel in-engine for easy of use
* BT28: turn off ticks on certin tank C++ classes also log out bug involeing Aim Soltion not being found
* BT29: move header file metions to forward declaration
* BT30: Clamp used to limit vaules to allow barrel to move up and down 
* BT31: My creation of the Tank Turret Roation code 
* BT32: final Commit of turret Roation cleaned up code and chnage tick on TankAimingComponent
* BT33: Added Projectile C++ class and fireing abilty to Tank C++ classs resulting in print to log 
* BT34: Basic spawning of projectile at the end of Barrel
* BT35: Projectile Movement Components added to projectile class/BP and Tank now fireing Projectile at launch speed

* BT36: Makeing AI Tanks fire added Fireing to all tanks aswell as reload timer and can fire bool

* BT37: EditAnywhere vs EditDefaultsOnly Chnaged over code from EditAnywhere to EditDefaultsonly as default
* BT38: Removed collision from Barrel & Turret and added new box collision To TankBP

* BT39: Setup Track Throttles made TankTrack C++ class and added it TankBP/ Printed out to log Player controller input

* BT40: ApplyForceAtLocation() in Action added Force to the loction of Each track allowing tank to move but cant as friction in game is to high
* BT41: Physics Materials & Friction Added Movment to tanks through Left & Right tracks aswell as added a phys Material for tracks
* BT42: TankMovementComponent C++ class added
* BT43: Using BlueprintReadOnly conneting Input with intend forward movement fuction

* BT44: A Better Component Architecture added extra controll to the tank with num keys to allow forward/backward movment through one key
* BT45: Completing Manual Tank Movement added left and right turn to tank controlles throught tankmovementComponent
* BT46: Added Navi mesh to landscape
* BT47: Dissecting RequestDirectMove() Print to log where the AI Tanks are trying to reach to hit the player 
* BT48: CrossProduct() Vector Operator AITanks now move
* BT49: Finalising Your Class Code Moveing tanks added to the game 
