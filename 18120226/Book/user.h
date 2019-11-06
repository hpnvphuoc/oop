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
	int role;
	//0: admin
	//1: book manager
	//2: active user
	///3: guest user
	bill userBill;
public:
	user();
	void login();
	bool checkLogin();
	void addBill(book& book);
	int getRole();
	void checkBill();
	~user();
};

//khach vo tim sach neu co cuon sach do thi co the chon mua hoac tiep tuc lua sach
//Neu mua sach thi add vao hoa don
//neu khong mua thi thoi

//Quan li
//-quan li doi tac
//them sach
//xoa sach
//admin: co tat ca cac quyen tren

//sach: