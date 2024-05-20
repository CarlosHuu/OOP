#include <iostream>
#include <fstream>
#include <string>
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

void Read_Netlist(string dir, map<string, int> &libsize, vector<NODE*> &allnode) {
    ifstream in(dir);
    if (!in) {
        cerr << "Error opening file: " << dir << endl;
        return;
    }

    int ln, l, lh;
    in >> ln;
    for (int i = 0; i < ln; i++) {
        string name;
        int a;
        in >> name >> a;
        libsize[name] = a;
    }

    in >> l;
    map<string, NODE*> node_map;
    for (int i = 0; i < l; i++) {
        NODE* node = new NODE();
        in >> node->name;
        node->type = node->name;
        node->f1 = nullptr;
        node->f2 = nullptr;
        allnode.push_back(node);
        node_map[node->name] = node;
    }

    in >> lh;
    for (int i = 0; i < lh; i++) {
        string n1, n2, n3, n4;
        in >> n1 >> n2 >> n3 >> n4;
        if (node_map.find(n2) != node_map.end()) {
            NODE* node = node_map[n2];
            node->type = n1;
            if (node_map.find(n3) != node_map.end()) {
                node->f1 = node_map[n3];
            }
            if (node_map.find(n4) != node_map.end()) {
                node->f2 = node_map[n4];
            }
        }
    }
}

void TotalFaninSize(map<string, int> &libsize, vector<NODE*> &allnode) {
    for (NODE* node : allnode) {
        if (node->type == "and" || node->type == "or" || node->type == "nand" || node->type == "xor" ) {
            cout << node->name << ":";
            int fanin_size = 0;
            if (node->f1 && libsize.find(node->f1->type) != libsize.end()) {
                fanin_size += libsize[node->f1->type];
            }
            if (node->f2 && libsize.find(node->f2->type) != libsize.end()) {
                fanin_size += libsize[node->f2->type];
            }
            cout << fanin_size << endl;
        }
    }
}

int main(int argc, char *argv[]) {
    // if (argc < 2) {
    //     cerr << "Usage: " << argv[0] << " <input_file>" << endl;
    //     return 1;
    // }
    string dir = argv[1];
    map<string, int> libsize;
    vector<NODE*> allnode;
    Read_Netlist(dir, libsize, allnode);

    sort(allnode.begin(), allnode.end(), nodecmp);

    for (NODE* node : allnode) {
        cout << node->name << " ";
    }
    cout << endl;

    TotalFaninSize(libsize, allnode);

    // Free allocated memory
    // for (NODE* node : allnode) {
    //     delete node;
    // }

    return 0;
}