#include <iostream>
#include <fstream>
#include <string>
#include "polynomial.h"

int main(int argc, char** argv)
{
    PolySeq p1, p2, p3;
    int degree;
    int x1, x2;

    ifstream input(argv[1]);
    
    // Read P1
	input >> degree;
    p1.setDegree(degree);
	input >> p1;

    // Read P2
	input >> degree;
    p2.setDegree(degree);
	input >> p2;

    // Read x1 , x2
    input >> x1 >> x2;

    p3 = p1 + p2;
    cout << p3.getValue(x1) << endl;

    p3 = p1 * p2;
    cout << p3.getValue(x1) << endl;
    
    p3 = p1.Derivative();
    cout << p3.getValue(x1) << endl;

    cout << p2.Integral(x2, x1) << endl;
    
    return 0;
}