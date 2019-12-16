using namespace std;
#include "user.h"
user::user()
{	
	ID = "";
	username = "";
	password = "";
	name = "";
}

user::user(account& user)
{
	this->ID = user.GetID();
	this->username = user.GetUsername();
	this->password = user.GetPassword();
	this->name = user.GetName();
	this->role = user.GetRole();
}

string user::GetName()
{
	return this->name;
}
user::~user()
{
}

void user::addBill(listBook&list,int index,int number) {
	userBill.addBill(list, index, number);
}

void user::DeleteBill()
{
	userBill.deleteBill();
	
}

void user::checkBill() {
	cout << "username: " << this->username << endl;
	cout << "password" << this->password << endl;
	userBill.checkBill();
}

void user::updateBill()
{
	userBill.updateBill();
}

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
	return this->userBill;
}

string user::GetUsername()
{
	return this->username;
}

string user::GetPassword()
{
	return this->password;
}
