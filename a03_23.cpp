#include <iostream>
#include <string>
using namespace std;

string ReadInput(){
    string str = "";
    cout << "Enter your text to print first letter of the word: ";
    getline(cin, str);

    return str;
}

int main(){
    string str = ReadInput();
    bool isfirstLetter = true;
    for(int x = 0; x <= str.length(); x++){
        if(str[x] != str.find(' ') && isfirstLetter){
            cout << str[x] << endl;
        }

        isfirstLetter = str[x] == ' ' ? true : false;
        
    }
    return 0;
}