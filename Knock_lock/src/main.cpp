#include <Arduino.h>

// put function declarations here:
#include <Servo.h> // Port in Servo library
Servo myServo; // Create Servo object

// Set variables for INPUT and OUTPUT pins
const int piezo = A0;
const int switchPin = 2;
const int yellowLed = 3;
const int greenLed = 4;
const int redLed = 5;

// Set variables for piezo and switch
int knockVal;
int switchVal;

// Set variables for piezo sound
const int quietKnock = 10;
const int loudKnock = 100;

// Set more variables for piezo and servo
boolean locked = false;
int numberOfKnocks = 0;

// Set up OUTPUT and INPUTS of pins
void setup() {
  myServo.attach(9);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600); // Serial object sets up communication between computer and Arduino
  digitalWrite(greenLed, HIGH); // Initialise green LED to be on from setup
  myServo.write(0); // Sets angle of Servo to 0 degrees
  Serial.println("The box is unlocked!"); // Prints message on computer
}

  // The switch is how we lock the box
void loop() {
  if(locked == false){
    switchVal = digitalRead(switchPin);
    if(switchVal == HIGH){
      locked = true;
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }
  // The piezo is how we unlock the box
  if(locked == true){
    knockVal = analogRead(piezo);
    if(numberOfKnocks < 5 && knockVal > 0){
      if(checkForKnock(knockVal) == true){
      numberOfKnocks++;
     }   
    Serial.print(5-numberOfKnocks);
    Serial.println(" more knocks to go");
    }
    if(numberOfKnocks > 4){
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked");
      numberOfKnocks = 0;
    }
  }
}

// Create function to check for valid knock value
boolean checkForKnock(int value){
  if(value > quietKnock && value < loudKnock){
    digitalWrite(yellowLed, HIGH);
    delay(50);
    digitalWrite(yellowLed, LOW);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  }
  else{
    Serial.print("Bad knock value ");
    Serial.println(value);
    return false;
  }
}


// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}