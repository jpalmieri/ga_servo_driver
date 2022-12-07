//Create an Arduino program that allows users to manipulate a grid of 20 analog servo motors, then store and retrieve their position values.

//include libraries
#include <Servo.h>

//declare variables
Servo servoGrid[20]; //declare an array of 20 servo motors
int posVal[20]; //declare an array of 20 position values

//setup
void setup()
{
  //loop through the servoGrid array and attach each servo motor
  for(int i = 0; i < 20; i++)
  {
    servoGrid[i].attach(i);
    posVal[i] = 0; //set the initial position value to 0
  }
}

//loop
void loop()
{
  //loop through the servoGrid array and set each motor to its corresponding position value
  for(int i = 0; i < 20; i++)
  {
    servoGrid[i].write(posVal[i]);
  }
  
  //create a function that allows the user to change the position values of the servo motors
  changePositionValues();
  
  //create a function that allows the user to store the position values in a file
  storePositionValues();
  
  //create a function that allows the user to retrieve the position values from a file
  retrievePositionValues();
}

//user input function
void changePositionValues()
{
  //prompt the user to enter a position value for each servo motor
  for(int i = 0; i < 20; i++)
  {
    Serial.print("Enter position value for servo motor ");
    Serial.println(i);
    
    //read the user input and store it in the posVal array
    posVal[i] = Serial.read();
  }
}

//file storage function
void storePositionValues()
{
  //open a file with the name 'positionValues.txt'
  File myFile = SD.open("positionValues.txt", FILE_WRITE);
  
  //loop through the posVal array and write each value to the file
  for(int i = 0; i < 20; i++)
  {
    myFile.print(posVal[i]);
  }
  
  //close the file
  myFile.close();
}

//file retrieval function
void retrievePositionValues()
{
  //open the file 'positionValues.txt'
  File myFile = SD.open("positionValues.txt");
  
  //loop through the posVal array and read the values from the file
  for(int i = 0; i < 20; i++)
  {
    posVal[i] = myFile.read();
  }
  
  //close the file
  myFile.close();
}
