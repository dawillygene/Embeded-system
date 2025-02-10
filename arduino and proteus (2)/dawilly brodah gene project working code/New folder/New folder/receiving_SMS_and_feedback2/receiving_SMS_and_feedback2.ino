/*
 * SIM800L SMS RELAY v1.0
 * Arduino Hardware (Author): Nano V3 (ATmega328)
 * Arduino IDE (Author): 1.6.9
 * T.K.Hareendran/2018
 */

#include <SoftwareSerial.h>
#define echoPin 4
#define trigPin 5
long duration; 
int distance;
int y=0;
//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2 

char incomingByte; 
String inputString;
int relay = 13; // Output for Relay Control

void setup() 
{
  
      pinMode(relay,OUTPUT);
      pinMode(trigPin,OUTPUT); 
pinMode(echoPin,INPUT);
      digitalWrite(relay, LOW); // Initial state of the relay
      Serial.begin(9600);
      mySerial.begin(9600); 

     while(!mySerial.available()){
        mySerial.println("AT");
        delay(1000); 
        Serial.println("Connecting...");
        }
      Serial.println("Connected!");  
      mySerial.println("AT+CMGF=1");  //Set SMS to Text Mode 
      delay(1000);  
      mySerial.println("AT+CNMI=1,2,0,0,0");  //Procedure to handle newly arrived messages(command name in text: new message indications to TE) 
      delay(1000);
      mySerial.println("AT+CMGL=\"REC UNREAD\""); // Read Unread Messages
     }

     int ultrasonic1(){
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(100);  // Delay of 1000 milli seconds or 1 second
  mySerial.print("AT+CMGS=");
  mySerial.print("\"");
  mySerial.print("+");
  mySerial.print("255679335817");
  mySerial.println("\""); 
  delay(100);
  mySerial.println("MAFUTA YAPO YAKUTOSHA");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(400);
}

void SendMessage1()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(100);  // Delay of 1000 milli seconds or 1 second
  mySerial.print("AT+CMGS=");
  mySerial.print("\"");
  mySerial.print("+");
  mySerial.print("255679335817");
  mySerial.println("\""); 
  delay(100);
  mySerial.println("MAFUTA YAPO NUSU");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(400);
}

void SendMessage2()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(100);  // Delay of 1000 milli seconds or 1 second
  mySerial.print("AT+CMGS=");
  mySerial.print("\"");
  mySerial.print("+");
  mySerial.print("255679335817");
  mySerial.println("\""); 
  delay(100);
  mySerial.println("MAFUTA YANAKARIBIA KUISHA KABISA");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(400);
}

void loop()
{  
  distance=ultrasonic1();
  Serial.print("Distance: ");
  Serial.println(distance);
  if(mySerial.available()){
      delay(100);

      // Serial Buffer
      while(mySerial.available()){
        incomingByte = mySerial.read();
        inputString += incomingByte; 
        }

        delay(10);      

        Serial.println(inputString);
        inputString.toUpperCase(); // Uppercase the Received Message

        //turn RELAY ON or OFF
        if (inputString.indexOf("MAFUTA") > -1){
          digitalWrite(relay,HIGH);
          distance=ultrasonic1();
          Serial.print("Enter in condition");
          delay(1000);
          
          if(distance<8 && distance>1){
          Serial.println("condion high");
          SendMessage();
          inputString = "";
          }
          if(distance<15 && distance>=8){
            Serial.println("condion level");
            
          SendMessage1();
          inputString = "";
          }
         
          
          }
        /*if (inputString.indexOf("OFF") > -1){
          digitalWrite(relay,LOW);
          }          

        delay(50);

        //Delete Messages & Save Memory
       if (inputString.indexOf("OK") == -1){
        mySerial.println("AT+CMGDA=\"DEL ALL\"");

        delay(1000);
        

        inputString = "";
  }*/

}

else if(distance<21 && distance>=16){
            Serial.println("condion low");
          SendMessage2();
          delay(10000);
          inputString = "";
         
          }
          else{
            
            }
}
