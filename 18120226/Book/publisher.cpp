#include "publisher.h"

publisher::publisher()
{
}

publisher::~publisher()
{
}

publisher*  publisher::readPublisherFromFile()
{
	int n;
	string tempPublisher;
	string number;
	fstream f;
	string tempID;
	string tempUsername;
	string tempPassword;
	string tempName;
	f.open("publiser.txt", ios::in);
	getline(f, number);
	n = stoi(number);
	publisher* temp = new publisher[n];
	for(int i=0;i<n;i++){
		getline(f, tempPublisher);
		tempID = message::cutstring(tempPublisher);
		tempUsername = message::cutstring(tempPublisher);
		tempPassword = message::cutstring(tempPublisher);
		tempName = message::cutstring(tempPublisher);
		temp[i].CreatePublisher(tempID, tempUsername, tempPassword, tempName);
	}
	f.close();
	return temp;
}

void publisher::writePublisherToFile(publisher *list,int number) {
	fstream f;
	f.open("publiser.txt", ios::out);
	f << number;
	for (int i = 0; i < number; i++) {
		f << list[i].ID << list[i].username << list[i].password << list[i].name << endl;
	}
}

string publisher::getUsername()
{
	return this->username;
}

string publisher::getName()
{
	return this->name;
}

string publisher::getPassword()
{
	return this->password;
}

string publisher::getID()
{
	return this->ID;
}

void publisher::setName(string name)
{
	this->name = name;
}

void publisher::CreatePublisher(string& ID, string& Username, string& Password, string& name)
{
	if ("" == ID) {
		 this->ID= generateID();
	}
	this->username = Username;
	this->password = Password;
	this->name = name;
}

void publisher::GetBook(listBook& list)
{
	bookList = list.findBookByPublisher(this->name);
}

void publisher::CheckBook(listBook& list) {
	cout << "STT" << setw(10) << "IBSN" << setw(10) << "TEN" << setw(15) << "GIA" << setw(20) << "NHA XUAT BAN" << setw(15) << "SO LUONG" << setw(15) << "TAC GIA" << endl;
	for (int i = 0; i < bookList.size(); i++) {
		list.printElementI(bookList[i], 0, false);
		list.printElementI(bookList[i], role, false);
	}
}