
#include <CheapStepper.h>


CheapStepper stepper (8,9,10,11); 



boolean moveClockwise = true;
const int button1Pin = 7;
int button1State = 0;

void setup() {
  stepper.setRpm(20); 
  Serial.begin(9600); Serial.println();
  Serial.print(" rpm = delay of ");
  Serial.print(stepper.getDelay()); // get delay between steps for set RPM
  Serial.print(" microseconds between steps");
  Serial.println();
  pinMode(button1Pin,INPUT);
  
}

void loop() {
  
  button1State = digitalRead(button1Pin);
  
  moveClockwise = true;
  if (button1State==HIGH){
      stepper.moveDegrees(moveClockwise, 90);
  
      delay(1000); // wait a sec
  }

  
}
