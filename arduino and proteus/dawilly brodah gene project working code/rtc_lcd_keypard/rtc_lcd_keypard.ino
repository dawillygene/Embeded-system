#include "Arduino.h"
#include "Keypad.h"
#include "LiquidCrystal_PCF8574.h"
#include "Wire.h"
#include "RTClib.h"


#define KEYPADMEM3X4_PIN_ROW1  5
#define KEYPADMEM3X4_PIN_ROW2 6
#define KEYPADMEM3X4_PIN_ROW3 7
#define KEYPADMEM3X4_PIN_ROW4 8
#define KEYPADMEM3X4_PIN_COL1 0
#define KEYPADMEM3X4_PIN_COL2 2
#define KEYPADMEM3X4_PIN_COL3 4




char keypadmem3x4keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};

#define LCD_ADDRESS 0x3F
#define LCD_ROWS 4
#define LCD_COLUMNS 20
#define SCROLL_DELAY 150
#define BACKLIGHT 255
// object initialization
Keypad keypadmem3x4(KEYPADMEM3X4_PIN_COL1,KEYPADMEM3X4_PIN_COL2,KEYPADMEM3X4_PIN_COL3,KEYPADMEM3X4_PIN_ROW1,KEYPADMEM3X4_PIN_ROW2,KEYPADMEM3X4_PIN_ROW3,KEYPADMEM3X4_PIN_ROW4);
LiquidCrystal_PCF8574 lcd20x4;
RTC_DS3231 rtcDS;


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;
void setup() 
{   Serial.begin(9600);
    while (!Serial) ;
    Serial.println("start");
    
    //Initialize the keypad with selected key map
    keypadmem3x4.begin(keypadmem3x4keys);
    // initialize the lcd
    lcd20x4.begin(LCD_COLUMNS, LCD_ROWS, LCD_ADDRESS, BACKLIGHT); 
    if (! rtcDS.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
    }
    if (rtcDS.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    rtcDS.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
    menuOption = menu();
    
}

void loop() 
{
    
    
    if(menuOption == '1') {
    char keypadmem3x4Key = keypadmem3x4.getKey();
    if (isDigit(keypadmem3x4Key) ||  keypadmem3x4Key == '*' ||  keypadmem3x4Key == '#')
    {
    Serial.print(keypadmem3x4Key);
    }
    }
    else if(menuOption == '2') {
    lcd20x4.clear();                       
    lcd20x4.selectLine(2);                    
    lcd20x4.print("    Circuito.io  ");                  
    lcd20x4.selectLine(3);                   
    lcd20x4.print("      Rocks!  ");                   
    delay(1000);

    }
    else if(menuOption == '3') {
    // RTC - Real Time Clock - Test Code
    //This will display the time and date of the RTC. see RTC.h for more functions such as rtcDS.hour(), rtcDS.month() etc.
    DateTime now = rtcDS.now();
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print("  ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    delay(1000);
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}




char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) Membrane 3x4 Matrix Keypad"));
    Serial.println(F("(2) LCD Display 20x4 I2C"));
    Serial.println(F("(3) RTC - Real Time Clock"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
          Serial.println(F("Now Testing Membrane 3x4 Matrix Keypad"));
        else if(c == '2') 
          Serial.println(F("Now Testing LCD Display 20x4 I2C"));
        else if(c == '3') 
          Serial.println(F("Now Testing RTC - Real Time Clock"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}
