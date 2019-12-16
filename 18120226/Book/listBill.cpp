#include "listBill.h"

listBill::listBill()
{
}

void listBill::WriteListBillToFile()
{
	fstream f;
	f.open("listbill.txt", ios::out);
	for (int i = 0; i < this->numbill; i++) {
		f << list[i].GetID()<<","<<list[i].GetUsername()<<","<<list[i].GetPassword()<<list[i].GetName()<<endl;
		list[i].GetBill().getBill().writeListBookToFile();
	}
}

void listBill::LoadListBillFormFile()
{
	fstream f;
	f.open("listbill.txt", ios::in);
	string temp;
	string ID;
	string username;
	string password;
	string name;
	string tempNumkind;
	string tempBook;
	string tempIBSN;
	string tempName;
	int tempPrice;
	string tempPublisher;
	int tempNumber;
	string tempAuthor;
	bool tempIsBlock;	
	getline(f, temp);
	numbill = stoi(temp);
	user t;
	user* list = new user[numbill];
	int i = 0;
	while (!f.eof()) {
		getline(f, temp);
		ID = message::cutstring(temp);
		username = message::cutstring(temp);
		password = message::cutstring(temp);
		name = message::cutstring(temp);
		int numKind;
		getline(f, tempNumkind);
		numKind = stoi(tempNumkind);
		book *list_book = new book[numKind];
		for (int i = 0; i < numKind; i++) {
			getline(f, tempBook);
			tempIBSN = message::cutstring(tempBook);
			tempName = message::cutstring(tempBook);
			tempPrice = stoi(message::cutstring(tempBook));
			tempPublisher = message::cutstring(tempBook);
			tempNumber = stoi(message::cutstring(tempBook));
			tempAuthor = message::cutstring(tempBook);
			tempIsBlock = stoi(message::cutstring(tempBook));
			list_book[i].set(tempIBSN, tempName, tempPrice, tempPublisher, tempNumber, tempAuthor, tempIsBlock);
		}
		listBook b(list_book, numKind);
		bill te;
		te.setBill(b);
		t.CreateUser(ID, username, password, name, te);
		list[i] = t;
		i++;
	}
	this->list = list;
}



listBill::~listBill()
{
}

void listBill::addBill(user&usr) {
	this->numbill =this->numbill+1;
	list[numbill] = usr;
}

void listBill::OutputListbill()
{
	for (int i = 0; i < this->numbill; i++) {
		list[i].checkBill();
	}
}

int listBill::size()
{
	return this->numbill;
}

listBook listBill::getListItem()
{
	listBook temp;
	listBook result;
	for (int i = 0; i < numbill; i++) {
		temp = this->list[i].GetBill().getItem();
		result = result.concatenate(temp);
	}	
	return result;
}
