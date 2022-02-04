#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int but = 6, pir = 10;
int but2 = 7, but3 = 8, but4 = 9; // and all of them must link to a stepper motor, which we'll get later
bool wait = 0;

void setup() {
  // put your setup code here, to run once:
  wait = 0;
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Initializing PIR");
  Serial.begin(9600);
  Serial.println();
  Serial.println("initializing pir");
  for(int i = 0; i < 16; i++)
  {
    lcd.setCursor(i,1);
    lcd.print(".");
    delay(1000);
  }
  Serial.println("done");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DONE");
  delay(690);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Insert a million");
  lcd.setCursor(0,1);
  lcd.print("dollars now");
  pinMode(but, INPUT);
  pinMode(pir, INPUT);
}

int pre = 0, pre2 = 0, pre3 = 0, pre4 = 0;
int aft = 1;
void loop() {
  if(wait)
  {
    // Serial.println(digitalRead(pir));
    // wait
    if(digitalRead(pir) == HIGH && digitalRead(pir) != aft)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("$$ found");
      delay(621); // dElay
      wait = 0;
      pre = pre2 = pre3 = pre4 = 0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Insert a million");
      lcd.setCursor(0,1);
      lcd.print("dollars now");
    }
    aft = digitalRead(pir);
    return;
  }
  aft = 1;
  // put your main code here, to run repeatedly:
  if(digitalRead(but) == pre && digitalRead(but2) == pre && digitalRead(but3) == pre && digitalRead(but4) == pre) return;
  if(digitalRead(but) == LOW && digitalRead(but2) == LOW && digitalRead(but3) == LOW && digitalRead(but4) == LOW)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Insert a million");
    lcd.setCursor(0,1);
    lcd.print("dollars now");
  } else if(digitalRead(but) == HIGH)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ordering item");
    lcd.setCursor(0,1);
    lcd.print("1");
    wait = 1; // need to start waiting for payment
  } else if(digitalRead(but2) == HIGH)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ordering item");
    lcd.setCursor(0,1);
    lcd.print("2");
    wait = 1; // need to start waiting for payment
  } else if(digitalRead(but3) == HIGH)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ordering item");
    lcd.setCursor(0,1);
    lcd.print("3");
    wait = 1; // need to start waiting for payment
  } else if(digitalRead(but4) == HIGH)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ordering item");
    lcd.setCursor(0,1);
    lcd.print("4");
    wait = 1; // need to start waiting for payment
  }
  pre = digitalRead(but);
  pre2 = digitalRead(but2);
  pre3 = digitalRead(but3);
  pre4 = digitalRead(but4);
}
