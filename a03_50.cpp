#include <cctype>
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
    bool markForDelete = false;
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


string ReadClientAccountNumber(){
    string accountNumber;

    do
    {
        cout << "Enter client account ID to search: ";
        getline(cin, accountNumber);
    } while (accountNumber.length() < 4);
    return accountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClientInfo> vClients, sClientInfo& Client){
    for (sClientInfo C : vClients){
        if (C.accountNumber == AccountNumber){
            Client = C;
            return true;
            }
        }
    return false;
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

string ConvertRecordToLine(sClientInfo Client, string Seperator = "#//#"){
    string stClientRecord = "";
    stClientRecord += Client.accountNumber + Seperator;
    stClientRecord += Client.pinCode + Seperator;
    stClientRecord += Client.clientName + Seperator;
    stClientRecord += Client.clientPhone + Seperator;
    stClientRecord += to_string(Client.clientBalance);
    return stClientRecord;
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



void PrintClientInfo(sClientInfo Client){
     cout << "\nThe following are the client details:\n";     
     cout << "\nAccout Number : " << Client.accountNumber;    
     cout << "\nPin Code     : " << Client.pinCode;     
     cout << "\nName         : " << Client.clientName;     
     cout << "\nPhone        : " << Client.clientPhone;     
     cout << "\nAccount Balance: " << Client.clientBalance;
     cout << endl;
}


char DeleteConfirm(){
    char confrimation = 'n';

     cout << "Are you sure you want to delete this client record ? [y] yes [n] no: ";
     cin >> confrimation;

    return confrimation;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClientInfo>& vClients){
    for (sClientInfo& C : vClients){
        if (C.accountNumber == AccountNumber){
            C.markForDelete = true;
            return true;
        }
    }
    return false;
}

vector<sClientInfo> SaveNewClientsDataToFile(string clientRecordFile, vector<sClientInfo> &allClientData){
    fstream clientsFile;
    clientsFile.open(clientRecordFile, ios::out);
    string RecordLine;
    if(clientsFile.is_open()){
        for(sClientInfo Client: allClientData){
            if(Client.markForDelete == false){
               RecordLine = ConvertRecordToLine(Client);

               clientsFile << RecordLine << endl;
            }
     }
     clientsFile.close();
    }

    return allClientData;
    
}


bool DeleteClientByAccountNum(string accountNumber, vector<sClientInfo>& allClientData){
    char confirmDelete = 'n';
    sClientInfo Client;

    if(FindClientByAccountNumber(accountNumber, allClientData, Client)){
        PrintClientInfo(Client);

        cout << "Please confirm yes [y] or no [n] to delete the client: ";
        cin >> confirmDelete;

        if(tolower(confirmDelete) == 'y'){
            MarkClientForDeleteByAccountNumber(accountNumber, allClientData);
            SaveNewClientsDataToFile(clientRecordFile, allClientData);

            allClientData = LoadClientData(clientRecordFile);
            

            cout << "Record Deleted successfuly." << endl;
            return true;
        }else{
            cout << "No changes have been made" << endl;
            return false;
        }
    }
     cout << "Client with account number (" << accountNumber << ") Not Found" << endl;
     return false; 
    
}


int main(){
    vector<sClientInfo> allClientData = LoadClientData(clientRecordFile);
    string accountNumber = ReadClientAccountNumber();

    DeleteClientByAccountNum(accountNumber, allClientData);

    return 0;
}