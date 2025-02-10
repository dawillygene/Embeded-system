#include<Arduino.h>
#include <EEPROM.h>
unsigned long times_seted;
int dawilly;
int main_selector_variable = 4;
unsigned long interval_time;
unsigned long interval_time1 = 0;
int selector_mainInt;
int dayset=0;
int limit=10; //is to limit misunderstanding between scanserial2 and day setting in selector 2
String set_days;
int timing = 0;
int selector = 0;
int setTIME; //used to set times_seted interchangebly
size_t bytesReceived;
size_t bytesReceived1;
unsigned long start = micros();
const unsigned long transmitInterval=4.5e6;//one million micro seconds
 char customaization_set[5]; //= {'\0'}   ;
 char customaization_set1[5];
  char customaization1[3]; //= {'\0'}   ;
   char empty[3]=" ";
    char selector_main[2];
 
const char* ackMessageyes ="yes";
const char* ackMessageno ="no";
const char* Number_of_period_per_day ="yes";
/*********************************************************************************************/

int period_one_hour;
int period_one_minutes;
int period_two_hour;
int period_two_minutes;
int period_three_hour;
int period_three_minutes;
int period_four_hour;
int period_four_minutes;
int period_five_hour;
int period_five_minutes;
int period_six_hour;
int period_six_minutes;
int period_seven_hour;
int period_seven_minutes;



/*********************************************************************************************/
void lines()
{
   Serial.print("*");delay(10);
    Serial.print("*");delay(10);
     Serial.print("*");delay(10);
      Serial.print("*");delay(10);
       Serial.print("*");delay(10);
        Serial.print("*");delay(10);
         Serial.print("*");delay(10);
          Serial.print("*");delay(10);
           Serial.print("*");delay(10);
            Serial.print("*");delay(10);
             Serial.print("*");delay(10);
              Serial.print("*");delay(10);
               Serial.print("*");delay(10);
                Serial.print("*");delay(10);
                 Serial.print("*");delay(10);
                  Serial.print("*");delay(10);
                   Serial.print("*"); Serial.print("*"); Serial.print("*"); Serial.print("*"); Serial.print("*"); Serial.print("*"); Serial.print("*"); Serial.print("*"); Serial.print("*");
                    Serial.println("*");
  
  }
/**********************************************************************************/
void readyState()
{
  const char* readyMessage = "Enter the password to Customize";
    const char* ackMessage = "123";
       char messageReceived[sizeof(ackMessage)+1] = {'\0'}   ;
       bool ackReceived = false;
        while(ackReceived ==false)
         { 
           if((micros()-start)>transmitInterval)
            {
              Serial.println(readyMessage);
               Serial.println(" "); Serial.println(" ");
              start = micros();
            }

             if(Serial.available()>2)
             {
              bytesReceived =  Serial.readBytesUntil('\n',messageReceived,strlen(ackMessage));
              if(bytesReceived == strlen(ackMessage))
                {
                  if(strcmp(messageReceived,ackMessage)==0)
                 {
                   Serial.print("");
                   ackReceived = true;
                 }
                 else
                 {
                  Serial.print("Wrong password,please Try again!");
                 // Serial.println(messageReceived);
                 } 
                }
                else
             {
              Serial.print("Wrong password,please Try again!");
                 // Serial.print(bytesReceived);
             }
             }
             
         } 
}
/**********************************************************************************************/

void scanSerial()
 {
  if( Serial.available()>0)
             {
                            
              bytesReceived =  Serial.readBytesUntil('\n',customaization_set,3);               
             }
 }
/**********************************************************************************************/
/**********************************************************************************************/

void scanSerial2()
 {
if(limit==0){  
    if(Serial.available()>=1)
       { 
   
 int inByte = Serial.read();
    switch (inByte) {
      case '1':
        Serial.println("this is 1");
        inByte=1;
        break;
      case '2':
        Serial.println("this is 2");
        inByte=2;
        break;
      case '3':
         Serial.println("this is 3");
         inByte=3;
        break;
      case '4':
         Serial.println("this is 4");;
        break;
      case '5':
        Serial.println("this is 5");
        break;
      case '6':
        Serial.println("this is 6");
        break;
       case '7':
        Serial.print("7.MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY,SUNDAY");
        Serial.println("  Selected");
        limit=1;
          dayset=7;
            timing=0;
              bytesReceived=0;
        break;
      default:
         Serial.println("invalid selection");
       }
    }
  }               
 }                     
         
 
/**********************************************************************************************/

void scanSerial1()
 {
  if( Serial.available()>0)
             {
                            
              bytesReceived =  Serial.readBytesUntil('\n',customaization_set1,3);  
                      
             }
 }
/*********************************************************************************************/
void scanSerial4()
 {
  
  if( Serial.available()>0)
             {
                  bytesReceived =  Serial.readBytesUntil('\n',customaization1,2);             
 setTIME =atoi(customaization1);
               
           }
 }
/*********************************************************************************************/

void scanSerial_selector()
  {
  if(Serial.available()>0 && limit==10)
             {
                            
            bytesReceived =  Serial.readBytesUntil('\n',selector_main,3);  
              selector_mainInt=atoi(selector_main);       
             }
             if(selector_mainInt==1 && limit==10 )
              {
                main_selector_variable=0;
                 limit=0;
                  }
                   if(selector_mainInt==2 && limit==10)
                    {
                      main_selector_variable=22;
                       limit=0;
                       }
 }
/**********************************************************************************************/
void daysetting()
{
  if(dayset==7)
  {
    scanSerial4();

/***************************************PERIOD ONE******************************************************/    
    if((micros()-start)>transmitInterval &&  timing ==0 )
            {
             
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("First period");
              Serial.print("Enter hour : ");
              period_one_hour =setTIME;
              EEPROM.update(0,period_one_hour);
              Serial.println(period_one_hour);
              if(bytesReceived > 0)
               {
                timing++;
                bytesReceived=0;
               setTIME=0;
            
                }
              start = micros();
            }
            
            if((micros()-start)>transmitInterval && timing ==1  )
            {
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("First period");
              Serial.print("Enter minutes : ");
              period_one_minutes = setTIME;
              EEPROM.update(1,period_one_minutes);
              Serial.println(period_one_minutes);
              start = micros();
               if(bytesReceived > 0)
               {
                timing++;
                bytesReceived = 0;
                setTIME=000;
              
                }
            }
            
/********************************PERIOD 2*************************************************************/
             if((micros()-start)>transmitInterval &&  timing ==2 )
            {
             
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("Second period");
              Serial.print("Enter hour : ");
              period_two_hour =setTIME;
              EEPROM.update(2,period_two_hour);
               Serial.println(period_two_hour);
                if(bytesReceived > 0)
               {
                timing++;
                bytesReceived=0;
               setTIME=00;
                }
              start = micros();
            }
            if((micros()-start)>transmitInterval && timing ==3  )
            {
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("Second period");
              Serial.print("Enter minutes : ");
              period_two_minutes = setTIME;
              EEPROM.update(3,period_two_minutes);
              Serial.println(period_two_minutes);
              start = micros();
               if(bytesReceived > 0)
               {
                timing++;
                bytesReceived = 0;
                setTIME=00;
                }
            }           
/********************************PERIOD 3*************************************************************/
             if((micros()-start)>transmitInterval &&  timing ==4 )
            {
             
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("Third period");
              Serial.print("Enter hour : ");
             period_three_hour =setTIME;
             EEPROM.update(4,period_three_hour);
              Serial.println(period_three_hour);
              if(bytesReceived > 0)
               {
                timing++;
                bytesReceived=0;
               setTIME=0;
                }
              start = micros();
            }
            if((micros()-start)>transmitInterval && timing ==5  )
            {
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("Third period");
              Serial.print("Enter minutes : ");
               period_three_minutes = setTIME;
               EEPROM.update(5,period_three_minutes);
              Serial.println(period_three_minutes);
              start = micros();
               if(bytesReceived > 0)
               {
                timing++;
                bytesReceived = 0;
                setTIME=0;
                }
            }
/********************************PERIOD 4*************************************************************/
             if((micros()-start)>transmitInterval &&  timing ==6 )
            {
             
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("Fourth period");
              Serial.print("Enter hour : ");
             period_four_hour =setTIME;
              EEPROM.update(6,period_four_hour);
              Serial.println(period_four_hour);
              if(bytesReceived > 0)
               {
                timing++;
                bytesReceived=0;
               setTIME=0;
                }
              start = micros();
            }
            if((micros()-start)>transmitInterval && timing ==7  )
            {
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("Fourth period");
              Serial.print("Enter minutes : ");
               period_four_minutes = setTIME;
                EEPROM.update(7,period_four_minutes);
              Serial.println(period_four_minutes);
              start = micros();
               if(bytesReceived > 0)
               {
                timing++;
                bytesReceived = 0;
                setTIME=0;
                }
            }
/********************************PERIOD 5*************************************************************/
             if((micros()-start)>transmitInterval &&  timing ==8 )
            {
             
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("Fifth  period");
              Serial.print("Enter hour : ");
             period_five_hour=setTIME;
             EEPROM.update(8,period_five_hour);
              Serial.println(period_five_hour);
              if(bytesReceived > 0)
               {
                timing++;
                bytesReceived=0;
               setTIME=0;
                }
              start = micros();
            }
            if((micros()-start)>transmitInterval && timing ==9  )
            {
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("Fifth period");
              Serial.print("Enter minutes : ");
               period_five_minutes = setTIME;
               EEPROM.update(9,period_five_minutes);
              Serial.println(period_five_minutes);
              start = micros();
               if(bytesReceived > 0)
               {
                timing++;
                bytesReceived = 0;
                setTIME=0;
                }
            }
/********************************PERIOD 6*************************************************************/
             if((micros()-start)>transmitInterval &&  timing ==10 )
            {
             
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("Sixth period");
              Serial.print("Enter hour : ");
             period_six_hour =setTIME;
             EEPROM.update(10,period_six_hour);
              Serial.println(period_six_hour);
              if(bytesReceived > 0)
               {
                timing++;
                bytesReceived=0;
               setTIME=0;
                }
              start = micros();
            }
            if((micros()-start)>transmitInterval && timing ==11)
            {
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("Sixth period");
              Serial.print("Enter minutes : ");
               period_six_minutes = setTIME;
               EEPROM.update(11,period_six_minutes);
              Serial.println(period_six_minutes);
              start = micros();
               if(bytesReceived > 0)
               {
                timing++;
                bytesReceived = 0;
                setTIME=0;
                }
            }
/********************************PERIOD 7*************************************************************/
             if((micros()-start)>transmitInterval &&  timing ==12 )
            {
             
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("Seventh period");
              Serial.print("Enter hour : ");
             period_seven_hour =setTIME;
             EEPROM.update(12,period_seven_hour);
              Serial.println(period_seven_hour);
              if(bytesReceived > 0)
               {
                timing++;
                bytesReceived=0;
               setTIME=0;
                }
              start = micros();
            }
            if((micros()-start)>transmitInterval && timing == 13)
            {
              Serial.println("**************************************************************");
              Serial.println("**************************************************************");
              Serial.println("....Monday setting....");
              Serial.println("<**************************>");
              Serial.println("Seventh period");
              Serial.print("Enter minutes : ");
               period_seven_minutes = setTIME;
               EEPROM.update(13,period_seven_minutes);
              Serial.println(period_seven_minutes);
              start = micros();
               if(bytesReceived > 0)
               {
                timing++;
                bytesReceived = 0;
                setTIME=0;
                }
            }
/*********************************************************************************************/
if(timing == 14){
  set_ed_Time_table();
  delay(10000);
  
  }
   } 
}
/*********************************************************************************************/
 void intro()
{ 
scanSerial_selector();
if(main_selector_variable==22){
 if( selector == 0 )
  {
    
 
    scanSerial();
    if((micros()-start)>transmitInterval && timing == 0 )
            {
              Serial.println("School Alarm with a simple Customazation");
                  Serial.println("do you want to customize it?");
                     Serial.println("1.Yes");
                       Serial.println("2.No");
                          Serial.println(" ");
                            Serial.println(" ");
              start = micros();
            }
         //  bluetooth.println(customaization_set1);
            if(strcmp(customaization_set,ackMessageyes)==0 )
             {
                    Serial.println("Set the Alarm");
                        Serial.println("Are You sure You Want to Customize It");
                          Serial.println(" ");
                            Serial.println(" ");
                        timing=1;
                          selector = 1;
             }
     
  }

  if( selector == 1 )
    { 
      scanSerial1();
        if (strcmp(customaization_set1,Number_of_period_per_day)== 0)
             { 
              selector = 2;
                    Serial.println("Enter number of days to run from 1 - 7 ");
                      Serial.println(" ");
                        Serial.println(" ");
                          Serial.println("1.MONDAY ");
                             Serial.println("2.MONDAY,TUESDAY ");
                               Serial.println("3.MONDAY,TUESDAY,WEDNESDAY ");
                                 Serial.println("4.MONDAY,TUESDAY,WEDNESDAY,THURSDAY");
                                   Serial.println("5.MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY");
                                     Serial.println("6.MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY");
                                       Serial.println("7.MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY,SUNDAY");
                                       //  Serial.println(selector);
                               } 
}

     if( selector == 2 )
        {
      scanSerial2();
      daysetting();
      
      }
}
}
/*********************************************************************************************/

void set_ed_Time_table(){
  
if(main_selector_variable==0){
  

 Serial.print("The first period Hour: ");
 // period_one_hour
   Serial.print(EEPROM.read(0));Serial.print(" ");  // period_one_hour
     Serial.print("Minutes: ");
     period_one_minutes=EEPROM.read(1);
       Serial.println(period_one_minutes);

         
 Serial.print("The Second period Hour: ");
 period_two_hour=EEPROM.read(2);
   Serial.print(period_two_hour);Serial.print(" ");
     Serial.print("Minutes: ");
     period_two_minutes=EEPROM.read(3);
       Serial.println(period_two_minutes);

Serial.print("The Third period Hour: ");
period_three_hour=EEPROM.read(4);
   Serial.print(period_three_hour);Serial.print(" ");
   period_three_minutes=EEPROM.read(5);
     Serial.print("Minutes: ");
       Serial.println(period_three_minutes);
       
        
Serial.print("The Fourth period Hour: ");
period_four_hour=EEPROM.read(6);
   Serial.print(period_four_hour);Serial.print(" ");
     Serial.print("Minutes: ");
     period_four_minutes=EEPROM.read(7);
       Serial.println(period_four_minutes);

Serial.print("The Fifth period Hour: ");
period_five_hour=EEPROM.read(8);
   Serial.print(period_five_hour);Serial.print(" ");
   period_five_minutes=EEPROM.read(9);
     Serial.print("Minutes: ");
       Serial.println(period_five_minutes);

Serial.print("The Sixth period Hour: ");
period_six_hour=EEPROM.read(10);
   Serial.print(period_six_hour);Serial.print(" ");
     Serial.print("Minutes: ");
     period_six_minutes=EEPROM.read(11);
       Serial.println(period_six_minutes);
       
Serial.print("The Seventh period Hour: ");
period_seven_hour=EEPROM.read(12);
   Serial.print(period_seven_hour);Serial.print(" ");
     Serial.print("Minutes: ");
     period_seven_minutes=EEPROM.read(13);
       Serial.println(period_seven_minutes);
 Serial.println("..................................................");       
         
         delay(5000);
}
}
/*********************************************************************************************/
void setup()
{
    init();
      Serial.begin(9600);
      //EEPROM.begin(1);
//       bluetooth.begin(9600);
      //readyState();
       Serial.println("........WELCOME TO THE SYSTEM........."); 
         Serial.println(" "); 
           Serial.println("1.View the present settings"); 
             Serial.println("2.Customize"); 
               Serial.println(" ");
                  Serial.println(" ");
                  
}
void loop()
  {
   //  lines();
       intro();
       set_ed_Time_table();
       
      
  }
