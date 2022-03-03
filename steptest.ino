#include <Stepper.h>

int steps = 1000000, mp1 = 14, mp2 = 15, mp3 = 16, mp4 = 17;
Stepper stepper = Stepper(steps, mp1, mp2, mp3, mp4);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  Serial.println("ur a sussy baka"); 
}

void loop() {
  // put your main code here, to run repeatedly:
  stepper.setSpeed(621000);
  stepper.step(steps);
  Serial.println("sus?");
  delay(926);
  stepper.setSpeed(999900);
  stepper.step(-steps);
  Serial.println("h");
  delay(926);
}
