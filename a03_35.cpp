#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadInput(){
    string str = "";

    cout << "Enter your string: ";
    getline(cin, str);

    return str;
}


void PrintEachWordInString(string S1) { 
    string delimeter = " ";
    short position = 0;
    string word;
    cout << "Your string word are \n\n";

    while((position = S1.find(delimeter)) != std::string::npos) {
        word = S1.substr(0, position);
        if(!word.empty()){
            cout << word << endl;
        }
        S1.erase(0, position + delimeter.length());
    }  
    if(!S1.empty() ){
        cout << S1 << endl;
    }
   }



int main() {
    string str  = ReadInput();
    PrintEachWordInString(str);
    return 0;
}