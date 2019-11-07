#ifndef BOOK_H_
#define BOOK_H_
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class book
{
private:
	string IBSN;
	string name;
	int price;
	int publisher;
	int number;
	int author;
public:
	book();
	book(string IBSN,string name, int price,int publisher,int number,int author);
	book(const book& book);

	string getName();
	string getIBSN();
	int getPrice();
	string getPublisher();
	int getNumber();
	string getAuthor();

	void set(string IBSN, string name, int price, int publisher, int number,int author);
	
	~book();
};
#endif

