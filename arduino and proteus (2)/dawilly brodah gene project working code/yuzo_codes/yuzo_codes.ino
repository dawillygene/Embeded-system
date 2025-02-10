#define pinA 3
#define pinB 4
#define pinC 5
#define pinD 6
#define Temp_pin A0
#define heat 7
byte pinA_state = 1;
byte pinB_state = 1;
byte pinC_state = 1;
byte pinD_state = 1;
byte heat_state = 0;
byte state_function = 0;
void setup() {
 pinMode(pinA,INPUT);
  pinMode(pinB,INPUT);
   pinMode(pinC,INPUT);
    pinMode(pinD,INPUT);
     pinMode(Temp_pin,INPUT);
      pinMode(heat,OUTPUT);

}

void loop() {
 pinA_state=digitalRead(pinA); //for temperature lower than 15c
  pinB_state=digitalRead(pinB); //for temperature lower than 20 but higher than 15
   pinC_state=digitalRead(pinC); //for temperature lower than 30c but higher than 20
    pinD_state=digitalRead(pinD); //for Stop Operation
     float Temp_pinState=analogRead(Temp_pin);


       //conditions 
         if(pinA_state==LOW && state_function==0){
          Serial.println("button for 15 temp has been pressed");
           if(Temp_pinState > 15){
            digitalWrite(heat,LOW);
            }
            else if(Temp_pinState < 15)
            {
              digitalWrite(heat,HIGH);
              Serial.println("hater is ON up to 15c ");
              heat_state = 1;
              }
         }
           else if(pinB_state==LOW)
           {
             Serial.println("button for 20 temp has been pressed");
              if(Temp_pinState >=15 && Temp_pinState <=20)
              {
                digitalWrite(heat,HIGH);
                heat_state = 2;
                }
                else
                {
                  digitalWrite(heat,LOW);
                  }
              
            
            }
              else if(pinC_state==LOW)
                 {
                      Serial.println("button for 30 temp has been pressed");
                     if(Temp_pinState >=20 && Temp_pinState <=30)
                        {
                          digitalWrite(heat,HIGH);
                                 heat_state = 3;
                                   }
                               else
                                 {
                               digitalWrite(heat,LOW);
                                       }}
                                        else if(pinD_state==LOW)
                                      {
                                   Serial.println("button STOP has been pressed");
                                          digitalWrite(heat,LOW);
                                      }
                               
                               
                  

       //

         
         else if(heat_state== 1 && Temp_pinState >=15 )
         {
          digitalWrite(heat,LOW);
          heat_state=0;
            }
               else if(heat_state== 2 && Temp_pinState >=20 )
               {
                   digitalWrite(heat,LOW);
                     heat_state=0;
               }
                   else if(heat_state== 2 && Temp_pinState >=20 )
                      {
                        digitalWrite(heat,LOW);
                          heat_state=0;
                           }
                              else if(heat_state== 3 && Temp_pinState >=30 )
                                 {
                                    digitalWrite(heat,LOW);
                                        heat_state=0;
                                        }
                                         
         
         
}
