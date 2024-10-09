// 3x3 Random Matrix
#include <cstdlib>
#include <ios>
#include <iostream>
#include <limits>
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

void GetCountNumber(short &num){
   
    do {
    cout << "Enter number from 1-10 to count in metrix: ";
    cin >> num;
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter integer only." << endl;
        cin >> num;
    }

    }while (num < 0 || num > 10);
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


int main(){
    int twoDarray[3][3];
    short number;
    srand((unsigned) time(NULL));
    AddRandom3x3Matrix(twoDarray, 3, 3);
    cout << " Matrix-1: " << endl;
    PrintMatrix(twoDarray, 3, 3);
    cout << endl;
    GetCountNumber(number);
    cout << "Number " << number << " count in metrix is " << SearchNumberInMetrix(number, twoDarray, 3, 3);
    cout << endl;

    return 0;
}