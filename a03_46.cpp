#include <iostream>
#include <vector>
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


vector<string> Spliter(vector<string> &vWords, string str ,string delimeter){
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

int main(){
    cout << "Please enter client data: \n\n";
    vector<string> extractedInfo;
    vector<string> InfoTitles = {"Account Number: ", "PIN Code: ", "Name: ", "Phone: ", "Account Balance: "};
    sClientInfo clientInfo = AccountInformation();
    cout << "\n\n";
    string InfoLine = Joiner(clientInfo, "#//#");
    cout << "Line record is: " << endl;
    cout << InfoLine << "\n\n";
    cout << "The following is the extracted client record:" << endl;
    extractedInfo = Spliter(extractedInfo, InfoLine, "#//#");

    for(int x = 0; x < InfoTitles.size(); x++){
        cout << InfoTitles.at(x) << extractedInfo.at(x) << endl;
    }



    return 0;
}