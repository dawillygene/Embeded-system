#include <Keypad.h>
#include <EEPROM.h>
#define Solenoid 11            

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

byte rowPins[numRows] = {5, 4, 3, 2}; //Rows
byte colPins[numCols]= {9, 8, 7, 6}; //Columns 


Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup()
         {
          Serial.begin(9600);
pinMode(Solenoid,OUTPUT);       
            Serial.println("standby");        

         }


void loop()
{

  keypressed = myKeypad.getKey();               //Constantly waiting for a key to be pressed
    if(keypressed == '*'){                      // * to open the lock
            Serial.println("Enter code");            //Message to show
            GetCode();                          //Getting code function
                  if(a==sizeof(code))           //The GetCode function assign a value to a (it's correct when it has the size of the code array)
                  OpenDoor();                   //Open lock function if code is correct
                  else{
                             
                 Serial.println("Wrong");          //Message to print when the code is wrong
                  }
            delay(2000);
            
            Serial.println("Standby");             //Return to standby mode it's the message do display when waiting
        }

     if(keypressed == '#'){                  //To change the code it calls the changecode function
      
      Serial.print("Standby");                 //When done it returns to standby mode
     }


         
}

void GetCode(){                  //Getting code sequence
       i=0;                      //All variables set to 0
       a=0;
       j=0; 
                                     
     while(keypressed != 'A'){                                     //The user press A to confirm the code otherwise he can keep typing
           keypressed = myKeypad.getKey();                         
             if(keypressed != NO_KEY && keypressed != 'A' ){       //If the char typed isn't A and neither "nothing"
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
 
  Serial.print("Welcome");       //With a message printed
  digitalWrite(Solenoid,HIGH);
  delay(3000);
  digitalWrite(Solenoid,LOW);
}
