#include "Fin.h"

Fin::Fin(Joystick* left, Joystick* right, Joystick* op) {
	leftStick = left;
	rightStick = right;
	operatorStick = op;
	motor = new Victor(1, finMotorPWM);

	limitForward = new DigitalInput(1, finLimitForwardDIO);
	limitBack = new DigitalInput(1, finLimitBackDIO);
}

/**
 * Get the fin so we do not allocate hardware more than once
 * @return fin functionality
 */
/**
 * driver control the fin
 * joystick 3 is forward
 * joystick 2 is backward
 * else stop the fin
 */
void Fin::control() {
	if (operatorStick->GetRawButton(3)) {
		forward();
	} else if (operatorStick->GetRawButton(2)) {
		backward();
	} else {
		stop();
	}
}

/**
 * make the fin go forward
 * @return true if able to move, false if at limit
 */
bool Fin::forward() {
	if (!limitForward->Get()) {
		motor->Set(forwardSpeed);
		return true;
	} else {
		stop();
		return false;
	}
}

/**
 * make the fin go backward
 * @return true if able to move, false if at limit
 */
bool Fin::backward() {
	if (!limitBack->Get()) {
		motor->Set(backSpeed);
		return true;
	} else {
		stop();
		return false;
	}
}

/**
 * stop the motor
 */
void Fin::stop() {
	motor->Set(0);
}

