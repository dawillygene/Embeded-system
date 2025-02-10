#include<LiquidCrystal.h>
LiquidCrystal lcd( 6,7,2,3,4,5);
#define breaker 13
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
void setup() {

   Serial.begin(9600); 
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("dawilly gene");
    delay(3000);
    Serial.println(F("DHTxx test!"));

  dht.begin();

 
  // By default the relay is off
  digitalWrite(breaker,LOW);
  // Initializing serial commmunication
  



  }
  

void loop(){  
  delay(3000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  float f = dht.readTemperature(true);
 //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hum:");
  lcd.setCursor(4,0);
  lcd.print(h);
   lcd.setCursor(9,0);
     lcd.print("%");
     lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.setCursor(5,1);
  lcd.print(t);
   lcd.setCursor(10,1);
     lcd.print("C");
  
  
 
}
