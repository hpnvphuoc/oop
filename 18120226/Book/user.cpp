using namespace std;
#include "user.h"
user::user()
{
	age = 0;
	IsLogin = false;
}
int user::getRole()
{
	return role;
}
user::~user()
{
}

void user::login() {
	cin.ignore();
	cout << "username: ";
	getline(cin, username);
	cout << "password: ";
	getline(cin, password);
	cout << "Tuoi: ";
	cin >> age;
	cout << this->username << " " << this->password << " " << this->age << endl;
	IsLogin = true;
}

bool user::checkLogin() {
	return IsLogin;
}


void user::addBill(book& book) {
	userBill.addBill(book);
}

void user::checkBill() {
	userBill.checkBill();
}
