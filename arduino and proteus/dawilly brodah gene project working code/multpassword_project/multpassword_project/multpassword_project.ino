#include <Keypad.h>
#include <LiquidCrystal.h>
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //three columns
byte gene=0;
#define breaker A4
char keys[ROW_NUM][COLUMN_NUM] = {
   {'*', '0', '#','D'},
  {'7', '8', '9','C'},
  {'4', '5', '6','B'},
  {'1', '2', '3','A'}
};
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);  
byte pin_rows[ROW_NUM] = {6,7,8,9};   //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5,4,3,2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

String inputString;
int inputInt1;
int inputInt2;
int  inputInt3;
int inputInt;
int inputInt4=1234;

int var1=1;
int var2=1;
int var3=1;

void setup() {
  lcd.begin(20,4);
  inputString.reserve(10); // maximum number of digit for a number is 10, change if neede
  pinMode(breaker,OUTPUT);
}



void loop() {

lcd.setCursor(0,1);
lcd.print("USER1=");
lcd.print(inputInt1);

lcd.setCursor(0,2);
lcd.print("USER2=");
lcd.print(inputInt2);
lcd.setCursor(0,3);
lcd.print("USER3=");

 keyss();
 
 }




void keyss(){
 char key = keypad.getKey();
  if (key) {
lcd.setCursor(0,0);
lcd.print(key);
    if (key >= '0' && key <= '9') {     // only act on numeric keys
      inputString += key;               // append new character to input string
    } else if (key == 'A') {
      if (inputString.length() > 0) {
        inputInt1 = inputString.toInt(); // YOU GOT AN INTEGER NUMBER
       inputString = "";               // clear input
        // DO YOUR WORK HERE
     
      }
    } else if (key == 'B') {
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
      else if (key == '#') {
     if (inputString.length() > 0) {
       inputInt4= inputString.toInt(); // YOU GOT AN INTEGER NUMBER
      inputString = "";               // clear input
     // DO YOUR WORK HERE

lcd.setCursor(13,0);
lcd.print(inputInt4);  


lcd.setCursor(18,1);
lcd.print(var1);
  
lcd.setCursor(18,2);
lcd.print(var2);

lcd.setCursor(18,3);
lcd.print(var3);
  
lcd.setCursor(13,1);
lcd.print(inputInt1); 
lcd.setCursor(13,2);
lcd.print(inputInt2);
lcd.setCursor(13,3);
lcd.print(inputInt3);
func1();
//func2();
//func3();

    }
    
    }

else if (key == '*') {
      inputString = "";                 // clear input

    }
  }
 }


void func1(){
if(gene==0){
if (inputInt1==inputInt4) {
digitalWrite(breaker,HIGH);
gene=1;
}
}
else if(gene==1)
{
  if (inputInt1==inputInt4) {
digitalWrite(breaker,LOW);
gene=0;
}
  }


}



void func2(){
if (var2==1){
if (inputInt2==inputInt4) {
digitalWrite(breaker,HIGH);
var2=2;
}
}
if (var2==2){
if (inputInt2==inputInt4) {
digitalWrite(breaker,LOW);
var2=1;
}
}
}


void func3(){
if (var3==1){
if (inputInt3==inputInt4) {
digitalWrite(breaker,HIGH);
var3=2;
}
}
if (var3==2){
if (inputInt3==inputInt4) {
digitalWrite(breaker,LOW);
var3=1;
}
}
}
