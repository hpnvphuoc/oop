#pragma once
#include"account.h"
#include<iostream>
#include"book.h"
using namespace std;
class publisher:public account
{
private:
	vector<int> bookList;
public:
	publisher();

	void writePublisherToFile(publisher* list, int number);
	publisher* readPublisherFromFile();
	
	string getUsername();
	string getName();
	string getPassword();
	string getID();

	void setName(string name);

	void CreatePublisher(string& ID, string& Username, string& Password, string& name);
	void CheckBook(listBook& list);
	void GetBook(listBook& list);

	~publisher();
};

//them  xoa sua sach cua NXB minh