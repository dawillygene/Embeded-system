#include "RTClib.h"
#include <Wire.h>

RTC_DS3231 rtc;
#define buzzer A0
#define motor1 11
#define motor2 12
#define pump 7

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {

   Serial.begin(9600); 
 pinMode(motor1,OUTPUT);
 pinMode(motor2,OUTPUT);
 pinMode(pump,OUTPUT);
 pinMode(buzzer,OUTPUT);
 digitalWrite(pump,LOW);
 
 if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
  }
digitalWrite(buzzer,HIGH);
  delay(3000);
   digitalWrite(buzzer,LOW);
  }
int states=0; 
int number; 
int second_state;
int count=0;

void motor(){
  digitalWrite(motor1,HIGH);
  delay(500);
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);
  delay(700);
  digitalWrite(motor2,LOW);
  }

  void pumps()
  {
    digitalWrite(pump,HIGH);
    delay(8000);
    digitalWrite(pump,LOW);
    
    }
  

void loop(){
  DateTime now = rtc.now();
    Serial.print(now.hour());
    Serial.print(':');
    Serial.print(now.minute());
    Serial.print(':');
    Serial.print(now.second());
    Serial.println();
    Serial.println(second_state);
     Serial.println(number);

     

                                 if(states==0){
                                  Serial.println("IMEKUBALI ONE");
                                   number=(now.minute()+1);
                                   states=1;
                                  
                                  }
                                  
                                    else if(states==1)
                                    {
                                     if(now.minute()==number)
                                       {  Serial.println("IMEKUBALI");
                                       count=0;
                                         digitalWrite(buzzer,HIGH);
  delay(3000);
   digitalWrite(buzzer,LOW);
                                          digitalWrite(motor1,HIGH);
  delay(500);
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);
  delay(700);
  digitalWrite(motor2,LOW);
                                           delay(3000);
                                            digitalWrite(pump,HIGH);
    delay(5000);
     digitalWrite(pump,LOW);
                                             states=0;
                                             
                                        }
                       

                                        }
                                     

}
