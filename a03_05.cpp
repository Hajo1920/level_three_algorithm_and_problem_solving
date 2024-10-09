// 3x3 Random Matrix
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int ReadRandom(int from, int to){
    return rand() % (to - from + 1) + from;
}

void AddRandom3x3Matrix(int twoDarray[3][3], short Col, short Row){
    
    for(int col = 0; col < Col; col++){
        
        for(int row = 0; row < Row; row++){
            
            twoDarray[col][row] = ReadRandom(1, 100);
           
        }
        
    }
}

void PrintMatrix(int twoDarray[3][3], short col, short row){
    for(int x = 0; x < col; x++){
        for(int y = 0; y < row; y++){
            cout  << setw(2) << twoDarray[x][y] << "  ";
        }
        cout << "\n";
    }
}

int ColumnSum(int twoDarray[3][3], int ColNum, int Row){
     int sum = 0;

         for(int x = 0; x <= Row-1; x++){

          sum += twoDarray[x][ColNum];

        }
       
    return sum;
}

void  AddSumOf2dArrayColumnToSingleArray(int twoDarray[3][3], int singleArray[3], short Col, short Row){

    for(int z = 0; z < Col; z++){
   
    singleArray[z] = ColumnSum(twoDarray, z, Row);
   
    }
     
}

void PrintSingleArrayColumnSum(int singleArray[3], short Cols){
    for(int x = 0; x < Cols; x++){
        cout << "Column [" << x+1 << "]: "<< singleArray[x] << endl; 
    }
}


int main(){
    int twoDarray[3][3];
    int singleArray[3];
    srand((unsigned) time(NULL));
    AddRandom3x3Matrix(twoDarray, 3, 3);
    cout << "2D Matrix: " << endl;
    PrintMatrix(twoDarray, 3, 3);
    cout << endl;
    AddSumOf2dArrayColumnToSingleArray(twoDarray, singleArray, 3,3);
    cout << "Sum of all columns in a matrix:" << endl;
    PrintSingleArrayColumnSum(singleArray, 3);
    return 0;
}