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
            printf(" %0*d ",2,twoDarray[x][y]);
        }
        cout << "\n";
    }
}


void PrintSumOfAllMatrixElements(int totalSum){
    cout << "Total sum of all matrix element: " << totalSum << endl;
}


short ShowMinumumNumberInMetrix(int twoDarray[3][3], short col, short row){
    short minimumNumber = twoDarray[0][0];

     for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++){
           if(twoDarray[x][y] < minimumNumber){
            minimumNumber = twoDarray[x][y];
           }
        }
        
    }
    return minimumNumber;
}

short ShowMaximumNumberInMetrix(int twoDarray[3][3], short col, short row){
     short maximumNumber = twoDarray[0][0];


     for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++){
            if(twoDarray[x][y] > maximumNumber){
                 maximumNumber = twoDarray[x][y];
           }
           
        }
      
    }
   return maximumNumber;
}
int main(){
    int twoDarray[3][3];
    srand((unsigned) time(NULL));
    AddRandom3x3Matrix(twoDarray, 3, 3);
    cout << " Matrix-1: " << endl;
    PrintMatrix(twoDarray, 3, 3);
    cout << endl;
    cout << "Minimum number in metrix: " << ShowMinumumNumberInMetrix(twoDarray, 3,3);
    cout << endl;
    cout << "Maximum number in metrix: " << ShowMaximumNumberInMetrix(twoDarray,3,3);
    cout << endl;

    return 0;
}