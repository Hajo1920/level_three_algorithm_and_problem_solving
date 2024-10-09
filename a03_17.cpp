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

void GetNumberToSearch(short &num){
   
    do {
    cout << "Enter number from 1-100 to count in metrix: ";
    cin >> num;
    while(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter integer only." << endl;
        cin >> num;
    }

    }while (num < 0 || num > 100);
}

string SearchNumberInMetrixResult(short number, int twoDarray[3][3], short col, short row){
    

    for(int x = 0; x < row; x++){
        for(int y = 0; y < col; y++){
            if(number == twoDarray[x][y]){
                return "Yes! Number exist in metrix";
            }
            
        }
    }

   return "No! Number does not exist in metix.";
}


int main(){
    int twoDarray[3][3];
    short number;
    srand((unsigned) time(NULL));
    AddRandom3x3Matrix(twoDarray, 3, 3);
    cout << " Matrix-1: " << endl;
    PrintMatrix(twoDarray, 3, 3);
    cout << endl;
    GetNumberToSearch(number);
    cout << SearchNumberInMetrixResult(number, twoDarray, 3, 3) << endl;
    cout << endl;

    return 0;
}