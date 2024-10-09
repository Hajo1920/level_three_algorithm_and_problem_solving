#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

string ReadInput(){
    string str = "";

    cout << "Enter small lettered words: ";
    getline(cin, str);

    return str;
}

string ConvertLettersToUpper(string userInput){
    for(short x = 0; x < userInput.length(); x++){
    
            userInput[x] = toupper(userInput[x]);
        
        
    }

    return userInput;
}

string ConvertLettersToLower(string userInput){
    for(short x = 0; x < userInput.length(); x++){
        
            userInput[x] = tolower(userInput[x]);
        
        
    }

    return userInput;
}

int main(){
string str = ReadInput();
vector <char> stringStore;
cout << "String after uppercase:" << endl;
cout << ConvertLettersToUpper(str) << endl;
cout << endl;
cout << "String after lowercase:"<< endl;
cout << ConvertLettersToLower(str) << endl;

}

