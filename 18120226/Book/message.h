#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<vector>
class message
{
private:
	string sender;
	string receiver;
	string content;
public:
	static string cutstring(string& s);
	void SetReceiver(string receiver);
	static void SendMessage(string sender);
	static vector<message> RecieveMessage(string receiver);
	void PrintMessage(message message);

	string GetSender();
	string GetReceiver();
	string GetContent();
};

