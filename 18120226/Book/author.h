#pragma once
#include"account.h"
class author :public account
{
private:
public:
	author();
	~author();
	void CheckBook(listBook& list);
	void GetBook(listBook& list);

};

//Them xoa sua sach cua minh