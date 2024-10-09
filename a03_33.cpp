#include <cctype>
#include <iostream>

using namespace std;


string ReadInput(){
    string str = "";

    cout << "Enter your string: ";
    getline(cin, str);

    return str;
}

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

short VowelCount(string str){
    short count = 0;
    string vowels = "aeiou";
    for(char c: str){
      
        if(isCharVowel(c)) {
            count++;
        }
    }

  return count; 
}

int main(){
    string str = ReadInput();

    cout << "Total Vowel alphabets in string: " << VowelCount(str) << endl;
    return 0;
}