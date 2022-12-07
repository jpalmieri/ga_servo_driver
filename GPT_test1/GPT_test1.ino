//Create an arduino program that moves an array of 4 servo motors in an oscillating pattern. Use the Adafruit PWM and Wire libraries.

#include <Wire.h> // Include the Wire library
#include <Adafruit_PWMServoDriver.h> // Include the Adafruit PWM library

// Set up the servo driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Variables for the servo positions
int servoPosition1 = 0;
int servoPosition2 = 0;
int servoPosition3 = 0;
int servoPosition4 = 0;

// Variables for the oscillation amount
int servoOscillation1 = 180;
int servoOscillation2 = 180;
int servoOscillation3 = 180;
int servoOscillation4 = 180;

void setup() {
  pwm.begin(); // Begin the servo driver
  pwm.setPWMFreq(60); // Set the frequency of the PWM
}

void loop() {
  // Move each servo in an oscillation pattern
  for (int i = 0; i < servoOscillation1; i++) {
    servoPosition1++;
    pwm.setPWM(0, 0, servoPosition1);
    delay(10);
  }
  for (int i = 0; i < servoOscillation2; i++) {
    servoPosition2++;
    pwm.setPWM(1, 0, servoPosition2);
    delay(10);
  }
  for (int i = 0; i < servoOscillation3; i++) {
    servoPosition3++;
    pwm.setPWM(2, 0, servoPosition3);
    delay(10);
  }
  for (int i = 0; i < servoOscillation4; i++) {
    servoPosition4++;
    pwm.setPWM(3, 0, servoPosition4);
    delay(10);
  }
  for (int i = 0; i < servoOscillation1; i++) {
    servoPosition1--;
    pwm.setPWM(0, 0, servoPosition1);
    delay(10);
  }
  for (int i = 0; i < servoOscillation2; i++) {
    servoPosition2--;
    pwm.setPWM(1, 0, servoPosition2);
    delay(10);
  }
  for (int i = 0; i < servoOscillation3; i++) {
    servoPosition3--;
    pwm.setPWM(2, 0, servoPosition3);
    delay(10);
  }
  for (int i = 0; i < servoOscillation4; i++) {
    servoPosition4--;
    pwm.setPWM(3, 0, servoPosition4);
    delay(10);
  }
}
