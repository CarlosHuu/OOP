//#include "Pairs_operation.cpp"
#include "Pairs_operation.h"
#include <fstream>
#include <iostream>
int main(int argc,char ** argv)
{
    ifstream file;
    file.open(argv[1]);
    int opera;
    int mult_int;
    int first,second;
    Pairs a ;
    file >> first;
    Pairs b (first);
    file >> first >> second;
    Pairs c(first,second);
    Pairs d;
    file >> d;
    Pairs e;
    file >> e;
    bool st=1;
    while(st){
        file >>opera;
        switch(opera){
        case 1:
            b=c+b;break;
        case 2:
            file >> mult_int;
            b=c* mult_int;break;
        case 3:
            file >> a;break;
        case 4:
            d=e-c; break;
        case 5:
            cout << a << endl;
            cout << b << endl;
            cout << c << endl;
            cout << d << endl;
            cout << e << endl;break;
        case 6:
            c=d+e;break;

        }
        file>>st;
    }
    file.close();
}