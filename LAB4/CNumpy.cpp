#include "CNumpy.h"

using namespace std;

CNumpy::CNumpy(const char *input_filename){
    
    ifstream inp;
    inp.open(input_filename);
    inp >> row >> col;

    matrix = new int*[row];
    for (int k =0; k < row ; k++){
        matrix[k] = new int[col];
    }
    for(int i=0; i <row; i++){
        for(int j=0; j<col; j++){
            inp >> matrix[i][j];
        }
    }
    inp.close();
}
CNumpy::~CNumpy(){
    for(int i=0; i< row ; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
}
int **CNumpy::getMatrix() const{
    return matrix;
}
int CNumpy::getRow()const{
    return row;
}
int CNumpy::getCol()const{
    return col;
}


int CNumpy::min()const{
    int min = matrix[0][0];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[i][j] < min){
                min = matrix[i][j];
            }
        }
    }
    return min;
}
int CNumpy::max()const{
    int max = matrix[0][0];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[i][j] > max){
                max = matrix[i][j];
            }
        }
    }
    return max;
}
void CNumpy::argmin(int *idx1, int *idx2){
    int min_ = min();
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[i][j] == min_){
                
                *idx1 = i;
                *idx2 = j;
            }
        }
    }
}
void CNumpy::argmax(int *idx1, int *idx2){
    int max_ = max();
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[i][j] ==max_){

                *idx1 = i;
                *idx2 = j;
            }
        }
    }
}

void CNumpy::concatenate(const CNumpy &othermatrix, int axis){
    if(axis == 0){
        int newrow = row + othermatrix.row;
        int **newmatrix = new int*[newrow];
        for(int i=0; i<newrow ; i++){
            newmatrix[i] = new int[col];
        }
        for(int i=0 ; i <row ; i++){
            for(int j=0; j<col;j++){
                newmatrix[i][j] = matrix[i][j];
            }
        }
        for (int i=0 ;i < othermatrix.row ; i++){
            
            for(int j=0; j<othermatrix.col ; j++){
                newmatrix[row+i][j] = othermatrix.matrix[i][j];
            }
        }
        for(int i=0; i< row ; i++){
            delete [] matrix[i];
        }
        delete [] matrix;
        row = newrow;
        
        matrix=new int *[row];
        for(int i=0;i<row;i++){
            matrix[i]=new int [col];
            }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                matrix[i][j]=newmatrix[i][j];
            }
        }
        for(int i=0; i< row ; i++){
            delete [] newmatrix[i];
        }
        delete [] newmatrix;
        
    }
    else if(axis == 1){
        int newcol = col + othermatrix.col;
        int **newmatrix = new int*[row];
        for(int i = 0 ; i< row ; i++){
            newmatrix[i] = new int [newcol];
        }
        for(int i = 0 ; i< row ; i++){
            for (int j = 0 ; j <col ; j++){
                newmatrix[i][j] = matrix[i][j];
            }
        }
        for(int i = 0; i <othermatrix.row ; i++){
            
            for(int j =0 ; j <othermatrix.col ;j++){
                newmatrix[i][j+col] = othermatrix.matrix[i][j];
            }
        }
        for(int i=0; i< row ; i++){
            delete [] matrix[i];
        }
        delete [] matrix;
        col = newcol;
        
        matrix=new int *[row];
        for(int i=0;i<row;i++){
            matrix[i]=new int [col];
            }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                matrix[i][j]=newmatrix[i][j];
            }
        }
        
        for(int i=0; i< row ; i++){
            delete [] newmatrix[i];
        }
        delete [] newmatrix;
    }
}

void CNumpy::render(){
    for(int i =0 ; i < row ; ++i){
        for (int j =0; j<col ; ++j){
            if(matrix[i][j] > 127){
                cout<<"@@";
            }
            else cout << "__";
        }
        cout << endl;
    }
}