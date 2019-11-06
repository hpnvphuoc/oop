#include "listBook.h"

listBook::listBook()
{
	this->list = NULL;
	this->numKind = 0;
}

void listBook::inputList(int numKind)
{
	this->numKind = numKind;
	this->list = new book[numKind];
	string tempIBSN;
	string tempName;
	int tempPrice;
	string tempPublisher;
	int tempNumber;
	if (numKind != 0) {
		for (int i = 0; i < numKind; i++) {
			cout << "Sach " << i << endl;
			cin.ignore();
			cout << "Ma sach: ";
			getline(cin, tempIBSN);

			cout << "Ten: ";
			getline(cin, tempName);

			cout << "Gia sach: ";
			cin >> tempPrice;
			cin.ignore();

			cout << "Nha xuat ban: ";
			getline(cin, tempPublisher);

			cout << "So luong: ";
			cin >> tempNumber;
			cin.ignore();

			list[i].set(tempIBSN, tempName, tempPrice, tempPublisher, tempNumber);
		}
	}
	else {
		for (int i = 0; i < numKind; i++) {
			cout << "Sach " << i << endl;
			cin.ignore();
			cout << "Ma sach: ";
			getline(cin, tempIBSN);

			cout << "Ten: ";
			getline(cin, tempName);

			cout << "Gia sach: ";
			cin >> tempPrice;
			cin.ignore();

			cout << "Nha xuat ban: ";
			getline(cin, tempPublisher);

			cout << "So luong: ";
			cin >> tempNumber;
			cin.ignore();

			list[i].set(tempIBSN, tempName, tempPrice, tempPublisher, tempNumber);
		}
	}
	
}

void listBook::outputList() {
	cout << "STT" << setw(10) << "IBSN" << setw(10) << "TEN" << setw(10) << "GIA" << setw(10) << "NXB" << setw(10) << "SO LUONG" << endl;
	for (int i = 0; i < numKind; i++) {
		cout <<left << setw(8) << i <<left<<setw(10)<<list[i].getIBSN() <<left<<setw(15) <<list[i].getName() <<left<<setw(15) <<list[i].getPrice() <<left<<setw(15)<<list[i].getPublisher()<<left<<setw(15)<<list[i].getNumber()<< endl;
	}
}
void listBook::printElementI(int index)
{
	cout << "STT" << setw(10) << "IBSN" << setw(10) << "TEN" << setw(10) << "GIA" << setw(10) << "NXB" << setw(10) << "SO LUONG" << endl;
	cout << left << setw(8) << index << left << setw(10) << list[index].getIBSN() << left << setw(15) << list[index].getName() << left << setw(15) << list[index].getPrice() << left << setw(15) << list[index].getPublisher() << left << setw(15) << list[index].getNumber() << endl;
}
int listBook::getNumKind()
{
	return numKind;
}

int listBook::search(string name)
{

	for (int i = 0; i < this->numKind; i++) {
		if (this->list[i].getName() == name) {
			return i;
		}
	}
	return -1;
}

bool listBook::deleteBook(int index)
{
	if (index<0 || index>this->numKind) {
		return false;
	}
	for (int i = index; i < this->numKind-1; i++) {
		this->list[i]= this->list[i + 1];
	}
	this->numKind = this->numKind - 1;
	return true;
}
void listBook::addBook(book &b) {
	numKind = numKind + 1;
	if (list == NULL) {
		list = new book;
		*list =b ;
		return;
	}
	book* temp = new book[numKind];
	for (int i = 0; i < numKind - 1; i++) {
		temp[i] = list[i];
	}
	temp[numKind - 1] = b;
	delete[]list;
	list = temp;

}
void listBook::findBook()
{
	string temp;
	cout << "Nhap ten sach can tim";
	getline(cin, temp);
	for (int i = 0; i < this->numKind; i++) {
		if (this->list[i].getName() == temp) {
			cout << "STT" << setw(10) << "IBSN" << setw(10) << "TEN" << setw(10) << "GIA" << setw(10) << "NXB" << setw(10) << "SO LUONG" << endl;
			cout << left << setw(8) << i << left << setw(10) << list[i].getIBSN() << left << setw(15) << list[i].getName() << left << setw(15) << list[i].getPrice() << left << setw(15) << list[i].getPublisher() << left << setw(15) << list[i].getNumber() << endl;
		}
	}

}
book listBook::getBookI(int index)
{
	return list[index];
}
listBook::~listBook()
{
}
