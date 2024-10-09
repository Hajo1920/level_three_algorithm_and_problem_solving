#include <cctype>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

string Joiner(vector<string> &vWords, string delimeter){

    string result;

    for(string &word: vWords){
        result = result + word + delimeter;
    }


    return result.substr(0, result.length()-delimeter.length());
}

string Joiner(string arr[], short arrLength, string delimeter){

    string result;

    for(int x = 0; x < arrLength; x++){
        result = result + arr[x] + delimeter;
    }


    return result.substr(0, result.length()-delimeter.length());
}



int main() {
    // string str = ReadInput();
    vector<string> vWrods = {"Mohamed", "Fadi", "Ali", "Muna"};
    string arr[4] = {"Mohamed", "Fadi", "Ali", "Muna"};
    short length = size(arr);
    cout << "Join From Vector" << endl;
    cout << Joiner(vWrods, "-") << endl;
    cout << "Join From Array" << endl;
    cout << Joiner(arr, length, "_") << endl;
    return 0;
}