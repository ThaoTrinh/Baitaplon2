#include <tuychon.h>
using namespace std;

int Tuychon(vector<Nguoidung>& Dangnhap, Nguoidung & Ngdung_dangnhap) {
	system("cls");
	cout << "CHAO MUNG DEN VOI LIBPR0" << endl;
	cout << "_________________________________________________" << endl;
	cout << "Moi ban chon dich vu" << endl;
	cout << "1.	Dang nhap" << endl;
	cout << "2.	Dang ki" << endl;
	cout << "3.	Quen mat khau" << endl;
	cout << "4.	Thoat" << endl;
	cout << "Lua chon cua ban la: ";

	int luachon;
	cin >> luachon;
	while (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Loi nhap lua chon. Vui long nhap lai: ";
		cin >> luachon;

	}
	return luachon;
}

int Tuychon_docgia(vector<Nguoidung>& Dangnhap, Nguoidung & Ngdung_dangnhap) {
	system("cls");
	cout << "Moi ban chon tuy chon" << endl;
	cout << "1.	Tim va muon sach" << endl;
	cout << "2.	Tra sach" << endl;
	cout << "3.	Xem thong tin ca nhan" << endl;
	cout << "4.	Xem thong bao" << endl;
	cout << "5.	Cai dat" << endl;
	cout << "6.	Quay lai" << endl;
	cout << "Lua chon cua ban la: ";
	int chon;
	cin >> chon;
	while (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Loi nhap lua chon. Vui long nhap lai: ";
		cin >> chon;

	}
	return chon;
}

int Tuychon_thuthu(vector<Nguoidung>& Dangnhap, Nguoidung & Ngdung_dangnhap) {
	system("cls");
	cout << "Moi ban chon tuy chon" << endl;
	cout << "1.	Them sach" << endl;
	cout << "2.	Duyet muon sach" << endl;
	cout << "3.	Duyet tra sach" << endl;
	cout << "4.	Cai dat" << endl;
	cout << "5.	Thong tin ca nhan" << endl;
	cout << "6.	Thoat" << endl;
	cout << "Lua chon cua ban la: ";
	int chon;
	cin >> chon;
	while (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Loi nhap lua chon. Vui long nhap lai: ";
		cin >> chon;

	}
	return chon;
}

int Tuychon_Quanli(vector<Nguoidung>& Dangnhap, Nguoidung & Ngdung_dangnhap) {
	system("cls");
	cout << "Moi ban chon tuy chon" << endl;
	cout << "1.	Duyet tuy chon nguoi dung" << endl;
	cout << "2.	Xoa tuy chon nguoi dung" << endl;
	cout << "3.	Duyet tai khoan nguoi dung dang ki" << endl;
	cout << "4.	Cai dat" << endl;
	cout << "5.	Thong tin ca nhan" << endl;
	cout << "6.	Tim kiem nguoi dung" << endl;
	cout << "7.	Reset mat khau nguoi dung" << endl;
	cout << "8.	Thoat" << endl;
	cout << "Lua chon cua ban la: ";
	int chon;
	cin >> chon;
	while (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Loi nhap lua chon. Vui long nhap lai: ";
		cin >> chon;

	}
	return chon;
}

int Tuychon_chucnang(vector<Nguoidung>& Dangnhap, Nguoidung & Ngdung_dangnhap) {
	system("cls");
	cout << "Ban muon dang nhap voi tu cach la: " << endl;
	cout << "1.	Doc gia" << endl;
	cout << "2.	Thu thu" << endl;
	cout << "3.	Quan li nguoi dung" << endl << endl;
	cout << "Hoac ban muon chon tuy chon nao" << endl;
	cout << "4.	Lich su dang nhap" << endl;
	cout << "5.	Vo hieu hoa tai khoan" << endl;
	cout << "6.	Dang xuat" << endl;
	cout << "Lua chon cua ban la: ";
	int chon;
	cin >> chon;
	while (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Loi nhap lua chon. Vui long nhap lai: ";
		cin >> chon;

	}
	return chon;
}