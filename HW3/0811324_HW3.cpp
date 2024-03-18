# include<iostream>
using namespace std;
char *deleteRepeat(char *letters, int &size);
int main(){
    int size = 0 ;
    cout << "Please enter the size of string: ";
    cin >> size;
    char *array = new char[size];
    cout << "Please enter string: ";
    for (int i = 0; i < size ; i++){
        cin >> array[i];
    }
    deleteRepeat(array, size);
    cout << "The new size of string is "<< size << endl;
    cout << "The string after deleteRepeats is ";
    for (int i=0 ; i < size ; i++){
        cout << array[i];
    }
    return 0;
}

char *deleteRepeat(char *letters, int &size){
    for (int i=0 ; i <size ;i++){
        for (int j =0 ; j <size ; j++){
            if (i==j) continue;
            if (letters[j]==letters[i]){
                for (int k = j ; k<size ; k++){
                    letters[k]=letters[k+1];
                }
                size--;
                j--;
            }

        }
    }
    return letters;
}