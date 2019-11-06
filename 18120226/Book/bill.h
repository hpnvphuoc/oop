#pragma once
using namespace std;
#include"listBook.h"
class bill
{
private:
	listBook list;
public:
	bill();
	~bill();
	void addBill(book &book);
	void checkBill();
};

