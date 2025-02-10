void setup()
{
  pinMode(1, OUTPUT);
  pinMode(10, INPUT);
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(8, INPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(5, INPUT);
 pinMode(11, INPUT);
}

int count=0;


void loop()
{
 int count=digitalRead(10);// digitalRead(10) start butonu
if(digitalRead(12)==1)     // digitalRead(12) 4 tekrar butonu
{
  count=2;
}
  
  switch(count){
    
    
    case 1:  
 
    digitalWrite(1,HIGH);
    delay(10);
   digitalWrite(3,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);
   
  if(digitalRead(2)==1)//1. swich
  {
    digitalWrite(1,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);
     
    digitalWrite(3,HIGH);
    delay(10);
     
  }
    
  else if(digitalRead(4)==1)// 2. swich
  {
    digitalWrite(3,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
    digitalWrite(1,LOW);
    delay(10);
      
    digitalWrite(9,HIGH);
    delay(10);
      
  }

  else if(digitalRead(8)==1)//  3.swich
  {
    digitalWrite(3,LOW);
    delay(10);
    digitalWrite(1,LOW);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);
      
    digitalWrite(6,HIGH);
    delay(10);
      
  }
    
    else  if(digitalRead(11)==1) //4.swich
  {
    digitalWrite(3,LOW);
    delay(10);
    digitalWrite(1,LOW);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
      
  }
    break;
   
    
    case 2:
    
    digitalWrite(1,HIGH);
    delay(10);
    digitalWrite(3,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);

  if(digitalRead(2)==1   )//1. swich
  {
    digitalWrite(1,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);
     
    digitalWrite(3,HIGH);
    delay(10);
     
  }
  
    
 else  if(digitalRead(4)==1)// 2. swich
  {
    digitalWrite(3,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
    digitalWrite(1,LOW);
    delay(10);
       
    digitalWrite(9,HIGH);
    delay(10);
      
  }
  
    
 else  if(digitalRead(8)==1)//  3.swich
  {
    digitalWrite(3,LOW);
    delay(10);
    digitalWrite(1,LOW);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);
      
    digitalWrite(6,HIGH);
    delay(10);
      
  }
   else  if(digitalRead(11)==1) //4.swich başa dön
  {
    digitalWrite(3,LOW);
    delay(10);
    digitalWrite(1,HIGH);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
      
  }
     
else  if(digitalRead(2)==1)//1. swich
  {
    digitalWrite(1,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);
     
    digitalWrite(3,HIGH);
    delay(10);
     
  }
  
    
 else   if(digitalRead(4)==1)// 2. swich
  {
    digitalWrite(3,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
    digitalWrite(1,LOW);
    delay(10);
          
    digitalWrite(9,HIGH);
    delay(10);
      
  }
  
    
  else  if(digitalRead(8)==1)//  3.swich
  {
    digitalWrite(3,LOW);
    delay(10);
    digitalWrite(1,LOW);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);
          
    digitalWrite(6,HIGH);
    delay(10);
      
  }
   else  if(digitalRead(11)==1) //4.swich başa dön
  {
    digitalWrite(3,LOW);
    delay(10);
    digitalWrite(1,HIGH);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
      
  }
    
  
 else  if(digitalRead(2)==1)//1. swich
  {
    digitalWrite(1,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);
     
    digitalWrite(3,HIGH);
    delay(10);
     
  }
  
    
  else  if(digitalRead(4)==1)// 2. swich
  {
    digitalWrite(3,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
    digitalWrite(1,LOW);
    delay(10);    
      
    digitalWrite(9,HIGH);
    delay(10);
      
  }
  
    
  else  if(digitalRead(8)==1)//  3.swich
  {
    digitalWrite(3,LOW);
    delay(10);
    digitalWrite(1,LOW);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);
         
    digitalWrite(6,HIGH);
    delay(10);
      
  }
   else  if(digitalRead(11)==1) //4.swich durdur
  {
    digitalWrite(3,LOW);
    delay(10);
    digitalWrite(1,LOW);
    delay(10);
    digitalWrite(9,LOW);
    delay(10);
    digitalWrite(6,LOW);
    delay(10);
      
  }
    break;
    
  }
}
