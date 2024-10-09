#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct sClientInfo {
    string accountNumber;
    string pinCode;
    string clientName;
    string clientPhone;
    double clientBalance;
};

const string clientRecordFile = "UsersAccoutInformation.txt";

vector<string> Spliter(string str ,string delimeter){
    vector<string> vWords;
    string word;
    short pos = 0;

    while((pos = str.find(delimeter)) != std::string::npos){
        word = str.substr(0, pos);

        if(!word.empty()){
            vWords.push_back(word);
        }

        str.erase(0, pos + delimeter.length());
    }
    if(!str.empty()){
        vWords.push_back(str);
    }

    return vWords;
}
sClientInfo ConvertLinetoRecord(string Line, string Seperator = "#//#") { 

    sClientInfo Client; 
    vector<string> vClientData;     
    vClientData = Spliter(Line, Seperator);     
    Client.accountNumber = vClientData[0];     
    Client.pinCode = vClientData[1];     
    Client.clientName = vClientData[2];     
    Client.clientPhone = vClientData[3];     
    Client.clientBalance = stod(vClientData[4]); //cast string to doublereturn Client; 

    return Client;
    
    } 

string ReadClientAccountNumber(){
    string accountNumber;

    do
    {
        cout << "Enter client account ID to search: ";
        getline(cin, accountNumber);
    } while (accountNumber.length() < 4);
    return accountNumber;
}

vector<sClientInfo> LoadClientData(string file){

    fstream myFile;
    vector<sClientInfo> ClientInfo;

    myFile.open(file, ios::in); // readmood

    if(myFile.is_open()){
        string line;
        sClientInfo Client;
        while(getline(myFile, line)){
            Client = ConvertLinetoRecord(line);
            ClientInfo.push_back(Client);
        }
    }
    myFile.close();

    return ClientInfo;
}

bool FindClientData(string accountNumber, sClientInfo& Client){
    vector <sClientInfo> ClientData = LoadClientData(clientRecordFile);

    for(sClientInfo C: ClientData){
        if(accountNumber == C.accountNumber){
            Client = C;
            return true;
        }
    }

    return false;
}

void PrintClientInfo(sClientInfo Client){
     cout << "\nThe following are the client details:\n";     
     cout << "\nAccout Number : " << Client.accountNumber;    
     cout << "\nPin Code     : " << Client.pinCode;     
     cout << "\nName         : " << Client.clientName;     
     cout << "\nPhone        : " << Client.clientPhone;     
     cout << "\nAccount Balance: " << Client.clientBalance;
     cout << endl;
}

int main(){
    sClientInfo Client;
    string accountNumber = ReadClientAccountNumber();
    

    if(FindClientData(accountNumber, Client)){
        PrintClientInfo(Client);
    }else{
        cout << "Client with Account ID (" << accountNumber << ") Not Found!" << endl;
    }


    return 0;
}