#include <Keypad.h>
#include <LiquidCrystal.h>
#define sensor1 36  
const byte numRows= 4;          //number of rows on the keypad
const byte numCols= 4;          //number of columns on the keypad
char keymap[numRows][numCols]= 
{
{'*', '0', '#','D'},
  {'7', '8', '9','C'},
  {'4', '5', '6','B'},
  {'1', '2', '3','A'}
};
LiquidCrystal lcd(18,5,19,3,1,23);  
char keypressed;                 //Where the keys are stored it changes very often
char code[]= {'6','6','0','1'};  //The default code, you can change it or make it a 'n' digits one
char gene[]= {'3','0','7','1'};  
char vene[]= {'6','6','0','1'};  
short a=0,i=0,s=0,j=0,g=0,e=0,n=0;          //Variables used later

byte rowPins[numRows] = {6,7,8,9}; //Rows
byte colPins[numCols]= { 11,4,3,2}; //Columns 

int value;
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);


void setup()
{Serial.begin(9600);
  Serial.println("standby");        
  lcd.begin(20,4);                    
  lcd.setCursor(0,0);
  lcd.print("standby");
pinMode(sensor1,INPUT);
   
}

void loop()
{

  }
