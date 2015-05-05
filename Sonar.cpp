// 
// 
// 

#include "Sonar.h"
#include "Servo.h"
#include <Ultrasonic.h>

Sonar::Sonar()
{
	bzero((void*)rangeInchesAtDeg, sizeof(rangeInchesAtDeg));
}

void Sonar::init(int servoPin, int echoPin, int trigPin)
{
	_curAngle = 0;
	// Create the servo and attach it to it's pin
	servoPtr = new Servo;
	servoPtr->attach(servoPin);
	// Create the sensor and attach it to it's pin
	sensorPtr = new Ultrasonic(trigPin,echoPin);
	// Set default sweep limits
	minSweepDeg = 90;
	maxSweepDeg = 90;
	numSweepDeg = 1;
}

void Sonar::sweep()
{
	// Move to current Angle
	servoPtr->writeDegrees(_curAngle);
	
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
	if(++_curAngle > maxSweepDeg)
	{
		_curAngle = minSweepDeg;
	}	
}

void Sonar::setSweepLimits(int minDeg, int maxDeg)
{
	maxSweepDeg = maxDeg;
	minSweepDeg = minDeg;
	numSweepDeg = maxDeg - minDeg + 1;
}

int Sonar::rangeInches(int angle)
{
	if(angle < minSweepDeg || angle > maxSweepDeg){
		return -1;
	}
	return rangeInchesAtDeg[angle];
}


