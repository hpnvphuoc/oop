#include "admin.h"



admin::admin()
{
}


admin::~admin()
{
}

vector<account> admin::getAllAccount(const string file_name)
{
	fstream f;
	f.open(file_name, ios::in);
	string temp;
	account* accTemp = new account;
	getline(f, temp);
	while (!f.eof()) {
		getline(f, temp);
		string tempID = message::cutstring(temp);
		string tempUsername = message::cutstring(temp);
		string tempPassword = message::cutstring(temp);
		string tempName = message::cutstring(temp);
		int tempRole = stoi(message::cutstring(temp));
		accTemp->SetAccount(tempID, tempUsername, tempPassword, tempName,tempRole);
		acc.push_back(*accTemp);
	}
	f.close();
	return this->acc;
}

void admin::OutputListAccount()
{
	cout << left<<setw(10)<<"ID" << setw(15) << "Username" << setw(20) << "Password" << setw(18) << "Name" <<setw(18)<<"Type"<< endl;
	for (int i = 0; i < acc.size(); i++) {
		cout <<left<<setw(10)<< acc[i].GetID() << left<<setw(15) << acc[i].GetUsername() <<left <<setw(20) << acc[i].GetPassword() <<left<< setw(20) << acc[i].GetName() <<left<< setw(13) << acc[i].GetAccountType(acc[i].GetRole())<<endl;
	}
}

void admin::AddAccount()
{
	string ID = account::generateID();
	string username;
	string password;
	string name;
	int role;
	cout << "Username: ";
	cin.ignore();
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);
	cout << "Name: ";
	getline(cin, name);
	account temp;
	cout << "Role: ";
	cin >> role;
	temp.SetAccount(ID, username, password, name,role);
	acc.push_back(temp);
	
}

void admin::UpdateAccount()
{
	int index;
	this->OutputListAccount();
	cout << "Nhap STT tai khoan can cap nhat: ";
	cin >> index;
	string ID;
	string username;
	string password;
	string name;
	int role;
	cin.ignore();
	cout << "ID";
	getline(cin, ID);
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);
	cout << "Name: ";
	getline(cin, name);
	account temp;
	cout << "Role: ";
	cin >> role;
	temp.SetAccount(ID, username, password, name,role);
	acc[index] = temp;
}

void admin::DeleteAccount()
{
	int index;
	cout << "Nhap vao STT tai khoan can xoa: ";
	cin >> index;
	
	acc.erase(acc.begin() + index);
}

void admin::WriteListAccountToFile()
{
	fstream f;
	f.open("account.txt", ios::out);
	f << acc.size() << endl;
	for (int i = 0; i < acc.size(); i++) {
		f << acc[i].GetID() << "," << acc[i].GetUsername() << "," << acc[i].GetPassword() << "," << acc[i].GetName() << "," << acc[i].GetRole() << endl;
	}
	f.close();
}

