using namespace std;
#include "user.h"
user::user()
{	
	ID = "";
	username = "";
	password = "";
	name = "";
}

string user::GetName()
{
	return this->name;
}

void user::SignUp(vector<account>& list_account)
{
	string box = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz0123456789";
	int length = box.length();
	for (int i = 0; i < 5; i++)
	{
		ID[i] = box[rand() % length];
	}
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);
	cout << "Name";
	getline(cin, name);
	role = 4;
	account temp;
	temp.SetAccount(ID, username, password, name, role);
	list_account.push_back(temp);

}

user::~user()
{
}

void user::addBill(listBook&list,int index,int number) {
	userBill.addBill(list, index, number);
}

//void user::DeleteBill()
//{
//	userBill.deleteBill();
//	
//}

void user::checkBill() {
	cout << "username" << this->username << endl;
	cout << "password" << this->password << endl;
	userBill.checkBill();
}

//void user::updateBill()
//{
//	userBill.updateBill();
//}

void user::checkoutBill()
{
	userBill.checkout();
}
void user::WriteMessage(string name)
{
	message::SendMessage(name);
}
void user::ReadMessage(string receiver) {
	mess = message::RecieveMessage(receiver);
	for (int i = 0; i < mess.size(); i++) {
		mess[i].PrintMessage(mess[i]);
	}
	if (mess.size() == 0) {
		cout << "Ban khong co tin nhan" << endl;
	}
}

void user::CreateUser(string ID, string username, string password, string name, bill b)
{
	this->ID = ID;
	this->username = username;
	this->password = password;
	this->name = name;
	this->role = 4;
	this->userBill = b;
}
int user::GetRole()
{
	return role;
}
string user::GetID()
{
	return ID;
}
bill user::GetBill()
{
	return userBill;
}

string user::GetUsername()
{
	return this->username;
}

string user::GetPassword()
{
	return this->password;
}
