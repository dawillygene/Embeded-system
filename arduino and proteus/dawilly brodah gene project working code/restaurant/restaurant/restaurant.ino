#define ir 2
#define ir2 3
#define led 5
#define led2 6
#define buzzer 7
#define button 10
int number_count=0;
int x=0;
int y=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(ir,INPUT);
pinMode(ir2,INPUT);
pinMode(button,INPUT);
pinMode(led,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(buzzer,OUTPUT);
}

void loop() {
int a=digitalRead(ir);
int b=digitalRead(ir2);
int c=digitalRead(button);

Serial.print("IR1: ");
Serial.println(a);
Serial.print("IR2: ");
Serial.println(b);


if(a==LOW && b==LOW && number_count==0){
  digitalWrite(led,HIGH);
   digitalWrite(led2,HIGH);
  digitalWrite(buzzer,HIGH);
   number_count++;
  }
else if(a==LOW && x==0)
{
  digitalWrite(led,HIGH);
  digitalWrite(buzzer,HIGH);
  x=1;
  }
  else if(b==LOW && y==0)
  {
   digitalWrite(led2,HIGH);
  digitalWrite(buzzer,HIGH); 
  y=1;
    }
    
   else if(c==LOW)
    {
         number_count=0;
          x=0;
           y=0;
      digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
  digitalWrite(led2,LOW);
  
        }
         else{
          
  
          }


}
