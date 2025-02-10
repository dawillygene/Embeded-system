//unsigned long time_mine;
//unsigned long interval_time;
//unsigned long interval_time1 = 0;
byte customaization_set;
byte Number_of_period_per_day;
byte set_days;
byte cust=0;
byte period=0;
void setup() {
Serial.begin(9600);
Serial.println("School Alarm with a simple Customazation");
  Serial.println("do you want to customize it?");
   Serial.println("1.Yes");
    Serial.println("2.No");
}

void loop() {     
    // Serial.setTimeout(time);
   if(Serial.available()>0)
      {
    customaization_set = Serial.read();
    Serial.println(customaization_set);    
   // delay(10);
    if(customaization_set==49)
          { 
         Serial.println("Set the Alarm");
          Serial.println("Enter the number of Periods per day");
          cust=1;  
            }
          } 
          
       if(cust==1)
          {
                    //  Serial.println("Set the Alarm");
                       // Serial.println("Enter the number of Periods per day");
         
              else if(Serial.available()>0)
                  {
                     Number_of_period_per_day = Serial.read();
                    byte Number_of_period_per_day1 = Serial.read();
                     byte Number_of_period_per_day2 = Serial.read();
                      byte Number_of_period_per_day3 = Serial.read();
                       byte Number_of_period_per_day4 = Serial.read();
                       Serial.println(Number_of_period_per_day);  
                          //delay(100);
                       else if(Number_of_period_per_day==49 || Number_of_period_per_day1==49 || Number_of_period_per_day2==49 ||Number_of_period_per_day3==49 || Number_of_period_per_day4 ==49)
                       {
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
                                         period=1;
                        }
                        else
                          {
                          Serial.print("Invalid selection");
                              Serial.print("Device doesn't programmed to perform that less task");
                              }
                        
                        }
                
                     
                           
                              
          
                    }
       //  else if(customaization_set == 50)
         //{
          //          }
}

  




/*void Monday()
{
int Monday_period_one_hour;
int Monday_period_one_minutes;
Serial.println("Enter the Hour for Period one");
 if(Serial.available()>0)
 {
 Monday_period_one_hour=Serial.read();

 }



} */
