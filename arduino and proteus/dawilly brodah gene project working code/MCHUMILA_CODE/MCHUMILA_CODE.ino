#include<LiquidCrystal.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
#include <Keypad.h>


const byte ROWS = 3; //four rows
const byte COLS = 10; //three columns
char keys[ROWS][COLS] = {
  {'p','w','e','r','t','y','u','i','o'},
  {'a','s','d','f','g','h','j','k','l'},
  {'z','x','c','v','b','n','m',' ','#'}
};
byte rowPins[ROWS] = { 12, 13, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {11, 10, 9, 8, 7, 6, 5, 4, 3}; //connect to the column pinouts of the keypad
byte count_value=0;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
String inputString;
void setup(){
  Serial.begin(9600);
  lcd.begin(20,4);
lcd.clear();
lcd.cursor();
lcd.setCursor(0,1);
lcd.print(".......standby......");
lcd.setCursor(0,2);
lcd.print("please wait");
delay(1000);
lcd.clear();
}
void sendSMS(){
  Serial.print("AT+CMGF=1\r"); 
  delay(100);
  Serial.println("AT + CMGS = \"XXXXXXXXXX\""); 
  delay(100);
  Serial.println(inputString); 
  delay(100);
  Serial.println((char)26); 
  delay(100);
  Serial.println();
  delay(1000);  
}

  
void loop(){
  char key = keypad.getKey();
  char hash =keypad.getKey();
  if (key && count_value <=19){
    lcd.setCursor(count_value,0);
    lcd.print(key);
    inputString +=key;
    delay(20);
    count_value++;
   
    }
   else if(key && count_value>=20 && count_value <=40) 
   {
    lcd.setCursor((count_value - 20),1);
    lcd.print(key);
    inputString +=key;
    delay(20);
    count_value++;
 
    
    }
     else if(key && count_value>=40 && count_value <=60) 
   {
    lcd.setCursor((count_value - 40),2);
    lcd.print(key);
    inputString +=key;
    delay(20);
    count_value++;
   
   
    }
      else if(key && count_value>=60 && count_value <=80) 
   {
    lcd.setCursor((count_value - 60),3);
    lcd.print(key);
    inputString +=key;
    delay(20);
    count_value++;
    

    }
  else if(hash == '#')
  {
lcd.clear();
lcd.setCursor(0,1);
lcd.print(".....MSG SENDING....");
delay(1000);
sendSMS();
count_value=0;
lcd.clear();
    }
    else if(hash == 'x')
  {
count_value--;
hash==' ';
    }


  
 else
 {}
    
}
