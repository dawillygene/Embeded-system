#include <LiquidCrystal.h>
LiquidCrystal lcd(26,16,19,18,5,17);
#include "RTClib.h"
#include <Wire.h>

RTC_DS3231 rtc;
#define breaker 32
#define buzzer 4
#define PIRs 2

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {

   Serial.begin(9600); 
    lcd.begin(16,2);
    lcd.setCursor(0,0);
  // Set relay as OUTPUT
 pinMode(breaker,OUTPUT);
 pinMode(buzzer,OUTPUT);
 pinMode(PIRs,INPUT);
lcd.print("starting");
 digitalWrite(breaker,HIGH);
 digitalWrite(buzzer,HIGH);
 delay(5000);
  digitalWrite(breaker,LOW);
 digitalWrite(buzzer,LOW);
 lcd.clear();
 
  
  // By default the relay is off
  digitalWrite(breaker,LOW);
  // Initializing serial commmunication
  


 
 if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
  }

  }
int states=0; 
int number; 
int second_state;
int count=0;

void loop(){
  byte elia=digitalRead(PIRs);
  DateTime now = rtc.now();
   /* Serial.print(now.hour());
    Serial.print(':');
    Serial.print(now.minute());
    Serial.print(':');
    Serial.print(now.second());
    Serial.println();*/
    Serial.println(second_state);
     Serial.println(number);
      Serial.println(elia);
     lcd.setCursor(0,0);
     lcd.print("TIME");
         lcd.setCursor(4,0);
         lcd.print(":");
         lcd.setCursor(5,0);
                lcd.print(now.hour(), DEC);
                    lcd.setCursor(7,0);
                       lcd.print(":");
                        lcd.setCursor(8,0);
                          lcd.print(now.minute(), DEC);
                             lcd.setCursor(10,0);
                                lcd.print(":");
                                  lcd.setCursor(11,0);
                                    lcd.print(now.second(), DEC);
                                      delay(100);


                                 if(states==0){
                                   number=(now.minute()+1);
                                   second_state = number+1;
                                  states=1;
                                  
                                  }
                                   else if(now.minute()==second_state)
                                        {lcd.setCursor(8,1);
                                       lcd.print("Alarm");
                                          digitalWrite(buzzer,HIGH);
                                           delay(6000);
                                           digitalWrite(buzzer,LOW);
                                          digitalWrite(breaker,LOW);
                                          lcd.clear();
                                          count=0;
                                           states=0;
                                          }
                                  else if(elia==HIGH && count==0){
                                    count++;
                                    }
                                     else if(count== 1){
                                      lcd.setCursor(0,1);
                                   lcd.print("DETECTED");
                                   count++;
                                    }
                                    else if(states==1)
                                    {
                                     if(now.minute()==number)
                                       {
                                       count=0;
                                        
                                           digitalWrite(breaker,HIGH);
                                             states=2;
                                             lcd.clear();
                                        
                                        }
                       

                                        else{
                                          
                                          }
                                      }
                                     

}
