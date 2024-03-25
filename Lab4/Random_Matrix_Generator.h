#ifndef _RANDOM_MATRIX_GENERATOR_H_
#define _RANDOM_MATRIX_GENERATOR_H_

#include <bits/stdc++.h>
#include <chrono>
using namespace std;

class Random_Matrix_Generator {
    public:
        void generateRandomMatrixFile(const char* filename);

    private:
        int generateRandomNumber(int min, int max);
};

#endif
