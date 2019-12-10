#pragma once
#ifndef USER_H_
#define USER_H_
#include<iostream>
#include"bill.h"
#include"guest.h"
#include"book.h"
#include"account.h"
using namespace std;
class user :public guest
{
private:
	string ID;
	string username;
	string password;
	int role;
	string name;
	bill userBill;
	vector<message> mess;
public:
	user();
	string GetName();
	void SignUp(vector<account>& list_account);
	int  addBill(listBook&list,int index=0);
	void DeleteBill();
	void checkBill(listBook&list);
	void updateBill();
	void checkoutBill();
	void WriteMessage(string name);
	void ReadMessage(string receiver);
	void CreateUser(string ID, string username, string password, string name);
	//void getNumber();
	~user();
};


#endif // !USER_H_

