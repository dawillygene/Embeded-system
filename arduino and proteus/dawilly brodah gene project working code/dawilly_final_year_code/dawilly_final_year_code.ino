#include "DHT.h"
#define DHTPIN A4
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
#define pir 11
#define fan 7
#define bulb 8
#define switch1 2
#define switch2 3
int gene_state;
int opstate=0;
 const unsigned long eventInterval = 30000;
unsigned long previousTime = 0;
int count;


void setup() {
Serial.begin(9600); 
pinMode(switch1,INPUT);
pinMode(switch2,INPUT);
pinMode(pir,INPUT);
pinMode(fan,OUTPUT);
pinMode(bulb,OUTPUT);
digitalWrite(fan,LOW);

}

void loop()
 {
  dht.begin();
  unsigned long currentTime = millis();
  int Second_state=digitalRead(switch1);
   int Third_state= digitalRead(switch2);
    byte PIR_READINGS=digitalRead(pir);
   Serial.println(PIR_READINGS);
digitalWrite(bulb,LOW);
int h = dht.readHumidity();
int temp = dht.readTemperature();
  Serial.println(temp);
   delay(2000);
    Serial.println(currentTime);
     Serial.println(previousTime);



if (currentTime - previousTime >= eventInterval) {
   previousTime = currentTime;
      if(PIR_READINGS==LOW){
                     digitalWrite(fan,HIGH);
                      
                             }
                              
    
   
  }



  if(PIR_READINGS==HIGH){
    previousTime = currentTime;
  
    if(Second_state==LOW && Third_state==LOW )
                 {
                  if(temp > 12){
                     digitalWrite(fan,LOW);
                      
                             }
                               else{
                                    digitalWrite(fan,HIGH);
                                                  }
                  }
                  
                  
 }
 else if(Second_state==HIGH && Third_state==LOW)
 {
  digitalWrite(fan,HIGH);
  
  }
   else if(Second_state==LOW && Third_state==HIGH)
 {
  digitalWrite(fan,HIGH);
  
  }
 

 }





  
