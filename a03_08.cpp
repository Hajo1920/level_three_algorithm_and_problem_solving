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

void MultipluyTwoMatrix(int multiReslut[3][3], 
                      int twoDarray1[3][3], 
                      int twoDarray2[3][3], 
                      short col, 
                      short row ){

for(int x = 0; x < row; x++){
    for(int y = 0; y < col; y++){
        multiReslut[x][y] = twoDarray1[x][y]*twoDarray2[x][y];
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


int main(){
    int twoDarray1[3][3], twoDarray2[3][3], multiTwoDarr[3][3];
    srand((unsigned) time(NULL));
    AddRandom3x3Matrix(twoDarray1, 3, 3);
    cout << " Matrix-1: " << endl;
    PrintMatrix(twoDarray1, 3, 3);

    AddRandom3x3Matrix(twoDarray2, 3, 3);
    cout << endl;
    cout << " Matrix-2: " << endl;
    PrintMatrix(twoDarray2, 3, 3);

    cout << endl;
    cout << " Result: " << endl;
    MultipluyTwoMatrix(multiTwoDarr,twoDarray1, twoDarray2, 3 ,3);

    PrintMatrix(multiTwoDarr, 3, 3);
    return 0;
}