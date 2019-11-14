#include "guest.h"
guest::guest() {
	username = "";
	password = "";
	isLogin = false;
}
guest::~guest() {
	username = "";
	password = "";
	isLogin = false;
}
bool guest::IsLogin()
{
	return isLogin;
}
void guest::generateID()
{
	string box = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz0123456789";
	int length = box.length();
	for (int i = 0; i < 5; i++)
		{
			ID[i] = box[rand() % length ];
		}
}
void guest::login() {
	cin.ignore();
	cout << "username: ";
	getline(cin, username);
	cout << "password: ";
	getline(cin, password);
	isLogin = true;
}



