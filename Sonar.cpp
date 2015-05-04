// 
// 
// 

#include "Sonar.h"
#include "Servo.h"
#include <Ultrasonic.h>

void SonarClass::init(int servoPin, int echoPin, int trigPin)
{
	_curAngle = 0;
	// Create the servo and attach it to it's pin
	servoPtr = new Servo;
	servoPtr->attach(servoPin);
	// Create the sensor and attach it to it's pin
	sensorPtr = new Ultrasonic(trigPin,echoPin);
}

void SonarClass::sweep()
{
	// Move to current Angle
	servoPtr->writeMicroseconds(map(_curAngle, 0, NUM_DEGREES, ZERO_DEG_TO_MILLISEC, MAX_DEG_TO_MILLISEC));
	
	// Record range at current deg
	long microsec = sensorPtr->timing();
	rangeInchesAtDeg[_curAngle] = sensorPtr->convert(microsec, Ultrasonic::IN);
	if(SONAR_DEBUG_ON)
	{
		Serial.print("Range: ");
		Serial.print(rangeInchesAtDeg[_curAngle]);
		Serial.print(" @ Deg:");
		Serial.println(_curAngle);
	}
	if(++_curAngle > NUM_DEGREES)
	{
		_curAngle = 0;
	}	
}


SonarClass Sonar;

