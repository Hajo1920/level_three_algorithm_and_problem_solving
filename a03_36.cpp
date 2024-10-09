#include <cctype>
#include <iostream>


using namespace std;


string ReadInput(){
    string str = "";

    cout << "Enter your string: ";
    getline(cin, str);

    return str;
}

short CountWordsInString(string str){
    short numOfWords = 0;
    string delim = " "; // delimiter 
    cout <<"\nYour string wrords are: \n\n"; 
    short pos = 0; 
    string sWord; // define a string variable // use find() function to get the position of the delimiters 
    
    while ((pos = str.find(delim)) != std::string::npos) { 
        sWord =str.substr(0, pos); // store the word 
        if (sWord !="") { 
            numOfWords++;
            } 
        str.erase(0, pos + delim.length()); 
        /* erase() until positon and move to next word. */ 
    } if (str!="") { numOfWords++;
    }
    return numOfWords;
}

int main() {
    string str = ReadInput();
    cout << CountWordsInString(str);
    return 0;
}