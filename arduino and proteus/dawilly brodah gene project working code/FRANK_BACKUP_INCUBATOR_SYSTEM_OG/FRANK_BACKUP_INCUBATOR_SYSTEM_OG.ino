#include<LiquidCrystal.h>
const int rs=6,en=7,d4=2,d5=3,d6=4,d7=5;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
#include <Wire.h> 
#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHTPIN A0
#define DHTTYPE DHT11 
DHT dht(DHTPIN,DHTTYPE);
#define relay 10
    

void setup() {
  Serial.begin(9600);
    dht.begin();
  pinMode(relay,OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("INCUBATOR");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("");
  delay(1000);
  lcd.clear();

}

void loop() {
int h = dht.readHumidity();
int temp = dht.readTemperature();
 
lcd.setCursor(0,0);
  lcd.print("TEMP:");
    lcd.setCursor(5,0);
    lcd.print(temp);
     lcd.setCursor(8,0);
       lcd.print("C");
        lcd.setCursor(0,1);
  lcd.print("HUMD:");
    lcd.setCursor(5,1);
    lcd.print(h);
     lcd.setCursor(8,1);
       lcd.print("%");
      delay(2000);


if(h<50)
{
 digitalWrite(relay,LOW); 
  }
  else{
     digitalWrite(relay,HIGH);
    }
 
  
 
}
