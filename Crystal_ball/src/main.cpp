#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

#include <LiquidCrystal.h> // import the LCD library
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // create lcd library

const int switchPin = 6; // designate constant variable for switch
int switchState = 0; // variable to hold state of switch
int prevSwitchState = 0; // variable to hold previous state of switch
int reply; // variable to hold reply of screen

void setup() {
  lcd.begin(2, 16); // begin function on lcd object to set dimensions of display
  pinMode(switchPin, INPUT); // initialise switch to be an input
  lcd.print("Ask the"); // print function on lcd object to print text
  lcd.setCursor(0,1); // setCursor function on lcd object for subsequent text
  lcd.print("Crystal Ball!"); // print function on lcd object to print text
}

void loop() {
  switchState = digitalRead(switchPin); // read switch to determine action on LCD display
  if (switchState != prevSwitchState){ // action if switch has been 'pressed'
    if (switchState == HIGH){ // action only if switch is in 'pressed' state
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("The ball says:");
      lcd.setCursor(0,1);
      switch(reply){
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("Most likely");
        break;
        case 2:
        lcd.print("Certainly");
        break;
        case 3:
        lcd.print("Outlook good");
        break;
        case 4:
        lcd.print("Unsure");
        break;
        case 5:
        lcd.print("Ask again");
        break;
        case 6:
        lcd.print("Doubtful");
        break;
        case 7:
        lcd.print("No");
        break;
      }
      delay(1000);
      lcd.clear();
      delay(1000);
      lcd.setCursor(0,0);
      lcd.print("Try another");
      lcd.setCursor(0, 1);
      lcd.print("question!");

    } 
  }
  prevSwitchState= switchState;

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}