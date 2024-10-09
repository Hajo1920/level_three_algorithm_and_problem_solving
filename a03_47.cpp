#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
 fstream myFile;

struct sClientInfo {
    string accountNumber;
    string pinCode;
    string clientName;
    string clientPhone;
    double clientBalance;
};


sClientInfo AccountInformation(){

    sClientInfo ClientInfo;

    cout << "Enter account number: ";
    getline(cin >> ws, ClientInfo.accountNumber);

    cout << "Enter PIN code: ";
    getline(cin,ClientInfo.pinCode);

    cout << "Enter your Name: ";
    getline(cin, ClientInfo.clientName);

    cout << "Enter your phone number: ";
    getline(cin, ClientInfo.clientPhone);

    cout << "Enter your account balance: ";
    cin >> ClientInfo.clientBalance;

    return ClientInfo;
}

string Joiner(sClientInfo ClientInfo, string delimeter){

    string result = "";
    result+=ClientInfo.accountNumber+delimeter;
    result+=ClientInfo.pinCode+delimeter;
    result+=ClientInfo.clientName+delimeter;
    result+=ClientInfo.clientPhone+delimeter;
    result+=to_string(ClientInfo.clientBalance);

    return result;
}

void SaveAccountInfoToFile(){
       vector<string> InfoTitles = {"Account Number:", "PIN Code:", "Name:", "Phone:", "Account Balance:"};
       sClientInfo Info = AccountInformation();
    
        myFile.open("UsersAccoutInformation.txt", ios::app); 

        if(myFile.is_open()){
        myFile << Joiner(Info, "#//#") << endl;
        
    }

     myFile.close();   
    } 

void AddClients(){
    char addMore = 'Y';
    do {
        system("clear");
        cout << "Adding new client: \n\n";
        SaveAccountInfoToFile();
        cout << "Do you want to add more ? (y) for y (n) for No: ";
        cin >> addMore;
    }while (addMore == 'y' || addMore == 'Y');
}    

int main(){
    AddClients();
    return 0;
}