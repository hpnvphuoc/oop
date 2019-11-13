#include "publisher.h"



publisher::publisher()
{
}

publisher::~publisher()
{
}

void listBook::readListBookFromFile()
{
	string tempNumkind;
	string tempBook;
	string tempIBSN;
	string tempName;
	int tempPrice;
	string tempPublisher;
	int tempNumber;
	string tempAuthor;
	fstream f;
	f.open("listBook.txt", ios::in);
	getline(f, tempNumkind);
	numKind = stoi(tempNumkind);
	this->list = new book[numKind];
	for(int i=0;i<numKind;i++){
		getline(f,tempBook);
		tempIBSN = cutstring(tempBook);
		tempName = cutstring(tempBook);
		tempPrice = stoi(cutstring(tempBook));
		tempPublisher = cutstring(tempBook);
		tempNumber = stoi(cutstring(tempBook));
		tempAuthor = cutstring(tempBook);
		list[i].set(tempIBSN, tempName, tempPrice, tempPublisher, tempNumber, tempAuthor);
	}
	f.close();
}