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

#define NUM_DEGREES (180)
#define ZERO_DEG_TO_MILLISEC (1000)
#define MAX_DEG_TO_MILLISEC (2000)


class SonarClass
{
 protected:
	int rangeInchesAtDeg[NUM_DEGREES];
	int _curAngle;
	Servo* servoPtr;
	Ultrasonic* sensorPtr;

	
 public:
	void init(int servoPin, int echoPin, int trigPin );
	void sweep();
	int rangeInches(int angle);

};

extern SonarClass Sonar;

#endif

