#include <Servo.h>

byte button_up = 10;
byte button_down = 11;
byte button_trigger = 12;
byte servo_pin = 6;

byte stepPin = 2;
byte dirPin = 3;
bool trigger_pressing = 0;

Servo release;
release.attach(servo_pin);

unsigned long currentMillis = millis();
unsigned long previousMillis = 0;
int trigger_interval = 1500;

// Move stepper x steps (steps, direction)
void moveStepper (distance, direction){
  digitalWrite(dirPin, direction); // Enables the motor to move in a particular direction
  for(int x = 0; x < distance; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
}

// release pulley from spline
void engagePulley (){
  release.write(90);  // set servo to end-point
}

// attach pulley to spline
void disengagePulley (){
  release.write(180);  // set servo to mid-point
}

void setup() {
    release.attach(6);

    pinMode(button_up, INPUT);
    pinMode(button_down, INPUT);
    pinMode(button_trigger, INPUT);
    pinMode(step, OUTPUT);
    pinMode(dir, OUTPUT);
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
}

void loop() {
    currentMillis = millis();
    if(digitalRead(button_up)){
      moveStepper(50, HIGH);
    } else if (digitalRead(button_down)) {
      moveStepper(50, LOW);
    } else if (digitialRead(button_trigger)){
      trigger_pressing = 1;
      trigger_interval = currentMillis;

      if (currentMillis - previousMillis > trigger_interval){
        trigger_pressing = 0;

      }

    } else {
      // Do nothing

    }

}
