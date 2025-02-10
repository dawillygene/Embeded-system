#include<iostream>
using namespace std;

int main()
{
    char alpha_selector;
     cout<<"Enter the character from A to E "<<endl;
      cin>>alpha_selector;

       if(alpha_selector=='A' || alpha_selector=='a')
       {
        cout<<"Accommodation"<<endl;
       }
       else if(alpha_selector=='B' || alpha_selector=='b')
         {
            cout<<"Benzine"<<endl;
          }
           else if(alpha_selector=='C' || alpha_selector=='c')
            {
            cout<<"Chlorine"<<endl;
               }
                else if(alpha_selector=='D' || alpha_selector=='d')
                  {
                    cout<<"Dopamine"<<endl;
                    }else if(alpha_selector=='D' || alpha_selector=='d')
                  {
                    cout<<"Dopamine"<<endl;
                    }
                     else if(alpha_selector=='E' || alpha_selector=='e')
                       {
                    cout<<"Embeded system"<<endl;
                           }
                           else
                            {
                             cout<<"The letter isn't defined in a system"<<endl;
                            }
                             return 0;
}