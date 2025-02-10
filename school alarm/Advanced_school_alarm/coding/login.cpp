#include <iostream>

using namespace std;

string usrnam[] = { "admin", "user", "" };
string pasword[] = { "root", "default", ""};

string temp_pass;
string temp_usr;

bool loggedin;

int n = sizeof(usrnam) / sizeof(string);

int findPassword( string str[], int array_size, string query )
{
    for ( int i = 0; i < array_size; i++ )
    {
        if ( str[i] == query )
    {
        return i;
    }
}
}

int commandC()
{
    int stage;
    cout << "Enter '1' for calculator: ";
    cin >> stage;
    switch(stage)
{
    case 1: {
        cout << endl;
        cout << "Not fully developed" << endl << endl;

    }
}

cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-";
}

void login(string user, string pass){
     if ( pass == pasword[findPassword(usrnam, n, user)] )
     {
        cout << "Logged in as " << user << endl << endl;
        loggedin = true;
        commandC();
     }
}

void registerUser()
{
    string answer;
    cout << "No matches found in the database...would you like to make new account? (Y/N)";
    cin >> answer;
    if (answer == "y" || answer == "Y")
    {
        cout << "Please enter a username: ";
        cin >> usrnam[n-1];
        cout << "Please enter a password: ";
        cin >> pasword[n-1];

        login(usrnam[n-1],pasword[n-1]);
    }
}

int main()
{
    cout << "Enter username: ";
    cin >> temp_usr;
    cout << "Enter password; ";
    cin >> temp_pass;

    login(temp_usr,temp_pass);

    if(!loggedin)
        registerUser();
}