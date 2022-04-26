#include <Servo.h>

Servo s[4];
Servo s0, s1, s2, s3;
int but[4] = {6, 7, 8, 9};

int v = 10;

void setup() {
  // put your setup code here, to run once:
  s0.attach(22);
  s1.attach(23);
  s2.attach(24);
  s3.attach(25);

  s0.write(90);
  s1.write(90);
  s2.write(90);
  s3.write(90);
  
  Serial.begin(9600);
}

void loop() {
    if (digitalRead(but[0]))
        s0.write(90 + v);
    else
        s0.write(90);

    if (digitalRead(but[1]))
        s1.write(90 + v);
    else
        s1.write(90);

    if (digitalRead(but[2]))
        s2.write(90 + v);
    else
        s2.write(90);

    if (digitalRead(but[3]))
        s3.write(90 + v);
    else
        s3.write(90);

    bool buttonPressed = false;
    for (int i = 0; i < 4; ++i)
        buttonPressed = buttonPressed || digitalRead(but[i]);
    if (buttonPressed)
        delay(1000);

  Serial.println("Update:");
  Serial.println(s0.read());
}
