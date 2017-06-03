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
	int dodai = Dangnhap.size();// do dai cu
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
	cout << "Nhap mat khau: ";
	getline(cin, B.Matkhau);
	cout<<"Nhap biet hieu: ";
	getline(cin,B.Biethieu);

	Dangnhap.push_back(B);// do dai luc nay + 1, nhung lay do dai cu
	// nguoi dung moi se co so chieu toi la [dodai]
	FILE << endl;
	FILE << Dangnhap[dodai - 1].Maso + 1 << "	" << B.Taikhoan << "	"
		<< B.Matkhau<<"	"<<B.Biethieu;
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
	int dodai = Dangnhap.size();// do dai sau khi da them
	thongtin_nguoidung A;
	cout << "Ho va ten: ";
	getline(cin, A.hoten);
	cout<<"Nhap so CMND: ";
	getline(cin, A.CMND);
	cout << "Nam sinh: ";
	getline(cin, A.namsinh);
	cout << "Gioi tinh: ";
	getline(cin, A.gioitinh);
	cout << "Dia chi: ";
	getline(cin, A.diachi);
	cout << "Truong: ";
	getline(cin, A.truong);
	cout << "Khoa: ";
	getline(cin, A.khoa);

	Dangki_taikhoan.push_back(A);

	FILE << endl;
	FILE << Dangnhap[dodai - 2].Maso + 1 << "|" << A.hoten <<"|"<<A.CMND<< "|" << A.namsinh
	     <<"|"<<A.gioitinh<< "|" << A.diachi << "|" << A.truong << "|" << A.khoa<<"|";
	FILE.close();
	return true;
}

bool Chucnang_dangki(vector<thongtin_nguoidung>& Dangki_taikhoan, Nguoidung& Ngdung_dangnhap,vector<Nguoidung>& Dangnhap){
		fstream FILE("chucnang.txt", ios::out | ios::app);
	if (!FILE.is_open()) {
		cout << "Loi mo file";
		return false;
	}
	int dodai = Dangnhap.size();
	FILE<<endl;
	FILE << Dangnhap[dodai - 2].Maso + 1<<"   " << "1    0   0";
	FILE.close();
	return true;
}


void Dangki_main(vector<thongtin_nguoidung>& Dangki_taikhoan, Nguoidung& Ngdung_dangnhap,vector<Nguoidung>& Dangnhap){
	cout<<"Ban muon dang ki tai khoan(y/n): ";
	string t;
	getline(cin,t);
	
	if (t != "y") return;

	if (!Dangki(Dangnhap)) return;

	if (!thongtin_dangki(Dangki_taikhoan,Ngdung_dangnhap,Dangnhap)) {
		cout << "Khong dang ki duoc tai khoan" << endl;
		system("pause");
		return;
	}

	Chucnang_dangki(Dangki_taikhoan,Ngdung_dangnhap,Dangnhap);
	cout << "Ban da duoc dang ki vao he thong" << endl;
	system("pause");
}