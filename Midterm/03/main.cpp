#include <iostream>
#include "x2.h"

using namespace std;

int main(int argc, char **argv)
{

    if (argv[1][0] == '1')
    {
        // test constructor and set function and show function
        X_2 equation1;
        X_2 equation2(1, 0, -4);
        equation1.show_equation();
        equation2.show_equation();
        equation2.set_equation(10, 1000, 12);
        equation2.show_equation();
        equation2.set_equation(-100, 23, 111);
        equation2.show_equation();
        equation2.set_equation(1, 1, 1);
        equation2.show_equation();
        equation2.set_equation(-1, -1, -1);
        equation2.show_equation();
        equation2.set_equation(-1, 2, -1);
    }
    else if (argv[1][0] == '2')
    {
        // test find_vertex and show function
        X_2 equation2;
        equation2.find_vertex();
        equation2.set_equation(-1, 2, -1);
        equation2.find_vertex();
        equation2.set_equation(22, 102, -55);
        equation2.find_vertex();
    }
    else if (argv[1][0] == '3')
    {
        // test operator +
        X_2 equation2(1, 1, 1);
        X_2 equation1(3, 3, 3);
        equation1 = equation1 + equation2;
        equation1.show_equation();
        equation2.set_equation(-10, -9, -8);
        equation1 = equation1 + equation2;
        equation1.show_equation();
        equation2.set_equation(5, 4, 3);
        equation1 = equation1 + equation2;
        equation1.show_equation();
    }
    else if (argv[1][0] == '4')
    {
        // test find_real_root(roots are integer)
        X_2 equation2;
        equation2.set_equation(1, 1, 1);
        equation2.show_equation();
        equation2.find_real_root();
        cout << endl;
        equation2.set_equation(1, 2, 1);
        equation2.show_equation();
        equation2.find_real_root();
        cout << endl;
        equation2.set_equation(1, 0, -9);
        equation2.show_equation();
        equation2.find_real_root();
        cout << endl;
    }
    else if (argv[1][0] == '5')
    {
        // test find_real_root(roots are float)
        X_2 equation2;
        equation2.set_equation(5, 12, 4);
        equation2.find_real_root();
        equation2.set_equation(-2, 13, 20);
        equation2.find_real_root();
    }

    return 0;
}