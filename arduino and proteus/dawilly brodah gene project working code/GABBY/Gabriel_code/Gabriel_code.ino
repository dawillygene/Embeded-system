#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

int ldr=A4;
int tanesco_in=A0;
int solar_in=A1;
int generator_in=A2;

int tanesco_relay=4;
int solar_relay=3;
int generator_relay=2;

int tanesco_LED=7;
int solar_LED=6;
int generator_LED=5;


void setup() {

lcd.begin(16,4);

lcd.setCursor(2,0);
 lcd.print("ARUSHA TECHNICAL");
 lcd.setCursor(4,1);
 lcd.print("COLLEGE.");
delay(100);
lcd.clear();
lcd.setCursor(4,0);
 lcd.print("AUTOMATIC");
 lcd.setCursor(4,1);
 lcd.print("CHANGE-OVER");
lcd.setCursor(4,2);
 lcd.print("SWITCH");
lcd.setCursor(0,3);
 lcd.print("********************");
delay(100);
lcd.clear();

lcd.setCursor(5,0);
 lcd.print("");
 lcd.setCursor(0,1);
 lcd.print("TANESCO  :");
lcd.setCursor(0,2);
lcd.print("SOLAR    :");
lcd.setCursor(0,3);
 lcd.print("GENERATOR:");
delay(1000);





pinMode(ldr,INPUT);
pinMode(tanesco_in,INPUT);
pinMode(solar_in,INPUT);
pinMode(generator_in,INPUT);

pinMode(tanesco_relay,OUTPUT);
pinMode(solar_relay,OUTPUT);
pinMode(generator_relay,OUTPUT);

pinMode(tanesco_LED,OUTPUT);
pinMode(solar_LED,OUTPUT);
pinMode(generator_LED,OUTPUT);


}

void loop() {
int tanesco_indata=digitalRead(tanesco_in);
int solar_indata=digitalRead(solar_in);
int generator_indata=digitalRead(generator_in);
int ldr_data=analogRead(ldr);
lcd.setCursor(2,0);
 
  

  if(ldr_data>200)
  {
       if(tanesco_indata==1&&solar_indata==1&&generator_indata==1)
       {

        lcd.setCursor(8,0);
 lcd.print("DAY");
 lcd.setCursor(0,1);
 lcd.print("TANESCO  : OFF");
lcd.setCursor(0,2);
lcd.print("SOLAR    : ON");
lcd.setCursor(0,3);
 lcd.print("GENERATOR: OFF");


        digitalWrite(solar_relay,0);
        digitalWrite(solar_LED,1);
        digitalWrite(tanesco_relay,1);
        digitalWrite(tanesco_LED,0);
        digitalWrite(generator_relay,1);
        digitalWrite(generator_LED,0);
       }

       else if(tanesco_indata==1&&solar_indata==0&&generator_indata==1)
       {
lcd.clear();      
 lcd.setCursor(8,0);
 lcd.print("DAY");
 lcd.setCursor(0,1);
 lcd.print("TANESCO  : ON");
lcd.setCursor(0,2);
lcd.print("SOLAR    : OFF");
lcd.setCursor(0,3);
 lcd.print("GENERATOR: OFF");


        digitalWrite(solar_relay,1);
        digitalWrite(solar_LED,0);
        digitalWrite(tanesco_relay,0);
        digitalWrite(tanesco_LED,1);
        digitalWrite(generator_relay,1);
        digitalWrite(generator_LED,0);
       }

       else if(tanesco_indata==0&&solar_indata==0&&generator_indata==1)
       {
        lcd.clear();      
 lcd.setCursor(8,0);
 lcd.print("DAY");
 lcd.setCursor(0,1);
 lcd.print("TANESCO  : OFF");
lcd.setCursor(0,2);
lcd.print("SOLAR    : OFF");
lcd.setCursor(0,3);
 lcd.print("GENERATOR: ON");

        digitalWrite(solar_relay,1);
        digitalWrite(solar_LED,0);
        digitalWrite(tanesco_relay,1);
        digitalWrite(tanesco_LED,0);
        digitalWrite(generator_relay,0);
        digitalWrite(generator_LED,1);
       }

       else if(tanesco_indata==0&&solar_indata==0&&generator_indata==0)
       {
        lcd.clear();      
 lcd.setCursor(8,0);
 lcd.print("DAY");
 lcd.setCursor(0,1);
 lcd.print("TANESCO  : OFF");
lcd.setCursor(0,2);
lcd.print("SOLAR    : OFF");
lcd.setCursor(0,3);
 lcd.print("GENERATOR: OFF");

        digitalWrite(solar_relay,1);
        digitalWrite(solar_LED,0);
        digitalWrite(tanesco_relay,1);
        digitalWrite(tanesco_LED,0);
        digitalWrite(generator_relay,1);
        digitalWrite(generator_LED,0);
       }

      else if(tanesco_indata==0&&solar_indata==1&&generator_indata==0)
       {
        lcd.clear();      
 lcd.setCursor(8,0);
 lcd.print("DAY");
 lcd.setCursor(0,1);
 lcd.print("TANESCO  : OFF");
lcd.setCursor(0,2);
lcd.print("SOLAR    : ON");
lcd.setCursor(0,3);
 lcd.print("GENERATOR: OFF");

        digitalWrite(solar_relay,0);
        digitalWrite(solar_LED,1);
        digitalWrite(tanesco_relay,1);
        digitalWrite(tanesco_LED,0);
        digitalWrite(generator_relay,1);
        digitalWrite(generator_LED,0);
       }


 else if(tanesco_indata==0&&solar_indata==1&&generator_indata==1)
       {
        lcd.clear();      
 lcd.setCursor(8,0);
 lcd.print("DAY");
 lcd.setCursor(0,1);
 lcd.print("TANESCO  : OFF");
lcd.setCursor(0,2);
lcd.print("SOLAR    : ON");
lcd.setCursor(0,3);
 lcd.print("GENERATOR: OFF");

        digitalWrite(solar_relay,0);
        digitalWrite(solar_LED,1);
        digitalWrite(tanesco_relay,1);
        digitalWrite(tanesco_LED,0);
        digitalWrite(generator_relay,1);
        digitalWrite(generator_LED,0);
       }





  








      else if(tanesco_indata==1&&solar_indata==1&&generator_indata==0)
       {
               lcd.clear();      
 lcd.setCursor(8,0);
 lcd.print("DAY");
 lcd.setCursor(0,1);
 lcd.print("TANESCO  : OFF");
lcd.setCursor(0,2);
lcd.print("SOLAR    : ON");
lcd.setCursor(0,3);
 lcd.print("GENERATOR: OFF");

        digitalWrite(solar_relay,0);
        digitalWrite(solar_LED,1);
        digitalWrite(tanesco_relay,1);
        digitalWrite(tanesco_LED,0);
        digitalWrite(generator_relay,1);
        digitalWrite(generator_LED,0);
       }

     else  if(tanesco_indata==1&&solar_indata==0&&generator_indata==0)
       {
        lcd.clear();      
 lcd.setCursor(8,0);
 lcd.print("DAY");
 lcd.setCursor(0,1);
 lcd.print("TANESCO  : ON");
lcd.setCursor(0,2);
lcd.print("SOLAR    : OFF");
lcd.setCursor(0,3);
 lcd.print("GENERATOR: OFF");

        digitalWrite(solar_relay,1);
        digitalWrite(solar_LED,0);
        digitalWrite(tanesco_relay,0);
        digitalWrite(tanesco_LED,1);
        digitalWrite(generator_relay,1);
        digitalWrite(generator_LED,0);
       }
  
 }


  else if(ldr_data<200)
  {

        if(tanesco_indata==1 && generator_indata==1)
         {
          lcd.clear();      
 lcd.setCursor(7,0);
 lcd.print("NIGHT");
 lcd.setCursor(0,1);
 lcd.print("TANESCO  : ON");
lcd.setCursor(0,2);
lcd.print("SOLAR    : OFF");
lcd.setCursor(0,3);
 lcd.print("GENERATOR: OFF");
        digitalWrite(solar_relay,1);
        digitalWrite(solar_LED,0);
        digitalWrite(tanesco_relay,0);
        digitalWrite(tanesco_LED,1);
        digitalWrite(generator_relay,1);
        digitalWrite(generator_LED,0);
         }

      else if(tanesco_indata==0 && generator_indata==1)
         {
          lcd.clear();      
 lcd.setCursor(7,0);
 lcd.print("NIGHT");
 lcd.setCursor(0,1);
 lcd.print("TANESCO  : OFF");
lcd.setCursor(0,2);
lcd.print("SOLAR    : OFF");
lcd.setCursor(0,3);
 lcd.print("GENERATOR: ON");
 
        digitalWrite(solar_relay,1);
        digitalWrite(solar_LED,0);
        digitalWrite(tanesco_relay,1);
        digitalWrite(tanesco_LED,0);
        digitalWrite(generator_relay,0);
        digitalWrite(generator_LED,1);
          
         }

         else if(tanesco_indata==1&&generator_indata==0)
         {
          lcd.clear();      
 lcd.setCursor(7,0);
 lcd.print("NIGHT");
 lcd.setCursor(0,1);
 lcd.print("TANESCO  : ON");
lcd.setCursor(0,2);
lcd.print("SOLAR    : OFF");
lcd.setCursor(0,3);
 lcd.print("GENERATOR: OFF");
          digitalWrite(tanesco_relay,1);
          digitalWrite(tanesco_LED,0);
          digitalWrite(generator_relay,1);
          digitalWrite(generator_LED,0);
          digitalWrite(tanesco_relay,0);
          digitalWrite(tanesco_LED,1);
         }

        else if (tanesco_indata==0 && generator_indata==0)
         {
          lcd.clear();      
 lcd.setCursor(7,0);
 lcd.print("NIGHT");
 lcd.setCursor(0,1);
 lcd.print("TANESCO  : OFF");
lcd.setCursor(0,2);
lcd.print("SOLAR    : OFF");
lcd.setCursor(0,3);
 lcd.print("GENERATOR: OFF");
        digitalWrite(solar_relay,1);
        digitalWrite(solar_LED,0);
        digitalWrite(tanesco_relay,1);
        digitalWrite(tanesco_LED,0);
        digitalWrite(generator_relay,1);
        digitalWrite(generator_LED,0);
         }
    
  }

 delay(1000);
}
