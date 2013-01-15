#include "WPILib.h"
#include "Math.h"
#include "Utility.h"

class KitBase : public IterativeRobot
{
	DriverStation		*ds;

	Victor 			*drive1, *drive2;
	Joystick		*left, *right;
	
	// Local variables to count the number of periodic loops performed
	UINT32 autoCount;
	UINT32 disabledCount;
	UINT32 teleCount;
	UINT32 printSec;
		
public:
	
	KitBase(void)
	{
		wpi_stackTraceOnAssertEnable(true);
		
		ds         = DriverStation::GetInstance();
		left       = new Joystick(1);
		right      = new Joystick(2);
		
		drive1     = new Victor(1);		// PWM 1 & 2
		drive2     = new Victor(2);
				
		// Initialize counters to record the number of loops completed in autonomous and teleop modes
		autoCount     = 0;
		disabledCount = 0;
		teleCount     = 0;

		printf("KitBase constructor Completed\n");
	}
	
	// Init routines
	void 
	RobotInit(void)
	{
		printf("RobotInit completed.\n");
		return;
	}
	
	void 
	DisabledInit(void)
	{
		disabledCount = 0;			// Reset the loop counter for disabled mode
		printSec = (UINT32)GetClock() + 1;
		
		printf("DisabledInit finished\n");
		return;
	}

	void 
	AutonomousInit(void)
	{
		autoCount = 0;				// Reset the loop counter for autonmous mode
		printSec = (UINT32)GetClock() + 1;
		
		printf("AutonomousInit finished\n");
		return;
	}

	void 
	TeleopInit(void)
	{
		teleCount = 0;				// Reset the loop counter for teleop mode
		printSec = (UINT32)GetClock() + 1;
		
		return;
	}

	// Periodic routines
	
	void 
	DisabledPeriodic(void)
	{
		
		// while disabled, printout the duration of current disabled mode in seconds
		if (GetClock() > printSec) {
			// increment the number seconds counter while in disabled mode
			printf("Disabled seconds: %d\n", disabledCount++);
			printSec = (UINT32)GetClock() + 1;
		}
		
		return;
	}

	void 
	AutonomousPeriodic(void)
	{
		
		if(GetClock() > printSec) {
			// increment the number of seconds counter while in autonomous mode
			printf("Autonomous seconds: %d\n", autoCount++);
			printSec = (UINT32)GetClock() + 1;
		}
	}
	
	void 
	TeleopPeriodic(void)
	{
		
		// Get driver actions
		float lval = left->GetY();
		float rval = right->GetY();
		
		drive1->Set(lval);
		drive2->Set(rval);
		
		if(GetClock() > printSec) {
			// increment the number of teleop periodic loops completed
			printf("Teleop seconds %d left speed %f right speed %f\n", 
						teleCount++, lval, rval);
			printSec = (UINT32)GetClock() + 1;
		}
		return;	
	}

	// Continuous routines
	void 
	DisabledContinuous(void) 
	{
	}

	void 
	AutonomousContinuous(void)
	{
	}

	void 
	TeleopContinuous(void)
	{
	}
};

START_ROBOT_CLASS(KitBase);
