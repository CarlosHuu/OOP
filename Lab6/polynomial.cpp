#include "polynomial.h"

void PolySeq::setDegree(int d)
{
    this->highest_degree = d;
    c = new double[this->highest_degree+1];
    for(int i=0;i<=this->highest_degree;i++){ c[i]=0; }
}

void PolySeq::setCoeff(int exp, double coef)
{
    c[exp] = coef;
}

PolySeq::~PolySeq()
{
    // vvvvv put your code here vvvvv
    delete [] c ;
    // ^^^^^ put your code here ^^^^^
}

const double PolySeq::getValue(double x)
{
    // vvvvv put your code here vvvvv
    double sum=0;
    for(int i = 0; i <= highest_degree ; i++){
        sum += c[i] * pow(x, i);
    }
    return sum;
    // ^^^^^ put your code here ^^^^^
}

istream &operator>>(istream &in, PolySeq &poly)
{
    // vvvvv put your code here vvvvv
    for (int i = poly.highest_degree; i >= 0 ; i--){
        in >> poly.c[i];
    }
    return in;
    // ^^^^^ put your code here ^^^^^
}

ostream &operator<<(ostream &out, const PolySeq &poly)
{
    // vvvvv put your code here vvvvv
    // out << poly;
    return out;
    // ^^^^^ put your code here ^^^^^   
}

PolySeq& PolySeq::operator=(const PolySeq &rhs){
    // vvvvv put your code here vvvvv
    if (this != &rhs)
    {
        highest_degree = rhs.highest_degree;
        delete[] c;
        c = new double[highest_degree + 1];
        for (int i = 0; i <= highest_degree; ++i)
        {
            c[i] = rhs.c[i];
        }
    }
    return *this;
    // ^^^^^ put your code here ^^^^^
}

const PolySeq operator+(const PolySeq &lhs, const PolySeq &rhs)
{
    // vvvvv put your code here vvvvv
    int max_degree = max(lhs.highest_degree, rhs.highest_degree);
    PolySeq result;
    result.setDegree(max_degree);
    for (int i = 0; i <= max_degree; ++i)
    {
        double coef_lhs = (i <= lhs.highest_degree) ? lhs.c[i] : 0;
        double coef_rhs = (i <= rhs.highest_degree) ? rhs.c[i] : 0;
        result.setCoeff(i, coef_lhs + coef_rhs);
    }
    return result;
    // ^^^^^ put your code here ^^^^^
}

const PolySeq operator*(const PolySeq &lhs, const PolySeq &rhs)
{
    // vvvvv put your code here vvvvv
    PolySeq prod;
    prod.setDegree(lhs.highest_degree + rhs.highest_degree);
    int exp;
    double coef;
  
    for (int i = 0 ; i <= lhs.highest_degree ; ++i){
        for (int j = 0 ; j <= rhs.highest_degree ; ++j){
            exp = i + j;
            coef = lhs.c[i] * rhs.c[j];
            prod.c[exp]+=coef;
        }
    }
    return prod;
    // ^^^^^ put your code here ^^^^^
}

const PolySeq PolySeq::Derivative()
{
    // vvvvv put your code here vvvvv
    PolySeq deriv;
    deriv.setDegree(highest_degree-1);
    for (int i = 1 ; i <= highest_degree ; ++i) {
            deriv.c[i-1] = i*c[i];
        }
    return deriv;
    // ^^^^^ put your code here ^^^^^
}

const double PolySeq::Integral(int up_bound, int low_bound)
{
    // vvvvv put your code here vvvvv
    double integ = 0;
    for (int i = 0; i <= highest_degree; ++i)
    {
        integ += c[i] / (i + 1) * (pow(up_bound, i + 1) - pow(low_bound, i + 1));
    }
    return integ;
    // ^^^^^ put your code here ^^^^^
}