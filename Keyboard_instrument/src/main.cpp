#include <Arduino.h>

int notes[] = {262,294,330,349,450};

void setup() {
Serial.begin(9600);
}

void loop() {
int keyVal = analogRead(A0);
Serial.println(keyVal);
if(keyVal == 1023){
  tone(8, notes[0]);
}
else if(keyVal >= 990 && keyVal <= 1010){
  tone(8, notes[1]);
}
else if(keyVal >= 510 && keyVal <= 513){
  tone(8, notes[2]);
}

else if(keyVal >= 514 && keyVal <= 516){
  tone(8, notes[4]);
}

else if(keyVal >= 5 && keyVal <= 15){
  tone(8, notes[3]);
}
else{
  noTone(8);
}


}
