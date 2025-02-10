 #include <SoftwareSerial.h>
SoftwareSerial sim800l(11,12);
void setup() {
 sim800l.begin(4800);
 Serial.begin(9600);
 delay(2000); // give time to log on to network. 
}

void loop() {
sms();
  }

void sms(){
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  sim800l.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(1000);
  sim800l.print("AT+CMGS=\"+255762818261\"\r");
  delay(1000); 
  sim800l.print("THE PATIENT HAS SHOWN MOVEMENT ON HIS RIGHT ARM");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(1000);
  sim800l.print((char)26);// (required according to the datasheet)
  delay(5000);
  sim800l.println();
  Serial.println("Text Sent.");
  delay(1000);
}
