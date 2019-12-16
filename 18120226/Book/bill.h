#pragma once
using namespace std;
#include"listBook.h"
class bill
{
private:
	listBook bookList;
	int total;
public:
	bill();
	~bill();
	void addBill(listBook&list,int index,int number);
	void checkBill();
	listBook getBill();
	void setBill(listBook& list);
	void printBill();
	void updateBill();
	void deleteBill();
	void checkout();
	listBook getItem();
};

