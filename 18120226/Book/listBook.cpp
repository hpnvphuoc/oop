#include "listBook.h"

listBook::listBook()
{
	this->list = NULL;
	this->numKind = 0;
}

listBook::listBook(book*& list,int number)
{
	this->list = list;
	this->numKind = number;
}

void listBook::inputList(int numKind)
{
	this->numKind += numKind;
	book* temp = new book[this->numKind];
	for (int i = 0; i < this->numKind - numKind; i++) {
		temp[i] = list[i];
	}
	for (int i = 0; i < this->numKind - numKind; i++) {
		list[i].~book();
	}
	list = temp;
	string tempIBSN;
	string tempName;
	int tempPrice;
	string tempPublisher;
	int tempNumber;
	string tempAuthor;
	for (int i = this->numKind-numKind; i < this->numKind; i++) {
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
			getline(cin,tempPublisher);

			cout << "So luong: ";
			cin >> tempNumber;
			cin.ignore();

			cout << "Tac gia: ";
			getline(cin,tempAuthor);

			list[i].set(tempIBSN, tempName, tempPrice, tempPublisher, tempNumber,tempAuthor,false);
		}
}
	

void listBook::outputList(int role,bool header) {
	if (header) {
		cout << "STT" << setw(9) << "IBSN" << setw(10) << "TEN" << setw(15) << "GIA" << setw(23) << "NHA XUAT BAN" << setw(15) << "SO LUONG" << setw(15) << "TAC GIA" << endl;
	}
	
	if(-1==role){
		for (int i = 0; i < numKind; i++) {
			cout << left << setw(8) << i << left << setw(10) << list[i].getIBSN() << left << setw(15) << list[i].getName() << left << setw(15) << list[i].getPrice() << left << setw(20) << list[i].getPublisher() << left << setw(15) << list[i].getNumber() << left << setw(5) << list[i].getAuthor() << endl;
		}
	}
	else {
		for (int i = 0; i < numKind; i++) {
			if(list[i].IsBlock()==role)
			cout << left << setw(8) << i << left << setw(10) << list[i].getIBSN() << left << setw(15) << list[i].getName() << left << setw(15) << list[i].getPrice() << left << setw(20) << list[i].getPublisher() << left << setw(15) << list[i].getNumber() << left << setw(5) << list[i].getAuthor() << endl;
		}
	}
	
}
void listBook::printElementI(int index,int role,bool header)
{
	if (header) {
		cout << setw(8) << "STT" << setw(10) << "IBSN" << setw(15) << "TEN" << setw(15) << "GIA" << setw(20) << "NHA XUAT BAN" << setw(15) << "SO LUONG" << setw(15) << "TAC GIA" << endl;
	}
	if (list[index].IsBlock() == role) {//in ra sach bi block boi ai do
		cout << left << setw(8) << index << left << setw(10) << list[index].getIBSN() << left << setw(15) << list[index].getName() << left << setw(15) << list[index].getPrice() << left << setw(20) << list[index].getPublisher() << left << setw(15) << list[index].getNumber() << left << setw(5) << list[index].getAuthor() << endl;

	}
		
}
void listBook::printHeader()
{
	cout << setw(8) << "STT" << setw(10) << "IBSN" << setw(15) << "TEN" << setw(15) << "GIA" << setw(20) << "NHA XUAT BAN" << setw(15) << "SO LUONG" << setw(15) << "TAC GIA" << endl;

}
void listBook::printNameBookI(int index)
{
	cout <<setw(20)<< list[index].getName();
}
listBook listBook::concatenate(listBook& list)
{
	int temNumKind = numKind + list.getNumKind();
	book* temp = new book[temNumKind];
	for (int i = 0; i < this->numKind; i++)
	{
		temp[i] = this->list[i];
	}
	for (int i = numKind; i < temNumKind; i++) {
		temp[i] = list.getBookI(i-numKind);
	}
	listBook bookList(temp, temNumKind);
	return bookList;
}
int listBook::getNumKind()
{
	return numKind;
}

vector<int> listBook::findBookByName(string name)
{
	vector<int> temp;
	for (int i = 0; i < this->numKind; i++) {
		if (this->list[i].getName() == name) {
			temp.push_back(i);
		}
	}
	return temp;
}

vector<int> listBook::findBookByPublisher(string publisher)
{
	vector<int> temp;
	for (int i = 0; i < this->numKind; i++) {
		if (this->list[i].getPublisher()==publisher ) {
			temp.push_back(i);
		}
	}
	return temp;

}

vector<int> listBook::findBookByAuthor(string author)
{
	vector<int> temp;
	for (int i = 0; i < this->numKind; i++) {
		if (this->list[i].getAuthor()== author) {
			temp.push_back(i);
		}
	}
	return temp;
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

void listBook::updateBook(int index,book& newbook)
{
	list[index] = newbook;
}

book listBook::getBookI(int index)
{
	return list[index];
}
void listBook::BlockBookI(int index,int role)
{
	list[index].Block(role);
}
void listBook::UnBlockBookI(int index)
{
	list[index].UnBlock();
}
listBook::~listBook()
{
	//if (list != nullptr) {
	//	delete[]list;
	//	list = NULL;
	//	this->numKind = 0;
	//}
}

void listBook::readListBookFromFile(const string file_name)
{
	string tempNumkind;
	string tempBook;
	string tempIBSN;
	string tempName;
	int tempPrice;
	string tempPublisher;
	int tempNumber;
	string tempAuthor;
	bool tempIsBlock;
	fstream f;
	f.open(file_name, ios::in);
	getline(f, tempNumkind);
	numKind = stoi(tempNumkind);
	this->list = new book[numKind];
	for(int i=0;i<numKind;i++){
		getline(f,tempBook);
		tempIBSN = message::cutstring(tempBook);
		tempName = message::cutstring(tempBook);
		tempPrice = stoi(message::cutstring(tempBook));
		tempPublisher = message::cutstring(tempBook);
		tempNumber = stoi(message::cutstring(tempBook));
		tempAuthor = message::cutstring(tempBook);
		tempIsBlock = stoi(message::cutstring(tempBook));
		list[i].set(tempIBSN, tempName, tempPrice, tempPublisher, tempNumber, tempAuthor,tempIsBlock);
	}
	f.close();
}

void listBook::writeListBookToFile()
{
	fstream f;
	f.open("listbook.txt", ios::out);
	f <<numKind<<endl;
	for (int i = 0; i < numKind; i++) {
		f << list[i].getIBSN() << "," << list[i].getName() << "," << list[i].getPrice() << "," << list[i].getPublisher() << "," << list[i].getNumber() << "," << list[i].getAuthor() <<","<<list[i].IsBlock()<< endl;
	}
	f.close();
}
