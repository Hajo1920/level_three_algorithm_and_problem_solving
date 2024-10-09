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
            
            twoDarray[col][row] = ReadRandom(0, 1);
           
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

string CheckMetrixScalar(int twoDarray1[3][3], short col, short row){
    bool isScalar;
    int firstDiagonalDigit = twoDarray1[0][0];
    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++){
            if(x == y && twoDarray1[x][y] != firstDiagonalDigit){
                isScalar = false;
            }
            else if(x != y && twoDarray1[x][y] != 0){
                isScalar = false;
            }
            else isScalar = true;
        }
    }

    if(isScalar) return "Metrix is Scalar !";
    else return "Metrix is not Scalar!";
}


int main(){
    int twoDarray1[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    srand((unsigned) time(NULL));
    // AddRandom3x3Matrix(twoDarray1, 3, 3);
    cout << " Matrix-1: " << endl;
    PrintMatrix(twoDarray1, 3, 3);

    cout << endl;

    cout << CheckMetrixScalar(twoDarray1, 3, 3) << endl;

    return 0;
}