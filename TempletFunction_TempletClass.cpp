#include <iostream>
using namespace std;

// 1. Template Function to find max of two values
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// 2. Template Class for Calculator
template <typename T>
class Calculator {
private:
    T num1, num2;

public:
    // Constructor
    Calculator(T n1, T n2){
        num1 = n1;
        num2 = n2;
    }

    // Addition
    T add() {
        return num1 + num2;
    }

    // Subtraction
    T subtract() {
        return num1 - num2;
    }

    // Multiplication
    T multiply() {
        return num1 * num2;
    }

    // Division
    T divide() {
        return num1 / num2;
    }
};


int main() {
    // For template function
    int i1 = 5, i2 = 0;
    float f1 = 3.5, f2 = 2.6;
    double d1 = 7.8, d2 = 4.2;

    cout << "Max of " << i1 << " and " << i2 << " is: " << findMax(i1, i2) << endl;  // int
    cout << "Max of " << f1 << " and " << f2 << " is: " << findMax(f1, f2) << endl;  // float
    cout << "Max of " << d1 << " and " << d2 << " is: " << findMax(d1, d2) << endl;  // double
    
    // Integer Calculation
    Calculator<int> intCalc(i1, i2);
    cout << "\nInteger Operations: " <<endl;
    cout << "Addition : " << i1 << " + " << i2 << " = " << intCalc.add() << endl;
    cout << "Subtraction : " << i1 << " - " << i2 << " = " << intCalc.subtract() << endl;
    cout << "Multiplication : " << i1 << " * " << i2 << " = " << intCalc.multiply() << endl;
    if(i2 != 0)
        cout << "Division : " << i1 << " / " << i2 << " = " << intCalc.divide() << endl;
    else
        cout << "Error: Division by zero!" << endl;

    // Float Calculation
    Calculator<float> floatCalc(f1, f2);
    cout << "\nFloat Operations: " <<endl;
    cout << "Addition : " << f1 << " + " << f2 << " = " << floatCalc.add() << endl;
    cout << "Subtraction : " << f1 << " - " << f2 << " = " << floatCalc.subtract() << endl;
    cout << "Multiplication : " << f1 << " * " << f2 << " = " << floatCalc.multiply() << endl;
    if(f2 != 0)
        cout << "Division : " << f1 << " / " << f2 << " = " << floatCalc.divide() << endl;
    else
        cout << "Error: Division by zero!" << endl;

    // Double Calculation
    Calculator<double> doubleCalc(d1, d2);
    cout << "\nDouble Operations: " <<endl;
    cout << "Addition : " << d1 << " + " << d2 << " = " << doubleCalc.add() << endl;
    cout << "Subtraction : " << d1 << " - " << d2 << " = " << doubleCalc.subtract() << endl;
    cout << "Multiplication : " << d1 << " * " << d2 << " = " << doubleCalc.multiply() << endl;
    if(d2 != 0)
        cout << "Division : " << d1 << " / " << d2 << " = " << doubleCalc.divide() << endl;
    else
        cout << "Error: Division by zero!" << endl;

    return 0;
}

