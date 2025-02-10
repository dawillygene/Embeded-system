#include "RTClib.h"

#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4; //three columns
int geneme;
char keys[ROW_NUM][COLUMN_NUM] = {
  {'*', '0', '#','D'},
  {'7', '8', '9','C'},
  {'4', '5', '6','B'},
  {'1', '2', '3','A'}
};

byte pin_rows[ROW_NUM] = {6,7,8,9};   //connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {5,4,3,2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );




void setup() {
   Serial.begin(9600);
   lcd.begin(16,4);
}

void loop(){
keyss();
}

void keyss(){
 char key = keypad.getKey();
  if (key) {
    lcd.print(key);
    Serial.println(key);
}}
