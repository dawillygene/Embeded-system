#include<LiquidCrystal.h>
const int rs= 7,en=6,d4=2,d5=3,d6=4,d7=5;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
#include <dht.h>

#define detectionPin 12
#define dht_apin 11     
#define fan 10
#define bulb 8
#define heater 9
 dht DHT;

void setup() {
  Serial.begin(9600); 
  pinMode(fan,OUTPUT);
  pinMode(heater,OUTPUT);
  pinMode(bulb,OUTPUT);
  pinMode(detectionPin,INPUT);
  lcd.begin(16,4);
  lcd.setCursor(2,0);
  lcd.print("  FANK");
  delay(100);
  lcd.setCursor(0,2);
  lcd.print("INCUBATOR SYSTEM");
  delay(100);
  lcd.clear();

}

void loop() {
  DHT.read11(dht_apin);
  byte detect=digitalRead(detectionPin);
  int h = DHT.humidity;  
  int t=DHT.temperature;
  lcd.setCursor(0,0);
  lcd.print("HUM :");
  lcd.setCursor(5,0);
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("TEMP:");
   lcd.setCursor(5,1);
  lcd.print(t);
  Serial.println(DHT.humidity);
  Serial.println(DHT.temperature);

if(detect==HIGH){
 lcd.setCursor(0,2);
  lcd.print("PWR :");
    lcd.setCursor(5,2);
      lcd.print("BACKUP ");

  if(h<=80 && t >38.1)
  {
  digitalWrite(heater,HIGH);
    digitalWrite(bulb,LOW);
  }
   else if(h<=80 && t <36.9)
  {
  digitalWrite(heater,HIGH);
    digitalWrite(bulb,LOW);
  }
   else if(h>89.9 && t <36.9)
   {
     digitalWrite(heater,LOW);
    digitalWrite(bulb,HIGH);
   }
    else if(h>89.9 && t >38.0)
   {
     digitalWrite(heater,LOW);
    digitalWrite(bulb,LOW);
   }
   else
{
 digitalWrite(heater,LOW);
    digitalWrite(bulb,LOW);
}
  
}
else if(detect==LOW)
{lcd.setCursor(0,2);
  lcd.print("PWR :");
    lcd.setCursor(5,2);
      lcd.print("TANESCO");
if(h<=80 && t >38.1)
  {
  digitalWrite(heater,HIGH);
    digitalWrite(bulb,LOW);
  }
   else if(h<=80 && t <36.9)
  {
  digitalWrite(heater,HIGH);
    digitalWrite(bulb,LOW);
  }
   else if(h>89.9 && t <36.9)
   {
     digitalWrite(heater,LOW);
    digitalWrite(bulb,HIGH);
   }
    else if(h>89.9 && t >38.0)
   {
     digitalWrite(heater,LOW);
    digitalWrite(bulb,LOW);
   }
   else
{
 digitalWrite(heater,LOW);
    digitalWrite(bulb,LOW);
}
  


  
  }

}
