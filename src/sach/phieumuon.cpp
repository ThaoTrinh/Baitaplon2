#include <phieumuon.h>
#include <nhapphieu.h>
#include<timsach.h>
using namespace std;
string DocFileSachGiaoTrinh(Nguoidung &Ngdung_dangnhap, vector<string>& SachGiaoTrinh, sach &Giaotrinh) {
	ifstream infilesachGiaoTrinh;
	infilesachGiaoTrinh.open("sach.txt");
	if (!infilesachGiaoTrinh.is_open()) {
		cout << "Loi mo file cac loai sach";
	}
	string str1;
	getline(infilesachGiaoTrinh, str1); // L?y ra d?ng ð?u tiên
	while (getline(infilesachGiaoTrinh, str1))
	{
		if (str1.empty())
			continue;
		SachGiaoTrinh.push_back(str1);
	}
	infilesachGiaoTrinh.close();


	float selection = LuaChonSach(Ngdung_dangnhap, Giaotrinh);
	int bien;
	string str2 = SachGiaoTrinh[int(selection) - 1];
	int index[5];
	int dem = 0;
	for (int i = 0; i<str2.length(); i++) {
		if (str2[i] == '|') {
			index[dem] = i;
			dem++;
		}
	}
	string ten_sach;
	for (int i = index[0] + 1; i < index[1]; i++) {
		ten_sach += str2[i];
	}
	return ten_sach;
}
string tenFileSachGiaoTrinh(Nguoidung &Ngdung_dangnhap, vector<string>& SachGiaoTrinh, sach &Giaotrinh) {
	ifstream infilesachGiaoTrinh;
	infilesachGiaoTrinh.open("sach.txt");
	if (!infilesachGiaoTrinh.is_open()) {
		cout << "Loi mo file cac loai sach";
	}
	string str1;
	getline(infilesachGiaoTrinh, str1); // L?y ra d?ng ð?u tiên
	while (getline(infilesachGiaoTrinh, str1))
	{
		if (str1.empty())
			continue;
		SachGiaoTrinh.push_back(str1);
	}
	infilesachGiaoTrinh.close();

	//Ph?n code này dùng th?c hi?n ch?c nãng khi ngý?i dùng ch?n s? th? t? sách ( ví d? nhý th? i )
	//Th? s? getline d?ng th? i trong file sách ðó
	//Ti?p theo là s? ð?c ph?n tên sách trong s?ng th? i ð? hi?n th? ra màn h?nh
	float selection = Giaotrinh.maso;
	int bien;
	string str2 = SachGiaoTrinh[selection - 1];
	int index[5];
	int dem = 0;
	for (int i = 0; i<str2.length(); i++) {
		if (str2[i] == '|') {
			index[dem] = i;
			dem++;
		}
	}
	string ten_sach;
	for (int i = index[0] + 1; i < index[1]; i++) {
		ten_sach += str2[i];
	}
	return ten_sach;
}
void PhieuMuon(Nguoidung &Ngdung_dangnhap, vector<string>& SachGiaoTrinh, sach &Giaotrinh) {
	char y;
	cout << "Co phai ban muon muon sach: " << DocFileSachGiaoTrinh(Ngdung_dangnhap, SachGiaoTrinh, Giaotrinh) << "	(y/n)" << endl;
	cout << "(Neu dung thi vui long nhan phim y, hoac nhan phim n de quay lai chon sach khac)" << endl;
	cin.ignore();
	cin >> y;
	switch (y)
	{
	case 'y':
	{
		Nhapphieumuonsach(Ngdung_dangnhap, SachGiaoTrinh, Giaotrinh);
		break;
	}
	case 'n':
	{
		break;
	}
	}
}

float LuaChonSach(Nguoidung &Ngdung_dangnhap, sach &Giaotrinh) {
	float selection = 0;
	cout << "Nhap so thu tu sach ma ban muon muon doc: ";
	cin >> selection;

	while (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Loi nhap lua chon. Vui long nhap lai: ";
		cin >> selection;

	}
	while (selection < 0 || int(selection) != selection)
	{
		cout << "Loi nhap lua chon ! Ban khong the nhap so thu tu lon hon so sach hoac nho hon 0..." << endl;
		cout << "Nhap lai lua chon: ";
		cin >> selection;
	}
	//nhapvao=selection;
	Giaotrinh.maso = selection;
	return selection;
}

bool LuaChonMuonSach(Nguoidung &Ngdung_dangnhap, vector<string>& SachGiaoTrinh, sach &Giaotrinh) {
	//vector<string> SachGiaoTrinh;
	switch (Select(Ngdung_dangnhap, SachGiaoTrinh, Giaotrinh))
	{
	case 1:
	{
		PhieuMuon(Ngdung_dangnhap, SachGiaoTrinh, Giaotrinh);
		//DocFileSachGiaoTrinh(SachGiaoTrinh);
		break;
	}
	case 2:
	{
		return true;
	}
	}
	return true;
}

int Select(Nguoidung &Ngdung_dangnhap, vector<string>& SachGiaoTrinh, sach &Giaotrinh) {
	int select;
	cout << "Nhan phim 1 neu ban muon muon sach." << endl;
	cout << "Nhan phim 2 de quay lai." << endl;
	cin >> select;
	return select;
}