#include <iostream>
using namespace std;

char ReadCharacter() {
    char input;
    do {
        cout << "Enter a letter character: ";
        cin >> input;
    } while (input < 'A' || (!isalpha(input))); // Better validation
    return input;
}

char InvertCharacter(char character) {
    return isupper(character) ? tolower(character) : toupper(character);
}

int main(){
    
    cout << InvertCharacter(ReadCharacter()) << endl;
    
    return 0;
}