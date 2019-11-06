#pragma once
#include<iostream>
#include"list_book.h"
#include"listBill.h"
#include"user.h"
using namespace std;
class menu
{
private: 
	int command;
	int tempCommand;
public:
	menu();
	~menu();
	void printMainMenu();
	void printMenu();
	void funRunMenu();
	void printAdminMenu();
};

