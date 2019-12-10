#pragma once
#include"user.h"
struct bill {
	string username;
	string IBSN;
	int number;
	int price;
};
class listBill
{
private:
	vector<bill> list;
public:
	listBill();
	void WriteListBillToFile();
	void LoadListBillFormFile();
	void addBill(string username, string IBSN, int number, int price);
	~listBill();
};

//Nguoi dung vao tim kiem sach,
//Khi tim thay thi add vao gio hang
//xem gio hang cua minh
//admin he thong co the xem duoc co bao nhieu nguoi da mua hang o cho minh