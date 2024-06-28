#include <SoftwareSerial.h>

SoftwareSerial BT(9, 10);

#define btn D3
#define act D4

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  // put your setup code here, to run once:
  pinMode(btn, INPUT_PULLUP);
  pinMode(act, OUTPUT);
}

long time_var = 0;
bool a_state = false;
bool state = 1;

void loop() {
  time_var = millis();
  if(time_var > 40000) time_var = 2000;
  // put your main code here, to run repeatedly:
  if (digitalRead(btn) == LOW && time_var % 1000 == 0) 
    BT.write("closed\n");

  if (BT.available() && BT.read() == 49)
  {
    Serial.println("open");
    digitalWrite(act, HIGH);
    delay(3000);
    digitalWrite(act, LOW);
  }

  state = digitalRead(btn);
}
