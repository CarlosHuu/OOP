#include <iostream>
#include <vector>
#include "heap.hpp" 
using namespace std;

int main(int argc, char** argv){
    Circuit circuit;
    vector<int> delay;
  	delay=circuit.readinput(argv[1]);
    circuit.buildgate(delay);
    circuit.printout();
  	return 0;
}