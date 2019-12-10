#include "message.h"

void message::SetReceiver(string receiver)
{
	this->receiver = receiver;
}

void message::SendMessage(string sender)
{
	string receiver;
	cout << "Nhap ten nguoi nhan ";
	cin.ignore();
	getline(cin, receiver);
	string content;
	cout << "Noi dung: ";
	getline(cin, content) ;
	fstream f;
	f.open("message.txt", ios::out);
	f << receiver << "," << sender << "," << content << endl;
	f.close();
}
string message::cutstring(string& s) {
	if (s == "") {
		return "0";
	}
	int pos = s.find(',');
	string a;
	a = s.substr(0, pos);
	s.erase(0, pos + 1);
	return a;
}


vector<message> message::RecieveMessage(string receiver)
{
	fstream f;
	f.open("message.txt", ios::in);
	string temp;
	string tempSender;
	string tempReceiver;
	string tempContent;
	vector<message> list_message;
	while (!f.eof()) {
		getline(f, temp);
		tempReceiver = cutstring(temp);
		if (tempReceiver == receiver) {
			tempSender = cutstring(temp);
			tempContent = cutstring(temp);
			message m;
			m.receiver = tempReceiver;
			m.sender = tempSender;
			m.content = tempContent;
			list_message.push_back(m);
		}
	}
	return list_message;
}

void message::PrintMessage(message message)
{
		cout << "From: " << message.GetSender() << endl;
		cout << "To: " << message.GetReceiver() << endl;
		cout << "Content: " << message.GetContent() << endl;
}

string message::GetSender()
{
	return this->sender;
}

string message::GetReceiver()
{
	return this->receiver;
}

string message::GetContent()
{
	return this->content;
}
