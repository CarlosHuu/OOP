#include <iostream>
#include <fstream>
#include <string>
#include "func.h"
using namespace std;
int main()
{
    PolySeq  p3;
    int degree;
    int x1, x2;
    float x3;
    
    // Read P1
	cin >> degree;
    PolySeq p1(degree);
	for (int i=degree-1; i>=0; i--){
        cin >> p1.c[i];
    }


    // Read P2
	cin >> degree;
    PolySeq p2(degree);
	for (int i=degree-1; i>=0; i--){
        cin >> p2.c[i];
    }
    
    cin >> x1 >> x2>>x3;

    p3 = p1 + p2;
    // using namespace Poly_Int;
    cout << Poly_Int::getValue(p3,x1) << endl;
    
    p3 = p1.Derivative();
    // using namespace Poly_Float;
    cout << Poly_Float::getValue(p3,x3) << endl;

    cout << p2.Integral(x2, x1) << endl;
    
    return 0;
}