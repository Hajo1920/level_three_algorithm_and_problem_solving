#include <iostream>

using namespace std;

string ReadInput(){
    string str = "";

    cout << "Enter your string: ";
    getline(cin, str);

    return str;
}


char InvertCharacter(char character) {
    return isupper(character) ? tolower(character) : toupper(character);
}

string InvertLettersViseVersa(string str){
    for(int x = 0; x < str.length(); x++){
       
        str[x] = InvertCharacter(str[x]);
    }

    return str;
}

int main(){
    string str = ReadInput();
    cout << "Convert letter viseversa: " << endl;
    cout << InvertLettersViseVersa(str) << endl;
   
    return 0;
}