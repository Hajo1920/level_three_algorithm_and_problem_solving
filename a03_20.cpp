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
            
            twoDarray[col][row] = ReadRandom(1, 100);
           
        }
        
    }
}

void PrintMatrix(int twoDarray[3][3], short col, short row){
    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++){
            printf(" %d ",twoDarray[x][y]);
        }
        cout << "\n";
    }
}

bool IsMatrixPalindrom(int twoDarray[3][3], short col, short row){
    bool isPalindrom;
     for(int x = 0; x < row; x++){
        for(int y = 0; y < col/2; y++){
            if(twoDarray[x][y] == twoDarray[x][col-1-y]){
                isPalindrom =  true;
            }else isPalindrom = false;
        }
       
    }
    return isPalindrom;
}


int main(){
    int twoDarray[3][3] = {{1,2,1},{5,5,5},{7,3,7}};
    // srand((unsigned) time(NULL));
    // AddRandom3x3Matrix(twoDarray, 3, 3);
    cout << " Matrix-1: " << endl;
    PrintMatrix(twoDarray, 3, 3);
    cout << endl;
    if(IsMatrixPalindrom(twoDarray, 3,3)){
        cout << "Yes! this matrix is palindrom" << endl;
    }else cout << "No! this matrix is not palindrom" << endl;
    cout << endl;

    return 0;
}