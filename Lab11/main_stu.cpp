#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct NODE{
	string type;
	string name;
	NODE *f1, *f2;
};

struct NODECMP {
  bool operator() (NODE *i, NODE *j) { return (i->name < j->name);}
} nodecmp;

void Read_Netlist(string dir, map<string, int> &libsize, vector<NODE*> &allnode){
	// TODO
}

void TotalFaninSize(map<string, int> &libsize, vector<NODE*> &allnode){
	// TODO
}

int main(int argc, char *argv[]){
	// Don't modify
	string dir = argv[1];
	
	map<string, int> libsize;
	vector<NODE*> allnode;
	Read_Netlist(dir, libsize, allnode);	
	
	sort(allnode.begin(), allnode.end(), nodecmp);
	
	for(int i = 0; i < allnode.size(); i++)
		cout << allnode[i]->name << " ";
	cout << endl;
	
	TotalFaninSize(libsize, allnode);
	
	return 0;
}
