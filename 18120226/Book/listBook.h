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

	void inputList(int numKind);
	void outputList();
	void printElementI(int index);
	int getNumKind();
	int search(string name);
	bool deleteBook(int index);
	void addBook(book&);
	void findBook();
	book getBookI(int index);
};

#endif // !LIST_BOOK_H_
