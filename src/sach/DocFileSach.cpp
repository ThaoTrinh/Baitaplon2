#include <DocFile.h>
using namespace std;

bool Doc_file_SachGiaoTrinh() {
	vector<string> List_DanhSach_Lattrang;
	ifstream infilesachGiaoTrinh;
	infilesachGiaoTrinh.open("Sach_Giao_Trinh.txt");
	if (!infilesachGiaoTrinh.is_open()) {
		cout << "Loi mo file cac loai sach";
	}

	string str1;
	int bien1;
	cout << "Danh sach cac loai sach: " << endl;
	cout << "*-------------------------------------------------------------------------------------*" << endl;

	getline(infilesachGiaoTrinh, str1); // Lấy ra dòng đầu tiên
	while (getline(infilesachGiaoTrinh, str1))
	{
		if (str1.empty())
			continue;
		cout << str1 << endl;
		cout << "*-------------------------------------------------------------------------------------*" << endl;
		List_DanhSach_Lattrang.push_back(str1);
	}
	infilesachGiaoTrinh.close();
	return true;
}

bool Doc_file_SachKHTN() {
	vector<string> List_DanhSach_Lattrang;
	ifstream infilesachKhoahocTuNhien;
	infilesachKhoahocTuNhien.open("Sach_KhoaHoc_TuNhien_KyThuat.txt");
	if (!infilesachKhoahocTuNhien.is_open()) {
		cout << "Loi mo file cac loai sach";
	}

	string str1;
	int bien1;
	cout << "Danh sach cac loai sach: " << endl;
	cout << "*-------------------------------------------------------------------------------------*" << endl;

	getline(infilesachKhoahocTuNhien, str1); // Lấy ra dòng đầu tiên
	while (getline(infilesachKhoahocTuNhien, str1))
	{
		if (str1.empty())
			continue;
		cout << str1 << endl;
		cout << "*-------------------------------------------------------------------------------------*" << endl;
		List_DanhSach_Lattrang.push_back(str1);
	}
	infilesachKhoahocTuNhien.close();
	return true;
}

bool Doc_file_SachVanHoc() {
	vector<string> List_DanhSach_Lattrang;
	ifstream infilesachVanHoc;
	infilesachVanHoc.open("Sach_Van_Hoc.txt");
	if (!infilesachVanHoc.is_open()) {
		cout << "Loi mo file cac loai sach";
	}
	string str1;
	cout << "Danh sach cac loai sach: " << endl;
	getline(infilesachVanHoc, str1); // Lấy ra dòng đầu tiên
	cout << str1 << endl;
	cout << "*-------------------------------------------------------------------------------------*" << endl;
	while (getline(infilesachVanHoc, str1))
	{
		if (str1.empty())
			continue;
		cout << str1 << endl;
		cout << "*-------------------------------------------------------------------------------------*" << endl;
		List_DanhSach_Lattrang.push_back(str1); // thêm vào vecto nhằm thực hiện ý tưởng lật trang
	}
	infilesachVanHoc.close();
	return true;
}

