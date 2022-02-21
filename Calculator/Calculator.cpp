#include <iostream>
using namespace std;

double readNumber(string variable)
{
    cout << "Enter the " << variable << ": ";
    double number;
    cin >> number;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(999, '\n');

        cout << "Invalid value! Please, try again...\n";
        return readNumber(variable);
    }
    
    return number;
}

char readOperation() {
    cout << "Enter operation sign: ";
    char sign;
    cin >> sign;

    if (sign != '+' && sign != '-' && sign != '*' && sign != '/' && sign != ':')
    {
        cin.clear();
        cin.ignore(999, '\n');

        cout << "Invalid value! Only 4 operation can be used (+, -, *, / (:)). Please, try again...\n";
        return readOperation();
    }

    return sign;
}

double performOperation(double firstNumber, double secondNumber, char operation)
{
    if (operation == '+')
    {
        return firstNumber + secondNumber;
    }
    else if (operation == '-')
    {
        return firstNumber - secondNumber;
    }
    else if (operation == '*')
    {
        return firstNumber * secondNumber;
    } 
    else
    {
        return secondNumber == 0 ? 0 : firstNumber / secondNumber;
    }
}

void printResult(double firstNumber, double secondNumber, double result, char operation)
{
    if (result == 0 && (operation == '/' || operation == ':'))
    {
        cout << "Error! You can not do division by zero!";
    }
    else 
    {
        cout << firstNumber << operation << secondNumber << "=" << result;
    }
}

void main()
{
    double firstNumber = readNumber("first number");
    char operation = readOperation();
    double secondNumber = readNumber("second number");

    double result = performOperation(firstNumber, secondNumber, operation);
    printResult(firstNumber, secondNumber, result, operation);
}
