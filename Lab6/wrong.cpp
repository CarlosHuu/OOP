// Wrong Code

#include <iostream>

using namespace std;

// --------------------------
// Correct code should print:
// 10
// 15
// 20
// 25
// 30
// 35
// 40
// 45
// 50
// 55
// --------------------------

void add_func(int** sum_result, int** array_10X5){
    int* temp = new int [10];

    for(int i=0; i<10; i++) *(temp+i) = 0;

    for(int i=0; i<10; i++){
        for(int j=0; j<5; j++){
            temp[i] = temp[i] + array_10X5[i][j];
        }
    }
    *sum_result = temp;

    delete [] temp;
    return;
}

int main(){
    int* sum_result;
    int** array_10X5 = new int*[10];

    for(int i=0; i<5; i++){
        *(array_10X5+i) = new int[5];
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<5; j++){
            array_10X5[i][j] = i+j;
        }
    }

    add_func(&sum_result, array_10X5);

    for(int i=0; i<10; i++){
        cout << sum_result[i] << endl;
    }

    delete [] sum_result;
    for(int i=0; i<10; i++) delete [] *(array_10X5+i);
    delete [] array_10X5;
    return 0;
}
