#include "WPILib.h"
#include <string>

using std::string;

/**
 * This is a demo program showing the use of the RobotDrive class.
 * The SampleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're inexperienced,
 * don't. Unless you know what you are doing, complex code will be much more difficult under
 * this system. Use IterativeRobot or Command-Based instead if you're new.
 */
//Author Name:Javed Nissar
//Purpose:Classified
//Date:February 13,2070
/*
                                   .'########:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ,## `#######
                                ;############+:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::, ##` #######.
                             ,################::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  ##  #######
                           :###################:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ;#' ,######+
                         .#####################:::::::::::::::::::::::::::::::::::::'+;::::::::::::::::::::::::::::::::::::::'++;::::::::::::::::::::::::::::::. ##  #######`
                        #######################+::::::::::::::::::::::::::::::::::;#####:::::######+::::::#######::::::::::#######+:::::::#:::::::::::::#;:::::: `##  #######
                      `#########################::::::::::::::::::::::::::::::::::#':::#+:::::'#::;##::::::;#::;##::::::::##:::::;##::::::#;::::::::::::#:::::::: +#: '######'
                     '##########################:::::::::::::::::::::::::::::::::+#:::::#:::::'#::::##:::::;#::::##::::::#+::::::::##:::::+#:::::::::::+#::::::::` ##  #######
                    ############################:::::::::::::::::::::::::::::::::#':::::#:::::'#:::::#:::::;#:::::#;::::##::::::::::#+:::::#:::::::::::#'::::::::: .## `#######
                   #############################:::::::::::::::::::::::::::::::::#':::::#:::::'#:::::#+::::;#:::::+#:::;#:::::::::::;#:::::#:::::+:::::#::::::::::: ##. +######,
                  '. ###########################:::::::::::::::::::::::::::::::::#':::::#:::::'#:::::+#::::;#:::::'#:::#+::::::::::::#;::::#+::::#::::'#:::::::::::  ##  #######
              ;##`  +###########################:::::::::::::::::::::::::::::::::#':::::#:::::'#:::::+#::::;#:::::'#:::#:::::::::::::+#::::;#::::#;:::#+:::::::::::: ;#+ ,######+
          `#####,   ############################:::::::::::::::::::::::::::::::::#':::::#:::::'#:::::#'::::;#:::::#+:::#:::::::::::::;#:::::#:::'##:::#:::::::::::::. ##` #######`
           ####+   ;###########################':::::::::::::::::::::::::::::::::#':::::#:::::'#:::::#:::::;#:::::#::::#:::::::::::::;#:::::#+::#+#::;#:::::::::::::: `##  #######
           `###      ,#########################::::::::::::::::::::::::::::::::::#':::::#:::::'#::::#+:::::;#::::##::::#:::::::::::::'#:::::'#::#:#::#+::::::::::::::: +#: '######'
            ##`        .#######################:::::::::::::::::::::::::::::::::;#';;;;;#:::::'#;;+##::::::;#;;+##:::::#;::::::::::::#+::::::#:;#:#+:#::::::::::::::::` ##  #######
             #           ,#####################:::::::::::::::::::::::::::::::::#########:::::'####;:::::::;####'::::::+#::::::::::::#:::::::#'#+:;#:#::::::::::::::::: .## `#######
             `   #+        '##################;::::::::::::::::::::::::::``::::::#':::::#:::::'#:##::::::::;#:+#::::::::#:::::::::::+#:::::::+##:::#+#:::::::::::::::::: ##. +######,
            .#  '####:       #################:::::::::::::::::::::::::::.  :::::#':::::#:::::'#::##:::::::;#::##:::::::+#:::::::::;#:::::::::##:::##;::::::::::::::::::` ##  #######
            ##` #######'      '###############:::::::::::::::::::::::::::.   ,:::#':::::#:::::'#:::#'::::::;#:::#+:::::::##:::::::'#+:::::::::##:::'#:::::::::::::::::::: :#+ ,#######
           `###+#########;     ,#############+:::::::::::::::::::::::.        `::#':::::#:::::'#:::;#::::::;#::::#;:::::::###;::'##'::::::::::+;::::#::::::::::::::::::::, ##` #######.
           ################,    ,############:::::::::::::::::::::,            ::#':::::#:::::'#::::##:::::;#::::'#::::::::;######::::::::::::::::::'::::::::::::::::::::: `##  #######
           #########.########    :###########:::::::::::::::::::`             ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: '#; ;######+
          ,########,  :#######.   '##########:::::::::::::::::.       `.::.  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::. ##  #######
          #########     +######'   #########'::::::::::::::::     .:::::::, ::::::''''''':::::::::::::::::;######'::::::::::::'''''''''':::::::::###+::::::::::::::::::::::: `## `#######
          #########      `#######   ########:::::::::::::::,   `:::::::::::,::::::+########:::::::::::::;##########'::::::::::##########:::::::+######;:::::::::::::::::::::: ##. +######:
          ########'        '######  .#######::::::::::::::`  `::::::::::::::::::::+#;;;;'###:::::::::::+###;:::::####:::::::::;;;;##;;;;::::::'##;::'##::::::::::::::::::::::` ##  #######
         ,########;         `######  #######:::::::::::::   ::::::  ,:::::::::::::+#::::::##::::::::::###::::::::::###::::::::::::##::::::::::##::::::#::::::::::::::::::::::: :#+ .#######
         +########+           ######  #####+::::::::::::  ,::::.     :::::::::::::+#::::::;#;::::::::+##::::::::::::+##:::::::::::##:::::::::;#'::::::::::::::::::::::::::::::, ##` #######.
         ##########            ;##### '####;:::::::::::  ::::`       ,::::::::::::+#:::::::#'::::::::##::::::::::::::##'::::::::::##:::::::::+#::::::::::::::::::::::::::::::::  ##  #######
         ##########             .##### ####::::::::::: .:::          .::::::::::::+#::::::'#;:::::::##::::::::::::::::##::::::::::##:::::::::##::::::::::::::::::::::::::::::::: '#; ;######+
         ##########.             `#####+###:::::::::: :::`           ,::::::::::::+#::::::##::::::::##::::::::::::::::'#':::::::::##:::::::::+#:::::::::::::::::::::::::::::::::. ##  #######
         ###########               ########:::::::::`::`             :::::::::::;##########;:::::::+#::::::::::::::::::##:::::::::##::::::::::##::::::::::::::::::::::::::::::::: `## `#######
         ###########                #######::::::::.::              .:::::::::::###########::::::::##::::::::::::::::::##:::::::::##::::::::::##'::::::::::::::::::::::::::::::::: ##, '######;
         ############              ;#######:::::::::`               ::::::::::::::+#:::::###;::::::##::::::::::::::::::+#:::::::::##:::::::::::###+::::::::::::::::::::::::::::::. ##  #######
         ############.          ,##########::::::::::`             :::::::::::::::+#::::::;##::::::##::::::::::::::::::;#;::::::::##::::::::::::#####+::::::::::::::::::::::::::: ;#' :######+
         #############`     `'#############::::::::::::::.        ::::::::::::::::+#:::::::'##:::::#+::::::::::::::::::;#;::::::::##::::::::::::::'####:::::::::::::::::::::::::  ##  #######
         ##################################:::::::::::::::::::::::::::::::::::::::+#::::::::##:::::##::::::::::::::::::;#;::::::::##:::::::::::::::::###:::::::::::::::::::::::, ##` #######,
         ###################################::::::::::::::::::::::::::::::::::::::+#::::::::'#:::::##::::::::::::::::::+#:::::::::##::::::::::::::::::##;:::::::::::::::::::::: ,## .#######
         '########,+########################::::::::::::::::::::::::::::::::::::::+#:::::::::#'::::##::::::::::::::::::##:::::::::##:::::::::::::::::::##:::::::::::::::::::::` ##  #######
         .######' ##########################':::::::::::::::::::::::::::::::::::::+#:::::::::#'::::+#::::::::::::::::::##:::::::::##:::::::::::::::::::##::::::::::::::::::::: ##, +######;
          ###### ####' ######################:::::::::::::::::::::::::::::::::::::+#::::::::;#;:::::##::::::::::::::::'#':::::::::##:::::::::::::::::::##:::::::::::::::::::: `##  #######
          ##### ####.  `######################::::::::::::::::::::::::::::::::::::+#::::::::+#::::::##::::::::::::::::##::::::::::##:::::::::::::::::::##:::::::::::::::::::. ##  #######
          #########.    ######################+:::::::::::::::::::::::::::::::::::+#::::::::##:::::::##::::::::::::::##'::::::::::##::::::::;#;::::::::##::::::::::::::::::: '#; :######+
          .########      ######################+::::::::::::::::::::::::::::::::::+#:::::::##':::::::+##::::::::::::+##:::::::::::##:::::::::##:::::::;#+::::::::::::::::::  ##  #######
           #########     `######################+:::::::::::::::::::::::::::::::::+#::::::+##:::::::::###::::::::::###::::::::::::##:::::::::##'::::::##::::::::::::::::::, ##` #######.
           +###### #      .#######################::::::::::::::::::::::::::::::::+#;;;;+###:::::::::::+###::::::+###:::::::::::::##::::::::::###:::;##':::::::::::::::::: :## .#######
            ######  ;       ########################::::::::::::::::::::::::::::::+#######+:::::::::::::;##########'::::::::::::::##:::::::::::#######'::::::::::::::::::` ##  #######
            ######  ``       +########################'::::::::::::::::;##::::::::'++++';:::::::::::::::::;######;::::::::::::::::++::::::::::::'###+:::::::::::::::::::: ##. +######:
            `#####.  :.       `############################+';;;;''+#####::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: .##  #######
             ######    #         '#######################################::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::. ##  #######
              #####     ``          ,###################################::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: '#; ;######+
              :#####                     `:'###########################+::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  ##  #######
               #####`                                    +#############::##########################################################################################::, ##` #######.
                #####                                    #############::;###################;;;##;;;###':#######'######;;;+#+;;;###':;####;;;#####################+:: :#+ ,#######
                `#####                                  `############;::#####################;###:####+##:##:##+:########;#####+##:###;##+########################::` ##  #######
                 ,#####                                ;############'::######################;###:####'##;###'#;:########'####'##'#####:#+#######################;:: ##. +######:
                  :#####                           ,;',,###########+::#######################;##+:+###'##;###+:#:#######;:####:##:#####+#+;:+####################:: .##  #######
                   :#####,                            `###########'::########################;###:####'##;######:#########:###'##:#####+####+###################::. ##  #######
                    ,######.                         .###########'::#########################;###:####::::######:#########'##+###:#####:#####'#################':: +#; ;######'
                     `#######'`                    ,############;::##########################;###:####'##;######:######+##:##:####'####'#####+#################:: `##  #######
                       ##########+;.`     ``.:;+###############:::###########################:###:::##'##;######:######+;:###'#####:';'###:;;#################::, ##` #######.
                        :####################################':::############################################################################################+:: :#+ ,#######
                          +#################################::::;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;::  ##  #######
                            +#############################::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ##. #######,
                              '########################+:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: .## `#######
                                `'##################+::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::` ##  #######
                                    `:+#########':::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: +#: '######'
*/
class Robot: public SampleRobot
{
	RobotDrive myRobot; // robot drive system
	Joystick controller; //gamepad used for controlling robot
	Talon forkLift; //Talon motor that controls forkLift
	//pneumatic solenoids for controlling two hooks
	Solenoid leftHook;
	Solenoid rightHook;
	//timer that ensures that input is not processed too quickly
	Timer pneumaticTimer;
	//two limit switches that act as endpoints for the robot
	DigitalInput topSwitch;
	DigitalInput middleSwitch;
	DigitalInput bottomSwitch;
	//counters measuring the number of times the limit switch has been hit
	Counter topCounter;
	Counter bottomCounter;
	//encoder for driving the robot
	Encoder driveEncoder;
	Joystick forkLiftControl;                                                                                                                                                                          //Lol, Jesus does water tricks
	Relay indicator;
	//Jawad was here
	//amount of time that must occur between inputs for pneumatic
	double secondsForPneumatic;
	//boolean controlling whether or not robot is inverted
	bool inverted;
	//boolean stating whether forklift should be moved upwards
	bool moveForkliftUp;
	//boolean stating whether forklift should be moved downwards
	bool moveForkliftDown;
public:
	Robot() :
			myRobot(0, 1),	// these must be initialized in the same order
			controller(0),
			forkLift(2),
			leftHook(0),
			rightHook(1),
			topSwitch(1),
			middleSwitch(2),
			bottomSwitch(0),
			//limit switches must be passed to counter as pointers
			topCounter(&topSwitch),
			bottomCounter(&bottomSwitch),
			driveEncoder(7,8),
			forkLiftControl(1),// as they are declared above.
			indicator(0)
	{
		myRobot.SetExpiration(0.1);
		inverted=false;
		secondsForPneumatic=0.5;
		//robot travels x feet in y revolutions with each revolution producing z pulses
		//thus, the distance per pulse is (x/yz) feet/pulse
		const int z=231;
		const double y=10;
		const double x=12;
		driveEncoder.SetDistancePerPulse(x/(y*z));
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
		driveEncoder.Reset();
		moveForkliftUp=true;
		moveForkliftDown=false;
		rightHook.Set(false);
		leftHook.Set(false);
		//targetDistance is the distance that the robot is supposed to travel in feet
		const double targetDistance=13.583333;
		while(IsAutonomous()&&IsEnabled()){
			if(driveEncoder.GetDistance()<targetDistance){
				myRobot.ArcadeDrive(0.5,0);
			}
			if(moveForkliftUp){
				forkLift.Set(0.3);
				if(!middleSwitch.Get()){
					moveForkliftDown=true;
				}
			}else if(moveForkliftDown){
				forkLift.Set(-0.3);
				if(!bottomSwitch.Get()){
					forkLift.Set(0);
					moveForkliftDown=false;
				}
			}
			Wait(0.005);
		}
	}
	void stopPulley(){
		forkLift.Set(0);
	}
	string YesOrNo(bool value){
		if(value){
			return "Yes";
		}else{
			return "No";
		}
	}
	string CanHooksBeMoved(){
		return YesOrNo(pneumaticTimer.Get()>0);
	}
	void OperatorControl()
	{
		myRobot.SetSafetyEnabled(true);
		driveEncoder.Reset();
		while (IsOperatorControl() && IsEnabled())
		{
			//if inverted, then invert drive and if not inverted, then don't
			if(inverted){
				myRobot.ArcadeDrive(controller.GetY()*0.5,controller.GetZ()*0.75);
				//run motors at maximum of 50% to prevent jerkiness and ensure smooth driving
			}else{
				myRobot.ArcadeDrive(-controller.GetY()*0.5,-controller.GetZ()*0.75); // drive with arcade style (use left stick of controller) without squared inputs
			}
			/*if button 13 on the controller is pressed (home button on the red controller used by team 3705),
			 * make controller inverted if it is not inverted and not inverted if it is inverted
			 */
			if(controller.GetRawButton(13)){
				if(inverted){
					inverted=false;
				}else{
					inverted=true;
				}
			}
			/*if the middle switch is being hit, then the forklift is in the correct position for initiating the locks.
			 *A not operation is performed on the output of the limit switch because the limit switch is wired as open by default;
			 * hence, it returns a 1 when not hit and a 0 when hit
			 */
			if(!middleSwitch.Get()){
				indicator.Set(Relay::kForward);
			}
			//if the topCounter is not being hit, then the locks should not be initiated.
			else{
				indicator.Set(Relay::kOff);
			}
			/*when you move the right stick of controller upwards and the top switch has not been triggered, the pulley will move upwards
			 *the motor of the pulley will be at 75% forwards. The top switch must not be triggered in order to prevent any damage from being done to the robot.
			 *the need for it to be above 0.1 is to accommodate the drift of the right stick of the controller (joystick value is never 0)
			 */
			double forkLiftControlY=forkLiftControl.GetY();
			if((forkLiftControlY>0.1)&&topSwitch.Get()){
				forkLift.Set(forkLiftControlY);
				bottomCounter.Reset();
			}
			/*
			 * when you move right stick of controller downwards and the bottom switch has not been triggered, the pulley will move downwards
			 * the motor of the pulley will be at 50% reverse. The bottom switch must not be triggered in order to prevent any damage from being done to the robot.
			 */
			else if((forkLiftControlY<-0.1)&&bottomSwitch.Get()){
				forkLift.Set(forkLiftControlY);
				topCounter.Reset();
			}
			//when right stick of controller is left alone, motor will not exert force on pulley; thus, causing the pulley to drift downwards.
			else{
				stopPulley();
			}
			//state whether tote is in correct position based on the middle switch (which is connected to port 2)
			SmartDashboard::PutString("Is Tote In Correct Position?",YesOrNo(middleSwitch.Get()));
			SmartDashboard::PutNumber("Distance covered by robot (in feet)",driveEncoder.GetDistance());

			//provide status on whether or not hooks can be moved
			SmartDashboard::PutString("Can I press the trigger on the joystick to move hooks?",CanHooksBeMoved());
			//states whether or not controls are inverted
			SmartDashboard::PutString("Are the controls inverted?",YesOrNo(inverted));
			//if button 1 on the joystick is pressed (the trigger on the default FRC joystick) and the timer on the pneumatic is not active
			//this is meant to prevent the hooks from bouncing by ensuring that the button input is not taken at all times
			if(forkLiftControl.GetRawButton(1)&&!(pneumaticTimer.Get()>0)){
				if(leftHook.Get()){
					leftHook.Set(false);
					rightHook.Set(false);	//moves left hook and right hook back to default position
				}else{
					leftHook.Set(true);		//moves left hook and right hook forwards
					rightHook.Set(true);
				}
				pneumaticTimer.Start();
			}else if(pneumaticTimer.Get()>secondsForPneumatic){
				//stop and reset timer to enable buttons to operate
				pneumaticTimer.Stop();
				pneumaticTimer.Reset();
			}

			Wait(0.005);			// wait for motor update time
		}
	}

	/**
	 * Runs during test mode
	 */
	void Test()
	{
	}
};

START_ROBOT_CLASS(Robot);

