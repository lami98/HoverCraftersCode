#include <Servo.h>

 Servo servoOne
 int servoOnePin = 0;
 int servoOneVal = 0;
 int servoOnePosition = 0;
void setup() {
servoOne.attach(9);

}

void loop() {
	// this will be where the functions are called when the buttons on the remote are used	
  hoveringMotors();
  droppingMechanism();
  backMotorAndServo(servoOneVal);

}


void hoveringMotors() {
	// this function is to control the downward facing hovering motors
}

void droppingMechanism() {
	// this function is to control the dropping mechanism
}

void backMotorAndServo(servoOneVal) {
	// this function is to control the motor that makes the craft move forward and the servo that 
	// moves that motor
	
  	servoOnePosition = map(servoOneVal, 0, 1023, 0, 180);
  	servoOne.write(servoOnePosition);

}
