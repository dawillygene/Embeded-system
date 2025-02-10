#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"
VR myVR(2,3);  
LiquidCrystal_I2C lcd(0x27,20,2);  // set  
int led = 13;
int pre_state=0;
#define Solenoid 12  
uint8_t records[7]; // save record
uint8_t buf[64];
const byte numRows= 4;          //number of rows on the keypad
const byte numCols= 4;          //number of columns on the keypad
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

char keypressed;                 //Where the keys are stored it changes very often
char code[]= {'6','6','0','1'};  //The default code, you can change it or make it a 'n' digits one
short a=0,i=0,s=0,j=0;          //Variables used later

byte rowPins[numRows] = {5, 4, 11, 10}; //Rows
byte colPins[numCols]= {9, 8, 7, 6}; //Columns 


Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);


#define onRecord    (0)
#define offRecord   (1) 
void printSignature(uint8_t *buf, int len)
{
  int i;
  for(i=0; i<len; i++){
    if(buf[i]>0x19 && buf[i]<0x7F){
      Serial.write(buf[i]);
    }
    else{
      Serial.print("[");
      Serial.print(buf[i], HEX);
      Serial.print("]");
    }
  }
}


void printVR(uint8_t *buf)
{
  Serial.println("VR Index\tGroup\tRecordNum\tSignature");

  Serial.print(buf[2], DEC);
  Serial.print("\t\t");

  if(buf[0] == 0xFF){
    Serial.print("NONE");
  }
  else if(buf[0]&0x80){
    Serial.print("UG ");
    Serial.print(buf[0]&(~0x80), DEC);
  }
  else{
    Serial.print("SG ");
    Serial.print(buf[0], DEC);
  }
  Serial.print("\t");

  Serial.print(buf[1], DEC);
  Serial.print("\t\t");
  if(buf[3]>0){
    printSignature(buf+4, buf[3]);
  }
  else{
    Serial.print("NONE");
  }
  Serial.println("\r\n");
}

void setup()
{
  
  myVR.begin(9600);
  Serial.begin(115200);
  Serial.println("Elechouse Voice Recognition V3 Module\r\nControl LED sample");
  pinMode(Solenoid,OUTPUT);       
  Serial.println("standby");        
  lcd.init();                      
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("standby");
  pinMode(led,OUTPUT);
  digitalWrite(Solenoid,LOW);
    
  if(myVR.clear() == 0){
    Serial.println("Recognizer cleared.");
  }else{
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while(1);
  }
  
  if(myVR.load((uint8_t)onRecord) >= 0){
    Serial.println("onRecord loaded");
  }
  
  if(myVR.load((uint8_t)offRecord) >= 0){
    Serial.println("offRecord loaded");
  }
}
void GetCode(){                  //Getting code sequence
       i=0;                      //All variables set to 0
       a=0;
       j=0; 
                                     
     while(keypressed != 'A'){                                     //The user press A to confirm the code otherwise he can keep typing
           keypressed = myKeypad.getKey();                         
             if(keypressed != NO_KEY && keypressed != 'A' ){       //If the char typed isn't A and neither "nothing"
              lcd.setCursor(j,1);                                  //This to write "*" on the LCD whenever a key is pressed it's position is controlled by j
              lcd.print("*");
              j++;
            if(keypressed == code[i]&& i<sizeof(code)){            //if the char typed is correct a and i increments to verify the next caracter
                 a++;                                              //Now I think maybe I should have use only a or i ... too lazy to test it -_-'
                 i++;
                 }
            else
                a--;                                               //if the character typed is wrong a decrements and cannot equal the size of code []
            }
            }
    keypressed = NO_KEY;

}
void OpenDoor(){             //Lock opening function open for 3s
  lcd.setCursor(0,1); 
  lcd.print("Welcome");       //With a message printed
  digitalWrite(Solenoid,HIGH);
  delay(3000);
  digitalWrite(Solenoid,LOW);
  pre_state=0;
}

void loop()
{
  int ret;
  ret = myVR.recognize(buf, 50);
  if(ret>0){
    switch(buf[1]){
      case onRecord:
      pre_state=1;
       printVR(buf);
       
        break;
      case offRecord:
      printVR(buf);
      pre_state=1;
        /** turn off LED*/
        
        break;
      default:
        Serial.println("Record function undefined");
        break;
         printVR(buf);
    }
    
   
  }
  else if(pre_state==1)
  {
    lcd.setCursor(0,1);
    lcd.print("Press *");
keypressed = myKeypad.getKey();               //Constantly waiting for a key to be pressed
    if(keypressed == '*'){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Enter code");
            Serial.println("Enter code");            //Message to show
            GetCode();                          //Getting code function
                  if(a==sizeof(code))           //The GetCode function assign a value to a (it's correct when it has the size of the code array)
                  OpenDoor();                   //Open lock function if code is correct
                  else{
                   lcd.clear();               
                  lcd.print("Wrong");          
                 Serial.println("Wrong");          //Message to print when the code is wrong
                  }
            delay(2000);
            lcd.clear();
            lcd.print("Standby");
            Serial.println("Standby");             //Return to standby mode it's the message do display when waiting
        }

     if(keypressed == '#'){                  //To change the code it calls the changecode function
      lcd.clear();
      lcd.print("Standby"); 
      Serial.print("Standby");




        
    }
  }}
