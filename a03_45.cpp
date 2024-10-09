#include <iostream>
#include <string>

using namespace std;

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
    cin >> ClientInfo.accountNumber;

    cout << "Enter PIN code: ";
    cin >> ClientInfo.pinCode;

    cout << "Enter your Name: ";
    cin.ignore(1, '\n');
    getline(cin, ClientInfo.clientName);

    cout << "Enter your phone number: ";
    cin >> ClientInfo.clientPhone;

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
    result+=to_string(ClientInfo.clientBalance)+delimeter;

    return result;
}


int main(){
    cout << "Please enter client data: \n\n";
    sClientInfo clientInfo = AccountInformation();
    cout << "\n\n";
    cout << Joiner(clientInfo, "#//#")<< endl;
    return 0;
}