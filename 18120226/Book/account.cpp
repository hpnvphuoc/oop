#include "account.h"
account::account() {
	ID = "";
	username = "";
	password = "";
	name = "";
	role = 0;
}
account::~account() {
	username = "";
	password = "";
}
int account::GetRole()
{
	return role;
}
string account::GetID()
{
	return ID;
}
string account::GetName()
{
	return name;
}
 string account::generateID()
{
	string box = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz0123456789";
	int length = box.length();
	for (int i = 0; i < 5; i++)
	{
			ID[i] = box[rand() % length ];
	}
	return ID;
}
 account* account::CheckLogin(const string& file_name, string& Username, string& Password)
 {
	 fstream f;
	 f.open(file_name, ios::in);
	 string temp;
	 account *acc=new account;
	 if (!f.is_open()) {
		 return acc;
	 }
	 getline(f, temp);
	 while (!f.eof()) {
		 getline(f, temp);
		 string tempID=message::cutstring(temp);
		 string tempUsername=message::cutstring(temp);
		 if(tempUsername!=Username){
			 continue;
		 }
		 else {
			 string tempPassword = message::cutstring(temp);
			 if (tempPassword != Password) {
				 continue;
			 }
			 else {
				 string tempName = message::cutstring(temp);
				 int tempRole = stoi(message::cutstring(temp));
				 acc->ID = tempID;
				 acc->username = tempUsername;
				 acc->password = tempPassword;
				 acc->name = tempName;
				 acc->role = tempRole;
				 return acc;
			 }
		 }
	 }
	 f.close();
	 return acc ;
 }
 void account::SetAccount(string ID, string username, string password, string name, int role)
 {
	 this->ID = ID;
	 this->username = username;
	 this->password = password;
	 this->name = name;
	 this->role = role;
 }
 void account::CreateAccount(account& account)
 {
	 ID = account.ID;
	 username = account.username;
	 password = account.password;
	 name = account.name;
	 role = account.role;
 }
 void account::WriteMessage(string name)
 {
	 message::SendMessage(name);
 }
 void account::ReadMessage(string receiver) {
	 mess=message::RecieveMessage(receiver);
	 for (int i = 0; i < mess.size(); i++) {
		 mess[i].PrintMessage(mess[i]);
	 }
	 if (mess.size() == 0) {
		 cout << "Ban khong co tin nhan" << endl;
	 }
 }

void account::login(string &file_name) {
	cin.ignore();
	cout << "username: ";
	getline(cin, username);
	cout << "password: ";
	getline(cin, password);
	this->CheckLogin(file_name,username, password);
}



void account::GetBook(listBook& list)
{
	bookList = list.findBookByPublisher(this->name);
}

void account::CheckBook(listBook& list) {
	cout << setw(8) << "STT" << setw(10) << "IBSN" << setw(15) << "TEN" << setw(15) << "GIA" << setw(20) << "NHA XUAT BAN" << setw(15) << "SO LUONG" << setw(15) << "TAC GIA" << endl;
	for (int i = 0; i < bookList.size(); i++) {
		list.printElementI(bookList[i], 0, false);
		list.printElementI(bookList[i], role, false);
	}
}

void account::AddBook(listBook& list) {
	book temp;
	string tempIBSN;
	string tempName;
	int tempPrice;
	int tempNumber;

	cout << "IBSN: ";
	cin.ignore();
	getline(cin, tempIBSN);

	cout << "Ten: ";
	getline(cin, tempName);

	cout << "Gia sach: ";
	cin >> tempPrice;
	cin.ignore();

	cout << "So luong: ";
	cin >> tempNumber;
	cin.ignore();
	if (2==role) {
		string tempAuthor;
		cout << "Tac gia: ";
		getline(cin, tempAuthor);

		temp.set(tempIBSN, tempName, tempPrice, this->name, tempNumber, tempAuthor, false);
	}
	if (3 == role) {
		string tempPublisher;
		cout << "Nha xuat ban: ";
		getline(cin, tempPublisher);

		temp.set(tempIBSN, tempName, tempPrice, tempPublisher, tempNumber, this->name,false);
	}
	
	list.addBook(temp);
	bookList.push_back(list.getNumKind());
}

void account::DeleteBook(listBook& list)
{
	int index;
	cout << "Nhap vao STT sach muon xoa: ";
	cin >> index;
	if (index > bookList.size()) {
		cout << "Sach khong co STT vua chon";
		return;
	}
	bookList.erase(bookList.begin() + index);
}

void account::UpdateBook(listBook& list)
{
	book temp;
	string tempIBSN;
	string tempName;
	int tempPrice;
	int tempNumber;
	string tempAuthor;
	int index;
	cout << "Nhap STT sach can cap nhat";
	cin >> index;
	cout << "Cap nhat lai thong tin sach";
	cout << "IBSN: ";
	cin.ignore();
	getline(cin, tempIBSN);

	cout << "Ten: ";
	getline(cin, tempName);

	cout << "Gia sach: ";
	cin >> tempPrice;
	cin.ignore();

	cout << "So luong: ";
	cin >> tempNumber;
	cin.ignore();

	if (2 == role) {
		string tempAuthor;
		cout << "Tac gia: ";
		getline(cin, tempAuthor);

		temp.set(tempIBSN, tempName, tempPrice, this->name, tempNumber, tempAuthor,false);
	}
	if (3 == role) {
		string tempPublisher;
		cout << "Nha xuat ban: ";
		getline(cin, tempPublisher);

		temp.set(tempIBSN, tempName, tempPrice, tempPublisher, tempNumber, this->name,false);
	}
	list.updateBook(index, temp);
}

void account::BlockBook(listBook& list, int index)
{
	list.BlockBookI(index, role);
}

void account::UnBlockBook(listBook& list, int index) {
	list.UnBlockBookI(index);
}

void account::setName(string name)
{
	this->name = name;

}

string account::GetUsername()
{
	return this->username;
}

string account::GetPassword()
{
	return this -> password;
}

void account::setPassword(string newPass)
{
	this->password = newPass;
}

string account::GetAccountType(int role)
{
	switch (role)
	{
	case 1: return "Admin";
	case 2:return "Publisher";
	case 3: return "Author";
	case 4: return "Normal user";
	default:
		return "";
	}
}

void account::SignUp()
{
	fstream f;
	f.open("account.txt", ios::app);
	string ID;
	string username;
	string password;
	string name;
	int role;
	string box = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz0123456789";
	int length = box.length();
	for (int i = 0; i < 5; i++)
	{
		ID = ID+box[rand() % length];
	}
	cin.ignore();
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);
	cout << "Name";
	getline(cin, name);
	role = 4;
	f << ID << "," << username << "," << password << "," << name << "," << role << endl;
}

