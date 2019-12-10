#pragma once
#include"account.h"
#include<vector>
class admin:public account
{
private:
	vector<account> acc;
public:
	admin();
	~admin();
	vector<account> getAllAccount(const string file_name);
	void OutputListAccount();
	void AddAccount();
	void UpdateAccount();
	void DeleteAccount();
	void WriteListAccountToFile();
};

