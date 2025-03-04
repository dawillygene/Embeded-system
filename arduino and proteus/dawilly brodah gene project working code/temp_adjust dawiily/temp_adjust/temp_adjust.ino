                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           #include<LiquidCrystal.h>
#include <Thermistor.h>
#include <NTC_Thermistor.h>
#define SENSOR_PIN             A0
#define REFERENCE_RESISTANCE   8000
#define NOMINAL_RESISTANCE     100000
#define NOMINAL_TEMPERATURE    25
#define B_VALUE                3950
const int rs=A5,en=A4,d4=A3,d5=A2,d6=A1,d7=13;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
#define button1 2
#define button2 3
#define button3 4
#define relay   6
#define buzzer 5
#define motor 7

byte button1_State, button2_State,button3_State ;
int count_value =0;
int prestate =0;
int change_number=111;



Thermistor* thermistor;

void setup() {
  Serial.begin(9600);
    lcd.begin(2,16);
  lcd.setCursor(0,0);
  lcd.print("CHEM MIXER");
    pinMode(button1,INPUT);
      pinMode(button2,INPUT);
       pinMode(button3,INPUT);
         pinMode(relay,OUTPUT);
          pinMode(buzzer,OUTPUT);
           pinMode(motor,OUTPUT);


  thermistor = new NTC_Thermistor(
    SENSOR_PIN,
    REFERENCE_RESISTANCE,
    NOMINAL_RESISTANCE,
    NOMINAL_TEMPERATURE,
    B_VALUE
  );
}

void loop() {
  const double celsius = thermistor->readCelsius();
  const double temp = celsius - 66.1;
  
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C, ");

button1_State = digitalRead(button1);
  button2_State = digitalRead(button2);
   button3_State = digitalRead(button3);
delay(300);
lcd.setCursor(0,1);
  lcd.print("cur:");
   lcd.setCursor(5,1);
  lcd.print(temp);
  lcd.setCursor(8,1);
  lcd.print("set:");
   lcd.setCursor(12,1);
  lcd.print(count_value);
  


 if (button1_State == LOW) {
    count_value++;  
  lcd.setCursor(12,1);
  lcd.print("   ");
  change_number=21;
   
  }

  else if (button2_State ==LOW) {
    count_value--;
  lcd.setCursor(12,1);
  lcd.print("   "); 
  change_number=21;
}

  else if(button3_State == LOW)
  {
    if(change_number == 0)
    {
      digitalWrite(relay,LOW);
      digitalWrite(buzzer,LOW);
      change_number = 21;
      
       
      } 
      else if(change_number == 21)
      {
        change_number = 11;
        } 
        else{}
    }
      else if(temp >= count_value && change_number == 11 )
      {
        digitalWrite(relay,LOW);
         digitalWrite(motor,LOW);
        
      
        change_number =0;
        }
          else if(temp < count_value && change_number == 11 )
          {
        digitalWrite(relay,HIGH);
        digitalWrite(motor,HIGH);
         change_number =0;
         
           } 
            else if(temp >= count_value && change_number ==0)
             {
              digitalWrite(relay,LOW);
                digitalWrite(buzzer,HIGH);
                 digitalWrite(motor,LOW);
              
              }

}
