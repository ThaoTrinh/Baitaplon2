#include <phieumuon.h>
#include <nhapphieu.h>
#include <insach.h>
using namespace std;

string DocFileSachGiaoTrinh(Nguoidung &Ngdung_dangnhap,vector<string>& SachGiaoTrinh,sach &Giaotrinh) {
	ifstream infilesachGiaoTrinh;
	infilesachGiaoTrinh.open("SachGiaoTrinh.txt");
	if (!infilesachGiaoTrinh.is_open()) {
		cout << "Loi mo file cac loai sach";
	}
	string str1;
	getline(infilesachGiaoTrinh, str1); // Lấy ra dòng đầu tiên
	while (getline(infilesachGiaoTrinh, str1))
	{
		if (str1.empty())
			continue;
		SachGiaoTrinh.push_back(str1);
	}
	infilesachGiaoTrinh.close();

	//Phần code này dùng thực hiện chức năng khi người dùng chọn số thứ tự sách ( ví dụ như thứ i )
	//Thì sẽ getline dòng thứ i trong file sách đó
	//Tiếp theo là sẽ đọc phần tên sách trong sòng thứ i để hiển thị ra màn hình
	float selection = LuaChonSach(Ngdung_dangnhap,Giaotrinh);
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

string tenFileSachGiaoTrinh(Nguoidung &Ngdung_dangnhap,vector<string>& SachGiaoTrinh,sach &Giaotrinh) {
	ifstream infilesachGiaoTrinh;
	infilesachGiaoTrinh.open("SachGiaoTrinh.txt");
	if (!infilesachGiaoTrinh.is_open()) {
		cout << "Loi mo file cac loai sach";
	}
	string str1;
	getline(infilesachGiaoTrinh, str1); // Lấy ra dòng đầu tiên
	while (getline(infilesachGiaoTrinh, str1))
	{
		if (str1.empty())
			continue;
		SachGiaoTrinh.push_back(str1);
	}
	infilesachGiaoTrinh.close();

	//Phần code này dùng thực hiện chức năng khi người dùng chọn số thứ tự sách ( ví dụ như thứ i )
	//Thì sẽ getline dòng thứ i trong file sách đó
	//Tiếp theo là sẽ đọc phần tên sách trong sòng thứ i để hiển thị ra màn hình
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
void PhieuMuon(Nguoidung &Ngdung_dangnhap,vector<string>& SachGiaoTrinh,sach &Giaotrinh) {
	//vector<string>SachGiaoTrinh;
	char y;
	//string s = DocFileSachGiaoTrinh(SachGiaoTrinh);
	cout << "Co phai ban muon muon sach: " << DocFileSachGiaoTrinh(Ngdung_dangnhap,SachGiaoTrinh,Giaotrinh) << "	(y/n)" << endl;
	cout << "(Neu dung thi vui long nhan phim y, hoac nhan phim n de quay lai chon sach khac)" << endl;
	cin.ignore();
	cin >> y;
	switch (y)
	{
	case 'y':
	{
		Nhapphieumuonsach(Ngdung_dangnhap,SachGiaoTrinh,Giaotrinh);
		break;
	}
	case 'n':
	{
		infilegiaotrinh(Ngdung_dangnhap,SachGiaoTrinh,Giaotrinh);
		break;
	}
	}
}

float LuaChonSach(Nguoidung &Ngdung_dangnhap,sach &Giaotrinh) {
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
	Giaotrinh.maso=selection;
	return selection;
}

bool LuaChonMuonSach(Nguoidung &Ngdung_dangnhap,vector<string>& SachGiaoTrinh,sach &Giaotrinh) {
	//vector<string> SachGiaoTrinh;
	switch (Select(Ngdung_dangnhap,SachGiaoTrinh,Giaotrinh))
	{
	case 1:
	{
		PhieuMuon(Ngdung_dangnhap,SachGiaoTrinh,Giaotrinh);
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

int Select(Nguoidung &Ngdung_dangnhap,vector<string>& SachGiaoTrinh,sach &Giaotrinh){
	int select;
	cout << "Nhan phim 1 neu ban muon muon sach." << endl;
	cout << "Nhan phim 2 de quay lai." << endl;
	cin >> select;
	return select;
}