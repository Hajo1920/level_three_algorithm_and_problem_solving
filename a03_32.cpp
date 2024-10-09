#include <cctype>
#include <iostream>
#include <vector>
using namespace std;

char ReadCharacter(){
    char findChar;
    do
    {
        cout << "Enter a character: ";
        cin >> findChar;
    } while (findChar < char(65)|| !(isalpha(findChar)));
    return findChar;
}

bool isCharVowel(char Char){
    char small =  tolower(Char);

    return (small == 'a') || (small == 'e') || (small == 'i') || (small == 'o') || (small == 'u');
   
}

int main(){


    char checkChar = ReadCharacter();

    if(isCharVowel(checkChar)) cout << "Yes '"<<checkChar<<"' is vowel" << endl;
    else cout << "No '"<<checkChar<<"' is not a vowel" << endl;
    return 0;
}