#include <iostream>
using namespace std;
bool state=true;
bool hold=true;

int main()
{
string shift[20]={"First","Second","Third","Fourth","Fifth","Sixth","Seventh","Eighth","Tenth","Eleventh","Twelve"};
 int counter=0;
  int hours[40];
   int minutes[40];
	while(state)
	{
	 cout<<"Enter the Hour of "<<shift[counter]<<" Period"<<endl;
	  cin>>hours[counter];
	   if(hours[counter]>12)
	    {
	      while(hold)
	       { 
	       cout<<"!!!Error input please Enter value between 1 - 12!!!"<<endl;
	        cout<<"*******************************************"<<endl;
	         cout<<"Enter the Hour of "<<shift[counter]<<" Period"<<endl;
	           cin>>hours[counter];
	            if(hours[counter]<13)
	            {
	            hold=false;
	            }
	       	       
	        }
	    
	    }
	 hold=true;
	  cout<<"Enter the Minutes of "<<shift[counter]<<" Period"<<endl;
	  cin>>minutes[counter];
	   if(minutes[counter]>60)
	    {
	      while(hold)
	       { 
	       
	       cout<<"!!!Error input please Enter value between 0 - 60!!!"<<endl;
	        cout<<"*******************************************"<<endl;
	         cout<<"Enter the Minutes of "<<shift[counter]<<" Period"<<endl;
	           cin>>hours[counter];
	            if(hours[counter]<61)
	            {
	            hold=false;
	            }
	       	       
	        }
	    
	    }
	    
	  counter++;
	  hold=true;
	}
	
	
}
