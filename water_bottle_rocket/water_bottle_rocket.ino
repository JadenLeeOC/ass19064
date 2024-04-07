//19064
#include <SparkFun_LPS25HB_Arduino_Library.h>
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SPI.h>
#include <SD.h>

//TEACHER COMMENT what are these lines of code doing?
//TEACHER COMMENT pressureSensor, and myLog are from the example code so need to be renamed to match our brief better
LPS25HB pressureSensor;
OpenLog myLog; //Create instance

//TEACHER COMMENT is this used anywhere? comment it out and see if any issues happen to check
const byte OpenLogAddress = 42; //Default Qwiic OpenLog I2C address

void setup() {

  Wire.begin();
  myLog.begin(); //Open connection to OpenLog (no pun intended)

  Serial.begin(9600); //9600bps is used for debug statements
  //TEACHER COMMENT can you delete these next several lines of code? comment it out and see if any issues happen
  Serial.println("Run OpenLog Append File Test");
  myLog.println("Run OpenLog Append File Test");
  Serial.begin(9600);
  Serial.println("LPS25HB Pressure Sensor Example 1 - Basic Readings");
  Serial.println();
  myLog.println("This is recorded to the default log file");
  myLog.println("This is recorded to JadenData.txt");
  myLog.println("If this file doesn't exist it is created and");
  myLog.println("anything sent to OpenLog will be recorded to this file");

 //TEACHER COMMENT add a comment to explain what are these line of code doing
  myLog.append("JadenData.txt");
  myLog.syncFile();

//TEACHER COMMENT and what this one is doing - any checks you would do on mylog and pressuresensor to check they are working well?
  pressureSensor.begin();  // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings
  Serial.println("Done!");
}

void loop() {
//TEACHER COMMENT add an explaination of what this is doing - I would suggest looking at how the example csv file on classroom looks to check yours looks correct
  myLog.print("Pressure in hPa: ");
  myLog.print(pressureSensor.getPressure_hPa());  // Get the pressure reading in hPa
  myLog.print(", Temperature (degC): ");
  myLog.println(pressureSensor.getTemperature_degC());
  delay(500);

}
