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
	user(account& user);
	string GetName();
	string GetUsername();
	string GetPassword();
	int GetRole();
	string GetID();
	bill GetBill();

	void  addBill(listBook&list,int index,int number);
	void DeleteBill();
	void checkBill();
	void updateBill();
	void checkoutBill();
	void WriteMessage(string name);
	void ReadMessage(string receiver);
	void CreateUser(string ID, string username, string password, string name,bill b);
	//void getNumber();
	~user();
};


#endif // !USER_H_

