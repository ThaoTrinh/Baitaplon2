#include <DocFile.h>
using namespace std;

bool Doc_file_SachGiaoTrinh() {
	vector<string> List_DanhSach_Lattrang;
	ifstream infilesachGiaoTrinh;
	infilesachGiaoTrinh.open("sach.txt");
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
