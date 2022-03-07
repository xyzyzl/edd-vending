#include <CheapStepper.h>

CheapStepper stepper[2] = {CheapStepper(13, 12, 11, 10),
                          CheapStepper(9, 8, 7, 6)};
//CheapStepper debugStepper(10, 11, 12, 13);

const int buttonPins[4] = {50, 51, 52, 53};

boolean moveClockwise = true;

void setup() {
    for (int i = 0; i < 2; ++i)
        stepper[i].setRpm(20);
        
    Serial.begin(9600);
//    Serial.print("rpm = delay of ");
//    Serial.print(stepper[0].getDelay()); // get delay between steps for set RPM
//    Serial.print(" microseconds between steps");
//    Serial.println();

    for (int i = 0; i < 4; ++i)
        pinMode(buttonPins[i], INPUT);
}

void loop() {
    int buttonStates[4];

    for (int i = 0; i < 2; ++i)
    {
        buttonStates[i] = digitalRead(buttonPins[i]);
//        if (buttonStates[i] && i < 2)
            stepper[i].moveDegrees(moveClockwise, 90);
    }

//    debugStepper.moveDegrees(true, 90);
}
