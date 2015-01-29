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
	Timer timer;
	bool forkLiftForward;
	bool forkLiftBackward;
	bool timerSet;
	unsigned int seconds;
	unsigned long microseconds;

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
		seconds=5;
		//microseconds is in microseconds so to get 5 seconds we do 5*(10^6)
		microseconds=seconds*pow(10.0,6.0);
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
			myRobot.ArcadeDrive(controller); // drive with arcade style (use left stick)
			if((controller.GetRawAxis(3)>0.1)&&timerSet==false){
				forwardsPulley();
			}
			else if((controller.GetRawAxis(3)<-0.1)&&timerSet==false){
				backwardsPulley();
			}
			else if(timerSet==false){
				stopPulley();
			}
			if(controller.GetRawButton(2)&&timerSet==false){
				forwardsPulley();
				timerSet=true;
				timer.Start();
				//forkLiftForward=true;
			}
			if(controller.GetRawButton(1)&&timerSet==false){
				backwardsPulley();
				timer.Start();
				timerSet=true;
			}
			if(timerSet==true&&timer.Get()>seconds){
				timer.Stop();
				timer.Reset();
				stopPulley();
				timerSet=false;
			}
			/*if(leftStick.GetRawButton(4)){
				forkLiftForward=true;
				if(forkLiftBackward==true){
					forkLiftBackward=false;
				}
			}
			if(leftStick.GetRawButton(5)){
				forkLiftBackward=true;
				if(forkLiftForward==true){
					forkLiftForward=false;
				}
			}
			if(leftStick.GetRawButton(2)){
				forkLiftForward=false;
				forkLiftBackward=false;
			}
			if(forkLiftForward==true&&forkLiftBackward==false){
				forkLift.Set(0.75);
			}
			if(forkLiftBackward==true&&forkLiftForward==false){
				forkLift.Set(-0.5);
			}
			if(forkLiftForward==false&&forkLiftBackward==false){
				forkLift.Set(0);
			}*/
			if(controller.GetRawButton(3)){
				if(leftHook.Get()){
					leftHook.Set(false);
					rightHook.Set(false);	//disables the solenoid output
				}else{
					leftHook.Set(true);		//enables the leftHook and the rightHook
					rightHook.Set(true);
				}
			}
			/*while (limitSwitch.Get())
			{
				Wait(0.005);
				if ((limitSwitch.Get())>0)
				{
					leftHook.Set(0.5);
					// exampleLed.Set(1);
				}
				else
				{
					leftHook.Set(0.5);
				}
			}*/
			  /*if(rightStick.GetRawButton(3)){
			  	leftHook.Set(DoubleSolenoid::kForward);	//make the solenoids go forward
			  	rightHook.Set(DoubleSolenoid::kForward);
			  }
			  else if(rightStick.GetRawButton(4)){
			  	leftHook.Set(DoubleSolenoid::kReverse);	//make the solenoids go back
			  	rightHook.Set(DoubleSolenoid::kReverse);
			  }
			  else{
			  	leftHook.Set(DoubleSolenoid::kOff);		//turn the solenoid off
			  	rightHook.Set(DoubleSolenoid::kOff);
			  }*/
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
