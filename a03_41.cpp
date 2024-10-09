#include <cctype>
#include <iostream>
#include <vector>


using namespace std;

string ReadInput(){
    string str = "";

    cout << "Enter your string: ";
    getline(cin, str);

    return str;
}

vector<string> Spliter(vector<string> &vWords, string str ,string delimeter){
    string word;
    short pos = 0;

    while((pos = str.find(delimeter)) != std::string::npos){
        word = str.substr(0, pos);

        if(!word.empty()){
            vWords.push_back(word);
        }

        str.erase(0, pos + delimeter.length());
    }
    if(!str.empty()){
        vWords.push_back(str);
    }

    return vWords;
}

string ReverseWord(string str, string delimeter){
    vector<string> strSplit;
    string reverse = "";

    strSplit = Spliter(strSplit, str, delimeter);

    vector<string>::iterator iter = strSplit.end();

    while(iter != strSplit.begin()){
        iter--;
        reverse += *iter + " ";
    }

    reverse = reverse.substr(0, reverse.length() - 1);

    return reverse;
}




int main() {
    string str = ReadInput();
    cout << "Normal: " << str << endl;
    cout << "Reversed: " << ReverseWord(str, " ") << endl;
    return 0;
}