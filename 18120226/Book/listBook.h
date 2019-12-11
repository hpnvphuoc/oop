#include"book.h"
#ifndef LISTBOOK_H_
#define LISTBOOK_H_
#include<iomanip>
#include<vector>
#include"message.h"
class listBook
{
private:
	book *list;
	int numKind;
public:
	listBook();
	~listBook();
	void readListBookFromFile();
	void writeListBookToFile();

	void createListbook(book*& list);
	void inputList(int numKind);
	void outputList(int role=-1,bool header=true);
	int getNumKind();
	bool deleteBook(int index);
	void addBook(book&);
	void updateBook(int index,book& newbook);
	book getBookI(int index);
	void BlockBookI(int index,int role);
	void UnBlockBookI(int index);


	vector<int> findBookByName(string name);
	vector<int> findBookByPublisher(string publiser);
	vector<int> findBookByAuthor(string author);

	void printElementI(int index, int role = 0, bool title = true );
	void printHeader();
	void printNameBookI(int index);


};

#endif // !LIST_BOOK_H_
