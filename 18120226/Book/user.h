#pragma once
#include<iostream>
#include"bill.h"
#include"guest.h"
#include"book.h"
using namespace std;
class user:public guest
{
private:
	bill userBill;
public:
	user();
	void addBill(book& book);
	void checkBill();
	~user();
};
