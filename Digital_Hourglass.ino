const int switchPin = 9; // Define pin our switch is connected to
unsigned long previousTime = 0; // Set initial time for our hourglass
int switchState = 0; // Switch state uses 1 or 0 as binary for digitalWrite command
int prevswitchState = 0; // Switch state again as binary to calibrate timings of hourglass
int led = 2; // First LED is set to second pin
int greenled = 8;
long interval = 2000; // Interval is 600,000 ms, so 10 minutes.


void setup() {
  for(int x=2;x<9;x++){
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT); // In setup, we turn every pin to output, except for 9 which is our input pin

}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;

    digitalWrite(led, HIGH);

    if (led == 7) {
      digitalWrite(greenled, HIGH); // Turn on green LED
      for (int x = 2; x < 8; x++) { // Turn off other LEDs (2 to 7)
        digitalWrite(x, LOW);
      }
    }

    led = (led + 1) % 8; // Wrap around to 0 if led reaches 7
  }

    
// The first part of the loop determines when 10 mintues has passed, and what LED to turn on. Once it reaches LED 7 we reset the LEDs
  
  switchState = digitalRead(switchPin);

  if(switchState != prevswitchState){

    for(int x = 2; x<9;x++){

      digitalWrite(x, LOW);
    }

    led = 2;

    previousTime = currentTime; // This is the hourglass mechanic. When the switch is constantly on, we keep the LEDs on HIGH. If the previous switch state do not match, we rest them by turning them on LOW
  }

prevswitchState = switchState;

}
