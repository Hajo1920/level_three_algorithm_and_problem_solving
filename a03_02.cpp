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

int RowSum(int twoDarray[3][3], int rowNumber, int Cols ){
    int sum = 0;
    for(int x = 0; x <= Cols-1; x++){
        sum += twoDarray[rowNumber][x];
    }
    return sum;
}

void PrintSumOfRowsInMatrix(int twoDarray[3][3], short Cols, short Rows){
   
    for(int x = 0; x < Rows; x++){
        
        cout << "Row " << x+1 << " Sum: " << RowSum(twoDarray, x, Cols) << endl;
    
        
    }
}


int main(){
    int twoDarray[3][3];
    srand((unsigned) time(NULL));
    AddRandom3x3Matrix(twoDarray, 3, 3);
    cout << "2D Matrix: " << endl;
    PrintMatrix(twoDarray, 3, 3);
    cout << endl;
    cout << "Sum of all rows in a matrix:" << endl;
    PrintSumOfRowsInMatrix(twoDarray, 3,3);
    return 0;
}