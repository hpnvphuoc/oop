#include "guest.h"
int guest::FindBookByName(listBook& list, string name) {
	int index=-1;
	vector<int> temp = list.findBookByName(name);
		if (temp.size() > 1) {
						cout << "Vui long nhap ma sach can tim";
						string tempIBSN;
						getline(cin, tempIBSN);
						for (int i = 0; i < temp.size(); i++) {
							if (tempIBSN == list.getBookI(temp[i]).getIBSN()) {
								index = temp[i];
								break;
							}
						}
					}
		else {
						if (temp.size() == 1) {
							index = temp[0];
							list.printElementI(index);
						}
						else {
							index = -1;
							cout << "Khong tim thay sach";
						}
					}
	return index;
}


