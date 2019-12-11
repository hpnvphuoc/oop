#include "bill.h"

bill::bill()
{
}

bill::~bill()
{
}

void bill::addBill(listBook&list,int index,int number) {
	book b = list.getBookI(index);
	b.setNumber(number);
	bookList.addBook(b);
}

void bill::checkBill() {
	for (int i = 0; i < bookList.getNumKind(); i++) {
		bookList.outputList();
	}
}

listBook bill::getBill()
{
	return bookList;
}

void bill::setBill(listBook& list)
{
	bookList = list;
}

void bill::printBill()
{
	bookList.outputList();
}

//void bill::updateBill()
//{
//	b temp;
//	cout << "Nhap STT sach can cap nhat";
//	cin >> temp.index;
//	cout << "Nhap so luong moi";
//	cin >> temp.number;
//	list_bill[temp.index] = temp;
//	cout << "Cap nhat hoa don thanh cong" << endl;
//}

//void bill::deleteBill()
//{
//	int index;
//	cout << "Nhap vao STT sach muon xoa: ";
//	cin >> index;
//	list_bill.erase(list_bill.begin() + index);
//}

void bill::checkout()
{
	for (int i = 0; i < bookList.getNumKind(); i++) {
		total = total +bookList.getBookI(i).getNumber() * bookList.getBookI(i).getPrice();
	}
	cout << "Tong tien ban can phai thanh toan la: ";
	cout << total;
}

