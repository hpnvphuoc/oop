#include "guest.h"
void guest::findbook(listBook& l, string name)
{
	int index = l.findBookByName(name);
	if (index!= -1) {
		l.printElementI(index);
	}
	else {
		cout << "Khong tim thay sach ";
	}
}



