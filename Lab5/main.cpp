#include <iostream>
#include <fstream>
#include <string>
#include "operator.h"

int main()
{
    Complex a, b;
    cout << "Please cin Complex a and Complex b: "<< endl;
    cin >> a >> b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "conjugate of a = " << !a << endl;

    if (a == b)
        cout << "a is equal to b." << endl;
    if (a != b)
        cout << "a is not equal to b." << endl;

    return 0;
}