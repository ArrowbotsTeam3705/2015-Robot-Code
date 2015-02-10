#include "WPILib.h"
#include <string>

using std::string;

//Written by Javed Nissar with some help from Fayaad/Harry/Gorgin/Jay
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
	DigitalInput bottomSwitch;
	//counters measuring the number of times the limit switch has been hit
	Counter topCounter;
	Counter bottomCounter;
	Joystick forkLiftControl;
	//amount of time that must occur between inputs for pneumatic
	double secondsForPneumatic;
	//boolean controlling whether or not robot is inverted
	bool inverted;

public:
	Robot() :
			myRobot(0, 1),	// these must be initialized in the same order
			controller(0),
			forkLift(2),
			leftHook(0),
			rightHook(1),
			topSwitch(1),
			bottomSwitch(0),
			//limit switches must be passed to counter as pointers
			topCounter(&topSwitch),
			bottomCounter(&bottomSwitch),
			forkLiftControl(1)// as they are declared above.
	{
		myRobot.SetExpiration(0.1);
		inverted=false;
		secondsForPneumatic=0.5;
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void Autonomous()
	{
		myRobot.SetSafetyEnabled(false);
		myRobot.Drive(-0.5, 0.0); 	// drive forwards half speed
		Wait(2.0); 				//    for 2 seconds
		myRobot.Drive(0.0, 0.0); 	// stop robot
	}

	/**
	 * Runs the motors with arcade steering.
	 */
	void forwardsPulley(){
		forkLift.Set(0.75);
	}
	void backwardsPulley(){
		forkLift.Set(-0.5);
	}
	void stopPulley(){
		forkLift.Set(0);
	}
	string CanHooksBeMoved(){
		if(pneumaticTimer.Get()>0){
			return "No";
		}else{
			return "Yes";
		}
	}
	void OperatorControl()
	{
		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl() && IsEnabled())
		{
			//if inverted, then invert drive and if not inverted, then don't
			if(inverted){
				myRobot.ArcadeDrive(controller.GetY(),controller.GetZ());
			}else{
				myRobot.ArcadeDrive(-controller.GetY(),-controller.GetZ()); // drive with arcade style (use left stick of controller) without squared inputs
			}
			//if button 7 on controller is pressed (left trigger on Maninder's controller), make controller inverted if it is not inverted and not inverted if it is inverted
			if(controller.GetRawButton(13)){
				if(inverted){
					inverted=false;
				}else{
					inverted=true;
				}
			}
			/*when you move the right stick of controller upwards and the top switch has not been triggered, the pulley will move upwards
			 *the motor of the pulley will be at 75% forwards. The top switch must not be triggered in order to prevent any damage from being done to the robot.
			 *the need for it to be above 0.1 is to accommodate the drift of the right stick of the controller (joystick value is never 0)
			 */
			if((forkLiftControl.GetY()>0.1)&&(topCounter.Get()==0)){
				forkLift.Set(forkLiftControl.GetY());
				bottomCounter.Reset();
			}
			/*
			 * when you move right stick of controller downwards and the bottom switch has not been triggered, the pulley will move downwards
			 * the motor of the pulley will be at 50% reverse. The bottom switch must not be triggered in order to prevent any damage from being done to the robot.
			 */
			else if((forkLiftControl.GetY()<-0.1)&&(bottomCounter.Get()==0)){
				forkLift.Set(forkLiftControl.GetY());
				topCounter.Reset();
			}
			//when right stick of controller is left alone, motor will not exert force on pulley; thus, causing the pulley to drift downwards.
			else{
				stopPulley();
			}
			SmartDashboard::PutNumber("Top switch",topCounter.Get());
			SmartDashboard::PutNumber("Bottom switch",bottomCounter.Get());
			//provide status on whether or not hooks can be moved
			SmartDashboard::PutString("Can I press right trigger to move hooks",CanHooksBeMoved());
			//provide status on whether or not controls are inverted
			SmartDashboard::PutBoolean("inverted",inverted);
			//if button 8 on the controller is pressed (the right trigger on Maninder's red controller) and the timer on the pneumatic is not active
			//this is meant to prevent the hooks from bouncing by ensuring that the button input is not taken at all times
			if(forkLiftControl.GetRawButton(3)&&!(pneumaticTimer.Get()>0)){
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
