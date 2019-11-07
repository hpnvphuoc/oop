#include"book.h"
book::book()
{
	this->IBSN = "";
	this->name = "";
	this->price = 0;
	this->publisher = 0;
	this->number = 0;
	this->author = 0;
	
}

book::~book()
{
	this->IBSN = "";
	this->name = "";
	this->price = 0;
	this->publisher = 0;
	this->number = 0; 
	this->author = 0;
}


book::book(string IBSN,string name,int price,int publisher,int number,int author)
{
	this->name = name;
	this->IBSN = IBSN;
	this->price = price;
	this->publisher = publisher;
	this->price = price;
	this->number = number;
	this->author = author;

}

book::book(const book& book) {
	this->name = book.name;
	this->IBSN = book.IBSN;
	this->price = book.price;
	this->publisher = book.publisher;
	this->number = book.number;
	this->author = book.author;
}


string book::getName() {
	return this->name;
}

string book::getIBSN() {
	return this->IBSN;
}
int book::getPrice() {
	return this->price;
}

string book::getPublisher()
{
	fstream f;
	f.open("publisher.txt", ios::out);
	getline(f)
	f.close();
	return publisher;
}

int book::getNumber() {
	return number;
}
string book::getAuthor() {
	return author;
}
void book::set(string IBSN, string name, int price, int publisher, int number,int author) {
	this->name = name;
	this->IBSN = IBSN;
	this->price = price;
	this->publisher = publisher;
	this->price = price;
	this->number = number;
	this->author = author;
}




