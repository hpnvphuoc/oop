#pragma once
#include"user.h"
class listBill
{
private:
	user *list;
	int numBill;
public:
	listBill();
	void addBill(user &usr);
	~listBill();
};

//Nguoi dung vao tim kiem sach,
//Khi tim thay thi add vao gio hang
//xem gio hang cua minh
//admin he thong co the xem duoc co bao nhieu nguoi da mua hang o cho minh