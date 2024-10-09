#include <iostream>

using namespace std;


string ReplaceWord(string str, string replaceWord, string replacingWord){
    short pos;

    pos = str.find(replacingWord);

    while(pos != std::string::npos){
        str = str.replace(pos,replacingWord.length(), replaceWord);
        pos = str.find(replacingWord);
    }
    return str;
}

int main(){
    string str = "Welcome to Qatar , Qatar is a beautiful country.";

    cout << ReplaceWord(str, "Eritrea", "Qatar") << endl;
    return 0;
}