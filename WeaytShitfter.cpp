#include "WeaytShifter.h"

WeaytShifter::WeaytShifter(Joystick* left, Joystick* right, Joystick* op) {
	leftStick = left;
	rightStick = right;
	operatorStick = op;
	weightShifterMotor = new Victor(1, weightMotorPWM);
	weightShifterLimitFwd = new DigitalInput(1, weightLimitFwdDIO);
	weightShifterLimitBck = new DigitalInput(1, weightLimitBckDIO);

}

void WeaytShifter::control() {
        if(operatorStick->GetRawButton(1)) {
            controlMove(speed);
        } else {
            controlMove(1);
        }
    }
bool WeaytShifter::controlMove(double percent) {
        return move(operatorStick->GetY(),percent);
    }
    
   bool WeaytShifter::move(double value, double percent) {
        double val = value * percent;
        //take joystick inputs and drive the robot
        return move(val);
    }
    
    bool WeaytShifter::move(double value) {
        if(value>0) {
            if(weightShifterLimitFwd->Get()) {
                weightShifterMotor->Set(0);
                return false;
            }
        } else if(value<0) {
            if(!weightShifterLimitBck->Get()) {
                weightShifterMotor->Set(0);
                return false;
            }
        }
        weightShifterMotor->Set(value);
        return true;
    }
    
void WeaytShifter::stop() {
        weightShifterMotor->Set(0);
    }
