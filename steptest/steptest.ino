#include <CheapStepper.h>

CheapStepper stepper[4] = {CheapStepper(13, 12, 11, 10),
                          CheapStepper(9, 8, 7, 6),
                          CheapStepper(5, 4, 3, 2),
                          CheapStepper(14, 15, 16, 17)};

const int buttonPins[4] = {50, 51, 52, 53};

boolean cw = true;
boolean ccw = false;

void setup() {
    for (int i = 0; i < 4; ++i)
    {
        stepper[i].setRpm(20);
        stepper[i].moveTo(ccw, 0);
    }
        
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

    for (int i = 0; i < 4; ++i)
    {
        buttonStates[i] = digitalRead(buttonPins[i]);

//        Serial.println(i + ": " + buttonStates[i]);
        
        if (buttonStates[i])
            stepper[i].moveDegrees(ccw, 90);
    }

//    debugStepper.moveDegrees(true, 90);
}
