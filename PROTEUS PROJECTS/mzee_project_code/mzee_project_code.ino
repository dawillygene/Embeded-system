#include<LiquidCrystal.h>
       LiquidCrystal lcd(7,6,A1,A2,4,5);
          #define ECHOPIN 2                            // Pin to receive echo pulse
            #define TRIGPIN 3 
               #define sensorPower 4
                 #define sensorPin A0
                   #define red 13
                     #define yellow 12
                       #define green 11
                         #define motor 9
                             int val= 0;

void setup() {
   Serial.begin(9600);
  pinMode(ECHOPIN,INPUT);
       pinMode(TRIGPIN,OUTPUT);
           pinMode(sensorPower,OUTPUT);
             pinMode(red,OUTPUT);
               pinMode(yellow,OUTPUT);
                 pinMode(green,OUTPUT);
                   pinMode(motor,OUTPUT);
                    digitalWrite(sensorPower,LOW);
               lcd.begin(16,2);
           lcd.print("TEMPERATURE");
}

void loop() {
     
  digitalWrite(TRIGPIN,LOW);           
       delayMicroseconds(2);
          digitalWrite(TRIGPIN,HIGH);               
             delayMicroseconds(10);
                 digitalWrite(TRIGPIN,LOW);                  
                    int distance = pulseIn(ECHOPIN,HIGH);        
                       distance= distance/58;                        
                           Serial.println(distance);                     
                               delay(50);
   int level=readSensor();
      Serial.print("Water level");
         Serial.println(level); 
           delay(100); 

           
//condition
if(distance>=40 && level<=512)
{
  digitalWrite(motor,HIGH);
   digitalWrite(yellow,HIGH);
     digitalWrite(green,LOW);
       digitalWrite(red,LOW);
  }
   else if(distance<=40 && level <=512)
   {
     digitalWrite(motor,LOW);
       digitalWrite(red,LOW);
         digitalWrite(yellow,LOW);
            digitalWrite(green,HIGH);    
    }
    else if(distance >=40 && level >=512)
   {
     digitalWrite(motor,LOW);
       digitalWrite(red,HIGH);
         digitalWrite(yellow,LOW);
            digitalWrite(green,LOW);       
    }
      else if(distance <=40 && level >=512)
   {
     digitalWrite(motor,LOW);
       digitalWrite(red,HIGH);
         digitalWrite(yellow,LOW);
            digitalWrite(green,LOW);       
    }
    else
   {
     digitalWrite(motor,LOW);
       digitalWrite(red,LOW);
         digitalWrite(yellow,LOW);
            digitalWrite(green,LOW);       
    }
                                                                       
}

int readSensor()
{
  digitalWrite(sensorPower,HIGH);
  delay(10);
  val=analogRead(sensorPin);
  digitalWrite(sensorPower,LOW);
  return val;
  }
