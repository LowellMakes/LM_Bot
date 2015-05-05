// Sonar.h

#ifndef _SONAR_h
#define _SONAR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Ultrasonic.h>
#include "Servo.h"

#define SONAR_DEBUG_ON (true)
#define MAX_DEGREES (360)

class Sonar
{
 public:
	Sonar();
	
 protected:
	int rangeInchesAtDeg[MAX_DEGREES];
	int _curAngle;
	Servo* servoPtr;
	Ultrasonic* sensorPtr;
	int maxSweepDeg;
	int minSweepDeg;
	int numSweepDeg;
	
 public:
	void init(int servoPin, int echoPin, int trigPin);
	
	// Set the limits to sweep through
	void setSweepLimits(int minDeg, int maxDeg);
	
	// Move to next location and record distance
	void sweep();
	
	// Return the last recorded distance at a given angle
	int rangeInches(int angle);

};

#endif

