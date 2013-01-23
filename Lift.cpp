#include "Lift.h"
//#include "RobotFunction.cpp"


	Lift::Lift() {		  					
		liftSpeed = 1;
		liftMotorFront = new Jaguar(1, liftMotorFrontPWM);
		liftMotorBack = new Jaguar(1, liftMotorBackPWM);

		//lift limits
		liftLimitFrontUp = new DigitalInput(1, liftLimitFrontUpDIO);
		liftLimitFrontDown = new DigitalInput(1, liftLimitFrontDownDIO);
		liftLimitBackUp = new DigitalInput(1, liftLimitBackUpDIO);
		liftLimitBackDown = new DigitalInput(1, liftLimitBackDownDIO);
	}

	void Lift::stop() {
		cout << "im a lift" << endl;
		liftMotorFront->Set(0);
		liftMotorBack->Set(0);
	}

	int Lift::down() {
		printf("down - 3\n");
		if (liftLimitFrontDown->Get()) {
			printf("down - 4\n");
			liftMotorFront->Set(-liftSpeed);
		} else {
			printf("down - 5\n");
			liftMotorFront->Set(0);
		}

		if (liftLimitBackDown->Get()) {
			printf("down - 6\n");
			liftMotorBack->Set(-liftSpeed);
		} else {
			printf("down - 7");					
			liftMotorBack->Set(0);
		}

		if (liftLimitBackDown->Get() && liftLimitFrontDown->Get()) {			
			return 3; // b11
		} else if (liftLimitFrontDown->Get()) {
			return 2; // b10
		} else if (liftLimitBackDown->Get()) {
			return 1; // b01
		} else {
			return 0; // b00
		}
	}

	int Lift::up() {
		if (liftLimitFrontUp->Get()) {
			liftMotorFront->Set(liftSpeed);
		} else {
			liftMotorFront->Set(0);
		}

		if (liftLimitBackUp->Get()) {
			liftMotorBack->Set(liftSpeed);
		} else {
			liftMotorBack->Set(0);
		}

		if (liftLimitBackUp->Get() && liftLimitFrontUp->Get()) {
			return 3; // b11
		} else if (liftLimitFrontUp->Get()) {
			return 2; // b10
		} else if (liftLimitBackUp->Get()) {
			return 1; // b01
		} else {
			return 0; // b00
		}
	}

	

