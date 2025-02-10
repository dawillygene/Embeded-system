#define IR 6
void setup() {
  Serial.begin(9600);
  pinMode(IR,INPUT);
}
void sms(){
  Serial.println("Sending SMS...");               //Show this message on serial monitor
  Serial.print("AT+CMGF=1\r");                   //Set the module to SMS mode
  delay(1000);
  Serial.print("AT+CMGS=\"+255753225961\"\r");
  delay(1000); 
  Serial.print("Dust bin is full");       //This is the text to send to the phone number, don't make it too long or you have to modify the SoftwareSerial buffer
  delay(1000);
  Serial.print((char)26);// (required according to the datasheet)
  delay(5000);
  Serial.println();
  Serial.println("Text Sent.");
  delay(1000);
}
void loop() {
  byte IR_reading=digitalRead(IR);

  if(IR_reading==LOW)
  {
    sms();
    }
    else
    {
      sms();
      }
}
