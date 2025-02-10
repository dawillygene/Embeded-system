#include <SPI.h>
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#define motor1 4
#define motor2 5
SoftwareSerial mySerial(9,10);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int fingerprintID = 0;
int count_value =0;
int prestate =0;


void sms(){
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  Serial.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(1000);
  Serial.print("AT+CMGS=\"+255675066546\"\r");
  delay(1000); 
  Serial.print("MLANGO UMEFUNGWA");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(1000);
  Serial.print((char)26);// (required according to the datasheet)
  delay(5000);
  Serial.println();
  Serial.println("Text Sent.");
  delay(1000);
}
void sms1(){
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  Serial.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(1000);
  Serial.print("AT+CMGS=\"+255675066546\"\r");
  delay(1000); 
  Serial.print("MLANGO UMEFUNGULIWA");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(1000);
  Serial.print((char)26);// (required according to the datasheet)
  delay(5000);
  Serial.println();
  Serial.println("Text Sent.");
  delay(1000);
}

void startFingerprintSensor()
{
  Serial.begin(9600);
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
    digitalWrite(8,HIGH);
  } else {
    Serial.println("Did not find fingerprint sensor");
  }
  Serial.println("Waiting for valid finger...");
}

void setup(void) {
pinMode(motor1,OUTPUT);
pinMode(motor2,OUTPUT);
startFingerprintSensor(); 
}
int getFingerprintID() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 

digitalWrite(motor1,LOW);
digitalWrite(motor2,LOW);
}


void loop() {

 int fingerprintID = getFingerprintID();
  delay(50);
  if((fingerprintID == 1 || fingerprintID == 2 || fingerprintID == 4) &&  prestate == 0)
  {
    count_value++;
    Serial.println(count_value);
   Serial.print("Mlango umefunguliwa");
   digitalWrite(motor1,HIGH);
  delay(700);
  digitalWrite(motor1,LOW);
   sms1();
   delay(100);
   sms1();
   delay(100);
    prestate = 1;
    return 0;
  }

   if((fingerprintID == 1 || fingerprintID == 2 || fingerprintID == 4) && prestate == 1)
  {
  Serial.print("MLANGO UMEFUNGWA");
  digitalWrite(motor2,HIGH);
  delay(700);
  digitalWrite(motor2,LOW);
  sms();
  prestate = 0;
  count_value=0;
  Serial.println(count_value);
  }
}
