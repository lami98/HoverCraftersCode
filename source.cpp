#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(10,6); // RX, TX

 //Servo servoOne;
 //int servoOnePin = 0;
 //int servoOneVal = 0;
 //int servoOnePosition = 0;
 int LED = 13; //on-board led
 int Data;
 int ch1;
 int ch2; 
void setup() {
//servoOne.attach(9);
Bluetooth.begin(9600);
Serial.println("Waiting for command...");
Bluetooth.println("Send 1 to trun on the LED, 0 for off");
pinMode(A0, INPUT);
pinMode(A1, INPUT);

Serial.begin (9600);
}

void loop() {
  // this will be where the functions are called when the buttons on the remote are used  
  //hoveringMotors();
  //droppingMechanism();
  //backMotorAndServo(servoOneVal);

  ch1 = pulseIn(A1, HIGH, 25000); //1840-1870 rest value
  ch2 = pulseIn(A0, HIGH, 25000); //1080-1100 rest value

  Serial.print(" Channel 2:");
  Serial.print(ch2);
  Serial.print('\n');
  Serial.print("Channel 1:"); 
  Serial.print(ch1);

  if (Bluetooth.available()){ //wait for data received
    Data=Bluetooth.read();
    if(Data=='1'){  
      digitalWrite(LED,1);
      Serial.println("LED On!");
      Bluetooth.println("LED On!");
    }
    else if(Data=='0'){
       digitalWrite(LED,0);
       Serial.println("LED Off!");
       Bluetooth.println("LED  On D13 Off ! ");
    }
    else{;}
}
}

//void hoveringMotors() {
  // this function is to control the downward facing hovering motors
//}

//void droppingMechanism() {
  // this function is to control the dropping mechanism
//}

//void backMotorAndServo(servoOneVal) {
  // this function is to control the motor that makes the craft move forward and the servo that 
  // moves that motor
  
    //servoOnePosition = map(servoOneVal, 0, 1023, 0, 180);
    //servoOne.write(servoOnePosition);

//}
