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

string CheckMetrixIdentity(int twoDarray1[3][3], short col, short row){
    bool isIdentical;

    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++){
            if(x == y && twoDarray1[x][y] != 1){
                isIdentical = false;
            }
            else if(x != y && twoDarray1[x][y] != 0){
                isIdentical = false;
            }
            else isIdentical = true;
        }
    }

    if(isIdentical) return "Metrix is identical !";
    else return "Metrix is not identical!";
}


int main(){
    int twoDarray1[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    srand((unsigned) time(NULL));
    // AddRandom3x3Matrix(twoDarray1, 3, 3);
    cout << " Matrix-1: " << endl;
    PrintMatrix(twoDarray1, 3, 3);

    cout << endl;

    cout << CheckMetrixIdentity(twoDarray1, 3, 3) << endl;

    return 0;
}