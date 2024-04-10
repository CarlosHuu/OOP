#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
class PolySeq
{
public:
PolySeq(){
    highest_degree = 0;
    c = NULL;
};
~PolySeq();

friend ostream &operator<<(ostream &out, const PolySeq &poly);
friend istream &operator>>(istream &in, PolySeq &poly);
friend const PolySeq operator+(const PolySeq &lhs, const PolySeq &rhs);
friend const PolySeq operator*(const PolySeq &lhs, const PolySeq &rhs);
PolySeq& operator=(const PolySeq &rhs);
const PolySeq Derivative();
const double Integral(int up_bound, int low_bound);
const double getValue(double);
void setDegree(int);
void setCoeff(int, double);

private:
int highest_degree;
double* c;
};

#endif