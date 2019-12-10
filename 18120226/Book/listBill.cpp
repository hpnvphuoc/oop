#include "listBill.h"

listBill::listBill()
{
}

void listBill::WriteListBillToFile()
{
	fstream f;
	f.open("listBill.txt", ios::out);
	for (int i = 0; i < list.size(); i++) {
		f << list[i].username << list[i].IBSN << list[i].number << list[i].price << endl;
	}
}

void listBill::LoadListBillFormFile()
{
	fstream f;
	f.open("listBill.txt", ios::in);
	string temp;
	bill t;
	while (!f.eof()) {
		getline(f, temp);
		t.username = message::cutstring(temp);
		t.IBSN = message::cutstring(temp);
		t.number = stoi(message::cutstring(temp));
		t.price = stoi(message::cutstring(temp));
		list.push_back(t);
	}
}


listBill::~listBill()
{
}

void listBill::addBill(string username,string IBSN, int number, int price) {
	bill t;
	t.username = username;
	t.IBSN = IBSN;
	t.number = number;
	t.price = price;
	list.push_back(t);
}