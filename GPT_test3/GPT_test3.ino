//Modify this code to allow a user to control the position of 20 analog servo motors. Use these libraries: #include <Wire.h>
//#include <Adafruit_PWMServoDriver.h>


#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//Initialize the PWM driver
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//An array to store the servo positions
int servoPositions[20];

void setup(){
  //Initialize the I2C communication
  Wire.begin();
  pwm.begin();
  pwm.setPWMFreq(60); // Sets the frequency of the PWM signal

  //Set up all servos to initial position
  for(int i = 0; i < 20; i++){
    servoPositions[i] = 0;
    pwm.setPWM(i, 0, servoPositions[i]);
  }
}

void loop(){
  //Read user input to update servo positions
  for(int i = 0; i < 20; i++){
    servoPositions[i] = readUserInput();
    pwm.setPWM(i, 0, servoPositions[i]);
  }
  
  //Wait a bit before reading user input again
  delay(50);
}

//Read user Input
int readUserInput(){
  //Read user input and return the servo position
  int servoPosition;
  //Read user input and assign it to servoPosition
  return servoPosition;
}
