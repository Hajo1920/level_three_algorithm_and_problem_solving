#include <iostream>
#include <string>
using namespace std;



string ReadInput(){
    string str = "";

    cout << "Enter your string: ";
    getline(cin, str);

    return str;
}


string TrimLeft(string S1) { 
    for (short i = 0; i < S1.length(); i++){
         if (S1[i] != '_'){
             return S1.substr(i, S1.length() - i);      
            } 
    } return""; 
    } 
    
string TrimRight(string S1){
     for (short i = S1.length() - 1; i >= 0; i--){ 
           if (S1[i] != '_'){ 
            return S1.substr(0, i + 1);
             }
        } return""; 
        
    } 

string Trim(string S1) { 
    return (TrimLeft(TrimRight(S1)));
     } 



int main() {
    string S1 = ReadInput();   
    cout <<"\nString     = "<< S1;     
    cout <<"\n\nTrim Left  = "<< TrimLeft(S1);     
    cout <<"\nTrim Right = "<< TrimRight(S1);     
    cout <<"\nTrim       = "<< Trim(S1);     

    return 0;
}