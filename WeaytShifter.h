#include "WPILib.h"
#include "Lift.h"

class WeaytShifter {
public:
	WeaytShifter(Joystick* left, Joystick* right, Joystick* op);
	Joystick* leftStick;
	Joystick* rightStick;
	Joystick* operatorStick;
	static const double speed = .5;	
	Victor* weightShifterMotor;
	DigitalInput* weightShifterLimitFwd;
	DigitalInput* weightShifterLimitBck;
	bool controlMove(double percent);
	void control();
	bool move(double value, double percent);
	bool move(double value);
	void stop();

};
