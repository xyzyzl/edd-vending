#include <Servo.h>

// speed of servo
const int v = 8;

// pins
const int ser[4] = {22, 24, 26, 28};
const int but[4] = {6, 7, 8, 9};
const int PIRPin = 5;

// servos, doesn't work in array for some reason I think
Servo s0, s1, s2, s3;

// whether or not coin has been inserted
bool paid = false;

void setup() {
    // debug
    Serial.begin(9600);
    
    for (int i = 0; i < 4; ++i)
    {
        pinMode(ser[i], OUTPUT);
        pinMode(but[i], INPUT);
    }
    
    s0.attach(22);
    s1.attach(24);
    s2.attach(26);
    s3.attach(28);
    
    s0.write(90);
    s1.write(90);
    s2.write(90);
    s3.write(90);

    // PIR initialization
    Serial.print("Intializing sensor ");
    for(int x = 0; x < 20; x++) //Initialization lasts for 20 sec
    {
        Serial.print(".");
        delay(1000);
    }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
}

void loop() {
    if (!paid)
    {
        if (digitalRead(PIRPin))
        {
            paid = true;
            Serial.println("Coin detected!");
        }
        return;
    }
    
    bool buttonPressed = false;
    for (int i = 0; i < 4; ++i)
        buttonPressed = buttonPressed || digitalRead(but[i]);
    if (buttonPressed)
    {
        Serial.println("Button pressed! Dispensing item...");
        paid = false;
    }

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

    if (buttonPressed)
        delay(1000);

    // debug
//  Serial.println("Update:");
//  Serial.println(s0.read());
}
