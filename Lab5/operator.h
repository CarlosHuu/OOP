#include <iostream>
#include <fstream>

using namespace std;

#ifndef _OPERATOR_H_
#define _OPERATOR_H_
class Complex
{
public:
    Complex(){};
    Complex(double r, double i);
    friend const Complex operator-(const Complex &lhs, const Complex &rhs);
    friend const Complex operator!(const Complex &c);
    friend bool operator==(const Complex &lhs, const Complex &rhs);
    friend istream &operator>>(istream &in, Complex &rhs);
    friend ostream &operator<<(ostream &out, const Complex &rhs);
    const Complex operator+(const Complex &rhs);
    const Complex operator*(const Complex &rhs);
    bool operator!=(const Complex &rhs);

private:
    double re;
    double im;
};
#endif