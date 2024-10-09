#include <iostream>

using namespace std;

void FabbionaciSeries(int num){
    int previous1 = 0;
    int previous2 = 1;
    int current = 0;
   
    for(short x = 0; x <= num; x++){
         if(num <= 1){
            cout << num << endl;
            break;
         }
       
        previous1 = previous2;
        previous2 = current;
        current = previous1 + previous2;
        cout << current << " ";
        
    }
 
}

int main(){
    int positon = 10;
    cout << "Fabbionaci series of postion "<< positon << ": " << endl;
    FabbionaciSeries(positon);
    cout << endl;
    return 0;
}