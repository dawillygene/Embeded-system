// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include "RTClib.h"
#include <Adafruit_I2CDevice.h>
 #include <Wire.h>
#include <SoftwareSerial.h>
 #include <SPI.h>
#define echo 7
#define trigger 8


RTC_DS3231 rtc;
#define alarm 5
#define led 6

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thur", "Fri", "Sat"};
// Configure software serial port
SoftwareSerial  mySerial(10,11);
// variables for current and voltage
 long duration;
int distance;
int var=1;
void setup () {
  // Initializing serial commmunication
 mySerial.begin(9600);
  Serial.begin(9600);
// Set relay as OUTPUT
pinMode(echo,INPUT);
pinMode(trigger,OUTPUT);
digitalWrite(trigger,LOW);
  pinMode(led, OUTPUT);
    pinMode(alarm, OUTPUT);
  // By default the relay is on
  digitalWrite(alarm, LOW);

#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }


    digitalWrite(alarm,HIGH);
   digitalWrite(led,HIGH);
   delay(500);
     digitalWrite(alarm, LOW);
       digitalWrite(led, LOW);
}

void loop () {
  DateTime now = rtc.now();
 Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigger,LOW);
 duration=pulseIn(echo,HIGH);
 distance=duration*0.017; 
   Serial.println(distance);
 remainder();
 updateSerial(); 
  delay(50);
}



// Function that sends SMS
void sendSMS1(){
 // AT command to set SIM900 to SMS mode
  mySerial.print("AT+CMGF=1\r"); 
  delay(100);
  // REPLACE THE X's WITH THE RECIPIENT'S MOBILE NUMBER
  // USE INTERNATIONAL FORMAT CODE FOR MOBILE NUMBERS
  mySerial.println("AT+CMGS=\"+255689470716\"\r");
  delay(100);
  // Send the SMS
  mySerial.println("There is a person in your premises");
  delay(100);
  // End AT command with a ^Z, ASCII code 26
 mySerial.println((char)26); 
  delay(100);
  mySerial.println();
  // Give module time to send SMS
  delay(5000);  
   Serial.print("SMS SENT");
}

void remainder(){
DateTime now = rtc.now();
if (now.hour()>=0 && now.minute() >=2){
if (distance < 5){
if (var==1){
  digitalWrite(alarm,HIGH);
   digitalWrite(led,HIGH);
sendSMS1();
var=2;
  }
}
else{
 digitalWrite(alarm,LOW);
  digitalWrite(led,LOW);
var=1;
 }
 }
 else{
 }
 
}


void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}
