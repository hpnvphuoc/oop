using namespace std;
#include "user.h"
user::user()
{	
}

user::~user()
{
}

void user::addBill(book& book) {
	userBill.addBill(book);
}

void user::checkBill() {
	userBill.checkBill();
}
