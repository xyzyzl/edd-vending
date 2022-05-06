#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 3, 2, 30, 32, 34);

void setup() {
    lcd.begin(16, 2);
    lcd.clear();
    lcd.print("Hello world");
}

void loop() {
    // put your main code here, to run repeatedly:

}
