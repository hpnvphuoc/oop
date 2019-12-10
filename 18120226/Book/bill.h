#pragma once
using namespace std;
#include"listBook.h"
struct b{
	int index;
	int number;
	int price;
};
class bill
{
private:
	vector<b> list_bill;
	int total;
public:
	bill();
	~bill();
	void addBill(listBook&list,int index=0);
	void checkBill(listBook& list);
	void updateBill();
	void deleteBill();
	void checkout();
};

