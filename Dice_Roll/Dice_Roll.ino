const byte POTPIN = 3;
const byte BUTTONPIN = A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(BUTTONPIN, INPUT);
  pinMode(POTPIN, INPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BUTTONPIN) == HIGH) {
    Serial.println("Rolling Dice");
    int diceType = analogRead(POTPIN);
    diceType = map(diceType, 0, 1023, 1, 6);
  }
}
