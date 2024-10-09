#include <iostream>

using namespace std;


string RemoveSpecialChar(string &str){
    string nospecial = "";
    for(int x = 0; x < str.length(); x++){
        if(!ispunct(str[x])){

            nospecial += str[x];
        }
        
    }

    return nospecial;
}


int main(){
    string str = "Welcome to Programming..... ...Programming is funny.";
    cout << "No special Character: " << endl;
    string nospecial = RemoveSpecialChar(str);

    cout << nospecial << endl;

    
    return 0;
}