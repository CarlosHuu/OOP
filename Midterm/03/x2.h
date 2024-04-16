#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class X_2
{
private:
    int a, b, c; // y = ax^2+bx+c
public:
    X_2();
    X_2(int v1, int v2, int v3);
    void set_equation(int v1, int v2, int v3);
    void show_equation();
    void find_real_root();
    void find_vertex();
    X_2 operator + (const X_2 & obj); 
};