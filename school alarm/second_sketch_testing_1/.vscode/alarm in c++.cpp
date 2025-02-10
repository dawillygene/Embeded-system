#include<iostream>
using namespace std;
string days[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
string count[]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};
int hour_set[20];
int min_set[20];




int main()
{
 int Number_of_days;
 int number_of_period;
    cout<<"Select Number of days"<<endl;
       cin>>Number_of_days;
         cout<<"Number of period per day"<<endl;
           cin>>number_of_period;
        
        int i=1;
         while (i<=number_of_period)
         {
            cout<<"Enter the hour of period "<<i<<endl;
            cin>>hour_set[i];
            cout<<"Enter the minutes of period"<<i<<endl;
            cin>>min_set[i];
            i++;
         }
         

}
