#pragma once
#include<iostream>
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
	void printUserMenu();
	void printAdminMenu();
	void printCommonMenu();

	void printMenu();
//	void printAdminMenu();
};

