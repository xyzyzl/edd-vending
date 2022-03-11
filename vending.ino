#include <LiquidCrystal.h>
#include <CheapStepper.h>
#include <Servo.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int but = 6, pir = 10;
int but2 = 7, but3 = 8, but4 = 9; // and all of them must link to a stepper motor, which we'll get later
bool wait = 0;

int mp1 = 13, mp2 = 14, mp3 = 15, mp4 = 16;
CheapStepper stepperx(mp1, mp2, mp3, mp4);
int mp5 = 25, mp6 = 26, mp7 = 27, mp8 = 28;
CheapStepper steppery(mp5, mp6, mp7, mp8);
Servo s[4];

int x[4] = {69, 69, 69, 69}; // will need to take measurements later
int y[4] = {69, 69, 69, 69};
int xn = 69, yn = 69; // neutral position, at the bottom near the recepticle

void move_to(int i)
{
  int sx = abs(x[i] - xn);
  int sy = abs(y[i] - xn);
  // number of steps between neutral and the ith slot
  // set direction to 0 if sx < 0 amd 1 if sx > 0
  // move horizontal stepper sx steps
  for(int i = 0; i < sx; i++)
  {
    // start move here
    stepperx.moveDegrees(1, sx); // will need to measure for exact values
    delayMicroseconds(300);
  }
  // repeat the same with y
  for(int i = 0; i < sy; i++)
  {
    steppery.moveDegrees(1, sy); // will need to measure for exact values
    delayMicroseconds(300);
  }
}

void move_from(int i)
{
  int sx = abs(xn - x[i]);
  int sy = abs(yn - y[i]);
  // number of steps between neutral and the ith slot
  // set direction to 0 if sx < 0 amd 1 if sx > 0
  // move horizontal stepper sx steps
  for(int i = 0; i < sx; i++)
  {
    stepperx.moveDegrees(0, sx);
    delayMicroseconds(300);
  }
  // repeat the same with y
  for(int i = 0; i < sy; i++)
  {
    steppery.moveDegrees(0, sy);
    delayMicroseconds(300);
  }
}

void move_motor(int i)
{
  // move motor to index x[i], y[i] specifically
  move_to(i);
  // rotate as needed with servo (measure how much it needs to rotate to knock one thing off)
  s[i].write(180);
  delay(950);
  s[i].write(90);
  delay(500);
  // move motor back
  move_from(i);
}

void setup() {
  // put your setup code here, to run once:
  wait = 0;
  // initialize the LCD and the PIR
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

  // initialize stepper motor
  stepperx.setRpm(20);
  steppery.setRpm(20);

  // initialize servo
  for(int i = 0; i < 4; i++) s[i].attach(20+i);
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
