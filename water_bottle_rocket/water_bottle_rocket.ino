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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Environment.begin();
  Serial.println("LPS25HB Pressure Sensor Example 1 - Basic Readings");
  Serial.println();

  while (!Serial) {
    ;
  }
  Serial.print("\nInitializing SD card...");
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card inserted?");
    Serial.println("* is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    while (1)
      ;
  } else {
    Serial.println("Wiring is correct and a card is present.");
  }

  // print the type of card
  Serial.println();
  Serial.print("Card type:         ");
  switch (card.type()) {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("Unknown");
  }

  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
  if (!volume.init(card)) {
    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
    while (1)
      ;
  }

  Serial.print("Clusters:          ");
  Serial.println(volume.clusterCount());
  Serial.print("Blocks x Cluster:  ");
  Serial.println(volume.blocksPerCluster());

  Serial.print("Total Blocks:      ");
  Serial.println(volume.blocksPerCluster() * volume.clusterCount());
  Serial.println();

  // print the type and size of the first FAT-type volume
  uint32_t volumesize;
  Serial.print("Volume type is:    FAT");
  Serial.println(volume.fatType(), DEC);

  volumesize = volume.blocksPerCluster();  // clusters are collections of blocks
  volumesize *= volume.clusterCount();
  volumesize /= 2;  // SD card blocks are always 512 bytes (2 blocks are 1KB)
  Serial.print("Volume size (Kb):  ");
  Serial.println(volumesize);
  Serial.print("Volume size (Mb):  ");
  volumesize /= 1024;
  Serial.println(volumesize);
  Serial.print("Volume size (Gb):  ");
  Serial.println((float)volumesize / 1024.0);

  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
  root.openRoot(volume);

  // list all files in the card with date and size
  root.ls(LS_R | LS_DATE | LS_SIZE);
}

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
