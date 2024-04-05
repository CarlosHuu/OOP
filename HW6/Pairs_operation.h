#include <iostream>
using namespace std;

#ifndef _PAIRS_H_
#define _PAIRS_H_

class Pairs
{
public:
	Pairs();
	Pairs(int first,int second);
	Pairs(int first);
	friend istream& operator >>(istream& in, Pairs & second);
	friend ostream& operator <<(ostream& outs, const Pairs & second);
	Pairs operator + (const Pairs & obj);
	Pairs operator - (const Pairs & obj);
Pairs operator * (int obj);

private:
	int f;
	int s;
};
#endif
