#include"book.h"
#ifndef LISTBOOK_H_
#define LISTBOOK_H_
#include<iomanip>
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

	void inputList(int numKind);
	void outputList();
	int getNumKind();
	bool deleteBook(int index);
	void addBook(book&);
	book getBookI(int index);

	int findBookByName(string name);
	int findBookByPublisher(string publiser);
	int findBookByAuthor(string author);
	void printElementI(int index);

};

#endif // !LIST_BOOK_H_
