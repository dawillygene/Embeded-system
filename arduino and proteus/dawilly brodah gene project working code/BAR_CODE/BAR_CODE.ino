#define button1 A4
#define button2 A5
#define led1 9
#define led2 11
#define IR1 2
#define IR2 3

void setup() {
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);

}

void loop() {
 byte button1_state=digitalRead(button1);
  byte button2_state=digitalRead(button2);
    byte IR1_state=digitalRead(IR1);
      byte IR2_state=digitalRead(IR2);



if(IR1_state == LOW && IR2_state==LOW)
  {
         digitalWrite(led2,HIGH);
          digitalWrite(led1,HIGH);
           if(button1_state==LOW)
            {
                 digitalWrite(led1,HIGH);
                    delay(700);
                       digitalWrite(led1,LOW);
                            delay(700);
                              digitalWrite(led1,HIGH);
                                   delay(700);
                                    digitalWrite(led1,LOW);
                                        delay(700);
                                              digitalWrite(led1,HIGH);
                                                 delay(700);
                                                     digitalWrite(led1,HIGH);
       delay(700);
        digitalWrite(led1,LOW);
          delay(700);
           digitalWrite(led1,HIGH);
             delay(700);
                digitalWrite(led1,LOW);
                 delay(700);
                    digitalWrite(led1,HIGH);
                       delay(1000);
               
      
      } 
      else  if(button2_state == LOW)
    {
      digitalWrite(led2,HIGH);
       delay(700);
        digitalWrite(led2,LOW);
          delay(700);
           digitalWrite(led2,HIGH);
             delay(700);
                digitalWrite(led2,LOW);
                 delay(700);
                    digitalWrite(led2,HIGH);
                       delay(700);
                          digitalWrite(led2,HIGH);
       delay(700);
        digitalWrite(led2,LOW);
          delay(700);
           digitalWrite(led2,HIGH);
             delay(700);
                digitalWrite(led2,LOW);
                 delay(700);
                    digitalWrite(led2,HIGH);
                       delay(1000);
               
               
      
      } 
        }


else if(IR1_state == LOW && IR2_state== HIGH)
  {
         digitalWrite(led2,LOW);
          digitalWrite(led1,HIGH);

if(button1_state==LOW)
            {
                 digitalWrite(led1,HIGH);
                    delay(700);
                       digitalWrite(led1,LOW);
                            delay(700);
                              digitalWrite(led1,HIGH);
                                   delay(700);
                                    digitalWrite(led1,LOW);
                                        delay(700);
                                              digitalWrite(led1,HIGH);
                                                 delay(700);
                                                     digitalWrite(led1,HIGH);
       delay(700);
        digitalWrite(led1,LOW);
          delay(700);
           digitalWrite(led1,HIGH);
             delay(700);
                digitalWrite(led1,LOW);
                 delay(700);
                    digitalWrite(led1,HIGH);
                       delay(1000);
               
      
      } 
          
        }
else if(IR1_state == HIGH && IR2_state== LOW)
  {
         digitalWrite(led2,HIGH);
          digitalWrite(led1,LOW);

           if(button2_state == LOW)
    {
      digitalWrite(led2,HIGH);
       delay(700);
        digitalWrite(led2,LOW);
          delay(700);
           digitalWrite(led2,HIGH);
             delay(700);
                digitalWrite(led2,LOW);
                 delay(700);
                    digitalWrite(led2,HIGH);
                       delay(700);
                          digitalWrite(led2,HIGH);
       delay(700);
        digitalWrite(led2,LOW);
          delay(700);
           digitalWrite(led2,HIGH);
             delay(700);
                digitalWrite(led2,LOW);
                 delay(700);
                    digitalWrite(led2,HIGH);
                       delay(1000);
               
               
      
      } 
        }
else if( IR1_state==LOW )
 {
  digitalWrite(led1,HIGH);
   if(button1_state==LOW)
            {
                 digitalWrite(led1,HIGH);
                    delay(700);
                       digitalWrite(led1,LOW);
                            delay(700);
                              digitalWrite(led1,HIGH);
                                   delay(700);
                                    digitalWrite(led1,LOW);
                                        delay(700);
                                              digitalWrite(led1,HIGH);
                                                 delay(700);
                                                     digitalWrite(led1,HIGH);
       delay(700);
        digitalWrite(led1,LOW);
          delay(700);
           digitalWrite(led1,HIGH);
             delay(700);
                digitalWrite(led1,LOW);
                 delay(700);
                    digitalWrite(led1,HIGH);
                       delay(1000);
               
      
      } 

    }
    
     else if(IR2_state == LOW)
     {
      digitalWrite(led2,HIGH);
      if(button2_state == LOW)
    {
      digitalWrite(led2,HIGH);
       delay(700);
        digitalWrite(led2,LOW);
          delay(700);
           digitalWrite(led2,HIGH);
             delay(700);
                digitalWrite(led2,LOW);
                 delay(700);
                    digitalWrite(led2,HIGH);
                       delay(700);
                          digitalWrite(led2,HIGH);
       delay(700);
        digitalWrite(led2,LOW);
          delay(700);
           digitalWrite(led2,HIGH);
             delay(700);
                digitalWrite(led2,LOW);
                 delay(700);
                    digitalWrite(led2,HIGH);
                       delay(1000);
               
               
      
      } 
        }

         else{
          digitalWrite(led2,LOW);
          digitalWrite(led1,LOW);
          }


}
