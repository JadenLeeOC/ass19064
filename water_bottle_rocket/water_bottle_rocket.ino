//19064
#include <SparkFun_LPS25HB_Arduino_Library.h>
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SPI.h>
#include <SD.h>

LPS25HB sensorPackage;  //Starts sensor
OpenLog jadenCSV;       //Creates a new log

bool button = 4;
int buttonState = 0;

void setup() {  
  buttonState = digitalRead(4); //sets buttonstate variable to read pin 4
  pinMode(4, INPUT);            //sets pin 4 to input mode 

  Wire.begin();
    Serial.begin(9600);              //9600bps is used for debug statements
  jadenCSV.begin();                  //Starts the connection to OpenLog
  jadenCSV.append("JadenData.txt");  // adds the log to the JadenData.txt file
  jadenCSV.syncFile();               // syncs JadenCSV

  sensorPackage.begin();    // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings
  Serial.println("Done!");  // prints a message to the serial monitor to show the user that the Pressure sensor is working properly and is connected to the I2C port
}
bool checkButtonState() {      // Checks whether button is on or off
  return digitalRead(button);  // returns the state of the button (on/off)
}

void loop() {
  int secondsPassed = millis() / 100;

  buttonState = checkButtonState();  //Checks button state
  if (digitalRead(buttonState) == HIGH) { //If button is on/pressed the code will run

    jadenCSV.println("Time, Pressure, Temperature");            // Adds a title line 
    jadenCSV.println(String(secondsPassed) + "," + String(sensorPackage.getPressure_hPa()) + "," + String(sensorPackage.getTemperature_degC())); // Inserts the readings

    Serial.println("Time, Pressure, Temperature");            // Adds a title line
    Serial.println(String(secondsPassed) + "," + String(sensorPackage.getPressure_hPa()) + "," + String(sensorPackage.getTemperature_degC())); // Inserts the readings
    
    delay(100);                                 // adds a 5 second delay
  } else if (digitalRead(buttonState) == LOW) { //If button is off/not pressed the following code will run

    Serial.println("Sensor Package is Turned off, Turn Sensor Package On to Recieve Sensor Readings"); // When button is turned off this text is displayed in serial monitor
    jadenCSV.println("Sensor Package is Turned off, Turn Sensor Package On to Recieve Sensor Readings"); // When button is turned off this text is displayed in the file.
  }
}
