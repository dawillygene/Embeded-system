char messageBuffer[5];
size_t bytesReceived;
bool messageReceived;

void setup() {
 Serial.begin(9600);
 Serial.print("bytesreceived: ");
 messageReceived=false;

}

void loop() {
  bytesReceived = Serial.readBytesUntil('\n',messageBuffer, 2);

   if(bytesReceived == 2)
   {
    Serial.print("message received");
    Serial.println(messageBuffer);
   }
    Serial.print("bytesreceived: ");
    Serial.println(bytesReceived);
}
