#pragma once
#include"listBook.h"
#include"menu.h"
#include"user.h"
#include"publisher.h"
#include"author.h"
#include"admin.h"
#include"listBill.h"
class process
{
private:
	listBook list;
	account usr;
	listBill bill;
	int role;
	int command;
	int tempCommand;
	menu menu;
public:
	process();
	~process();
	int GetRole();
	account* login(const string& file_name);
	void LoadData();
	void Process();
	//void UpdateData();
};

