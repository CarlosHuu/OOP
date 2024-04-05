#include "Pairs_operation.h"

Pairs::Pairs() : f(0), s(0){}
Pairs::Pairs(int first,int second){
    f = first;
    s = second;
}
Pairs::Pairs(int first){
    f = first;
    s = 0;
}
istream& operator >>(istream& in, Pairs & second){
    char ignored;
    in >> ignored;
    in >> second.f;
    in >> ignored;
    in >> second.s;
    in >> ignored;
    return in;
}
ostream& operator <<(ostream& outs, const Pairs & second){
    outs << "(" << second.f << "," << second.s << ")";
    return outs;
}
Pairs Pairs::operator + (const Pairs & obj){
    return Pairs(f + obj.f, s + obj.s);
}
Pairs Pairs::operator - (const Pairs & obj){
    return Pairs(f - obj.f, s - obj.s);
}
Pairs Pairs::operator * (int obj){
    return Pairs(f * obj, s * obj);
}