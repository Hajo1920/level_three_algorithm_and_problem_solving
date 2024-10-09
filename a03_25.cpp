#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

string ReadInput(){
    string str = "";

    cout << "Enter uppercase lettered words: ";
    getline(cin, str);

    return str;
}

string ConvertLettersToUpper(string userInput){
    bool checkFirstLetter = true;
    for(short x = 0; x < userInput.length(); x++){
        if(userInput[x] != ' ' && checkFirstLetter){
            userInput[x] = tolower(userInput[x]);
        }
        checkFirstLetter = userInput[x] == ' ' ? true:false;
    }

    return userInput;
}

int main(){
string str = ReadInput();
vector <char> stringStore;

cout << "lower every uppercase of a letter after space: " << endl;
cout << ConvertLettersToUpper(str) <<endl;

}

