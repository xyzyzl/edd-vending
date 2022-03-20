#include <CheapStepper.h>


//CheapStepper stepper[24] = {CheapStepper(10,11,12,13),
//CheapStepper(11,10,12,13),
//CheapStepper(12,10,11,13),
//CheapStepper(10,12,11,13),
//CheapStepper(11,12,10,13),
//CheapStepper(12,11,10,13),
//CheapStepper(12,11,13,10),
//CheapStepper(11,12,13,10),
//CheapStepper(13,12,11,10),
//CheapStepper(12,13,11,10),
//CheapStepper(11,13,12,10),
//CheapStepper(13,11,12,10),
//CheapStepper(13,10,12,11),
//CheapStepper(10,13,12,11),
//CheapStepper(12,13,10,11),
//CheapStepper(13,12,10,11),
//CheapStepper(10,12,13,11),
//CheapStepper(12,10,13,11),
//CheapStepper(11,10,13,12),
//CheapStepper(10,11,13,12),
//CheapStepper(13,11,10,12),
//CheapStepper(11,13,10,12),
//CheapStepper(10,13,11,12),
//CheapStepper(13,10,11,12)
//}; //5 7 8 13 14

// this does not work ???
//CheapStepper stepper[24] = {CheapStepper(10,11,12,13),
//CheapStepper(11,10,12,13),
//CheapStepper(12,10,11,13),
//CheapStepper(10,12,11,13),
//CheapStepper(11,12,10,13),
//CheapStepper(12,11,10,13)};

//CheapStepper stepper(12,11,10,13);

CheapStepper stepper[4] = {
    CheapStepper(12,11,10,13),
    CheapStepper(8, 7, 6, 9),
    CheapStepper(4, 3, 2, 5),
    CheapStepper(24, 26, 28, 22)
};

/*
                          CheapStepper(9, 8, 7, 6),
                          CheapStepper(5, 4, 3, 2),
                          CheapStepper(14, 15, 16, 17)};*/

const int stepperLength = sizeof stepper / sizeof stepper[0];

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

    for (int i = 0; i < stepperLength; ++i)
    {
//        buttonStates[i] = digitalRead(buttonPins[i]);

//        Serial.print((String)i + ": " + (String)buttonStates[i] + "    ");
        
//        if (buttonStates[i])
//            Serial.println(i);
            stepper[i].moveDegrees(ccw, 90);
    }

    Serial.println();

//    debugStepper.moveDegrees(true, 90);
}
