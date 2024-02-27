#include "Adafruit_LiquidCrystal.h"

const byte POTPIN = 3;
const byte NOISEPIN = A0;
const byte BUTTONPIN = A1;

Adafruit_LiquidCrystal screen(0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(BUTTONPIN, INPUT);
  pinMode(POTPIN, INPUT);

  randomSeed(analogRead(NOISEPIN));

  Serial.begin(9600);

  if (!screen.begin(16, 2)){
    Serial.println("Couldnt start the screen? check wiring");
    while(1);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BUTTONPIN) == HIGH) {
    Serial.println("Rolling Dice");
    int diceType = analogRead(POTPIN);
    diceType = map(diceType, 0, 1023, 1, 6);
  }
}

//HAN COMMENT just need to add the diceRoll method from part 1 of the dice roller model answer
