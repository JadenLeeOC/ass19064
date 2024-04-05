//19064
#include <SparkFun_LPS25HB_Arduino_Library.h>
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SPI.h>
#include <SD.h>
LPS25HB pressureSensor;

OpenLog myLog; //Create instance
const byte OpenLogAddress = 42; //Default Qwiic OpenLog I2C address

void setup() {

  Wire.begin();
  myLog.begin(); //Open connection to OpenLog (no pun intended)

  Serial.begin(9600); //9600bps is used for debug statements
  Serial.println("Run OpenLog Append File Test");
  myLog.println("Run OpenLog Append File Test");

  Serial.begin(9600);
  Serial.println("LPS25HB Pressure Sensor Example 1 - Basic Readings");
  Serial.println();

  myLog.println("This is recorded to the default log file");
  myLog.println("This is recorded to JadenData.txt");
  myLog.println("If this file doesn't exist it is created and");
  myLog.println("anything sent to OpenLog will be recorded to this file");

 
  myLog.append("JadenData.txt");
  myLog.syncFile();


  pressureSensor.begin();  // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings
  Serial.println("Done!");
}

void loop() {

  myLog.print("Pressure in hPa: ");
  myLog.print(pressureSensor.getPressure_hPa());  // Get the pressure reading in hPa
  myLog.print(", Temperature (degC): ");
  myLog.println(pressureSensor.getTemperature_degC());
  delay(500);

}
