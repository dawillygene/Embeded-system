#include "RTClib.h"

#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //three columns
int geneme;
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3','A'},
  {'4', '5', '6','B'},
  {'7', '8', '9','C'},
  {'*', '0', '#','D'}
};

byte pin_rows[ROW_NUM] = {8, 9, 10, 11};   //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {A0, A1, A2,A3}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

String inputString;
long inputInt1;
long inputInt2;
long inputInt3;
long inputInt4;
long inputInt5;
long inputInt6;
long inputInt7;
long inputInt8;
long inputInt9;
long inputInt;
int stateon = 0;
int var1,var2,var3;
RTC_DS3231 rtc;
#define breaker 13

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {

 inputString.reserve(10); // maximum number of digit for a number is 10, change if neede
   Serial.begin(9600);
   //Serial.begin(57600);
   Serial.println("ina start");
   delay(1000); 
    lcd.begin(20,4);
    lcd.setCursor(5,0);
    lcd.print("ALARM SYSTEM");
     delay(30);
        lcd.clear();
  // Set relay as OUTPUT
  pinMode(breaker, OUTPUT);
  
  // By default the relay is off
  digitalWrite(breaker, LOW);
  // Initializing serial commmunication
  


 
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  


void keyss(){
 char key = keypad.getKey();
  if (key) {
    lcd.clear();
lcd.setCursor(0,0);
    if (key >= '0' && key <= '9') {     // only act on numeric keys
      inputString += key;               // append new character to input string
    } else if (key == 'A') {
      lcd.clear();   
        stateon = 1 ;
        geneme=1;
         
    } else if (key == 'B') {
          lcd.clear();
         stateon = 2;
        geneme=2;

      
    }else if (key == 'C') {
          lcd.clear();
        stateon=3;
        geneme=3;
 
      }
      else if(key == 'D')
      {
      lcd.clear();
       inputInt1 = 0;
          inputInt2 = 0;
            inputInt3 = 0;
              inputInt4 = 0;
                inputInt5 = 0;
                   inputInt6 =0;
        
        }
      
     else if (key == '#' && geneme==1) {
      
        inputInt2 = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        inputString = "";  
        stateon = 0;
        lcd.clear();
    
      }

else if (key == '*' && geneme==1) {
        inputInt1 = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        inputString = "";               // clear input
      
    }
      else if (key == '#' && geneme==2) {
      
        inputInt4 = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        inputString = "";
        stateon=0;// clear input
    
      }

else if (key == '*' && geneme==2) {
      
        inputInt3 = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        inputString = "";               // clear input
        // DO YOUR WORK HERE
     
      
    }
    else if (key == '#' && geneme==3) {
     
        inputInt6 = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        inputString = ""; 
        stateon=0;
    
      }

else if (key == '*' && geneme==3) {
      
        inputInt5 = inputString.toInt(); 
        inputString = "";               
      
      
    }
                                                                                                                                                                                                                                                                                         

  }
}









void loop(){
  DateTime now = rtc.now();
    Serial.println(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

   int hourss=(now.hour(), DEC);
    int minutess=(now.minute(), DEC);
    Serial.println(stateon);
      keyss();


      if(stateon == 0){
      lcd.setCursor(3,0);
                lcd.print(now.hour(), DEC);
                    lcd.setCursor(6,0);
                       lcd.print(":");
                        lcd.setCursor(8,0);
                          lcd.print(now.minute(), DEC);
                             lcd.setCursor(11,0);
                                 lcd.print(":");
                                    lcd.setCursor(12,0);
                                     lcd.print(now.second(), DEC);
                                   lcd.setCursor(0,1);
                                  lcd.print("SUBJ A ENDS:");
                                 lcd.setCursor(12,1);
                                lcd.print(inputInt1);
                              lcd.setCursor(14,1);
                            lcd.print(":");
                           lcd.setCursor(15,1);
                         lcd.print(inputInt2);
                         
                     lcd.setCursor(0,2);
                       lcd.print("SUBJ B ENDS:");
                                 lcd.setCursor(12,2);
                                lcd.print(inputInt3);
                              lcd.setCursor(14,2);
                            lcd.print(":");
                           lcd.setCursor(15,2);
                         lcd.print(inputInt4);  

                         lcd.setCursor(0,3);
                       lcd.print("SUBJ C ENDS:");
                                 lcd.setCursor(12,3);
                                lcd.print(inputInt5);
                              lcd.setCursor(14,3);
                            lcd.print(":");
                           lcd.setCursor(15,3);
                         lcd.print(inputInt6);  
if(now.minute() < 50){
  if (now.hour()==inputInt1 && (now.minute()+ 10) ==inputInt2 && now.second()==0){
    lcd.clear();
    lcd.print("  10 remains for");
    lcd.setCursor(4,1);
    lcd.print("Subject 1");
        digitalWrite(breaker,HIGH);
          delay(5000);
             digitalWrite(breaker,LOW);
               lcd.clear();
                    }
    else if ( now.hour() == inputInt1 && now.minute() ==inputInt2 && now.second()==0){
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Time Ends for");
    lcd.setCursor(4,1);
    lcd.print("Subject 1");
        digitalWrite(breaker,HIGH);
          delay(5000);
             digitalWrite(breaker,LOW);
               lcd.clear();
                    }  




 if (now.hour()==inputInt3 && (now.minute()+ 10) ==inputInt4 && now.second()==0){
    lcd.clear();
    lcd.print("  10 remains for");
    lcd.setCursor(4,1);
    lcd.print("Subject 2");
        digitalWrite(breaker,HIGH);
          delay(5000);
             digitalWrite(breaker,LOW);
               lcd.clear();
                    }
    else if ( now.hour() == inputInt3 && now.minute() ==inputInt4 && now.second()==0){
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Time Ends for");
    lcd.setCursor(4,1);
    lcd.print("Subject 2");
        digitalWrite(breaker,HIGH);
          delay(5000);
             digitalWrite(breaker,LOW);
               lcd.clear();
                    }  





                     if (now.hour()==inputInt5 && (now.minute()+ 10) ==inputInt6 && now.second()==0){
    lcd.clear();
    lcd.print("  10 remains for");
    lcd.setCursor(4,1);
    lcd.print("Subject 3");
        digitalWrite(breaker,HIGH);
          delay(5000);
             digitalWrite(breaker,LOW);
               lcd.clear();
                    }
    else if ( now.hour() == inputInt5 && now.minute() ==inputInt6 && now.second()==0){
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Time Ends for");
    lcd.setCursor(4,1);
    lcd.print("Subject 3");
        digitalWrite(breaker,HIGH);
          delay(5000);
             digitalWrite(breaker,LOW);
               lcd.clear();
                    }  



      
      }  

     

else if(now.minute() > 50)
{
  
  if ((now.hour()+1)==inputInt1 && ((now.minute()+ 10)%60) ==inputInt2 && now.second()==0){
    lcd.clear(); 
    lcd.setCursor(4,0);
    lcd.print("  10m remains for");
    lcd.setCursor(4,1);
    lcd.print("Subject 1");
        digitalWrite(breaker,HIGH);
          delay(5000);
             digitalWrite(breaker,LOW);
               lcd.clear();
    
                    }  
                    else if ( now.hour() == inputInt1 && now.minute() ==inputInt2 && now.second()==0){
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Time Ends for");
    lcd.setCursor(4,1);
    lcd.print("Subject 1");
        digitalWrite(breaker,HIGH);
          delay(5000);
             digitalWrite(breaker,LOW);
               lcd.clear();
                    }  






                     if ((now.hour()+1)==inputInt3 && ((now.minute()+ 10)%60) ==inputInt4 && now.second()==0){
    lcd.clear(); 
    lcd.setCursor(4,0);
    lcd.print("  10m remains for");
    lcd.setCursor(4,1);
    lcd.print("Subject 2");
        digitalWrite(breaker,HIGH);
          delay(5000);
             digitalWrite(breaker,LOW);
               lcd.clear();
    
                    }  
                    else if ( now.hour() == inputInt3 && now.minute() ==inputInt4 && now.second()==0){
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Time Ends for");
    lcd.setCursor(4,1);
    lcd.print("Subject 2");
        digitalWrite(breaker,HIGH);
          delay(5000);
             digitalWrite(breaker,LOW);
               lcd.clear();
                    }  
      
  
      


      if ((now.hour()+1)==inputInt5 && ((now.minute()+ 10)%60) ==inputInt6 && now.second()==0){
    lcd.clear(); 
    lcd.setCursor(4,0);
    lcd.print("  10m remains for");
    lcd.setCursor(4,1);
    lcd.print("Subject 3");
        digitalWrite(breaker,HIGH);
          delay(5000);
             digitalWrite(breaker,LOW);
               lcd.clear();
    
                    }  
                    else if ( now.hour() == inputInt5 && now.minute() ==inputInt6 && now.second()==0){
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Time Ends for");
    lcd.setCursor(4,1);
    lcd.print("Subject 3");
        digitalWrite(breaker,HIGH);
          delay(5000);
             digitalWrite(breaker,LOW);
               lcd.clear();
                    }  

      
      
      }
  
      }






else if(stateon == 1){
  lcd.setCursor(0,0);
lcd.print("HOUR=");
lcd.setCursor(0,1);
lcd.print("MINUTE=");
 lcd.setCursor(5,0);
     lcd.print(inputInt1);
     lcd.setCursor(7,1);
       lcd.print(inputInt2);
          //lcd.print(inputInt1);
              lcd.setCursor(0,2);
                lcd.print(now.hour(), DEC);
                    lcd.setCursor(2,2);
                       lcd.print(":");
                        lcd.setCursor(3,2);
                          lcd.print(now.minute(), DEC);
                             lcd.setCursor(5,2);
                                lcd.print(":");
                                  lcd.setCursor(6,2);
                                      lcd.print(now.second(), DEC);
  
  
  }
  else if(stateon == 2){
     lcd.setCursor(0,0);
lcd.print("HOUR=");
lcd.setCursor(0,1);
lcd.print("MINUTE=");
 lcd.setCursor(5,0);
     lcd.print(inputInt3);
     lcd.setCursor(7,1);
       lcd.print(inputInt4);
          //lcd.print(inputInt1);
              lcd.setCursor(0,2);
                lcd.print(now.hour(), DEC);
                    lcd.setCursor(2,2);
                       lcd.print(":");
                        lcd.setCursor(3,2);
                          lcd.print(now.minute(), DEC);
                             lcd.setCursor(5,2);
                                lcd.print(":");
                                  lcd.setCursor(6,2);
                                      lcd.print(now.second(), DEC);
    }
 else if(stateon==3)
 {
     lcd.setCursor(0,0);
lcd.print("HOUR=");
lcd.setCursor(0,1);
lcd.print("MINUTE=");
 lcd.setCursor(5,0);
     lcd.print(inputInt5);
     lcd.setCursor(7,1);
       lcd.print(inputInt6);
          //lcd.print(inputInt1);
              lcd.setCursor(0,2);
                lcd.print(now.hour(), DEC);
                    lcd.setCursor(2,2);
                       lcd.print(":");
                        lcd.setCursor(3,2);
                          lcd.print(now.minute(), DEC);
                             lcd.setCursor(5,2);
                                lcd.print(":");
                                  lcd.setCursor(6,2);
                                      lcd.print(now.second(), DEC);
  
  
  }



/*else if (now.hour()==inputInt1 && (now.minute()==(inputInt2-10)) && now.second()==0){
lcd.setCursor(0,3);
lcd.print("alarm");
 digitalWrite(breaker,HIGH);
 delay(5000);
 digitalWrite(breaker,LOW);
 lcd.clear();
}  */
else{
  digitalWrite(breaker,LOW); 
}
}
