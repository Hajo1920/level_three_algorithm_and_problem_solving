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

bool isCharVowel(char Char){
    char small =  tolower(Char);

    return (small == 'a') || (small == 'e') || (small == 'i') || (small == 'o') || (small == 'u');
   
}


void RetriveAndPrintVowels(string str){
    
    short count = 0;
 

    for(int x = 0; x < str.length(); x++){
        if(isCharVowel(str[x])){
            cout << str[x] << "  ";
        }
        }
    }


int main(){
    string str = ReadInput();
  
    cout << "Total Vowel alphabets in string: " << endl;
     RetriveAndPrintVowels(str);
    return 0;
}