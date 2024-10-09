#include <cctype>
#include <iostream>
using namespace std;

string ReadInput(){
    string str = "";

    cout << "Enter your string: ";
    getline(cin, str);

    return str;
}

char ReadCharacter(){
    char findChar;
    do
    {
        cout << "Enter a character to search in string: ";
        cin >> findChar;
    } while (findChar < char(65)|| !(isalpha(findChar)));
    return findChar;
}

short CharCountInString(string str, char CharInString){
    short count = 0;
    for(int x = 0; x < str.length(); x++){
        if(str[x] == CharInString){
            count++;
        }
    }
    return count;
}



int main(){
    string str = ReadInput();
    char charInString = ReadCharacter();

    cout << "Letter '" << charInString << "' count in string is: " << CharCountInString(str, charInString) << endl;
    return 0;
}