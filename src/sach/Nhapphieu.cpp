#include <nhapphieu.h>
#include <phieumuon.h>
using namespace std;


void ThoiGianMuon(int& date, int& month, int& year ) {
	struct tm newtime;
	__time64_t long_time;
	_time64(&long_time);
	_localtime64_s(&newtime, &long_time);
	month = newtime.tm_mon + 1;
	date = newtime.tm_mday;
	year = newtime.tm_year + 1900;
	return;
}

void Nhapphieumuonsach(Nguoidung& Ngdung_dangnhap, vector<string>SachGiaoTrinh, sach & Giaotrinh) {
	ThoiGianMuonSach thoiGian;
	int soluong;
	system("cls");
	ThoiGianMuon(thoiGian.date, thoiGian.month, thoiGian.year);
	cout << "+) So luong: "; cin >> soluong;
	cout << "*----------------PHIEU MUON SACH--------------------*" << endl;
	cout << "Ten sach: " << tenFileSachGiaoTrinh(Ngdung_dangnhap, SachGiaoTrinh, Giaotrinh) << endl;
	cout << "Nguoi muon: " <<Ngdung_dangnhap.Biethieu << endl;
	cout << "Thoi gian muon: " << thoiGian.date << "/" << thoiGian.month << "/" << thoiGian.year << endl;
	cout << "Thoi han muon sach la 1 thang ke tu khi muon." << endl;
	cout << "*---------------------------------------------------*" << endl;
	cout << "Neu ban dong y muon sach thi nhan phim y yeu cau se duoc gui di." << endl;
	cout << "Hoac khong dong y thi hay nhan phim n de quay lai." << endl;
	char y;
	cin >> y;
	if (y == 'y')
	{
		ofstream PhieuMuonSach; 
		PhieuMuonSach.open("PhieuMuonSach.txt", ios::app);
		
		PhieuMuonSach << Ngdung_dangnhap.Maso << "|" << Ngdung_dangnhap.Biethieu << "|"
			<< tenFileSachGiaoTrinh(Ngdung_dangnhap, SachGiaoTrinh, Giaotrinh) << "|"
			<< thoiGian.date << "/" << thoiGian.month << "/" << thoiGian.year
			<< "|" << soluong << "|" << "n" << "|" << endl;
		PhieuMuonSach.close();
		cout << "Yeu cau muon sach da duoc gui di." << endl;
		return;
	}
	else
	{
		return;
	}
}