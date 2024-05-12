//19064
#include <SparkFun_LPS25HB_Arduino_Library.h>
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SPI.h>
#include <SD.h>

LPS25HB SensorPackage;  //Starts sensor
OpenLog JadenCSV;       //Creates a new log

bool button = 4;
int buttonstate = 0;

void setup() {
  buttonstate = digitalRead(4);
  pinMode(4, INPUT);

  Wire.begin();
  JadenCSV.begin();  //Starts the connection to OpenLog

  Serial.begin(9600);  //9600bps is used for debug statements

  JadenCSV.append("JadenData.txt");  // adds the log to the JadenData.txt file
  JadenCSV.syncFile();   // syncs JadenCSV

  SensorPackage.begin();    // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings
  Serial.println("Done!");  // prints a message to the serial monitor to show the user that the Pressure sensor is working properly and is connected to the I2C port
}

void loop() {
  if (digitalRead(buttonstate) == HIGH) {

    JadenCSV.print("Pressure in hPa: ");                    // Adds text to show readings in a proper sentence
    JadenCSV.print(SensorPackage.getPressure_hPa());        // Gets the pressure reading in hPa
    JadenCSV.print(", Temperature (degC): ");               // Adds text to show readings in a proper sentence
    JadenCSV.println(SensorPackage.getTemperature_degC());  // Gets the temperature reading in degrees celsius
    Serial.print("Pressure in hPa: ");                      // Adds text to show readings in a proper sentence
    Serial.print(SensorPackage.getPressure_hPa());          // Gets the pressure reading in hPa
    Serial.print(", Temperature (degC): ");                 // Adds text to show readings in a proper sentenceTRDCX
    Serial.println(SensorPackage.getTemperature_degC());    // Gets the temperature reading in degrees celsius
    delay(500);                                             // adds a 5 second delay
  } else if (digitalRead(buttonstate) == LOW) {

    Serial.println("Sensor Package is Turned off, Turn Sensor Package On to Recieve Sensor Readings");
    JadenCSV.println("Sensor Package is Turned off, Turn Sensor Package On to Recieve Sensor Readings");
  }
}
