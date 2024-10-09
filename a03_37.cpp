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

void PrintVectorContent(vector<string> vWords, string str ,string delimeter){
    vector <string> vFilledVector = Spliter(vWords, str, delimeter);

    cout << "Token: " << vFilledVector.size() << endl;
    for(string &word: vFilledVector){
        cout << word << endl;
    }
}

int main() {
    string str = ReadInput();
    vector<string> vWrods;
    PrintVectorContent(vWrods, str, " ");
    return 0;
}