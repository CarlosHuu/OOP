#include <iostream>
using namespace std;
int main()
{
    int num;
    
    while(1){
        int i=2;
        cin >> num;
        if (num==0){
            cout << "it can't be zero";
            return 0;
        }
        if (num==1){
            cout << num ;
        }
        int a=0;
        while(num>1){
            while(num%i==0){
                num/=i;
                // if(num==1)
                //     cout << i ;
                // else
                //     cout<< i<<"*";
                a++;
            }
            if(a>0 && num!=1)
                cout << i <<"^"<<a <<"*";
            else if(a>0)
                cout << i << "^"<<a;
            
            i++;
            a=0;
            
        }
        cout << endl;
        
    }
    return 0;

}