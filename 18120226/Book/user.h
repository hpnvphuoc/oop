#pragma once
#include<iostream>
#include"bill.h"
#include"guest.h"
#include"book.h"
using namespace std;
class user:public guest
{
private:
	string username;
	string password;
	int age;
	bool IsLogin;
	bill userBill;
public:
	user();
	void login();
	bool checkLogin();
	void addBill(book& book);
	void checkBill();
	~user();
};
