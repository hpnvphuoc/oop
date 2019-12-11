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
	string publisher;
	int number;
	string author;
	int isBlock;//1: admin, 2: publisher,3: author,4:user 
public:
	book();
	~book();
	book(string IBSN,string name, int price,string publisher,int number,string author);
	book(const book& book);

	string getName();
	string getIBSN();
	int getPrice();
	string getPublisher();
	int getNumber();
	string getAuthor();
	int IsBlock();
	void setNumber(int number);;
	void Block(int role);
	void UnBlock();
	void set(string IBSN, string name, int price, string publisher, int number,string author,bool isBlock);
	
	void CreateBook();
};
#endif

