#include "func.h"


PolySeq::PolySeq(int d){
    this->n = d;
    c = new int[this->n+1];
    for(int i=0;i<=this->n;i++){ c[i]=0; }
}



PolySeq :: ~PolySeq(){
    delete [] c;
}

PolySeq& PolySeq ::operator+(const PolySeq & poly){
    int max_degree = max(n, poly.n);
    PolySeq* result = new PolySeq(max_degree);
    for (int i = 0; i <= max_degree; ++i)
    {
        result->c[i]=poly.c[i]+c[i];
    }
    return *result;
}
       
PolySeq& PolySeq ::Derivative(){
    PolySeq* result = new PolySeq(this->n);
    
    for (int i = 1; i <= n; ++i)
    {
        result->c[i-1]=c[i]*(i);
    }
    return *result;
}
int PolySeq::Integral(int up_bound,int low_bound){
    int integ = 0;
    for (int i = 0; i <= n; ++i)
    {
        integ += c[i] / (i + 1) * (pow(up_bound, i + 1) - pow(low_bound, i + 1));
    }
    return integ;
}

namespace Poly_Int{
    int getValue(PolySeq&poly, int x){
        int sum=0;
        for(int i = 0; i <=poly.n; i++){
            sum += poly.c[i] * pow(x, i);
        }   
        return sum;
    };
}

namespace Poly_Float{
    float getValue(PolySeq&poly, float x){
        float sum=0;
        for(int i = 0; i <= poly.n; i++){
            sum += poly.c[i] * pow(x, i);
        }   
        return sum;
    };
}