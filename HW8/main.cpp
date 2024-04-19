#include <bits/stdc++.h>
#include "money.h"

using namespace std;

int main(int argc, char** argv){

    ifstream input_file(argv[1]);

    int option;
    int pat_num;
    int precent;
    int dollars, cents;

    Money m1(0, 0);
    Money m2(0, 0);

    input_file >> pat_num;
    for(int i = 0; i < pat_num; i++){
        input_file >> option;
        
        if(option == 4){                    // percent function
            input_file >> dollars >> cents;
            Money m1(dollars, cents);

            input_file >> precent;
            Money m2(0, 0);

            m2 = m1.percent(precent);
            cout << m2.getMoney() << endl;
        }
        else {                              // compare operators
            input_file >> dollars >> cents;
            Money m1(dollars, cents);

            input_file >> dollars >> cents;
            Money m2(dollars, cents);

            switch(option){
                case 0: 
                    cout << (m1 <  m2) << endl;
                    break;
                case 1: 
                    cout << (m1 <= m2) << endl;
                    break;
                case 2: 
                    cout << (m1 >  m2) << endl;
                    break;
                case 3: 
                    cout << (m1 >= m2) << endl;
                    break;
                default: break;
            }
        }
    }

    return 0;
}