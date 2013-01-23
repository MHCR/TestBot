#include "WPILib.h"
#include "Lift.h"
class Fin {

public:
	Fin(Joystick* left, Joystick* right, Joystick* op);
	Joystick* leftStick;
	Joystick* rightStick;
	Joystick* operatorStick;
	void control();
	bool forward();
	bool backward();
	void stop();
	DigitalInput* limitForward;
	DigitalInput* limitBack;
	Victor* motor;
	static const double forwardSpeed = .5;
	static const double backSpeed = -.4;
};
