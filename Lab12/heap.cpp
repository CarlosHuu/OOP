#include "heap.hpp"
#include <fstream>

vector<int> Circuit::readinput(string filename){
    vector<int> delay;
    ifstream fin(filename);
    string input;
    fin >> input;
    gatecount=stoi(input);
    for(int i=0;i<gatecount;++i){
        int temp;
        fin >> input;
        temp=stoi(input);
        delay.push_back(temp);
    }
    make_heap (delay.begin(),delay.end());
    return delay;
}

void Circuit::printout(){
    for(auto a:gate_list)
        cout<<a->gatetype<<a->gateID<<" ("<<a->outputnode<<","<<a->inputnodeA<<","<<a->inputnodeB<<");"<<endl;
}

bool sortbydelay(Gate* a, Gate* b) {
    return a->delay > b->delay;
}


void Circuit::buildgate(vector<int> &list) {
    for (int i = 0; i < gatecount; ++i) {
        Gate* gate = new Gate();
        
        // Calculate delay
        int del;
        if (2 * i + 2 < gatecount) {
            del = min(list[i] - list[2 * i + 1], list[i] - list[2 * i + 2]);
        } else if (2 * i + 1 < gatecount) {
            del = list[i] - list[2 * i + 1];
        } else {
            del = list[i]; // For leaf nodes
        }

        gate->delay = del;

        // Assign gate type and ID
        switch (del) {
            case 10:
                gate->gatetype = "NOR";
                gate->gateID = norcount++;
                break;
            case 15:
                gate->gatetype = "NAND";
                gate->gateID = nandcount++;
                break;
            case 20:
                gate->gatetype = "OR";
                gate->gateID = orcount++;
                break;
            case 25:
                gate->gatetype = "AND";
                gate->gateID = andcount++;
                break;
            case 30:
                gate->gatetype = "XOR";
                gate->gateID = xorcount++;
                break;
            default:
                gate->gatetype = "UNKNOWN";
                break;
        }

        // Assign output and input nodes
        gate->outputnode = (i == 0) ? "outputnode" : "n" + to_string(i);
        gate->inputnodeA = (2 * i + 1 < gatecount) ? "n" + to_string(2 * i + 1) : "inputnode";
        gate->inputnodeB = (2 * i + 2 < gatecount) ? "n" + to_string(2 * i + 2) : "inputnode";

        gate_list.push_back(gate);
    }

    // Sort gates by delay in descending order
    sort(gate_list.begin(), gate_list.end(), sortbydelay);
}