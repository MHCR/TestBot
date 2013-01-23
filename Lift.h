#ifndef LIFT_H
#define LIFT_H
#include "iostream.h"
#include "WPILib.h"

static const int frontLeftMotorPWM = 5;
static const int rearLeftMotorPWM = 6;
static const int frontRightMotorPWM = 1;
static const int rearRightMotorPWM = 2;

static const int liftMotorFrontPWM = 8;
static const int liftMotorBackPWM = 7;

static const int finMotorPWM = 3;

static const int weightMotorPWM = 4;

static const int liftLimitFrontUpDIO = 3;
static const int liftLimitFrontDownDIO = 4;
static const int liftLimitBackUpDIO = 2;
static const int liftLimitBackDownDIO = 1;

static const int finLimitForwardDIO = 8;
static const int finLimitBackDIO = 9;

static const int weightLimitFwdDIO = 10;
static const int weightLimitBckDIO = 7;

static const int rightADIO = 11;
static const int rightBDIO = 12;
static const int leftADIO = 13;
static const int leftBDIO = 14;

class Lift/* : public RobotFunction*/{

public:
	Lift();
	double liftSpeed;
	DigitalInput* liftLimitFrontUp;
	DigitalInput* liftLimitFrontDown;
	DigitalInput* liftLimitBackUp;
	DigitalInput* liftLimitBackDown;
	Jaguar* liftMotorFront;
	Jaguar* liftMotorBack;

	void stop();

	int down();

	int up();

};
#endif
