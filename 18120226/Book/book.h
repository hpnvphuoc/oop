#ifndef BOOK_H_
#define BOOK_H_
#include<iostream>
#include<string>
using namespace std;
class book
{
private:
	string IBSN;
	string name;
	int price;
	string publisher;
	int number;
public:
	book();
	book(string IBSN,string name, int price,string publisher,int number);
	book(const book& book);

	string getName();
	string getIBSN();
	int getPrice();
	string getPublisher();
	int getNumber();

	void set(string IBSN, string name, int price, string publisher, int number);
	
	~book();
};
#endif

