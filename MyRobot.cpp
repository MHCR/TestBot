#include "MyRobot.h"

/**
 * This is a demo program showing the use of the RobotBase class.
 * The SimpleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 */




	RobotDemo::RobotDemo(void) // as they are declared above.
	{
		lift = new Lift();		
		frontLeftMotor = new Victor(1, frontLeftMotorPWM);
		rearLeftMotor = new Victor(1, rearLeftMotorPWM);
		frontRightMotor = new Victor(1, frontRightMotorPWM);
		rearRightMotor = new Victor(1, rearRightMotorPWM);
		//myRobot = new RobotDrive(frontLeftMotor, frontRightMotor, rearLeftMotor ,rearRightMotor);
		rightStick = new Joystick(1);
		leftStick = new Joystick(2);
		operatorStick = new Joystick(3);
		fin = new Fin(leftStick, rightStick, operatorStick);
		weight = new WeaytShifter(leftStick, rightStick, operatorStick);
		//myRobot->SetExpiration(0.1);
	}
	
	
	void RobotDemo::RobotInit(){
		//myRobot->SetExpiration(9001);
		//timer->Start();
	}

	/**
	 * Drive left & right motors for 2 seconds then stop
	 */
	void RobotDemo::Autonomous(void) {
		
		//myRobot->SetSafetyEnabled(false);
		Wait(2.0); //    for 2 seconds
	}

	/**
	 * Runs the motors with arcade steering. 
	 */
	void RobotDemo::TeleopPeriodic() {
		printf("alot of me\n");		
		control();
		fin->control();
		weight->control();
	
				
	}

	/**
	 * Runs during test mode
	 */
	void RobotDemo::Test() {
		cout << "lol no" << endl;
	}
	
	void RobotDemo::controlTankDrive(double percent) {
			printf("tankdrive 1 %g\n", percent);
	        tankDrive(getLeftStick()->GetY(),getRightStick()->GetY(),percent);
	    }
	
	 void RobotDemo::tankDrive(double left, double right, double percent) {
		 printf("tankdrive 2 percent %g left %g right %g\n", percent, left, right);
	        double percentRight = (right*percent);
	        double percentLeft = (left*percent);
	        tankDrive(percentLeft,percentRight);
	    }
	 
	 void RobotDemo::tankDrive(double left, double right) {
		 printf("tankdrive 3 left %g right %g\n", left, right);
	         frontLeftMotor->Set(-left);
	         rearLeftMotor->Set(-left);
	         frontRightMotor->Set(right);
	         rearRightMotor->Set(right);
	     }
	 
	
	  
	 void RobotDemo::Disabled(){
		 stop();
		 fin->stop();
		 weight->stop();
	 }
	 
	 void RobotDemo::stop() {
	        frontLeftMotor->Set(0);
	        rearLeftMotor->Set(0);
	        frontRightMotor->Set(0);
	        rearRightMotor->Set(0);
	    }

	void RobotDemo::control() {
	        if (getRightStick()->GetRawButton(1) == true && getLeftStick()->GetRawButton(1) == true) {
	            controlTankDrive(.75);
	            lift->down();
	        } else if (getRightStick()->GetRawButton(1) == true || getLeftStick()->GetRawButton(1) == true) {
	            controlTankDrive(.50);
	            lift->down();
	        } else {
	            controlTankDrive(1);
	            if(getRightStick()->GetRawButton(2)) {	            	
	                lift->down();
	            } else {	            	
	                lift->up();
	                
	            }
	        }
	    }
	
	Joystick* RobotDemo::getLeftStick() {
		return leftStick;
	}

	Joystick* RobotDemo::getRightStick() {
		return rightStick;
	}

	Joystick* RobotDemo::getOperatorStick() {
		return operatorStick;
	}
				

START_ROBOT_CLASS(RobotDemo);

