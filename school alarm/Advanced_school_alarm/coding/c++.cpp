#include<iostream>
  using namespace std;

     int main()
      {
        float firstnumber,secondnumber;
           
            cout<<"Enter the first number"<<endl;
                cin>>firstnumber;
                    cout<<"Enter the second number"<<endl;
                        cin>>secondnumber;
                        double Divoperation;
                    Divoperation=firstnumber/secondnumber;
                cout<<"Divoperation :"<<Divoperation<<endl;
            int firstinteger=Divoperation;
          cout<<"firstinteger :"<<firstinteger<<endl;
       double answer=Divoperation-firstinteger;
     cout<<"answer :"<<answer<<endl;
    int finalise=answer*secondnumber;
  cout<<"The reminder is : "<<finalise<<endl;
cout<<"**************************"<<endl;
    int first=firstnumber;
        int second=secondnumber;
            int jibu=first%second;
                cout<<"The reminder is : "<<jibu<<endl;
                    return 0;





}
