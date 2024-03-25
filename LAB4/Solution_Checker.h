#ifndef _SOLUTION_CHECKER_H_
#define _SOLUTION_CHECKER_H_

#include <bits/stdc++.h>
#include "Random_Matrix_Generator.h"
using namespace std;

class Solution_Checker{
    private:
        int **matrix;
        int row;
        int col;
    
    public:
        Solution_Checker(const char *input_filename);
        ~Solution_Checker();

        bool Part1_Checker(int row, int col, int **matrix);
        bool Part2_Checker(int m1_min, int m1_max, int minIdx1, int minIdx2, int maxIdx1, int maxIdx2);
};

#endif