#include "bill.h"

bill::bill()
{
}

bill::~bill()
{
}

void bill::addBill(book &book) {
	list.addBook(book);
}

void bill::checkBill() {
	list.outputList();
}

