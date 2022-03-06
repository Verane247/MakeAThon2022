/*
An Arduino prgram that moves four motors with the first two moving before the last two

Procedure:

A switch is triggered. It activates two motors that move in opposite direction at the same magnitude.
After a long delay, two more motors will move in opposite direction with the same magnitude.

*/
#include <Servo.h>

// constants won't change
const int BUTTON_PIN = 7; // Arduino pin connected to button's pin
const int SERVO1_PIN  = 8; // Arduino pin connected to servo motor's pin
const int SERVO2_PIN  = 12; // Arduino pin connected to servo motor's pin

Servo servo1; // create servo object to control a servo
Servo servo2;

// variables will change:
int angle1 = 180;          // the current angle of servo motor
int angle2 = 0;
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button

void setup() {
  
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  // Servo 1 setup
  servo1.attach(SERVO1_PIN);           // attaches the servo on pin 9 to the servo object
  // Servo 2 setup
  servo2.attach(SERVO2_PIN);

  servo1.write(angle1);     // Servo 1 angle setup
  servo2.write(angle2);     // Servo 2 angle setup
  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(BUTTON_PIN); // read new state

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");

    // change angle of servo motor
    if(angle1 == 0)
      angle1 = 180;
    else
    if(angle1 == 180)
      angle1 = 0;
    // control servo motor arccoding to the angle
    servo1.write(angle1);

    delay(900);

    // change angle of servo motor
    if(angle1 == 0)
      angle1 = 180;
    else
    if(angle1 == 180)
      angle1 = 0;
    servo1.write(angle1);

    delay(2000);
    
    if(angle2 == 0)
      angle2 = 180;
    else
    if(angle2 == 180)
      angle2 = 0;
    servo2.write(angle2);

    delay(900);
    
    if(angle2 == 0)
      angle2 = 180;
    else
    if(angle2 == 180)
      angle2 = 0;
    servo2.write(angle2);
    

    
  }
}
