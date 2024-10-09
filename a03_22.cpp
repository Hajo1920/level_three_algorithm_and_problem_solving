#include <iostream>

using namespace std;

void FibbonaciSeries(int position, int prev1, int prev2){
    int current = 1;
    
    if(position > 0){
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
        cout << current << "  ";
        
        
        FibbonaciSeries(position-1,  prev1,  prev2);
    }
}

int main(){
    int positon = 10;
    int prev1 = 0;
    int prev2 = 1;
    cout << "Fabbionaci series of postion "<< positon << ": " << endl;
    FibbonaciSeries(positon,prev1, prev2);
    return 0;
}