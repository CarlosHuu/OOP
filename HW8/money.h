#include <bits/stdc++.h>

using namespace std;
#ifndef MONEY_H
#define MONEY_H
class Money{
    public:
        Money(int dollars, int cents){
                allCents = dollars * 100 + cents;
        };

        // ----------------------------
        friend bool operator <(const Money& amount1, const Money& amount2);
        friend bool operator <=(const Money& amount1, const Money& amount2);
        friend bool operator >(const Money& amount1, const Money& amount2);
        friend bool operator >=(const Money& amount1, const Money& amount2);
        Money percent(int percent_figure)const;

        // ----------------------------

        float getMoney(){
            return float(allCents)/100;
        };

    private:
        long allCents;
};
#endif