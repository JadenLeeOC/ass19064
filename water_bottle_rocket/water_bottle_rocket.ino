//19064
#include <SparkFun_LPS25HB_Arduino_Library.h>
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
#include <SPI.h>
#include <SD.h>
LPS25HB pressureSensor;
Sd2Card card;
SdVolume volume;
SdFile root;
const int TEMPSENSOR = 1;
const int PRESSURESENSOR = 2;
const int CHIPSELECT = 4;

void setup() 

OpenLog myLog; //Create instance

int ledPin = LED_BUILTIN; //Status LED connected to digital pin 13

const byte OpenLogAddress = 42; //Default Qwiic OpenLog I2C address

void setup()
{
  pinMode(ledPin, OUTPUT);

  Wire.begin();
  myLog.begin(); //Open connection to OpenLog (no pun intended)

  Serial.begin(9600); //9600bps is used for debug statements
  Serial.println("Run OpenLog Append File Test");
  myLog.println("Run OpenLog Append File Test");

  myLog.println("This is recorded to the default log file");
  myLog.append("JadenData.txt");
  myLog.println("This is recorded to appendMe.txt");
  myLog.println("If this file doesn't exist it is created and");
  myLog.println("anything sent to OpenLog will be recorded to this file");

  myLog.println();
  myLog.println(F("Note: We can use the F(\"\") in sketches to move big print statements into program memory to save RAM"));
  myLog.append("appendMe1.txt");
  myLog.println(F("Note: We can use the F(\"\") in sketches to move big print statements into program memory to save RAM"));
  myLog.println(F("Note: We can use the F(\"\") in sketches to move big print statements into program memory to save RAM"));
  myLog.syncFile();

  Serial.println("Done!");
}

void loop()
{
  //Blink the Status LED because we're done!
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}

{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Environment.begin();
  Serial.println("LPS25HB Pressure Sensor Example 1 - Basic Readings");
  Serial.println();

Wire.begin();
pressureSensor.begin();  // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings

if (pressureSensor.isConnected() == false)  // The library supports some different error codes such as "DISCONNECTED"
{
  Serial.println("LPS25HB disconnected. Reset the board to try again.");      // Alert the user that the device cannot be reached
  Serial.println("Are you using the right Wire port and I2C address?");       // Suggest possible fixes
  Serial.println("See Example2_I2C_Configuration for how to change these.");  // Suggest possible fixes
  Serial.println("");
  while (1)
    ;

  Serial.print("Temperature = ");
  Serial.print(Environment.readTemperature());  //print temperature
  Serial.println(" C");
  Serial.print("Humidity = ");
  Serial.print(Environment.readHumidity());  //print humidity
  Serial.println(" %");
  Serial.print("Pressure in hPa: ");
  Serial.print(pressureSensor.getPressure_hPa());  // Get the pressure reading in hPa
  Serial.print(", Temperature (degC): ");
  Serial.println(pressureSensor.getTemperature_degC());
  delay(40);
}
}
}
