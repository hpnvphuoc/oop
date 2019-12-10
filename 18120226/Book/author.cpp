#include "author.h"

author::author()
{
}


author::~author()
{
}

void author::GetBook(listBook& list)
{
	bookList = list.findBookByAuthor(this->name);
}

void author::CheckBook(listBook& list) {
	cout <<"STT" << setw(10) << "IBSN" << setw(10) << "TEN" << setw(15) << "GIA" << setw(20) << "NHA XUAT BAN" << setw(15) << "SO LUONG" << setw(15) << "TAC GIA" << endl;
	for (int i = 0; i < bookList.size(); i++) {
		list.printElementI(bookList[i], 0, false);
		list.printElementI(bookList[i], role, false);
	}
}