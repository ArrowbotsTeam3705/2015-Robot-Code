#include "WPILib.h"
#include <string>

using std::string;

//Written by Javed Nissar with some help from Fayaad/Jay/Harry
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
If you are at any point disturbed by the code below, please stare at
the safety pig.
                         _
 _._ _..._ .-',     _.._(`))
'-. `     '  /-._.-'    ',/
   )         \            '.
  / _    _    |             \
 |  a    a    /              |
 \   .-.                     ;
  '-('' ).-'       ,'       ;
     '-;           |      .'
        \           \    /
        | 7  .__  _.-\   \
        | |  |  ``/  /`  /
       /,_|  |   /,_/   /
          /,_/      '`-'
*/
class Robot: public SampleRobot
{
	RobotDrive myRobot; // robot drive system
	Joystick controller;
	Talon forkLift;
	Solenoid leftHook;
	Solenoid rightHook;
	Timer pneumaticTimer;
	unsigned int secondsForPulley;
	double secondsForPneumatic;

public:
	Robot() :
			myRobot(0, 1),	// these must be initialized in the same order
			controller(0),
			forkLift(2),
			leftHook(0),
			rightHook(1)// as they are declared above.
	{
		myRobot.SetExpiration(0.1);
		secondsForPulley=5;
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
			myRobot.ArcadeDrive(controller,false); // drive with arcade style (use left stick of controller) without squared inputs
			/*when you move the right stick of controller upwards, the pulley will move upwards
			 *the motor of the pulley will be at 75% forwards
			 *the need for it to be above 0.1 is to accommodate the drift of the right stick of the controller (joystick value is never 0)
			 */
			if(controller.GetRawAxis(3)>0.1){
				forwardsPulley();
			}
			/*
			 * when you move right stick of controller downwards, the pulley will move downwards
			 * the motor of the pulley will be at 50% reverse
			 */
			else if(controller.GetRawAxis(3)<-0.1){
				backwardsPulley();
			}
			//when right stick of controller is left alone, motor will not exert force on pulley; thus, causing the pulley to drift downwards.
			else{
				stopPulley();
			}
			//provide status on whether or not hooks can be moved
			SmartDashboard::PutString("Can I press right trigger to move hooks",CanHooksBeMoved());
			//if button 8 on the controller is pressed (the right trigger on Maninder's red controller) and the timer on the pneumatic is not active
			//this is meant to prevent the hooks from bouncing by ensuring that the button input is not taken at all times
			if(controller.GetRawButton(8)&&!(pneumaticTimer.Get()>0)){
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
			Wait(0.005);			// wait for a motor update time
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
