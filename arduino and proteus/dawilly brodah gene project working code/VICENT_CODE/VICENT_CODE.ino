#define IR 2
#define led1 6
#define buzzer 8
#define switch_state 4
void setup() {
  Serial.begin(9600);
 pinMode(IR,INPUT);
 pinMode(led1,OUTPUT);
 pinMode(buzzer,OUTPUT);
 pinMode(switch_state,INPUT);
}

void loop() {
 byte IRinput=digitalRead(IR);
 byte Switch_states=digitalRead(switch_state);
Serial.println(IRinput);


if(Switch_states==HIGH){
  if(IRinput==LOW){
    digitalWrite(led1,HIGH);
       digitalWrite(buzzer,HIGH);
  
      } 
    else if(IRinput==HIGH)
       {
    digitalWrite(led1,LOW);\
    digitalWrite(buzzer,LOW);
    }

     
     
     }
     else if(Switch_states==LOW)
{
  digitalWrite(led1,LOW);
    digitalWrite(buzzer,LOW);
     
}
}
