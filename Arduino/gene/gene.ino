void setup() {

 Serial.begin(9600);
  pinMode(2,OUTPUT);
   pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);

}

void loop() {
   digitalWrite(2,HIGH);
     delay(100);
       digitalWrite(2,LOW);
         digitalWrite(3,HIGH);
 
           delay(100);
           digitalWrite(3,LOW);
             digitalWrite(4,HIGH);
              delay(10);
               
               
           delay(100);
             digitalWrite(2,HIGH);
               digitalWrite(3,LOW);
                 digitalWrite(4,LOW);

}
