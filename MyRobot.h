#include "iostream.h"
#include "WPILib.h"
#include "Fin.h"
#include "WeaytShifter.h"

class RobotDemo: public IterativeRobot { 

public:
	RobotDemo(void); // as they are declared above.	
	Timer* timer;
	Victor* frontLeftMotor;
	Victor* rearLeftMotor;
	Victor* frontRightMotor;
	Victor* rearRightMotor;
	// robot drive system
	Joystick* leftStick;
	Joystick* rightStick;
	Joystick* operatorStick;
	Lift* lift;
	Fin* fin;
	WeaytShifter* weight;
	
	void RobotInit();
	void Autonomous(void);
	void TeleopPeriodic();
	void Test();	
	void controlTankDrive(double percent);	
    void tankDrive(double left, double right, double percent);	 
	void tankDrive(double left, double right);	 		  
	void Disabled();	 
	void stop();
	void control();	
	Joystick* getLeftStick();

	Joystick* getRightStick();

	Joystick* getOperatorStick();
				


	
	
	
};
