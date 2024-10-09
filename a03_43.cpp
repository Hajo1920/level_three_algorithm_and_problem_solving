#include <iostream>
#include <vector>
using namespace std;


vector<string> SplitAndStoreWords(string str, string delimeter){
    short position = 0;
    string word = "";
    vector <string> words;

    while((position = str.find(delimeter)) != std::string::npos){
        word = str.substr(0, position);

        if(!word.empty()){
            words.push_back(word);
        }

        str.erase(0, position+delimeter.length());
    }
    if(!str.empty()){
        words.push_back(str);
    }

    return words;
}
string Joiner(vector<string> &vWords, string delimeter){

    string result;

    for(string &word: vWords){
        result = result + word + delimeter;
    }


    return result.substr(0, result.length()-delimeter.length());
}

string ToLower(string userInput){
    bool checkFirstLetter = true;
    for(short x = 0; x < userInput.length(); x++){
        if(userInput[x] != ' ' && checkFirstLetter){
            userInput[x] = tolower(userInput[x]);
        }
        checkFirstLetter = userInput[x] == ' ' ? true:false;
    }

    return userInput;
}

string ReplaceWord(string str, string replaceWord, string replacingWord, bool matchCase = true){
    vector<string> wordStore;
    string finalResult = "";
    wordStore = SplitAndStoreWords(str, " ");

    for(string &word: wordStore){

        if(matchCase){
        if(word == replacingWord){
            word = replaceWord;
        }}else{
            if(ToLower(word) == ToLower(replacingWord)){
            word = replaceWord;
        }
        }

        
    }

    return Joiner(wordStore, " ");
}



int main(){
    string str = "Welcome to Qatar , Qatar is a beautiful country.";
    cout << "Orignal Text: " << str << endl;
    cout << "Replace word with match case: " << ReplaceWord(str, "Eritrea", "qatar") << endl;
    cout << "Replace word without match case: " << ReplaceWord(str, "Eritrea", "qatar",false) << endl;
    return 0;
}