#define ldr A0
#define IR 6
#define relay1 5
#define relay2 7

void setup()
{
  Serial.begin(9600);
pinMode(ldr,INPUT);
pinMode(IR,INPUT);
pinMode(relay1,OUTPUT);
pinMode(relay2,OUTPUT);
 digitalWrite(relay1,LOW); //DIM
 digitalWrite(relay2,LOW); //BRIGHT
}

void loop()
{
  
 int ldr_reading=analogRead(ldr);
 byte IR_reading=digitalRead(IR);
 delay(1000);
 Serial.println(ldr_reading);
   Serial.println(IR_reading);
if(IR_reading==LOW){
 if(ldr_reading<=800 && ldr_reading>=400)
 {
  //dim light
  digitalWrite(relay2,LOW);
  delay(100);
  digitalWrite(relay1,HIGH);
  
  
  }
  else if(ldr_reading<=400)
  {
    //bright light
    digitalWrite(relay1,LOW);
    delay(100);
    digitalWrite(relay2,HIGH);
    }

    else if(ldr_reading>=800)
    {
      //don't light
      digitalWrite(relay1,LOW); //DIM
      digitalWrite(relay2,LOW); //BRIGHT
      }
      else{}
}
else if(IR_reading==HIGH)
{
      digitalWrite(relay1,HIGH); //DIM
      digitalWrite(relay2,LOW); //BRIGHT
  }
  else
  {
    }
  }
