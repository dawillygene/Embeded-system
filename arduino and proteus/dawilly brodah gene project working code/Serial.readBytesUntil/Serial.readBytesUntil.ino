#include<Arduino.h>

size_t bytesReceived;


void readyState()
{
  const char* readyMessage = "READY";
    const char* ackMessage = "ACK";
     const unsigned long transmitInterval=1e6;//one million micro seconds
      unsigned long start = micros();
       char messageReceived[sizeof(ackMessage)+1] = {'\0'}   ;
       bool ackReceived = false;

        while(ackReceived ==false)
         { 
           if((micros()-start)>transmitInterval)
            {
              Serial.println(readyMessage);
              start = micros();
            }

             if(Serial.available()>2)
             {
              bytesReceived = Serial.readBytesUntil('\n',messageReceived,strlen(ackMessage));
              if(bytesReceived == strlen(ackMessage))
                {
                  if(strcmp(messageReceived,ackMessage)==0)
                 {
                   Serial.print("");
                   ackReceived = true;
                 }
                 else
                 {
                  Serial.print("Debug : ready state(),messsegereceived");
                  Serial.println(messageReceived);
                 } 
                }
                else
             {
              Serial.print("Debug : ready state(),byte received");
                  Serial.print(bytesReceived);
             }
             }
             
         } 
}

  int main(void)
{
    init();
      Serial.begin(9600);
      readyState();
       Serial.println("readystate complete"); 

  while(1)
  {
      Serial.println("am in while loop");
      delay(400);
  }
}
