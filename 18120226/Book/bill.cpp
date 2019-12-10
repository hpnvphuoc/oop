#include "bill.h"

bill::bill()
{
}

bill::~bill()
{
}

int bill::addBill(listBook&list ,int index) {
	if (index != 0) {
		b bill;
		bill.index=index;
		cout << "Nhap vao so luong muon mua: ";
		cin >> bill.number;
		bill.price = list.getBookI(bill.index).getPrice();
		list_bill.push_back(bill);
		return bill.number;
	}
	list.outputList();
	b bill;
	cout << "Nhap vao STT sach can mua: ";
	cin >> bill.index;
	cout << "Nhap vao so luong muon mua: ";
	cin >> bill.number;
	bill.price=list.getBookI(bill.index).getPrice();
	list_bill.push_back(bill);
	return bill.number;
}

void bill::checkBill(listBook &list) {
	cout << setw(20)<< "STT" << setw(20) << "Ten sach" << left << setw(15) << "So luong" << endl;
	for (int i = 0; i < list_bill.size(); i++) {
		cout << setw(20)<<i;
		list.printNameBookI(list_bill[i].index);
		cout << left << setw(20) << list_bill[i].number << endl;
	}
}

void bill::updateBill()
{
	b temp;
	cout << "Nhap STT sach can cap nhat";
	cin >> temp.index;
	cout << "Nhap so luong moi";
	cin >> temp.number;
	list_bill[temp.index] = temp;
	cout << "Cap nhat hoa don thanh cong" << endl;
}

void bill::deleteBill()
{
	int index;
	cout << "Nhap vao STT sach muon xoa: ";
	cin >> index;
	list_bill.erase(list_bill.begin() + index);
}

void bill::checkout()
{
	for (int i = 0; i < list_bill.size(); i++) {
		total = total + list_bill[i].number * list_bill[i].price;
	}
	cout << "Tong tien ban can phai thanh toan la: ";
	cout << total;
}

