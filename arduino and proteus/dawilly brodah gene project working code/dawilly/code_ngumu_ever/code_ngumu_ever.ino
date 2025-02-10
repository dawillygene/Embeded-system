#include "RTClib.h"

#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,2,3,4,5);

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //three columns

char keys[ROW_NUM][COLUMN_NUM] = {
  {'7', '8', '9','A'},
  {'4', '5', '6','B'},
  {'1', '2', '3','C'},
  {'*', '0', '#','D'}
};

byte pin_rows[ROW_NUM] = {8, 9, 10, 11};   //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {A0, A1, A2,A3}; //connect to the column pinouts of the keypad
int genestate=0;
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

String inputString;
long inputInt1;
long inputInt2;
long inputInt3;
long inputInt;
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
     delay(3000);
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

keyss();
if (now.hour()==inputInt1 && now.minute()==inputInt2 && now.second()==0){
lcd.setCursor(0,3);
lcd.print("alarm");
 digitalWrite(breaker,HIGH);
 delay(5000);
 digitalWrite(breaker,LOW);
 lcd.clear();
}  
else{
  digitalWrite(breaker,LOW); 
}
}

void keyss(){
 char key = keypad.getKey();
  if (key) {
    lcd.clear();
lcd.setCursor(0,0);
lcd.print(key);
    if (key >= '0' && key <= '9') {     // only act on numeric keys
      inputString += key;               // append new character to input string
    } else if (key == 'A') {
        genestate=1; 
      }
      
     else if (key == 'B') {
      if (inputString.length() > 0) {
        inputInt2 = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        inputString = "";               // clear input
        // DO YOUR WORK HERE
  //    lcd.setCursor(0,2);
//lcd.print("USER2=");
  //   lcd.print(inputInt2);
      }
    }else if (key == 'C') {
      if (inputString.length() > 0) {
        inputInt3= inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        inputString = "";               // clear input
        // DO YOUR WORK HERE
    //  lcd.setCursor(0,3);
//lcd.print("USER3=");
 //    lcd.print(inputInt3);
      }
      }
      else if (key == '#' && genestate==1) {
      if(inputString.length()>0) {
        inputInt1 = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
        inputString = "";               // clear input
        // DO YOUR WORK HERE
     
      }
      }

else if (key == '*' && genestate==1) {
      if (inputString.length() > 0) {
        inputInt2 = inputString. toInt(); // YOU GOT AN INTEGER NUMBER
        inputString = "";               // clear input
        // DO YOUR WORK HERE
  //    lcd.setCursor(0,2);
//lcd.print("USER2=");
  //   lcd.print(inputInt2);
      }
    }
  }
}                                                                                                                                                                                                                                                                                    
