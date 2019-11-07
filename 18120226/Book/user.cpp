using namespace std;
#include "user.h"
user::user()
{
	age = 0;
	IsLogin = false;
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
