#include "CNumpy.h"
#include <unistd.h>

int main() {
    // Part3 [Guess who is the guy in the result]
    CNumpy left_up("matrix_testcase/part1.matrix");
    cout << "Part 1 matrix: " << endl;
    left_up.render();
    sleep(3);
    cout << "\n\n\n\n\n\n" << endl;

    CNumpy right_up("matrix_testcase/part2.matrix");
    cout << "Part 2 matrix: " << endl;
    right_up.render();
    sleep(3);
    cout << "\n\n\n\n\n\n" << endl;

    CNumpy left_down("matrix_testcase/part3.matrix");
    cout << "Part 3 matrix: " << endl;
    left_down.render();
    sleep(3);
    cout << "\n\n\n\n\n\n" << endl;

    CNumpy right_down("matrix_testcase/part4.matrix");
    cout << "Part 4 matrix: " << endl;
    right_down.render();
    sleep(3);
    cout << "\n\n\n\n\n\n" << endl;

    left_up.concatenate(right_up, 1);
    left_down.concatenate(right_down, 1);
    left_up.concatenate(left_down, 0);
    left_up.render();

    return 0;
}
