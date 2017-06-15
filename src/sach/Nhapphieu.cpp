#include <nhapphieu.h>
#include <phieumuon.h>
using namespace std;

void Nhapphieumuonsach(Nguoidung& Ngdung_dangnhap, vector<string>SachGiaoTrinh, sach & Giaotrinh) {
	system("cls");
	int date, month, year;
	cout << "Vui long nhap phieu muon sach: " << endl;
	cout << "Nhap ngay muon: " << endl;
	cout << "+) Ngay: "; cin >> date;
	cout << "+) Thang: "; cin >> month;
	cout << "+) Nam: "; cin >> year;

	cout << "*----------------PHIEU MUON SACH--------------------*" << endl;
	cout << "Ten sach: " << tenFileSachGiaoTrinh(Ngdung_dangnhap, SachGiaoTrinh, Giaotrinh) << endl;
	cout << Ngdung_dangnhap.Biethieu << endl;
	cout << date << "/" << month << "/" << year << endl;
	cout << "Thoi han muon sach la 7 ngay ke tu khi muon." << endl;
	cout << "*---------------------------------------------------*" << endl;
	cout << "Neu ban dong y muon sach thi nhan phim y yeu cau se duoc gui di." << endl;
	cout << "Hoac khong dong y thi hay nhan phim n de quay lai." << endl;
	char y;
	cin >> y;
	if (y == 'y')
	{
		ofstream PhieuMuonSach; // M? file ghi phi?u mý?n vào file
		PhieuMuonSach.open("PhieuMuonSach.txt", ios::app);
		//ghi tên ngý?i dùng vào
		//trong file ghi:
		// M? s? | tên ngý?i dùng | sách mý?n | ngày mý?n | 
		PhieuMuonSach << "|" << Ngdung_dangnhap.Maso << "|" << Ngdung_dangnhap.Biethieu << tenFileSachGiaoTrinh(Ngdung_dangnhap, SachGiaoTrinh, Giaotrinh) << "|"
			<< date << "/" << month << "/" << year
			<< "|" << endl;
		PhieuMuonSach.close();
		cout << "Yeu cau muon sach da duoc gui di." << endl;
		return;
	}
	else
	{
		return;
	}
}
