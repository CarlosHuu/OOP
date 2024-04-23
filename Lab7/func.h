#ifndef _FUNC_H_
#define _FUNC_H_

#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include <algorithm> 
using namespace std;


class PolySeq{
    public:
        int* c;
        int n;
        PolySeq(int d);
        PolySeq(){
            this->c = new int[1];
            this->n = 1;
            this->c[0] = 0;
        };
        ~PolySeq();
        PolySeq& operator+(const PolySeq &poly);
        PolySeq& Derivative();
        int Integral(int up_bound,int low_bound);
};

namespace Poly_Int{
    int getValue(PolySeq&poly, int x);
}

namespace Poly_Float{
    float getValue(PolySeq&poly, float x);
}
#endif