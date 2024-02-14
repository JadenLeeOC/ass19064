#include <Servo.h>

const byte BUTTONPIN = 4;
const byte SERVOPIN = 3;
const byte MICPIN = 2;
const byte LEDPIN = 5;
const int KNOCKLEVEL = 250;

Servo lock;
void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPIN, OUTPUT);
  pinMode(MICPIN, INPUT);
  pinMode(BUTTONPIN, INPUT);

  lock.attach(SERVOPIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (analogRead(MICPIN) >= KNOCKLEVEL) {
    digitalWrite(LEDPIN, HIGH);
    lock.write(180);
    delay(5000);
    
  }
  if (analogRead(BUTTONPIN) == HIGH) {
    lock.write(0);
    digitalWrite(LEDPIN, LOW);
  }
}
