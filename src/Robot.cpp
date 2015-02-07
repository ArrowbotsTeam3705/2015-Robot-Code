#include "WPILib.h"
#include "math.h"

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
class Robot: public SampleRobot
{
	RobotDrive myRobot; // robot drive system
	//Joystick leftStick; // joystick 1
	//Joystick rightStick;//joystick 2
	Joystick controller;
	Talon forkLift;
	Solenoid leftHook;
	Solenoid rightHook;
	DigitalInput limitSwitch;
	Timer pulleyTimer;
	Timer pneumaticTimer;
	bool forkLiftForward;
	bool forkLiftBackward;
	bool timerSet;
	unsigned int secondsForPulley;
	double secondsForPneumatic;

	//DoubleSolenoid leftHook;
	//DoubleSolenoid rightHook;
public:
	Robot() :
			myRobot(0, 1),	// these must be initialized in the same order
			controller(0),
			forkLift(2),
			leftHook(0),
			rightHook(1),// as they are declared above.
			limitSwitch(0)
			//leftHook(1,2),
			//rightHook(3,4)
	{
		myRobot.SetExpiration(0.1);
		forkLiftForward=false;
		forkLiftBackward=false;
		timerSet=false;
		secondsForPulley=5;
		//microseconds is in microseconds so to get 5 seconds we do 5*(10^6)
		secondsForPneumatic=1;
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
	void OperatorControl()
	{
		myRobot.SetSafetyEnabled(true);
		while (IsOperatorControl() && IsEnabled())
		{
			myRobot.ArcadeDrive(controller,false); // drive with arcade style (use left stick) without squared inputs
			if((controller.GetRawAxis(3)>0.1)&&timerSet==false){
				forwardsPulley();
			}
			else if((controller.GetRawAxis(3)<-0.1)&&timerSet==false){
				backwardsPulley();
			}
			else if(timerSet==false){
				stopPulley();
			}
			SmartDashboard::PutBoolean("Is Pulley Timer Set?",timerSet);
			SmartDashboard::PutBoolean("Is Pneumatic Timer Started?",(pneumaticTimer.Get()>0));
			//if button 3 on the controller is pressed and the timer on the pneumatic is not running
			if(controller.GetRawButton(3)&&!(pneumaticTimer.Get()>0)){
				if(leftHook.Get()){
					leftHook.Set(false);
					rightHook.Set(false);	//disables the solenoid output
				}else{
					leftHook.Set(true);		//enables the leftHook and the rightHook
					rightHook.Set(true);
				}
				pneumaticTimer.Start();
			}else if(pneumaticTimer.Get()>secondsForPneumatic){
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
