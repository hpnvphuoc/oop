#include"book.h"
book::book()
{
	this->IBSN = "";
	this->name = "";
	this->price = 0;
	this->publisher = "";
	this->number = 0;
	this->author = "";
	this->isBlock = 0;
}

book::~book()
{
	this->IBSN = "";
	this->name = "";
	this->price = 0;
	this->publisher = "";
	this->number = 0; 
	this->author = "";
	this->isBlock = false;
}


book::book(string IBSN,string name,int price, string publisher,int number, string author)
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
	return publisher;
}

int book::getNumber() {
	return number;
}
string book::getAuthor() {
	return author;
}
int book::IsBlock()
{
	return isBlock;
}
void book::setNumber(int number)
{
	this->number = number;
}
void book::Block(int role)
{
	isBlock = role;
}
void book::UnBlock()
{
	isBlock = 0;
}
void book::set(string IBSN, string name, int price, string publisher, int number, string author,bool isBlock) {
	this->name = name;
	this->IBSN = IBSN;
	this->price = price;
	this->publisher = publisher;
	this->price = price;
	this->number = number;
	this->author = author;
	this->isBlock = isBlock;
}

void book::CreateBook() {

	cout << "Ma sach: ";
	cin.ignore();
	getline(cin,IBSN);

	cout << "Ten: ";
	getline(cin, name);

	cout << "Gia sach: ";
	cin >> price;
	cin.ignore();

	cout << "Nha xuat ban: ";
	getline(cin, publisher);

	cout << "So luong: ";
	cin >> number;
	cin.ignore();

	cout << "Tac gia: ";
	getline(cin, author);

}




