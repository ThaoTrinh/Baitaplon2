#include <Dangki_taikhoan.h>

using namespace std;

bool Dangki(vector<Nguoidung>& Dangnhap) {
	system("cls");
	// ios::app
	// thuc hien ghi file vao cuoi file
	fstream FILE("dangnhap.txt", ios::out | ios::app);
	if (!FILE.is_open()) {
		cout << "Loi mo file";
		return false;
	}

	Nguoidung B;

	cout << "Nhap ten tai khoan: ";
	getline(cin, B.Taikhoan);
	for (int i = 0; i < Dangnhap.size(); i++) {
		while (B.Taikhoan == Dangnhap[i].Taikhoan) {
			cout << "Tai khoan da ton tai, Moi chon tai khoan khac: " << endl;
			cout << "Nhap ten tai khoan: ";
			getline(cin, B.Taikhoan);
			i = -1;
			break;
		}
	}

	srand(time(NULL));
		for(int i=0;i<5;i++){
			B.Matkhau +=rand()%26+97;
		}

	cout << "Nhap biet hieu(Vui long nhap biet hieu khong co khoan trong): ";
	getline(cin, B.Biethieu);

	Dangnhap.push_back(B);
	int dodai = Dangnhap.size();
	Dangnhap[dodai - 1].Maso = Dangnhap[dodai - 2].Maso + 1;
	FILE << endl;
	FILE << Dangnhap[dodai - 1].Maso << "	" << B.Taikhoan << "	"
		<< B.Matkhau << "	" << B.Biethieu;
	FILE.close();
	return true;
}

bool thongtin_dangki(
	vector<thongtin_nguoidung>& Dangki_taikhoan,
	Nguoidung& Ngdung_dangnhap,
	vector<Nguoidung>& Dangnhap) {
	system("cls");
	// ios::app
	// thuc hien ghi file vao cuoi file
	fstream FILE("thongtin_nguoidung.txt", ios::out | ios::app);
	if (!FILE.is_open()) {
		cout << "Loi mo file";
		return false;
	}
	fstream duyet("duyettaikhoan.txt", ios::out | ios::app);
	if (!duyet.is_open()) {
		cout << "Loi mo file";
		return false;
	}

	thongtin_nguoidung A;
	cout << "Ho va ten: ";
	getline(cin, A.hoten);
	cout << "Ma so sinh vien/nhan vien: ";
	getline(cin, A.MSSV);
	cout << "Nhap so CMND: ";
	getline(cin, A.CMND);
	cout << "Nam sinh: ";
	getline(cin, A.namsinh);
	cout << "Gioi tinh: " << endl;
	cout << " 1.Nam" << endl;
	cout << " 2.Nu" << endl;
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

	while (chon>2 || chon<1) {
		cout << "Khong co lua chon moi chon lai: ";
		cin >> chon;
	}

	switch (chon) {
	case 1:
		A.gioitinh = "Nam";
		break;
	case 2:
		A.gioitinh = "Nu";
		break;
	}

	cin.ignore();
	cout << "Dia chi: ";
	getline(cin, A.diachi);
	cout << "Nghe nghiep: ";
	getline(cin, A.nghenghiep);
	cout << "Truong: ";
	getline(cin, A.truong);
	cout << "Khoa: ";
	getline(cin, A.khoa);
	cout << "Email: ";
	getline(cin, A.email);

	Dangki_taikhoan.push_back(A);
	int dodai = Dangnhap.size();
	FILE << endl;
	FILE << Dangnhap[dodai - 1].Maso << "|" << A.hoten << "|" << A.MSSV << "|" << A.CMND << "|" << A.namsinh
		<< "|" << A.gioitinh << "|" << A.diachi << "|" << A.nghenghiep << "|" << A.truong << "|" << A.khoa << "|" << A.email << "|";

	duyet<<Dangnhap[dodai - 1].Maso << "|" << A.hoten<<"|"<<endl;
	duyet.close();
	FILE.close();
	return true;
}

bool Chucnang_dangki(vector<thongtin_nguoidung>& Dangki_taikhoan, Nguoidung& Ngdung_dangnhap, vector<Nguoidung>& Dangnhap) {
	fstream FILE("chucnang.txt", ios::out | ios::app);
	if (!FILE.is_open()) {
		cout << "Loi mo file";
		return false;
	}
	int dodai = Dangnhap.size();
	FILE << endl;
	FILE << Dangnhap[dodai - 1].Maso << "   " << "1    0   0";
	FILE.close();
	return true;
}


void Dangki_main(vector<thongtin_nguoidung>& Dangki_taikhoan, Nguoidung& Ngdung_dangnhap, vector<Nguoidung>& Dangnhap) {
	cout << "Ban muon dang ki tai khoan(y/n): ";
	string t;
	getline(cin, t);

	if (t != "y") return;

	if (!Dangki(Dangnhap)) return;

	if (!thongtin_dangki(Dangki_taikhoan, Ngdung_dangnhap, Dangnhap)) {
		cout << "Khong dang ki duoc tai khoan" << endl;
		system("pause");
		return;
	}

	Chucnang_dangki(Dangki_taikhoan, Ngdung_dangnhap, Dangnhap);
	cout << "Ban da duoc dang ki vao he thong vui long cho xet duyet cua nguoi quan li."<<endl;
	cout<<"Vui long check mail de nhan thong bao ve mat khau" << endl;
	system("pause");
}