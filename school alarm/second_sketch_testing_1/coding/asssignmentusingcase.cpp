#include<iostream>
using namespace std;

int main()
{
    char alpha_selector;
     cout<<"Enter the character from A to E "<<endl;
      cin>>alpha_selector;
 
 switch(alpha_selector)
 {
    case 'A': cout<<"alarm"<<endl;
     break;
      case 'B': cout<<"Becon"<<endl;
       break;
         case 'C': cout<<"calculus"<<endl;
           break;
            case 'D': cout<<"drone"<<endl;
              break;
                case 'E': cout<<"Emotion"<<endl;
                  break;
     default: cout<<"non"<<endl;
 }
      
                             return 0;
}