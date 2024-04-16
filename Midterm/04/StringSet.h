#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StringSet{
private:
    vector<string> strings;
public:
    StringSet() {};
    StringSet operator|(const StringSet& other);
    StringSet operator&(const StringSet& other);
    friend void operator+=(StringSet &set, const string &str);
    bool operator*(string &str);
    friend ostream &operator<<(ostream &out, const StringSet &set);
};
