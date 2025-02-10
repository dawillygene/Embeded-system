#include <iostream>
using namespace std;
bool state = true;
float firstNumber;
float secondNumber;
string response;
char operators;
float answer;

int calculator()
{
    switch (operators)
    {
    case '+':
        answer = firstNumber + secondNumber;
        break;
    case '-':
        answer = firstNumber - secondNumber;
        break;
    case '*':
        answer = firstNumber * secondNumber;
        break;
    case '/':
        answer = firstNumber / secondNumber;
        break;
    default:
        cout << "Invalid input Operator" << endl;
        break;
    }

    cout << "The answer is :" << answer << endl;
}

int main()
{
    while (state)
        int
        {
            cout << "Enter the first Number" << endl;
            cin >> firstNumber;
            cout << "Enter the second Number" << endl;
            cin >> secondNumber;
            cout << "Enter the operator +,*,-,/" << endl;
            cin >> operators;

            calculator();

            cout << "do you wish to continue............?(yes/No)" << endl;
            cin >> response;
            if (response == "yes")
            {
                state = true;
            }
            else
            {
                state = false;
            }
        }
    return 0;
}
