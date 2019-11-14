#pragma once

#include"listBook.h"
class guest
{
private:
	string username;
	string password;
	string name;
	bool IsLogin;
public:
	virtual void login()=0;
	bool IsLogin();
};

