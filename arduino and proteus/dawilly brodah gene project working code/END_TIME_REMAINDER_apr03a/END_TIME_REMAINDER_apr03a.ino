#include <Key.h> 
#include <Keypad.h> 
#include <Keypad.h> 
#include <LiquidCrystal.h> 
int LED = 2; 
int buzzer = 13; 
int counter_delay = 1000; 
LiquidCrystal lcd(12,11,10,9,8,7); 
char key[4][4]={ 
{'1','2','3','A'}, 
{'4','5','6','B'}, 
{'7','8','9','C'}, 
{'*','0','#','D'} 
}; 
byte rowpins[4]={6,5,4,A1}; 
byte colpins[4]={A2,A3,A4,A5}; 
Keypad customKeypad = Keypad(makeKeymap(key),rowpins,colpins,4,4); 
//start void setup 

 
void setup(){ 
pinMode(LED, OUTPUT); 
pinMode(buzzer, OUTPUT); 
Serial.begin(9600); 
lcd.begin(20,4); 
MENU();} 
//start void loop 
void loop(){ 
char key = customKeypad.getKey(); 
if (key == '1') { 
CVL_ELE_TEL();}} 
//start MENU function 
void MENU (){ 
lcd.clear(); 
lcd.setCursor(0,0); 
lcd.print("=EXAMINATION TIMER="); 
lcd.setCursor(0,1); 
lcd.print("Set time in Minutes"); 
lcd.setCursor(0,2); 
lcd.print("Press 1 to continue"); 
delay(1000);} 

 
//start depertment function 
void CVL_ELE_TEL(){ 
lcd.clear(); 
lcd.print("enter Minutes:"); 
//civil 
lcd.setCursor(0,1); 
lcd.print("CVL: "); 
int convert1[3]; 
for(int a=0; a<3; a++){ 
char key = customKeypad.waitForKey(); 
convert1[a] = key - '0'; 
lcd.setCursor(a+6,1); 
lcd.print(convert1[a]);} 
//electrical 
lcd.setCursor(0,2); 
lcd.print("ELE: "); 
int convert2[3]; 
for(int a=0; a<3; a++){ 
char key = customKeypad.waitForKey(); 
convert2[a] = key - '0'; 
lcd.setCursor(a+6,2); 
 
 
lcd.print(convert2[a]);} 
//telecom 
lcd.setCursor(0,3); 
lcd.print("TEL: "); 
int convert3[3]; 
for(int a=0; a<3; a++){ 
char key = customKeypad.waitForKey(); 
convert3[a] = key - '0'; 
lcd.setCursor(a+6,3); 
lcd.print(convert3[a]);} 
int converted_value1 = convert1[0]*100 + convert1[1]*10 + convert1[2]; 
int converted_value2 = convert2[0]*100 + convert2[1]*10 + convert2[2]; 
int converted_value3 = convert3[0]*100 + convert3[1]*10 + convert3[2]; 
lcd.clear(); 
lcd.setCursor(0,0); 
lcd.print("Menutes Set are:"); 
lcd.setCursor(0,1); 
lcd.print("CVL: "); 
lcd.setCursor(5,1); 
lcd.print(converted_value1); 
lcd.setCursor(9,1); 
 
 
lcd.print("Minutes"); 
lcd.setCursor(0,2); 
lcd.print("ELE: "); 
lcd.setCursor(5,2); 
lcd.print(converted_value2); 
lcd.setCursor(9,2); 
lcd.print("Minutes"); 
lcd.setCursor(0,3); 
lcd.print("CVL: "); 
lcd.setCursor(5,3); 
lcd.print(converted_value3); 
lcd.setCursor(9,3); 
lcd.print("Minutes"); 
delay(2000); 
lcd.clear(); 
lcd.print("***COMFIRMATION***"); 
lcd.setCursor(0,1); 
lcd.print("press A to continue"); 
lcd.setCursor(0,2); 
lcd.print("press B to cancel"); 
delay(2000); 

 
char key = customKeypad.waitForKey(); 
if (key == 'A') { 
lcd.clear(); 
lcd.setCursor(0,1); 
lcd.print("COUNTER WILL START"); 
lcd.setCursor(0,2); 
lcd.print("AFTER : "); 
for(int a=5; a>=0; a--){ 
lcd.setCursor(9,2); 
lcd.print(a); 
lcd.setCursor(11,2); 
lcd.print("Seconds"); 
delay(1000);} 
if (converted_value1 == 0){} 
if((converted_value1 > converted_value2) && (converted_value1 > converted_value3)){ 
for(int a = converted_value1; a>=0; a--){ 
int b = converted_value2--; 
int c = converted_value3--; 
lcd.clear(); 
lcd.print("**COUNTER IS ON**"); 
if(a>=0){ 

 
if(a==0 || a==30 || a==60 || a==90 || a==120 || a==150 || a==180){alert_intervals();} 
if(a==0){alert();} 
lcd.setCursor(0,1); 
lcd.print("CVL: "); 
lcd.setCursor(6,1); 
lcd.print(a); 
lcd.setCursor(11,1); 
lcd.print("Minutes");} 
if(b>=0){ 
if(b==0){alert();} 
//if(b==30 || b==60 || b==90 || b==120 || b==150 || b==180){alert_intervals();} 
lcd.setCursor(0,2); 
lcd.print("ELE: "); 
lcd.setCursor(6,2); 
lcd.print(b); 
lcd.setCursor(11,2); 
lcd.print("Minutes");} 
if(c>=0){ 
if(c==0){alert();} 
//if(c==30 || c==60 || c==90 || c==120 || c==150 || c==180){alert_intervals();} 
lcd.setCursor(0,3); 

 
lcd.print("TEL: "); 
lcd.setCursor(6,3); 
lcd.print(c); 
lcd.setCursor(11,3); 
lcd.print("Minutes");} 
delay(counter_delay);}} 
if((converted_value2 > converted_value1) && (converted_value2 > converted_value3)){ 
for(int a = converted_value2; a>=0; a--){ 
int b = converted_value1--; 
int c = converted_value3--; 
lcd.clear(); 
lcd.print("**COUNTER IS ON**"); 
if(b>=0){ 
if(b==0){alert();} 
//if(b==30 || b==60 || b==90 || b==120 || b==150 || b==180){alert_intervals();} 
lcd.setCursor(0,1); 
lcd.print("CVL: "); 
lcd.setCursor(6,1); 
lcd.print(b); 
lcd.setCursor(11,1); 
lcd.print("Minutes");} 
 
 
if(a>=0){ 
if(a==0 || a==30 || a==60 || a==90 || a==120 || a==150 || a==180){alert_intervals();} 
if(a==0){alert();} 
lcd.setCursor(0,2); 
lcd.print("ELE: "); 
lcd.setCursor(6,2); 
lcd.print(a); 
lcd.setCursor(11,2); 
lcd.print("Minutes");} 
if(c>=0){ 
if(c==0){alert();} 
//if(c==30 || c==60 || c==90 || c==120 || c==150 || c==180){alert_intervals();} 
lcd.setCursor(0,3); 
lcd.print("TEL: "); 
lcd.setCursor(6,3); 
lcd.print(c); 
lcd.setCursor(11,3); 
lcd.print("Minutes");} 
delay(counter_delay);}} 
if((converted_value3 > converted_value1) && (converted_value3 > converted_value2)){ 
for(int a = converted_value3; a>=0; a--){ 

 
int b = converted_value1--; 
int c = converted_value2--; 
lcd.clear(); 
lcd.print("**COUNTER IS ON**"); 
if(b>=0){ 
if(b==0){alert();} 
//if(b==30 || b==60 || b==90 || b==120 || b==150 || b==180){alert_intervals();} 
lcd.setCursor(0,1); 
lcd.print("CVL: "); 
lcd.setCursor(6,1); 
lcd.print(b); 
lcd.setCursor(11,1); 
lcd.print("Minutes");} 
if(c>=0){ 
if(c==0){alert();} 
//if(c==30 || c==60 || c==90 || c==120 || c==150 || c==180){alert_intervals();} 
lcd.setCursor(0,2); 
lcd.print("ELE: "); 
lcd.setCursor(6,2); 
lcd.print(c); 
lcd.setCursor(11,2); 
 
 
lcd.print("Minutes");} 
if(a>=0){ 
if(a==0 || a==30 || a==60 || a==90 || a==120 || a==150 || a==180){alert_intervals();} 
if(a==0){alert();} 
lcd.setCursor(0,3); 
lcd.print("TEL: "); 
lcd.setCursor(6,3); 
lcd.print(a); 
lcd.setCursor(11,3); 
lcd.print("Minutes");} 
delay(counter_delay);}} 
if((converted_value3 == converted_value1) && (converted_value3 == converted_value2) && (converted_value1 == converted_value2) ){ 
for(int a = converted_value3; a>=0; a--){ 
int b = converted_value1--; 
int c = converted_value2--; 
lcd.clear(); 
lcd.print("**COUNTER IS ON**"); 
if(b>=0){ 
if(b==0){alert();} 
//if(b==30 || b==60 || b==90 || b==120 || b==150 || b==180){alert_intervals();} 
lcd.setCursor(0,1); 

 
lcd.print("CVL: "); 
lcd.setCursor(6,1); 
lcd.print(b); 
lcd.setCursor(11,1); 
lcd.print("Minutes");} 
if(c>=0){ 
if(c==0){alert();} 
//if(c==30 || c==60 || c==90 || c==120 || c==150 || c==180){alert_intervals();} 
lcd.setCursor(0,2); 
lcd.print("ELE: "); 
lcd.setCursor(6,2); 
lcd.print(c); 
lcd.setCursor(11,2); 
lcd.print("Minutes");} 
if(a>=0){ 
if(a==0 || a==30 || a==60 || a==90 || a==120 || a==150 || a==180){alert_intervals();} 
if(a==0){alert();} 
lcd.setCursor(0,3); 
lcd.print("TEL: "); 
lcd.setCursor(6,3); 
lcd.print(a); 
 
 
lcd.setCursor(11,3); 
lcd.print("Minutes");} 
delay(counter_delay);}} 
MENU();} 
if (key == 'B'){ 
CVL_ELE_TEL();}} 
//alert function 
void alert(){ 
lcd.clear(); 
lcd.setCursor(0,1); 
lcd.print("    TIMER OVER!!"); 
digitalWrite(buzzer, HIGH); 
delay(1000); 
digitalWrite(buzzer, LOW); 
delay(1000); 
digitalWrite(buzzer, HIGH); 
delay(1000); 
digitalWrite(buzzer, LOW); 
delay(1000); 
digitalWrite(buzzer, HIGH); 
delay(1000); 

 
digitalWrite(buzzer, LOW); 
delay(1000); 
digitalWrite(buzzer, HIGH); 
delay(1000); 
digitalWrite(buzzer, LOW); 
delay(1000);} 
void alert_intervals(){ 
lcd.clear(); 
lcd.setCursor(0,1); 
lcd.print("    Attention!!"); 
digitalWrite(buzzer, HIGH); 
delay(500); 
digitalWrite(buzzer, LOW); 
delay(500); 
digitalWrite(buzzer, HIGH); 
delay(500); 
digitalWrite(buzzer, LOW); 
delay(500); 
} 

 
 
