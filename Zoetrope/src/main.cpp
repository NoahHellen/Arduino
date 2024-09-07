#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

const int controlPin1 = 2; //connected to pin 7 on the H-bridge
const int controlPin2 = 3; //connected to pin 2 on the H-bridge
const int enablePin = 9; // connected to pin 1 on the H-bridge
const int directionSwitchPin = 4; // connected to the switch for directoin
const int onOffSwitchStateSwitchPin = 5; // connected to the switch for motor on/off
const int potPin = A0; // connected to the potentiometer's output

// create some variables to hold values from inputs
int onOffSwitchState = 0; // current state of the on/off swtich
int previousOnOffSwitchState = 0; // previous state of the on/off switch
int directionSwitchState = 0; // current state of direction switch
int previousDirectionSwitchState = 0; // previous state of direction switch

int motorEnabled = 0; // controls on/off state of motor
int motorSpeed = 0; // controls speed of motor
int motorDirection = 1; // controls direction of motor

void setup() {
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW);

}

void loop() {
  // read the value of the on/off switch
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);

  // read the value of the direction swtich
  directionSwitchState = digitalRead(directionSwitchPin);

  // set the speed of the motor based on the potentiometer
  motorSpeed = analogRead(potPin)/4;

  // if/then statement for pressing on/off button
  if(onOffSwitchState != previousOnOffSwitchState){
    if(onOffSwitchState == HIGH){
      motorEnabled = !motorEnabled;
    }
  }

  // if/then statement for pressing direction button
  if(directionSwitchState != previousDirectionSwitchState){
    if(directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }

  // code for outputting if/then statements into circuit using digitalWrite
  if(motorDirection == 1){
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);

  // code for outputting if/then statements into circuit using analogWrite
  }
  if(motorEnabled == 1){
    analogWrite(enablePin, motorSpeed);
  }
  else {
    analogWrite(enablePin, 0);
  }
  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}