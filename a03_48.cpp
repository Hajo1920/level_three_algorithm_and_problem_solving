#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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

vector<sClientInfo> LoadClientData(string file){

    fstream myFile;
    vector<sClientInfo> ClientInfo;

    myFile.open(file, ios::in); // readmood

    if(myFile.is_open()){
        string line;
        sClientInfo vClient;

        while(getline(myFile, line)){
            vClient = ConvertLinetoRecord(line);

            ClientInfo.push_back(vClient);
        }
    }
    myFile.close();

    return ClientInfo;
}


void TableTitle(vector<sClientInfo>& stClientData){
    
    cout << "\n";
    cout << setw(50) << "Client List ("<< stClientData.size() <<") Client(s)" << setw(50);
  
}

void TitlesHeader(){
   cout << "\n_______________________________________________________________";     
   cout << "_________________________________________\n" << endl;     
   cout << "| " << left << setw(15) << "Accout Number";     
   cout << "| " << left << setw(15) << "Pin Code";     
   cout << "| " << left << setw(40) << "Client Name";     
   cout << "| " << left << setw(12) << "Phone";     
   cout << "| " << left << setw(12) << "Balance";     
   cout << "\n______________________________________________________________";     
   cout << "_________________________________________\n" << endl;
}

void PrintClientRecord(sClientInfo Client) {     
    cout << "| " << setw(15) << left << Client.accountNumber;     
    cout << "| " << setw(15) << left << Client.pinCode;     
    cout << "| " << setw(40) << left << Client.clientName;    
    cout << "| " << setw(12) << left << Client.clientPhone;     
    cout << "| " << setw(12) << left << Client.clientBalance; } 

void RevealClientData(vector<sClientInfo>& stClientData){
  for(sClientInfo Client: stClientData){
    PrintClientRecord(Client);
    cout << endl;
  }
}
    


void ShowInfoTable(vector<sClientInfo> stClientData){
  TableTitle(stClientData);
  cout << endl;
  TitlesHeader();
  RevealClientData(stClientData);
}

int main(){
    vector <sClientInfo> stClientData = LoadClientData(clientRecordFile);

    ShowInfoTable(stClientData);
    return 0;
}