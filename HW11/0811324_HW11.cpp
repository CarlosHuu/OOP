#include <iostream>
#include <fstream>
using namespace std;

////////////////////////////////////////////////////
////// Finish deleteRepeats template function///////
//////        Write your code below          ///////

////////////////////////////////////////////////////
////////////////////////////////////////////////////
template <class T>
void deleteRepeats(T *letters, int &size){
    for (int i=0 ; i <size ;i++){
        for (int j = i + 1 /*0*/ ; j <size ; j++){
            // if (i==j) continue;
            if (letters[j]==letters[i]){
                for (int k = j ; k<size ; k++){
                    letters[k]=letters[k+1];
                }
                size--;
                j--;
            }

        }
    }
}

int main(int argc, char **argv){
  ifstream input;
  input.open(argv[1]);
  
  if(!input){
		cerr << "Fail to open input";
		exit(1);		
	}

  char str[100];
  int arr[100];
  int num_ch, num_int;

  input >> num_ch;
  for(int i=0; i<num_ch; i++){
    input >> str[i];
  }
  input >> num_int;
  for(int i=0; i<num_int; i++){
    input >> arr[i];
  }

  //template function
  deleteRepeats(str, num_ch);
  deleteRepeats(arr, num_int); 

  //cout
  for(int i=0; i<num_ch; i++){
    cout<<str[i]<<" ";
  }
  cout<<num_ch;
  cout<<endl;
  
  for(int i=0; i<num_int; i++){
    cout<<arr[i]<<" ";
  }
  cout<<num_int;
  cout<<endl;
	
  return 0;
}




