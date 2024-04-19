# include "money.h"

bool operator <(const Money& amount1, const Money& amount2){
    return (amount1.allCents < amount2.allCents);
}

bool operator >(const Money& amount1, const Money& amount2){
  return (amount1.allCents>amount2.allCents);
}

bool operator >=(const Money& amount1, const Money& amount2){
  return (amount1.allCents>amount2.allCents||amount1.allCents==amount2.allCents);
}

bool operator <=(const Money& amount1, const Money& amount2){
    return (amount1.allCents<amount2.allCents||amount1.allCents==amount2.allCents);
}

Money Money::percent(int percent_figure)const{
   
  long desired_ratio =(allCents*percent_figure/100);
  Money temp(desired_ratio/100, desired_ratio%100);

  return temp;
};