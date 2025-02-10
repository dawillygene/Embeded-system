

#include<LiquidCrystal.h>
const int rs= 7,en=6,d4=2,d5=3,d6=4,d7=5;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
#include <dht.h>

    #define motor 10    
       #define tempPin A0
          #define dht_apin 8 
             #define green 11
                 #define yellow 12
                     #define red 13
                        #define buzzer 5
                               #define vibrpin 9
      dht DHT;
         int vibration;
void setup(){
             Serial.begin(9600);
                 pinMode(motor,OUTPUT);
                       pinMode(green,OUTPUT);
                           pinMode(red,OUTPUT);
                               pinMode(yellow,OUTPUT);
                                  lcd.begin(16,2);
                                     Serial.println("AMON PROJECT");
}

void loop(){
//DHT START 
    DHT.read11(dht_apin);
    Serial.print("Current humidity = ");
    Serial.println(DHT.humidity);
    Serial.print("%  ");
    float h = DHT.humidity;
    delay(100);
  
//
vibration=digitalRead(vibrpin);
int  val=analogRead(tempPin);
float temp=(val/2.05317391304);
lcd.clear();
//
if(temp<=30 && h<=2 && vibration==LOW)
 {
  conditionsafe();
    lcd.print("OPERATE");
      lcd.setCursor(0,1);
        lcd.print("safe running");
          delay(10);
 }
 else if(temp<=30 && h<=2 && vibration==HIGH)
 {
 conditionHalfsafe();
 lcd.setCursor(0,0);
   lcd.print("ABNOMAL");
     lcd.setCursor(0,1);
       lcd.print("Vibration");
         delay(10);
 }
 else if(temp<=30 && h>2 && vibration==LOW)
 {
 conditionHalfsafe();
    lcd.setCursor(0,0);
      lcd.print("ABNOMAL");
        lcd.setCursor(0,1);
          lcd.print("Humidity");
            delay(10);
 }
  else if(temp<=30 && temp<=44 && h>2 && vibration==HIGH)
 {
 conditiondanger();
  lcd.setCursor(0,0);
    lcd.print("DANGER");
      lcd.setCursor(0,1);
       lcd.print("H&V");
         delay(10);
 }
 else if(temp>45 && h<=2 && vibration==LOW)
 {
 conditionHalfsafe();
  lcd.setCursor(0,0);
    lcd.print("ABNOMAL");
      lcd.setCursor(0,1);
        lcd.print("Temperature");
          delay(10);
 }
else if(temp>45 && h<=2 && vibration==HIGH)
 {
 conditiondanger();
  lcd.setCursor(0,0);
    lcd.print("danger");
     lcd.setCursor(0,1);
      lcd.print("Over heating");
        delay(10);
 }
 else if(temp>45 && h>2 && vibration==LOW)
 {
 conditiondanger();
  lcd.setCursor(0,0);
    lcd.print("DANGER");
     lcd.setCursor(0,1);
       lcd.print("humidity inside");
         delay(10);
 }
 else if(temp>45 && h>2 && vibration==HIGH)
 {
 conditiondanger();
  lcd.setCursor(0,0);
   lcd.print("DANGER");
     lcd.setCursor(0,1);
       lcd.print("T&H&V");
  delay(10);
 }
 else{
  NON();
  }
}
void conditionsafe()
{
digitalWrite(green,HIGH);
digitalWrite(buzzer,LOW);
digitalWrite(red,LOW);
digitalWrite(yellow,LOW);
}
void conditionHalfsafe()
{
digitalWrite(yellow,HIGH);
digitalWrite(green,LOW);
digitalWrite(buzzer,LOW);
digitalWrite(red,LOW);
digitalWrite(buzzer,HIGH);
}
void conditiondanger()
{
digitalWrite(red,HIGH);
digitalWrite(buzzer,HIGH);
delay(50);
digitalWrite(yellow,LOW);
digitalWrite(green,LOW);
}
void NON()
{
digitalWrite(red,LOW);
digitalWrite(buzzer,LOW);
digitalWrite(yellow,LOW);
digitalWrite(green,LOW);
}
