#include "menu.h"
menu::menu()
{
	command = 0;
	tempCommand = 0;
}
menu::~menu()
{
	command = 0;
	tempCommand = 0;
}
void menu::printMainMenu() {
	cout << "1. Nhap sach" << endl;
	cout <<"2. Tim kiem sach " << endl;
	cout << "3. Thoat" << endl;
	cout << "Vui long chon lenh" << endl;
	cin >> command;
}

void menu::funRunMenu() {
	listBook listBook;
	listBill listBill; 
	while (3!=command)
	{
		printMainMenu();
		if (0 > command || 4 < command) {
			cout << "Lenh khong hop le. Vui long nhap lai";
			cin >> command;
		}
		if (1 == command) {//Nhap sach
			int numKind;
			cout << "Nhap so loai sach can nhap";
			cin >> numKind;
			//check xem danh sach co rong hay khong
			if (listBook.getNumKind() != 0) {
				numKind = listBook.getNumKind() + numKind;
			}
			listBook.inputList(numKind);
			printMainMenu();
		}
		if (2 == command) {//Guest user tim sach va quyet dinh co mua sach hay khong

			//tim va luu lai sach ma khach hang tim kiem
			int index = -1;
			string tempName;
			cout << "Nhap ten sach can tim:" << endl;
			cin.ignore();
			getline(cin, tempName);
			index = listBook.findBookByName(tempName);
			
			if (index == -1) {
				cout << "Khong tim thay sach";
			}
			else {
				listBook.printElementI(index);
				book temp = listBook.getBookI(index);
				//kiem tra xem khach hang co mua sach hay khong
				user user;
				while (tempCommand != 3) {
					printMenu();
					if (1 == tempCommand) {
						if (user.checkLogin()) {
							user.addBill(temp);
							listBill.addBill(user);
						}
						else {
							cout << "Vui long dang nhap";
							user.login();
							user.addBill(temp);
							listBill.addBill(user);

						}
						
					}
					if (2 == tempCommand) {
						if (user.checkLogin()) {
							user.checkBill();
						}
						else {
							cout << "Vui long dang nhap";
							user.login();
							user.checkBill();

						}
					}

				}
			}
			
		}
		
	}
}

void menu::printMenu()
{
	cout << "1. Mua sach" << endl;;
	cout << "2. Kiem tra gio hang" << endl;
	cout << "3. Quay lai menu chinh" << endl;
	cin >> tempCommand;
}
