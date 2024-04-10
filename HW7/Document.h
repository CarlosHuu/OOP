#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#ifndef _DOCUMENT_H_
#define _DOCUMENT_H_
class Document
{
public:
    Document();
    Document(Document &docu);
    Document &addString(string add);
    int getLength();
    friend ostream& operator <<(ostream &out, Document &docu);

private:
    int length;
    vector<string> vec;
};
#endif