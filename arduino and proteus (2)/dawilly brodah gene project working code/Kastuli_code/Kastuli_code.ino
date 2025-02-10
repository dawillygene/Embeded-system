int openswitch = A5;; 
int closeswitch = A4;
int led1=11;
int led2=12;
int en=3;
int in1=2;
int in2=4;


void setup() {
  pinMode(openswitch, INPUT);
  pinMode(closeswitch, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(en, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  analogWrite(en,0);
  digitalWrite(in1,0);
  digitalWrite(in2,0);
}

void loop() {
 int openy=digitalRead(openswitch);
 int closy=digitalRead(closeswitch);

 if(openy==1)
 {
  analogWrite(en,40);
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  

 }


 if(closy==1)
 {
  analogWrite(en,40);
  digitalWrite(in1,0);
  digitalWrite(in2,1); 
 
 }

}
