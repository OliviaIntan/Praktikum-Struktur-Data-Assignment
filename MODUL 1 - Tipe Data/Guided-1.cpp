#include <iostream>
using namespace std;
//main program
int main()
{
    char op;
    float num1, num2;
    // it allows user to enter operator i.e. +, -, *,/
    cin >> op;
    //it allow user to enter operands
    cin >> num1 >> num2;
    //switch statement begins
    switch (op) {
    // if user enter +
    case '+':
        cout << num1 + num2;
        break;
    // if user enter -
    case '-':
        cout << num1 - num2;
        break;
    // if user enter *
    case '*':
        cout << num1 * num2;
        break;
    // if user enter /
    case '/':
        cout << num1 / num2;
        break;
    // if the operator is other than +, -, * or /,
    //eror massage will display
    default:
        cout << "Eror! operator is not correct";
    }
    return 0;
}