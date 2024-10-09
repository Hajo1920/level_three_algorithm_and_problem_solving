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

string Joiner(vector<string> &vWords, string delimeter){

    string result;

    for(string &word: vWords){
        result = result + word + delimeter;
    }


    return result.substr(0, result.length()-delimeter.length());
}

void PrintVectorContent(vector<string> vWords ,string delimeter){
    cout << Joiner(vWords, delimeter) << endl;
}

int main() {
    // string str = ReadInput();
    vector<string> vWrods = {"Mohamed", "Fadi", "Ali", "Muna"};
    PrintVectorContent(vWrods, "_");
    return 0;
}