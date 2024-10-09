// 3x3 Random Matrix
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

void Add3x3Matrix(int twoDarray[3][3], short Row, short Col){
    short ordered = 0;
    for(int col = 0; col < Col; col++){
        
        for(int row = 0; row < Row; row++){
            ordered++;
            twoDarray[col][row] = ordered;
            
        }
        
        
    }
}

void AddTransponded3x3Matrix(int twoDarray[3][3], int transposedArr[3][3] ,short Row, short Col){

    for(int col = 0; col < Col; col++){
        
        for(int row = 0; row < Row; row++){
            
            transposedArr[row][col] = twoDarray[col][row];
           
        }
         
        
        
    }
}

void PrintMatrix(int twoDarray[3][3], short col, short row){
    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++){
            cout  << setw(2) << twoDarray[x][y] << "  ";
        }
        cout << "\n";
    }
}


int main(){
    int twoDarray[3][3], transposedMatrix[3][3];
    
    srand((unsigned) time(NULL));
    Add3x3Matrix(twoDarray, 3, 3);
    cout << "Ordered 2D Matrix: " << endl;
    PrintMatrix(twoDarray, 3, 3);
    cout << endl;
    cout << "Transponded 2D Matrix: " << endl;
    AddTransponded3x3Matrix(twoDarray, transposedMatrix, 3, 3);
    PrintMatrix(transposedMatrix, 3, 3);
   
    return 0;
}