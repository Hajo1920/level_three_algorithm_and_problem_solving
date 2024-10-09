#include <cctype>
#include <iostream>
using namespace std;

enum enLettersCount {smallLetter=0, capitalLetter=1, TotalLength=2};



string ReadInput(){
    string str = "";

    cout << "Enter your string: ";
    getline(cin, str);

    return str;
}

int CountTypeOfLetters(string str, enLettersCount LetterType ){
    short count = 0;

    for(int x = 0; x < str.length(); x++){

        if(LetterType == enLettersCount::TotalLength){
          
                count  = str.length();
            
        }

        if(LetterType == enLettersCount::capitalLetter && isupper(str[x])){
          
                count++;
            
        }
        if(LetterType == enLettersCount::smallLetter && islower(str[x])){
            
                count++;
        }
    }
    return count;
}


int main() {
    string str = ReadInput();

    cout << "Total String Length: " << CountTypeOfLetters(str, enLettersCount::TotalLength) << endl;
    cout << "Total Capital letters: " << CountTypeOfLetters(str, enLettersCount::capitalLetter ) << endl;
    cout << "Total Small letters: " << CountTypeOfLetters(str, enLettersCount::smallLetter) << endl;
    return 0;
}