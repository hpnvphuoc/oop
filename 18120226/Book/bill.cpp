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
	bookList.outputList();
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

void bill::updateBill()
{
	int index;
	int number;
	cout << "Nhap STT sach can cap nhat";
	cin >> index;
	cout << "Nhap so luong moi";
	cin >> number;
	book temp = bookList.getBookI(index);
	temp.setNumber(number);
	bookList.updateBook(index,temp);
	cout << "Cap nhat hoa don thanh cong" << endl;
}

void bill::deleteBill()
{
	int index;
	cout << "Nhap vao STT sach muon xoa: ";
	cin >> index;
	bookList.deleteBook(index);
}

void bill::checkout()
{
	for (int i = 0; i < bookList.getNumKind(); i++) {
		total = total +bookList.getBookI(i).getNumber() * bookList.getBookI(i).getPrice();
	}
	cout << "Tong tien ban can phai thanh toan la: " << endl;
	cout << total;
}

listBook bill::getItem()
{
	return this->bookList;
}

