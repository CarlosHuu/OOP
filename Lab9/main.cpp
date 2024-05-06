#include <bits/stdc++.h>
#include "building.h"

// parameter setting
#define YEAR 10

using namespace std;

int main(int argc, char** argv){

    ifstream infile(argv[1]);
    
    // Resource belongs to your kingdom
    int    workforce;
    float  foodstuff;
    float  timber  = 0;
    string mineral = "";

    infile >> workforce
           >> foodstuff;

    // Resource exists in nature or buildings
    int   resident [1];
    float field    [1];
    float forest   [YEAR];
    char  lode     [YEAR];

    infile >> *resident
           >> *field;
    for(int i = 0; i < YEAR; i++) infile >> *(forest + i);
    for(int i = 0; i < YEAR; i++) infile >> *(lode   + i);


    // Declare 4 type of building here, which are
    // 2 generation building: house ,farm 
    // 2 exploitation building: mine, logging
    // the first one is done for you.

    // ↓↓↓ write down your code below ↓↓↓

    Building<int> *house = new Generation<int>(resident);
    Building<float> *farm = new Generation<float>(field);
    Building<float> *logging = new Exploitation<float>(forest);
    Building<char> *mine = new Exploitation<char>(lode);

    // ↑↑↑ write down your code above ↑↑↑
    
    int year = 0;
    
    cout << endl;
    cout << "口======= Year " << year << " =======口" << endl;
    cout << "   workforce: " << workforce << endl;
    cout << "   foodstuff: " << foodstuff << endl;
    cout << "      timber: " << timber << endl;
    cout << "     mineral: " << mineral << endl;
    cout << "口======================口" << endl;
    cout << "           ↓↓↓           " << endl;

    while (year < YEAR)
    {
        timber    += logging->production(&workforce, &foodstuff);
        mineral   += mine->production(&workforce, &foodstuff);
        workforce += house->production(&workforce, &foodstuff);
        foodstuff += farm->production (&workforce, &foodstuff);

        year++;
        cout << "口======= Year " << year << " =======口" << endl;
        cout << "   workforce: " << workforce << endl;
        cout << "   foodstuff: " << foodstuff << endl;
        cout << "      timber: " << timber << endl;
        cout << "     mineral: " << mineral << endl;
        cout << "口======================口" << endl;

        if(foodstuff < 0) {
            cout << endl << "Run out of foodstuff. Your kingdom collapses X(" << endl << endl;
            break;
        }
        else if(year == YEAR) {
            cout << endl << "Found diamonds. Your kingdom is prosperous :)" << endl << endl;
            break;
        }
        else cout << "           ↓↓↓           " << endl;
    }

    delete house;
    delete farm;
    delete mine;
    delete logging;
    
    return 0;
}