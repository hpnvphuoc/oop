#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include"listBook.h"
class account
{
protected:
	string ID;
	string username;
	string password;
	string name;
	int role;
	vector<message> mess;
	vector<int> bookList;
public:
	account();
	~account();
	int GetRole();
	string GetID();
	string GetName();
	void login(string &file_name);
	string generateID();
	account* CheckLogin(const string &file_name,string &UserName,string &Password);
	
	void SetAccount(string ID, string username, string password, string name,int role);
	void CreateAccount(account&account);
	void WriteMessage(string name);
	void ReadMessage(string receiver);

	void CheckBook(listBook& list);
	virtual void GetBook(listBook& list);

	void AddBook(listBook& list);
	void DeleteBook(listBook& list);
	void UpdateBook(listBook& list);
	void BlockBook(listBook& list, int index);
	void UnBlockBook(listBook& list, int index);

	void setName(string name);
	string GetUsername();
	string GetPassword();

	void setPassword(string newPass);
	string GetAccountType(int role);
	static void SignUp();
};

#endif // !ACCOUNT_H_



