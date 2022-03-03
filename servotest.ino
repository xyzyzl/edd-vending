#include <Servo.h>

Servo s;
int pos = 0;
void setup() {
  // put your setup code here, to run once:
  s.attach(2);
  s.write(90);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  s.write(180);
  delay(999);
  s.write(90);
  delay(999);
  s.write(0);
  delay(999);
  s.write(90);
  delay(1000);
  Serial.println("tttttttt");
}
