#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream infile;
    infile.open(argv[1],ios::in);
    set<string>list;
    string line;
    while(getline(infile,line)){
        list.insert(line);
    }
    for(auto it=list.begin();it!=list.end();it++){
        cout<<*it<<endl;
    }
    infile.close();

    return 0;
}