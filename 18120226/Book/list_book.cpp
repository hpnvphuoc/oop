#include "list_book.h"



list_book::list_book()
{
	this->list = new book;
}
void list_book::inputList(int number)
{
	this->list = new book[number];
	string tempName;
	string tempIBSN;
	int tempPrice;
	for (int i = 0; i < number; i++) {
		cout << "Sach " << i << endl;
		cout << "Ten: ";
		cin.ignore();
		getline(cin, tempName);
		cout << "Ma sach: ";
		cin.ignore();
		getline(cin, tempIBSN);
		cout << "Gia sach: ";
		cin >> tempPrice;
		this->list[i].set(tempName, tempIBSN, tempPrice);
	}
}

void list_book::outputList(int number) {
	cout << "STT     " << "Ten sach       " << "Ma sach      " << "Gia sach      " << endl;
	for (int i = 0; i < number; i++) {
		cout << i << "       " << this->list[i].getName() << "        " << this->list[i].getIBSN() << "        " << this->list[i].getPrice() << endl;
	}
}

list_book::~list_book()
{
	delete this->list;
}
