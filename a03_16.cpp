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
            printf(" %d ",twoDarray[x][y]);
        }
        cout << "\n";
    }
}
int SearchNumberInMetrix(short number, int twoDarray[3][3], short col, short row){
    
    short numCounter = 0;

    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++){
            if(number == twoDarray[x][y]){
                numCounter++;
            }
        }
    }

    return numCounter;
}

bool CheckMetrixSparce(int twoDarray[3][3], short col, short row){
    bool isSparse;
    short matrixSize =  row * col;
   

    return SearchNumberInMetrix(0, twoDarray, col, row) >= (matrixSize/2);
}


int main(){
    int twoDarray[3][3] = {{0,0,4},{0,0,6},{0, 0, 7}};

    srand((unsigned) time(NULL));
    // AddRandom3x3Matrix(twoDarray, 3, 3);
    cout << " Matrix-1: " << endl;
    PrintMatrix(twoDarray, 3, 3);
    cout << endl;
    cout << "Checking if metrix is sparce.." << endl;
    cout << endl;
    if(CheckMetrixSparce(twoDarray, 3,3)){
        cout << "Yes! it is sparce" << endl;
    }else cout << "No! it is not a sparce";
    cout << endl;

    return 0;
}