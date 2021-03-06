#include "Lidar.h"
#include "Sonar.h"

#include <Ultrasonic.h>

#define LEFT_FULL_FORWARD  128
#define RIGHT_FULL_FORWARD 127

#define LEFT_FULL_REVERSE  255
#define RIGHT_FULL_REVERSE 1

#define LEFT_STOP  192
#define RIGHT_STOP 64

#define LEFT_TRIGGER_PIN  (12)
#define LEFT_ECHO_PIN     (13)
#define LEFT_SERVO_PIN    (14)

#define RIGHT_TRIGGER_PIN  (10)
#define RIGHT_ECHO_PIN     (11)
#define RIGHT_SERVO_PIN     (9)


Sonar leftSonar;
Sonar rightSonar;

//Ultrasonic leftUltrasonic(LEFT_TRIGGER_PIN, LEFT_ECHO_PIN);
//Ultrasonic rightUltrasonic(RIGHT_TRIGGER_PIN, RIGHT_ECHO_PIN);

void setup()
{
	Serial.begin(9600);
	Serial1.begin(38400);
	
	leftSonar.init(LEFT_SERVO_PIN, LEFT_ECHO_PIN, LEFT_TRIGGER_PIN);
	rightSonar.init(RIGHT_SERVO_PIN, RIGHT_ECHO_PIN, RIGHT_TRIGGER_PIN);
	
}

void loop()
{	
	float rightDistInches, leftDistInches;
	//   long microsec = leftUltrasonic.timing();
	//   leftDistInches = leftUltrasonic.convert(microsec, Ultrasonic::IN);

	// This moves each sonar to it's next location
	// and takes a measurement
	leftSonar.sweep();
	rightSonar.sweep();

	// Read the distance straight ahead, left side
	leftDistInches = leftSonar.rangeInches(90);
	Serial.print(", IN: ");
	Serial.println(leftDistInches);
	
	//   microsec = rightUltrasonic.timing();
	//   rightDistInches = rightUltrasonic.convert(microsec, Ultrasonic::IN);

	// Read the distance straight ahead, right side
	rightDistInches = rightSonar.rangeInches(90);
	Serial.print(", IN: ");
	Serial.println(rightDistInches);
	
	// Close object, evasive action
	if(leftDistInches < 24 || rightDistInches < 24){
		if(leftDistInches > rightDistInches){
			Serial.println("FULL REVERSE!!");
			Serial1.write(RIGHT_FULL_REVERSE);
			Serial1.write(LEFT_FULL_REVERSE);
			delay(random(300,1200));
			Serial.println("180 TURN!!");
			Serial1.write(LEFT_FULL_FORWARD);
			delay(random(300,1200));
			Serial1.write(RIGHT_FULL_FORWARD);
			
		}
		else {
			Serial.println("FULL REVERSE!!");
			Serial1.write(LEFT_FULL_REVERSE);
			Serial1.write(RIGHT_FULL_REVERSE);
			delay(random(300,1200));
			Serial.println("180 TURN!!");
			Serial1.write(RIGHT_FULL_FORWARD);
			delay(random(300,1200));
			Serial1.write(LEFT_FULL_FORWARD);
		}
	}
	/*
	else if(leftDistInches < 90){
	Serial.println("LEFT TURN!!");
	Serial1.write(RIGHT_STOP);
	delay(100);
	Serial1.write(RIGHT_FULL_FORWARD);
	}
	else if(rightDistInches < 90){
	Serial.println("RIGHT TURN!!");
	Serial1.write(LEFT_STOP);
	delay(100);
	Serial1.write(LEFT_FULL_FORWARD);
	}
	*/
	else{
		Serial.println("AHEAD FULL!!");
		Serial1.write(LEFT_FULL_FORWARD);
		Serial1.write(RIGHT_FULL_FORWARD);
	}
}
