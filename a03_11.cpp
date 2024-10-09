// 3x3 Random Matrix
#include <cstdlib>
#include <iostream>
using namespace std;

int ReadRandom(int from, int to){
    return rand() % (to - from + 1) + from;
}

void AddRandom3x3Matrix(int twoDarray[3][3], short Row, short Col){
    
    for(int col = 0; col < Col; col++){
        
        for(int row = 0; row < Row; row++){
            
            twoDarray[col][row] = ReadRandom(1, 10);
           
        }
        
    }
}

void PrintMatrix(int twoDarray[3][3], short col, short row){
    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++){
            printf(" %0*d ",2,twoDarray[x][y]);
        }
        cout << "\n";
    }
}

int SumOfAllMatrixElement(int twoDarray[3][3], int col, int row){
    int sum = 0;

    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++){
            sum += twoDarray[x][y]; 
        }
    }
    return sum;
}

string CheckTwoMetricesSimilarity(int twoDarray1[3][3], int twoDarray2[3][3], short col, short row){
    bool isSimilar;

    isSimilar = SumOfAllMatrixElement(twoDarray1, col, row) == SumOfAllMatrixElement(twoDarray2, col, row);
   
    if(isSimilar) return "Metrices sum are equal !";
    else return "Metrices sum are not equal!";
}


int main(){
    int twoDarray1[3][3], twoDarray2[3][3];
    srand((unsigned) time(NULL));
    AddRandom3x3Matrix(twoDarray1, 3, 3);
    cout << " Matrix-1: " << endl;
    PrintMatrix(twoDarray1, 3, 3);

    AddRandom3x3Matrix(twoDarray2, 3, 3);
    cout << endl;
    cout << " Matrix-2: " << endl;
    PrintMatrix(twoDarray2, 3, 3);
    cout << endl;

    cout << CheckTwoMetricesSimilarity(twoDarray1, twoDarray2, 3, 3) << endl;

    return 0;
}