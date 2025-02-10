#include <LiquidCrystal_I2C.h>
const int buttonPin1 = 2, buttonPin2 = 3;    
int button1_State = 0, button2_State = 0;
int count_value =0;
int prestate =0;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("Counter");
  lcd.setCursor(2,1);
  lcd.print(count_value);
}

void loop() {
  // read the state of the pushbutton value:
  button1_State = digitalRead(buttonPin1);
  button2_State = digitalRead(buttonPin2);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (button1_State == HIGH && prestate == 0) {
    count_value++;  
  lcd.setCursor(0,1);
  lcd.print("> ");
  lcd.print(count_value);
  lcd.print(" ");
    prestate = 1;
  }
//decrement
  else if (button2_State == HIGH && prestate == 0) {
    count_value--;
  lcd.setCursor(0,1);
  lcd.print("< ");
  lcd.print(count_value);
  lcd.print(" ");
   prestate = 1;
  } 
 else if(button1_State == LOW && button2_State == LOW) {
    prestate = 0;
  }
}
