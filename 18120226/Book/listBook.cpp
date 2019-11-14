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
	string tempAuthor;
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
			cin>> tempPublisher;

			cout << "So luong: ";
			cin >> tempNumber;
			cin.ignore();

			cout << "Tac gia: ";
			cin >> tempAuthor;

			list[i].set(tempIBSN, tempName, tempPrice, tempPublisher, tempNumber,tempAuthor);
		}
}
	

void listBook::outputList() {
	cout << "STT" << setw(9) << "IBSN" << setw(9) << "TEN" << setw(15) << "GIA" << setw(24) << "NHA XUAT BAN" << setw(15) << "SO LUONG" <<setw(15)<<"TAC GIA"<< endl;
	for (int i = 0; i < numKind; i++) {
		cout <<left << setw(8) << i <<left<<setw(10)<<list[i].getIBSN() <<left<<setw(15) <<list[i].getName() <<left<<setw(15) <<list[i].getPrice() <<left<<setw(20)<<list[i].getPublisher()<<left<<setw(15)<<list[i].getNumber()<<left<<setw(5)<<list[i].getAuthor()<< endl;
	}
}
void listBook::printElementI(int index)
{
	cout <<setw(8)<< "STT" << setw(10) << "IBSN" << setw(15) << "TEN" << setw(15) << "GIA" << setw(20) << "NHA XUAT BAN" << setw(15) << "SO LUONG" << setw(15) << "TAC GIA" << endl;
	cout << left << setw(8) << index << left << setw(10) << list[index].getIBSN() << left << setw(15) << list[index].getName() << left << setw(15) << list[index].getPrice() << left << setw(20) << list[index].getPublisher() << left << setw(15) << list[index].getNumber() << left << setw(5) << list[index].getAuthor() << endl;
}
int listBook::getNumKind()
{
	return numKind;
}

int listBook::findBookByName(string name)
{

	for (int i = 0; i < this->numKind; i++) {
		if (this->list[i].getName() == name) {
			return i;
		}
	}
	return -1;
}

int listBook::findBookByPublisher(string publiser)
{
	for (int i = 0; i < this->numKind; i++) {
		if (this->list[i].getPublisher() == publiser) {
			return i;
		}
	}
	return -1;

}

int listBook::findBookByAuthor(string author)
{
	for (int i = 0; i < this->numKind; i++) {
		if (this->list[i].getAuthor()== author) {
			return i;
		}
	}
	return -1;

	return 0;
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
	for (int i = 0; i < numKind-1; i++) {
		list[i].~book();
	}
	list = temp;

}

book listBook::getBookI(int index)
{
	return list[index];
}
listBook::~listBook()
{
}

string cutstring(string& s) {
	int pos = s.find(',');
	string a;
	a = s.substr(0, pos);
	s.erase(0, pos + 1);
	return a;
}

void listBook::readListBookFromFile()
{
	string tempNumkind;
	string tempBook;
	string tempIBSN;
	string tempName;
	int tempPrice;
	string tempPublisher;
	int tempNumber;
	string tempAuthor;
	fstream f;
	f.open("listBook.txt", ios::in);
	getline(f, tempNumkind);
	numKind = stoi(tempNumkind);
	this->list = new book[numKind];
	for(int i=0;i<numKind;i++){
		getline(f,tempBook);
		tempIBSN = cutstring(tempBook);
		tempName = cutstring(tempBook);
		tempPrice = stoi(cutstring(tempBook));
		tempPublisher = cutstring(tempBook);
		tempNumber = stoi(cutstring(tempBook));
		tempAuthor = cutstring(tempBook);
		list[i].set(tempIBSN, tempName, tempPrice, tempPublisher, tempNumber, tempAuthor);
	}
	f.close();
}

void listBook::writeListBookToFile()
{
	fstream f;
	f.open("listbook.txt", ios::out);
	f <<numKind<<endl;
	for (int i = 0; i < numKind; i++) {
		f << list[i].getIBSN() << "," << list[i].getName() << "," << list[i].getPrice() << "," << list[i].getPublisher() << "," << list[i].getNumber() << "," << list[i].getPublisher() << endl;
	}
	f.close();
}
