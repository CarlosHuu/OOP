#include <iostream>
#include "StringSet.h"

using namespace std;

int main(int agrc, char **argv){
    string temp, s3;
    StringSet set1, set2, set3;

    // test operator+=
    while(cin >> temp && temp != ";")
        set1 += temp;
    while(cin >> temp && temp != ";")
        set2 += temp;
    cin >> s3;
    cout << endl;

    // test operator<<
    cout << "Set 1: " << set1 << endl;
    cout << "Set 2: " << set2 << endl;
    cout << "s3: " << s3 << endl << endl;

    // test operator|
    StringSet unionSet = set1 | set2;
    cout << "Union of Set 1 and Set 2:" << endl << unionSet << endl << endl;

    // test operator&
    StringSet intersectionSet = set1 & set2;
    cout << "Intersection of Set 1 and Set 2:" << endl << intersectionSet << endl << endl;

    // test operator*
    bool anagram = set1 * s3;
    if(anagram)
        cout << "Set 1 and s3 are anagrams." << endl;
    else
        cout << "Set 1 and s3 are not anagrams." << endl;

    return 0;
}
