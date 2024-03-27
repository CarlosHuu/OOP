# include <iostream>
# include <cmath>
using namespace std;

class AccountNumber{
    private:
    int *account;
    int size;
    int SUM;
    
    public:
    AccountNumber(int *array, int len);
    ~AccountNumber();
    bool checking();
    int *make_valid();

};

AccountNumber::AccountNumber(int *array, int len){
    account = new int[len];
    for (int i=0 ; i< len ; i++){
        account[i] = array[i];
    }
    size = len;
}
AccountNumber::~AccountNumber(){
    delete [] account;
}
bool AccountNumber::checking(){
    int *temp = new int [size];

    if(size %2!=0){
        for (int i=0; i < size ; i++){
            if((i+1)%2 ==0){
                temp[i] = 2*account[i];
            }
            else{
                temp[i] = account[i];
            }
        }
    }
    else{
        for (int i=0; i < size ; i++){
            if(i%2 ==0){
                temp[i] = 2*account[i];
            }
            else{
                temp[i] = account[i];
            }
        }
    }

    for (int i=0 ; i <size; i++ ){
        if(temp[i]>9) temp[i]-=9;
    }

    int sum =0;
    for(int i=0; i <size; i++){
        sum += temp[i];
    }
    SUM = sum;
    delete [] temp;
    if(sum%10==0) return true;
    else return false;
   
    
}
int *AccountNumber::make_valid(){
    if(!checking()){
        int remainder = 0 ;
        remainder = SUM%10;
        
        int *valid = new int [size];
       
        for(int i =0 ; i < size-1 ; i++){
            valid[i] = account[i];
        }
        if(account[size-1] >= remainder){
            valid[size-1] = account[size-1]-remainder;
        }
        else{
            valid[size-1] = account[size-1] +(10-remainder);
        }
        
        return valid;
        delete [] valid;
        
    }
    return account;
}


int main(){

    int len;
    cout << "Please enter the account's length:";
    cin >> len;
    cout << "Please enter your account number:";
    int number;
    cin >> number;
    int divisor = pow(10, len - 1);
    int *arr = new int [len];
    int i =0;
    while (divisor > 0) {
        int digit = number / divisor;
        arr[i] = digit;
        number %= divisor;
        divisor /= 10;
        i++;
    } 
    AccountNumber A (arr, len);
   
    bool check = A.checking();
    
    if(check) cout << "Account number is valid.";
    else cout << "Account number is not valid.";
    cout << endl;
    int *correct = A.make_valid();
    if(!check) cout << "Correct Account Number:";
    else cout <<"Account Number:";
    for(int i=0 ; i< len ; i++){
        cout<< correct[i];
    }
    delete [] arr;

    return 0 ;
}