#include"book.h"
#ifndef LIST_BOOK_H_
#define LIST_BOOK_H_
class list_book
{
private:
	book *list;
	
public:
	list_book();
	void inputList(int number);
	void outputList(int number);
	~list_book();
};

#endif // !LIST_BOOK_H_
