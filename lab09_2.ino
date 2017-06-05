#include <LiquidCrystal.h>
#include <Ultrasonic.h>
LiquidCrystal lcd(12,11,9,3,4,5);
#define TRIGGER_PIN 13
#define ECHO_PIN 8
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);


void setup() 
{
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(0,int0,LOW);
    lcd.begin(20, 2);
  lcd.print("hello, world!");
}
void loop() {


}
void int0()
{

    float cmMsec, inMsec;
long microsec = ultrasonic.timing();
cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); // 計算距離，單位: 英吋
lcd.setCursor (0,0);
  lcd.print ("MS:");   
  lcd.print(microsec);
  lcd.print ("  CM:");
  lcd.print(cmMsec);
   lcd.setCursor (0,1);
  lcd.print ("IN:");
  lcd.print(inMsec);
  delay(900);
  
}
