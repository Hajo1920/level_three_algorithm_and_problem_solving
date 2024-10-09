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

char InvertCharacter(char character) {
    return isupper(character) ? tolower(character) : toupper(character);
}


short CharCountInString(string str, char CharInString, bool caseSensetive=true){
     short count = 0;
     
    for(int x = 0; x < str.length(); x++){
        if(caseSensetive){
            if(str[x] ==  CharInString){
                count++;
            }
        } else {if(tolower(str[x]) == tolower(CharInString)){
                count++;
            }
        }
    }
    return count;
}


int main(){
    string str = ReadInput();
    char charInString = ReadCharacter();
   
    
    cout << "Letter '" << charInString << "' count in string is: " << CharCountInString(str, charInString) << endl;
    cout << "Letter '" << charInString << "' or '" << InvertCharacter(charInString) << "' count in string is: "  << CharCountInString(str, charInString,false) << endl;
    return 0;
}