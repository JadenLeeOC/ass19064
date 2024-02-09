
#include <Servo.h>


const byte LEDPIN = 13;       //Declares Pins
const byte PAWPIN1 = 1;       //Declares Pins
const byte PAWPIN2 = 2;       //Declares Pins
const byte PAWPIN3 = 3;       //Declares Pins
const byte PAWPIN4 = 4;       //Declares Pins
const byte LEFTEARPIN = 9;    //Declares Pins
const byte RIGHTEARPIN = 10;  //Declares Pins

Servo leftEar;
Servo rightEar;

void setup() {
  pinMode(LEDPIN, OUTPUT);  //Sets the LED to OUTPUT
  pinMode(PAWPIN1, INPUT);  //Sets pin to INPUT
  pinMode(PAWPIN2, INPUT);  //Sets pin to INPUT
  pinMode(PAWPIN3, INPUT);  //Sets pin to INPUT
  pinMode(PAWPIN4, INPUT);  //Sets pin to INPUT

  leftEar.attach(LEFTEARPIN);
  rightEar.attach(RIGHTEARPIN);
}

void loop() {
  // If Paw 1 is pressed then the LED will turn on
  if (digitalRead(PAWPIN1) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }
  // If Paw 2 is pressed then the LED will turn on
  if (digitalRead(PAWPIN2) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }
  // If Paw 3 is pressed then the LED will turn on
  if (digitalRead(PAWPIN3) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }
  // If Paw 4 is pressed then the LED will turn on
  if (digitalRead(PAWPIN4) == HIGH) {
    int score = playGame();
  }
}

int playGame() {
  byte score = 99;
  return score;
}

void wagEars() {
  leftEar.write(0);
  rightEar.write(0);
  leftEar.write(90);
  rightEar.write(90);
  leftEar.write(0);
  rightEar.write(0);
}

void blinkingLed() {
  byte randNumber = random(1, 3);
  for (int i = 0; i < randNumber; i++) {

    digitalWrite(LEDPIN, HIGH);
    delay(500);
    digitalWrite(LEDPIN, LOW);
    delay(500);
  }
}
