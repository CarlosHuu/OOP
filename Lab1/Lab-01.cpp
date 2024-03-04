#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int i=1;
    int j;
    while(1){
        if(num%i==0){
            j=num/i;
            if(i>j)
                break;
            cout<<i<<" "<<j<<endl;
            
        }
        
        i++;
    }

    return 0;

}