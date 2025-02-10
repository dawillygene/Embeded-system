#include<LiquidCrystal.h>
const int rs=8,en=7,d4=2,d5=3,d6=4,d7=6;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);


#define detectionPin 12
#define LED1 A5    
#define LED2 A3
#define BATTERY A2
#define relay 9
int BT=0;
void setup() {
  Serial.begin(9600); 
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(relay,OUTPUT);
  pinMode(BATTERY,INPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("BATTERY");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("CHARGER");
  delay(1000);
  lcd.clear();

}

void loop() {
int B;
 digitalWrite(relay,LOW);delay(1000);
 B=analogRead(BATTERY)/41.4808917197;
   BT=(B/12.661)*100;
    delay(100);
  lcd.setCursor(0,0);
  lcd.print("BATTERY CHARGER");
 
  
 




if(B>=12){
  lcd.clear();
    digitalWrite(LED2,LOW);
  digitalWrite(LED1,HIGH);
   lcd.setCursor(0,0);
  lcd.print("BATTERY CHARGER");
  digitalWrite(relay,LOW);
 lcd.setCursor(0,1);
  lcd.print("FULL");
   lcd.setCursor(9,1);
  lcd.print("100%");
  delay(1000);
  }
else if(B<12){
  lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("BATTERY CHARGER");
  

  digitalWrite(LED2,HIGH);
  digitalWrite(LED1,LOW);
  lcd.setCursor(0,1);
  lcd.print("Charging");
  lcd.setCursor(9,1);
  lcd.print(BT);
  lcd.setCursor(11,1);
  lcd.print("%");
   digitalWrite(relay,HIGH);
  delay(10000);
 
    
    
  }
}
