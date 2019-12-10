#include "process.h"

process::process()
{
	command = 0;
	tempCommand = 0;
}

process::~process()
{
}
void process::LoadData()
{
	list.readListBookFromFile();
}
account* process::login(const string& file_name)
{
	cout << "Username: ";
	string username;
	cin.ignore();
	getline(cin, username);
	cout << "Password: ";
	string pass;
	getline(cin, pass);
	return usr.CheckLogin(file_name, username, pass);

}
void process::Process()
{
	while (3 != command)
	{
		menu.printMainMenu();
		cin >> command;
		if (0 > command || 4 < command) {
			cout << "Lenh khong hop le. Vui long nhap lai";
			cin >> command;
		}
		if (1 == command) {//Dang nhap
			cout << "Vui long dang nhap" << endl;
			account* temp = login("account.txt");
			cout << temp->GetID();
			usr.CreateAccount(*temp);
			//cout << usr.GetID() << endl;
			while (usr.GetID() == "") {
				cout << "Tai khoan hoac mat khau khong chinh xac" << endl;
				cout << "Vui long dang nhap lai";
				temp=login("account.txt");
				usr.CreateAccount(*temp);
			}
			role = usr.GetRole();
			switch (role)
			{
			case 1://admin
			{
				admin ad;
				ad.CreateAccount(usr);
				ad.getAllAccount("account.txt");
				while (tempCommand != 12) {
					menu.printAdminMenu();
					cin >> tempCommand;
					switch (tempCommand)
					{
					case 1: {
						list.outputList();
						break;
					}//xem sach cua minh

					case 2://them sach cua minh
					{int number;
					cout << "Nhap so sach can them :";
					cin >> number;
					list.inputList(number);
					cout << "Them sach thanh cong" << endl;
					break;
					}
					case 3:
					{//xoa sach cua minh
						list.outputList();
						int index;
						cout << "Nhap so thu tu sach muon xoa" << endl;
						cin >> index;
						list.deleteBook(index);
						cout << "Xoa sach thanh cong" << endl;
						break;
					}
					case 4://update sach
					{
						int index;
						cout << "Nhap STT sach can cap nhat";
						cin >> index;
						book temp;
						temp.CreateBook();
						list.updateBook(index, temp);
						cout << "Cap nhat sach thanh cong" << endl;
						break;
					}
					case 5://block sach;
					{
						int index;
						cout << "Chon STT sach can khoa: ";
						cin >> index;
						list.BlockBookI(index, role);
						cout << "Khoa sach thanh cong" << endl;
						break;
					}
					case 6: //mo khoa sach
					{
						int index;
						cout << "Chon STT sach can mo khoa: ";
						cin >> index;
						list.UnBlockBookI(index);
						break;
					}
					case 7://xem tin nhan
					{
						ad.ReadMessage(ad.GetName());
						break;
					}
					case 8: //Nhan tin nhan
					{
						ad.WriteMessage(ad.GetName());
						cout << "Gui thu thanh cong" << endl;
						break;
					}
					case 9://Them tai khoan
					{
						ad.AddAccount();
						cout << "Them tai khoan thanh cong" << endl;
						break;
					}
					case 10://Xoa tai khoan
					{
						ad.OutputListAccount();
						ad.DeleteAccount();
						cout << "Xoa tai khoan thanh cong" << endl;
						break;
					}
					case 11: //cap nhat tai khoan 
					{
						ad.OutputListAccount();
						ad.UpdateAccount();
						cout << "Cap nhat tai khoan thanh cong" << endl;
						break;
					}
					case 12: {
						list.writeListBookToFile();
						ad.WriteListAccountToFile();
						break;
					}
					default:
						break;
					}
				}
			}



			case 2: //publisher
			{
				publisher pub;
				pub.CreateAccount(usr);
				while (tempCommand != 9) {
					menu.printCommonMenu();
					cin >> tempCommand;
					pub.GetBook(list);
					switch (tempCommand)
					{
					case 1://xem sach cua minh
					{
						pub.CheckBook(list);
						break;
					}
					case 2://cap nhat sach cua minh
					{
						pub.AddBook(list);
						cout << "Them sach thanh cong" << endl;
						break;
					}
					case 3://xoa sach cua minh
					{
						pub.DeleteBook(list);
						cout << "Xoa sach thanh cong" << endl;
						break;
					}
					case 4://update sach
					{
						pub.UpdateBook(list);
						cout << "Cap nhat sach thanh cong" << endl;
						break;
					}
					case 5://block sach;
					{
						int index;
						cout << "Chon STT sach can khoa: ";
						cin >> index;
						pub.BlockBook(list, index);
						break;
					}
					case 6: //mo khoa sach
					{
						int index;
						cout << "Chon STT sach can mo khoa: ";
						cin >> index;
						pub.UnBlockBook(list, index);
						break;
					}
					case 7://xem tin nhan
					{
						pub.ReadMessage(usr.GetName());
						break;
					}
					case 8: //Nhan tin nhan
					{
						pub.WriteMessage(pub.GetName());
						cout << "Gui thu thanh cong" << endl;
						break;
					}
					case 9:
					{
						list.writeListBookToFile();
						break;
					}
					default:
						break;
					}
				}
			}



			case 3://author
			{
				author auth;
				auth.CreateAccount(usr);
				while (tempCommand != 9) {
					menu.printCommonMenu();
					cin >> tempCommand;
					auth.GetBook(list);
					switch (tempCommand)
					{
					case 1://xem sach cua minh
					{
						auth.CheckBook(list);
						break;
					}
					case 2://cap nhat sach cua minh
					{
						auth.AddBook(list);
						cout << "Them sach thanh cong" << endl;
						break;
					}
					case 3://xoa sach cua minh
					{
						auth.DeleteBook(list);
						cout << "Xoa sach thanh cong" << endl;
						break;
					}
					case 4://update sach
					{
						auth.UpdateBook(list);
						cout << "Cap nhat sach thanh cong" << endl;
						break;
					}
					case 5://block sach;
					{
						int index;
						cout << "Chon STT sach can khoa: ";
						cin >> index;
						auth.BlockBook(list, index);
						break;
					}
					case 6: //mo khoa sach
					{
						int index;
						cout << "Chon STT sach can mo khoa: ";
						cin >> index;
						auth.UnBlockBook(list, index);
						break;
					}
					case 7://xem tin nhan
					{
						usr.ReadMessage(usr.GetName());
						break;
					}
					case 8: //Nhan tin nhan
					{
						auth.WriteMessage(auth.GetName());
						cout << "Gui thu thanh cong" << endl;
						break;
					}
					case 9: {
						list.writeListBookToFile();
						break;
					}
					default:
						break;
					}

				}

			}
			case 4://user 
			{
				user u;
				listBill b;
				b.LoadListBillFormFile();
				while (tempCommand != 9) {
					menu.printUserMenu();
					cin >> tempCommand;
					switch (tempCommand)
					{
					case 1://Tim sach
					{
						list.outputList(0);
						string name;
						cout << "Nhap ten sach can tim" << endl;
						cin.ignore();
						getline(cin, name);
						int index=u.FindBookByName(list, name);
						bool isBuy;
						cout << "Ban co muon mua sach nay khong" << endl;
						cout << "1. Co" << endl;
						cout << "2. Khong" << endl;
						cin >> isBuy;
						if (isBuy == 1) {
							u.CreateUser(temp->GetID(), temp->GetUsername(), temp->GetPassword(), temp->GetName());
							b.addBill(temp->GetUsername(), list.getBookI(index).getIBSN(), u.addBill(list, index), list.getBookI(index).getPrice());

						}
						break;
					}
					case 2://mua sach
					{
						
						b.addBill(temp->GetUsername(), list.getBookI().getIBSN(), u.addBill(list), list.getBookI(index).getPrice());
						cout << "Mua sach thanh cong" << endl;
						break;
					}
					case 3://kiem tra hoa don
					{
						u.checkBill(list);
						break;
					}
					case 4://xoa don hang sach
					{
						u.DeleteBill();
						cout << "Xoa don hang thanh cong" << endl;
						break;
					}
					case 5://cap nhat don hang sach;
					{
						u.updateBill();
						break;
					}
					case 6: //tinh tong tien sach
					{
						u.checkoutBill();
						break;
					}
					case 7://xem tin nhan
					{
						u.ReadMessage(u.GetName());
						break;
					}
					case 8: //Nhan tin nhan
					{
						u.WriteMessage(u.GetName());
						cout << "Gui thu thanh cong" << endl;
						break;
					}
					default:
						break;
					}
				}

				
			}
			default:
				break;
			}
		}
		else {
		}
		//else {
		//	if (2 == command) {
		//		guest* u=new guest;
		//		int index=-1;
		//		list.outputList(0);
		//		while (4 != tempCommand) {
		//			menu.printUserMenu();
		//			cin >> tempCommand;
		//			if (1 == tempCommand) {
		//				string temp_name;
		//				cout << "Vui long nhap ten sach can tim: " << endl;
		//				cin.ignore();
		//				getline(cin, temp_name);
		//				vector<int> temp = list.findBookByName(temp_name);
		//				if (temp.size() > 1) {
		//					cout << "Vui long nhap ma sach can tim";
		//					string tempIBSN;
		//					getline(cin, tempIBSN);
		//					for (int i = 0; i < temp.size(); i++) {
		//						if (tempIBSN == list.getBookI(temp[i]).getIBSN()) {
		//							index = temp[i];
		//							break;
		//						}
		//					}
		//				}
		//				else {
		//					if (temp.size() == 1) {
		//						index = temp[0];
		//						list.printElementI(index);
		//					}
		//					else {
		//						index = -1;
		//						cout << "Khong tim thay sach";
		//					}
		//				}
		//			}
		//			//else {
		//				if (2 == tempCommand) {

		//					while (usr.GetID()=="") {

		//						login("account");
		//					}
		//					u = new user;
		//					if (index == -1) {
		//						cout << "Vui long chon sach can mua";
		//						tempCommand = 1;
		//					}
		//					else {
		//						book temp = list.getBookI(index);
		//						u.addBill(temp);
		//						cout << "Sach da duoc them vao gio hang" << endl;
		//					}
		//					
		//				}
		//				else {
		//					if (3 == tempCommand) {
		//						if (usr.GetID() != "") {
		//							u->checkBill();
		//						}
		//						else {
		//							cout << "Vui long dang nhap"<<endl;
		//							tempCommand = 3;
		//						}
		//					}


		//				}

		//			}
		//		}
		//	}
		}
}

