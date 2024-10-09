#include <iostream>
#include <cctype>
using namespace std;

string ReadInput(){
    string str = "";

    cout << "Enter small lettered words: ";
    getline(cin, str);

    return str;
}


string ConvertLettersToUpper(string userInput){
    bool checkFirstLetter = true;
    for(short x = 0; x < userInput.length(); x++){
        if(userInput[x] != ' ' && checkFirstLetter){
            userInput[x] = toupper(userInput[x]);
        }
        checkFirstLetter = userInput[x] == ' ' ? true:false;
    }

    return userInput;
}

int main(){
string str = ReadInput();

cout << "Change first letter of a word to uppercase: " << endl;
cout << ConvertLettersToUpper(str) << endl;

}

