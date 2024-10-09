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

void PrintMiddleRow(int twoDarray[3][3], short Col, short Row){
    int middlerow = Row/2;
    for(int x = 0; x < Col; x++){

        printf(" %0*d ",2 ,twoDarray[x][middlerow]);
    }
    
}

void PrintMiddleCol(int twoDarray[3][3], short Col, short Row){
    short middlecol = Col/2;
    for(int x = 0; x < Row; x++){
       
        printf(" %0*d ",2 ,twoDarray[middlecol][x]);
    }
}


int main(){
    int twoDarray[3][3];
    srand((unsigned) time(NULL));
    AddRandom3x3Matrix(twoDarray, 3, 3);
    cout << " Matrix-1: " << endl;
    PrintMatrix(twoDarray, 3, 3);
    cout << endl;
    
    cout << "Middle Row of Matrix-1: " << endl;
    PrintMiddleRow(twoDarray, 3, 3);
    cout << endl;
    cout << endl;
    cout << "Middle Column of Matrix-1: " << endl;
    PrintMiddleCol(twoDarray, 3, 3);
    cout << endl;

    return 0;
}