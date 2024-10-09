/*
this project is second project of two projects for finalizing the algorithm and problem solivng level-3 course. 

Project-Name: Bank System Extension
Project-description: An extension of the previous bank system project with addition of some new Transaction Features.
Developer: Ahmed Osman
Start-Date: Tuesday 8-10-2024
Completion-Date: Tuesday 8-10-2024
Total Active Development Time: 3-Hours

Credit- Instructor Dr.Mohammed Abu-Hadhoud @ Programming Advices. 
*/
#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>
#include <fstream>

using namespace std;

void MainMenu(short &chooseOperation);

const string clientRecordFile = "UsersAccoutInformation.txt";

enum enBankOperation {ShowClientList=1, AddNewClient=2, DeleteClientRecord=3, UpdateClientRecord=4, FindClientRecord=5, Transactions=6, Exit=7};
enum enTransactionOperation {Deposit=1, Withdraw=2, TotalBalance=3, ExitToMainMenu=4};

struct sClientInfo {
    string accountNumber;
    string pinCode;
    string clientName;
    string clientPhone;
    double clientBalance;
    bool markForDelete = false;
};


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
            if(!(line.empty())){
                Client = ConvertLinetoRecord(line);
                ClientInfo.push_back(Client);
            }
        }
    }
    myFile.close();

    return ClientInfo;
}

void PrintClientInfo(sClientInfo Client){
     cout << "\nThe following are details of the client\n";     
     cout << "\nAccout Number : " << Client.accountNumber;    
     cout << "\nPin Code     : " << Client.pinCode;     
     cout << "\nName         : " << Client.clientName;     
     cout << "\nPhone        : " << Client.clientPhone;     
     cout << "\nAccount Balance: " << Client.clientBalance;
     cout << endl;
    
}

vector<sClientInfo> AddFreshCleint(string clientRecordFile, vector<sClientInfo> &allClientData, string accountNumber){
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

sClientInfo ReadNewAccountInformation(string accountNumber){

    sClientInfo ClientInfo;

    ClientInfo.accountNumber = accountNumber;

    cout << "Enter PIN code: ";
    getline(cin >> ws,ClientInfo.pinCode);

    cout << "Enter New Name: ";
    getline(cin, ClientInfo.clientName);

    cout << "Enter new phone number: ";
    getline(cin, ClientInfo.clientPhone);

    cout << "Update new account balance: ";
    cin >> ClientInfo.clientBalance;

    return ClientInfo;
}

string ReadClientAccountNumber(){
    string accountNumber;

    cout << "Enter client account number: ";
    cin >> accountNumber;
    return accountNumber;
}


bool UpdateClientData(string accountNumber, vector<sClientInfo>& allClientData){
    char confirmDelete = 'n';
    sClientInfo Client;

    if(FindClientByAccountNumber(accountNumber, allClientData, Client)){
        PrintClientInfo(Client);

        cout << "Please confirm yes [y] or no [n] to update this client: ";
        cin >> confirmDelete;

        if(tolower(confirmDelete) == 'y'){
            for(sClientInfo &Client: allClientData){
                if(Client.accountNumber == accountNumber){
                    Client = ReadNewAccountInformation(accountNumber);
                    break;
                }
            }
            AddFreshCleint(clientRecordFile, allClientData, accountNumber);

            system("clear");
            cout << "Record updated successfuly." << endl;
            cout << "\nPress any key to return to main menu.. \n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            return true;
        }else{
            system("clear");
            cout << "Revert Action:No changes have been made" << endl;
            cout << "\nPress any key to return to main menu.. \n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            return false;
        }
    }
     
     return false; 
    
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
            
            system("clear");
            cout << "Record Deleted successfuly." << endl;
            cout << "\nPress any key to return to main menu.. \n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            return true;
        }else{
            system("clear");
            cout << "No changes have been made" << endl;
            cout << "\nPress any key to return to main menu.. \n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            return false;
        }
    }
   
     return false; 
    
}

void TableTitle(vector<sClientInfo>& stClientData){
    
    cout << "\n";
    cout << setw(50) << right << "Client List ("<< stClientData.size() <<") Client(s)" << setw(50);
  
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

  cout << "\nPress any key to return to main menu.. \n";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  cin.get();
  return;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName){
vector <sClientInfo> vClients;
fstream MyFile;
MyFile.open(FileName, ios::in);//read Mode
if (MyFile.is_open()){
    string Line;
    sClientInfo Client;
    while (getline(MyFile, Line)){
        Client = ConvertLinetoRecord(Line);
        if (Client.accountNumber == AccountNumber){
            MyFile.close();
            return true;
     }
    vClients.push_back(Client);
    }
    MyFile.close();
    }
    return false;
}

sClientInfo ReadNewClient(){
    sClientInfo Client;
    cout << "Enter Account Number? ";
// Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.accountNumber);
    while (ClientExistsByAccountNumber(Client.accountNumber, clientRecordFile)){
        cout << "\nClient with [" << Client.accountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.accountNumber);
    }

    cout << "Enter PinCode? ";
    getline(cin, Client.pinCode);
    cout << "Enter Name? ";
    getline(cin, Client.clientName);
    cout << "Enter Phone? ";
    getline(cin, Client.clientPhone);
    cout << "Enter clientBalance? ";
    cin >> Client.clientBalance;

    return Client;
}

void AddDataLineToFile(string FileName, string stDataLine){
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open()){
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}


void AddClient(){

    sClientInfo Client;
    Client = ReadNewClient();
    AddDataLineToFile(clientRecordFile, ConvertRecordToLine(Client));
    
}

void AddNewClients(){
    char AddMore = 'Y';
    do{
    system("clear");
    cout << "Adding New Client:\n\n";
    AddClient();
    cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
    cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}


int ShowExitScreen(bool &mainContunity){
    system("clear");
    cout << setw(30) << right << "Thanks for using our bank system :) " << setw(30) << endl;
    cout << setw(35) << right << "Comeback any time " << setw(35) << endl;
    cout << setw(30) << right << "Press any key to exit the program... " << setw(30) << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    mainContunity = false;
    system("clear");
    return 0;
}

void ExitTransactionMainMenu(bool &transactionContunity){
    transactionContunity = false;
    return;
}

void MainMenu(short &chooseOperation){

    cout << "\n======================================================================\n";
    cout << setw(40)<< " Main Menu " << setw(20);
    cout << "\n======================================================================\n";
    cout << setw(25)<< left << "[1] Show Client List." << setw(20)<< endl;
    cout << setw(25)<< left << "[2] Add New Client." << setw(20) << endl;
    cout << setw(25)<< left << "[3] Delete Client Record." << setw(20) << endl;
    cout << setw(25)<< left << "[4] Update Client Record." << setw(20) << endl;
    cout << setw(25)<< left << "[5] Find Client Record" << setw(20) << endl;
    cout << setw(25)<< left << "[6] Transactions." << setw(20) << endl;
    cout << setw(25)<< left << "[7] Exit System." << setw(20);
    cout << "\n======================================================================\n";
    do {
     cout << "Choose what operation do you want to do ? [1 to 7]: ";
    cin >> chooseOperation;
    while (cin.fail()){
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input! please enter a number: ";
        cin >> chooseOperation;
    }
    }while (chooseOperation <= 0 || chooseOperation > 7);
}

void TransactionIntro(){
    system("clear");
    cout << "\n======================================================================\n";
    cout << setw(40)<< " Transaction Main Menu " << setw(20);
    cout << "\n======================================================================\n";
    cout << setw(25)<< left << "[1] Deposti" << setw(20)<< endl;
    cout << setw(25)<< left << "[2] Withdraw" << setw(20) << endl;
    cout << setw(25)<< left << "[3] Show TotalBalances" << setw(20) << endl;
    cout << setw(25)<< left << "[4] Back To Main Menu" << setw(20) << endl;
    cout << "\n======================================================================\n";
}

int ReadDepositAmount(){
    double deposit;
     do {
     cout << "How much amount do you want to deposit [min:1$ max:50,000$]: ";
     cin >> deposit;
    while (cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input! please enter a number: ";
        cin >> deposit;
    }
    }while (deposit <= 0 || deposit > 50000);

    return deposit;
}

void DepositCredit(vector<sClientInfo>& allClientData){
    string accountNumber = ReadClientAccountNumber();
    char depositConfirm = 'n';
    double depositAmout = 0;

    for(sClientInfo&Client: allClientData){
        while(!FindClientByAccountNumber(accountNumber, allClientData, Client)){
            cout << "We did not found (" << accountNumber << ") in the list. please try again. \n";
            accountNumber = ReadClientAccountNumber();
        }
        
        if(Client.accountNumber == accountNumber){
            PrintClientInfo(Client);
            depositAmout = ReadDepositAmount();
            cout << "Are you sure you want to deposit " << depositAmout << "$ to " << Client.clientName << ",s Balance ? [y] or [n]: ";
            cin >> depositConfirm;

            if(tolower(depositConfirm) == 'y'){
            Client.clientBalance+= depositAmout;
            SaveNewClientsDataToFile(clientRecordFile, allClientData);
            system("clear");
            cout << "\nDeposit Operation Successful.\n";
            cout << "\nNow " << Client.clientName << ",s balance is " << Client.clientBalance << "\n";
            cout << "\nPress any key to return to main menu.. \n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            return;

            }else{
                cout << "\nDeposit Operation Unsuccessful.\n";
                cout << setw(30) << right << "Press any key to return to main menu.. " << setw(30) << endl;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.get();
                return;
            }
            
        }
    }
    
}

int ReadWithdrawAmount(){
    double withdraw;
     do {
     cout << "How much amount do you want to withdraw: ";
     cin >> withdraw;
    while (cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input! please enter a number: ";
        cin >> withdraw;
    }
    }while (withdraw <= 0 || withdraw > 50000);

    return withdraw;
}

void WithDrawCredit(vector<sClientInfo>& allClientData){
    string accountNumber = ReadClientAccountNumber();
    char withdrawConfirm = 'n';
    double withdrawAmout = 0;

    for(sClientInfo&Client: allClientData){
        while(!FindClientByAccountNumber(accountNumber, allClientData, Client)){
            cout << "We did not found (" << accountNumber << ") in the list. please try again.\n";
            
            accountNumber = ReadClientAccountNumber();
        }
        if(Client.accountNumber == accountNumber){
            if(Client.clientBalance <= 0){
                cout << "Client have zero balance, withdrawal is impossible.\n";
                cout << setw(30) << right << "Press any key to return to main menu " << setw(30) << endl;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.get();
                return;

            }

            PrintClientInfo(Client);

            withdrawAmout = ReadWithdrawAmount();
            while(Client.clientBalance < withdrawAmout){
                cout << "\nYou can't withdraw amount which is greater than client,s current balance !\n";
                cout << "\nPlease enter balance lower or equal to " << Client.clientBalance << "$\n";
                withdrawAmout = ReadWithdrawAmount();
            }
            
            cout << "Are you sure you want to withdraw " << withdrawAmout << "$ from " << Client.clientName << ",s Balance ?[y] or [n]: ";
            cin >> withdrawConfirm;

            if(tolower(withdrawConfirm) == 'y'){
            Client.clientBalance+= -withdrawAmout;
            SaveNewClientsDataToFile(clientRecordFile, allClientData);
            system("clear");
            cout << "\nWithdraw Operation Successful.\n";
            cout << "\nNow " << Client.clientName << ",s balance is " << Client.clientBalance << "\n";
            cout << "\nPress any key to return to main menu.. \n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            return;

            }else{
                cout << "\nWithdraw Operation Unsuccessful.\n";
                cout << setw(30) << right << "Press any key to return to main menu.. " << setw(30) << endl;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.get();
                return;
            }
            
        }
    }

}

void PrintClientRecordBalanceLine(sClientInfo Client){

    cout << "| " << setw(15) << left << Client.accountNumber;
    cout << "| " << setw(40) << left << Client.clientName;
    cout << "| " << setw(12) << left << Client.clientBalance;
}

void ShowTotalBalances(){
    vector <sClientInfo> vClients = LoadClientData(clientRecordFile);
    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ")Client(s).";
    cout <<"\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout <<"\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    double TotalBalances = 0;
    if (vClients.size() == 0){

    }else {
        for (sClientInfo Client : vClients){
            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.clientBalance;
            cout << endl;
        }
    cout <<"\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t Total Balances = " << TotalBalances;
    cout << setw(30) << right << "\n\nPress any key to return to main menu.. " << setw(30) << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
    return;
}

}

void TransactionOperation(short transactionOperation, bool& transactionContunity,  vector<sClientInfo>& allClientData){
    
    switch (transactionOperation)
    {
    case enTransactionOperation::Deposit:
        system("clear");
        DepositCredit(allClientData);
        break;
    case enTransactionOperation::Withdraw:
        system("clear");
        WithDrawCredit(allClientData);
        break;
    case enTransactionOperation::TotalBalance:
        system("clear");
        ShowTotalBalances();
        break;
    case enTransactionOperation::ExitToMainMenu:
        ExitTransactionMainMenu(transactionContunity);
        break;
    
    default:
        break;
    }
}

void TransactionMainMenu(short& transactionOperation, vector<sClientInfo> allClientData ){
    bool transactionContunity = true;
    while(transactionContunity){
        TransactionIntro();
        
            do {
     cout << "Choose what operation do you want to do ? [1 to 4]: ";
    cin >> transactionOperation;
    while (cin.fail()){
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input! please enter a number: ";
        cin >> transactionOperation;
    }
    }while (transactionOperation <= 0 || transactionOperation > 4);

    TransactionOperation(transactionOperation, transactionContunity ,allClientData);

    }
}

int main(){

    bool mainContunity = true;
    sClientInfo FindClient;
    string accountNumber;
    while(mainContunity){
    system("clear");
    short chooseOperation;
    short transactionOperation;
    MainMenu(chooseOperation);

    vector<sClientInfo> allClientData = LoadClientData(clientRecordFile);

    switch (chooseOperation) {
    case enBankOperation::ShowClientList:
        system("clear");
        ShowInfoTable(allClientData);
        break;
    case enBankOperation::AddNewClient:
        system("clear");
        AddNewClients();
        break;
    case enBankOperation::DeleteClientRecord:
        system("clear");
        accountNumber = ReadClientAccountNumber();
        DeleteClientByAccountNum(accountNumber,allClientData);
        break;
    case enBankOperation::UpdateClientRecord:
        system("clear");
        accountNumber = ReadClientAccountNumber();
        UpdateClientData(accountNumber,allClientData);
        break;
    case enBankOperation::FindClientRecord:
        system("clear");
        accountNumber = ReadClientAccountNumber();
        if(FindClientByAccountNumber(accountNumber, allClientData, FindClient)){
            PrintClientInfo(FindClient);
            cout << setw(30) << right << "Press any key to return to main menu " << setw(30) << endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();

        }
        
        break;
    case enBankOperation::Transactions:
        system("clear");
        TransactionMainMenu(transactionOperation, allClientData);
        break;
    case enBankOperation::Exit:
        ShowExitScreen(mainContunity);
        break;
    default:
        break;

    }
    }
    
    return 0;
}