#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
struct Gate{
    int gateID;
    int delay;
    string gatetype;
    string outputnode;
    string inputnodeA;
    string inputnodeB;
};

class Circuit{
    private:
        int gatecount;
        int xorcount=1;
        int andcount=1;
        int nandcount=1;
        int orcount=1;
        int norcount=1;
        vector<Gate*> gate_list;
    public:
        vector<int> readinput(string filename);
        void buildgate(vector<int> &list);
        void printout();
};