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
	list_bill.LoadListBillFormFile();

}
account* process::login(const string& file_name)
{
	cout << "Username: ";
	string username;
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
			cin.ignore();
			account* temp = login("account.txt");
			usr.CreateAccount(*temp);
			//cout << usr.GetID() << endl;
			while (usr.GetID() == "") {
				cout << "Tai khoan hoac mat khau khong chinh xac" << endl;
				cout << "Vui long dang nhap lai" << endl;
				temp = login("account.txt");
				usr.CreateAccount(*temp);
			}
			tempCommand = 0;
			role = usr.GetRole();
			switch (role)
			{
			case 1://admin
			{
				admin ad;
				ad.CreateAccount(usr);
				ad.getAllAccount("account.txt");
				while (tempCommand != 15) {
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
							case 12://xuat tat ca tai khoan
						{
							ad.OutputListAccount();
							break;
						}

						case 13://xuat mang hoa don
						{
							list_bill.OutputListbill();
							break;
						}

						case 14://so tien thanh toan nhieu nhat
						{
							vector<string> Publisher;
							vector<int> total;
							listBook item;
							item = list_bill.getListItem();
							string tempPub;
							book temp;
							for (int i = 0; i < item.getNumKind(); i++)
							{
								temp = item.getBookI(i);
								Publisher.push_back(temp.getPublisher());
								total.push_back(temp.getPrice() * temp.getNumber());
							}
							for (int i = 0; i < Publisher.size(); i++) {
								for (int j = i + 1; j < Publisher.size(); j++) {
									if (Publisher[i] == Publisher[j]) {
										Publisher.erase(Publisher.begin() + j);
										total.at(i) = total.at(i) + total.at(j);
										total.erase(total.begin() + j);
									}
									if (i == Publisher.size()) {
										break;
									}
								}
							}
							int maxTotal = 0;
							for (int i = 1; i < total.size(); i++) {
								if (total.at(maxTotal) < total.at(i)) {
									maxTotal = i;
								}
							}
							cout << "Nha xuat ban co tien thanh toan nhieu nhat la:  " << endl;
							cout << "Nha xuat ban " << Publisher[maxTotal] << endl;
							cout << "So tien ";
							cout << total.at(maxTotal) << endl;
							break;
						}
						case 15: {
							list.writeListBookToFile();
							ad.WriteListAccountToFile();
							break;
						}
					
						default:
							break;
					}
				}
				break;
			}



			case 2: //publisher
			{
				publisher pub;

				pub.CreateAccount(usr);
				while (tempCommand != 10) {
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
						  		
								case 9: {//xem sach ban chay nhat

										vector<string> book_name;
										vector<int> number;
										listBook item;
										item = list_bill.getListItem();
										string temp_book_name;
										book temp;
										for (int i = 0; i < item.getNumKind(); i++)
										{
											temp = item.getBookI(i);
											book_name.push_back(temp.getName());
											number.push_back(temp.getNumber());
										}
										for (int i = 0; i < book_name.size(); i++) {
											for (int j = i + 1; j < book_name.size(); j++) {
												if (book_name[i] == book_name[j]) {
													book_name.erase(book_name.begin() + j);
													number.at(i) = number.at(i) + number.at(j);
													number.erase(number.begin() + j);
												}
												if (i == book_name.size()) {
													break;
												}
											}
										}
										int maxNumber = 0;
										for (int i = 1; i < number.size(); i++) {
											if (number.at(maxNumber) < number.at(i)) {
												maxNumber = i;
											}
										}
										cout << "sach ban chay nhat la:  " << endl;
										cout << "sach: " << book_name[maxNumber] << endl;
										cout << "So luong ";
										cout << number.at(maxNumber) << endl;
										break;
									}
								case 10:
									{
										list.writeListBookToFile();
										break;
									}
									default: break;
							}

					
				}
				break;
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
				user u(usr);
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
						if (-1 != index) {
							bool isBuy;
							cout << "Ban co muon mua sach nay khong" << endl;
							cout << "1. Co" << endl;
							cout << "2. Khong" << endl;
							cin >> isBuy;
							if (isBuy == 1) {
								int number;
								cout << "Nhap vao so luong ban muon mua " << endl;
								cin >> number;
								u.addBill(list, index, number);
								cout << "Mua hang thanh cong" << endl;
							}
						}
						break;

					}
					case 2://mua sach
					{
						int index;
						int number;
						cout << "Nhap vao STT sach can mua " << endl;
						cin >> index;
						cout << "Nhap vao so luong muon mua " << endl;
						cin >> number;
						list.outputList(0);
						u.addBill(list,index,number);
						cout << "Mua sach thanh cong" << endl;
						break;
					}
					case 3://kiem tra hoa don
					{

						u.checkBill();
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
		if (2 == command) {
			account::SignUp();
			cout << "Dang ki thanh cong" << endl;
			command = 1;
			}
		}

		}
}

