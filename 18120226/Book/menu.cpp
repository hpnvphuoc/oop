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
	cout << "1. Dang nhap" << endl;
	cout <<"2. Dang ki " << endl;
	cout << "3. Thoat" << endl;
	cout << "Vui long chon lenh" << endl;
}

void menu::printUserMenu()
{
	cout << "1. Tim kiem sach" << endl;
	cout << "2. Mua sach" << endl;
	cout << "3. Kiem tra don hang" << endl;
	cout << "4. Xoa don hang" << endl;
	cout << "5. Cap nhat don hang" << endl;
	cout << "6. Tinh tong tien" << endl;
	cout << "7. Xem tin nhan" << endl;
	cout << "8. Nhan tin" << endl;
	cout << "9. Thoat" << endl;
}

void menu::printAdminMenu()
{
	cout << "1. Xem sach" << endl;
	cout << "2. Them sach" << endl;
	cout << "3. Xoa sach" << endl;
	cout << "4. Sua thong tin sach" << endl;
	cout << "5.Khoa sach" << endl;
	cout << "6. Mo khoa sach" << endl;
	cout << "7. Xem tin nhan" << endl;
	cout << "8. Nhan tin" << endl;
	cout << "9. Them tai khoan" << endl;
	cout << "10. Xoa tai khoan " << endl;
	cout << "11. Cap nhat tai khoan" << endl;
	cout << "12. Xuat danh sach nguoi dung" << endl;
	cout << "13. Xuat hoa don" << endl;
	cout << "14. Xem NXB co tien thanh toan nhieu nhat" << endl;
	cout << "15. Thoat" << endl;
}

void menu::printCommonMenu()
{
	
	cout << "1. Xem sach" << endl;
	cout << "2. Them sach" << endl;
	cout << "3. Xoa sach" << endl;
	cout << "4. Sua thong tin sach" << endl;
	cout << "5.Khoa sach" << endl;
	cout << "6. Mo khoa sach" << endl;
	cout << "7. Xem tin nhan" << endl;
	cout << "8. Nhan tin" << endl;
	cout << "9. Xem sach ban chay nhat" << endl;
	cout << "10.Thoat" << endl;

}

void menu::printMenu()
{
	cout << "1. Mua sach" << endl;;
	cout << "2. Kiem tra gio hang" << endl;
	cout << "3. Quay lai menu chinh" << endl;
	cin >> tempCommand;
}
