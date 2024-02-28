#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
OpenLog sdCard; //Create instance

const String FILENAME = "joke.text";

int ledPin = LED_BUILTIN; //Status LED connected to digital pin 13

const byte OpenLogAddress = 42; //Default Qwiic OpenLog I2C address

void setup()
{
  pinMode(ledPin, OUTPUT);

  Wire.begin();
  sdCard.begin(); //Open connection to OpenLog (no pun intended)


  Serial.begin(9600); //9600bps is used for debug statements

  sdCard.append(FILENAME);
  sdCard.println("Knock knock joke");
  sdCard.syncFile();

  Serial.println("Run OpenLog Append File Test");
  sdCard.println("Run OpenLog Append File Test");

  sdCard.println("This is recorded to the default log file");
  sdCard.append("appendMe.txt");
  sdCard.println("This is recorded to appendMe.txt");
  sdCard.println("If this file doesn't exist it is created and");
  sdCard.println("anything sent to OpenLog will be recorded to this file");

  sdCard.println();
  sdCard.println(F("Note: We can use the F(\"\") in sketches to move big print statements into program memory to save RAM"));
  sdCard.append("appendMe1.txt");
  sdCard.println(F("Note: We can use the F(\"\") in sketches to move big print statements into program memory to save RAM"));
  sdCard.println(F("Note: We can use the F(\"\") in sketches to move big print statements into program memory to save RAM"));
  sdCard.syncFile();

  Serial.println("Done!");
}

void loop()
{

  sdCard.println("Knock Knock");
  
  Serial.println("Knock Knock");

    sdCard.println("Whos there?");
    Serial.println("Whos there?");

    sdCard.println("Justin's Grade");
    Serial.println("Justin's Grade");

      sdCard.println("South African Whimpering");
      Serial.println("South African Whimpering");

      sdCard.syncFile();
      

  //Blink the Status LED because we're done!
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
