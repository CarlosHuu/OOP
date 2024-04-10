#include "Document.h"

Document::Document() : vec(0){}
    
Document::Document(Document &docu){
    vec = docu.vec;
}
    
Document&Document::addString(string add){
    vec.push_back(add);
    return *this;
}
int Document:: getLength(){
    int total_length = 0;
    for(int i = 0; i < vec.size(); ++i){
        total_length += vec[i].length();
    }
    return total_length;
}
ostream& operator <<(ostream &out, Document &docu){
    for(int i = 0; i < docu.vec.size(); i++){
        out << docu.vec[i]<<" ";
    }
    return out;
}