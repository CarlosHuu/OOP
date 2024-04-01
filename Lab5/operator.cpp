#include "operator.h"

const Complex Complex::operator+(const Complex &rhs)
{
    // vvvvv put your code here vvvvv
    return Complex(re + rhs.re, im + rhs.im);
    // ^^^^^ put your code here ^^^^^
}

const Complex operator-(const Complex &lhs, const Complex &rhs)
{
    // vvvvv put your code here vvvvv
    Complex minus(lhs.re-rhs.re,lhs.im-rhs.im);
    return minus;
    // ^^^^^ put your code here ^^^^^
}

const Complex Complex::operator*(const Complex &rhs)
{   
    // vvvvv put your code here vvvvv
    return Complex(re*rhs.re - im*rhs.im, re*rhs.im + im*rhs.re);
    // ^^^^^ put your code here ^^^^^
}

const Complex operator!(const Complex &c)
{
    // vvvvv put your code here vvvvv
    Complex cnj(c.re,(-1)*c.im);
    return cnj;
    // ^^^^^ put your code here ^^^^^
}

bool operator==(const Complex &lhs, const Complex &rhs)
{
    // vvvvv put your code here vvvvv
    bool det;
    if((lhs.re==rhs.re)&&(lhs.im==rhs.im))det=true;
    else det=false;
    return det;
    // ^^^^^ put your code here ^^^^^
}

bool Complex::operator!=(const Complex &rhs)
{
    // vvvvv put your code here vvvvv
    bool det;
    if((re != rhs.re )||(im != rhs.im)) det = true;
    else det = false;
    return det;
    // ^^^^^ put your code here ^^^^^
}

ostream &operator<<(ostream &out, const Complex &rhs)
{
    // vvvvv put your code here vvvvv
    if(rhs.im<0) out<<rhs.re<<rhs.im<<"i";

    else out<<rhs.re<<"+"<<rhs.im<<"i";

    return out;
    // ^^^^^ put your code here ^^^^^
}

istream &operator>>(istream &in, Complex &rhs)
{
    // vvvvv put your code here vvvvv
    in>>rhs.re>>rhs.im;
    return in;
    // ^^^^^ put your code here ^^^^^
}

Complex::Complex(double r, double i) : re(r), im(i) {}