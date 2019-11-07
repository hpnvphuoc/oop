#include "listBill.h"

listBill::listBill()
{
	list = NULL;
	numBill = 0;
}


listBill::~listBill()
{
}

void listBill::addBill(user&usr) {
	numBill=numBill+1;
	//TH danh sach rong
	if (list == NULL) {
		list = new user;
		*list = usr;
		return;
	}

	//TH danh sach khac rong
	//sao chep tung phan tu sang mang tam;
	user* temp = new user[numBill];
	for (int i = 0; i < numBill-1; i++)
	{
		temp[i] = list[i];
	}
	temp[numBill - 1] = usr;
	list = new user[numBill];
	for (int i = 0; i < numBill; i++)
	{
		list[i] = temp[i];
	}
}