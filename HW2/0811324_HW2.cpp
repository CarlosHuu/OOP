#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int lowest_total_cost(int* arr, int first, int final);

int main(){
    int size;
    string filename;
    ifstream input;

    cout << "Please enter the filename: ";
    cin >> filename;

    input.open(filename);
    if(input.fail()){
        cout<< "File \"" << filename <<"\" does not exist.";
        exit(1);
    }

    input >> size;
    int *col = new int[size];
  
    for(int i=0; i<size ;i++){
        input >> col[i];
    }
    int ans = lowest_total_cost(col,0,size-1);
    cout <<"The lowest cost is " << ans;
    return 0;
}

int lowest_total_cost(int* arr, int first, int last){
    if(last==0){
        return arr[last];
    }
    if((first+1==last)||(first+2==last)){
        return(arr[first]+arr[last]);
    }
    else{
        if(lowest_total_cost(arr,first+1,last) > lowest_total_cost(arr,first+2,last)){
            return (arr[first]+lowest_total_cost(arr,first+2,last));
        }
        else{
            return (arr[first]+lowest_total_cost(arr,first+1,last));
        }
    }




}