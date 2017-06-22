#include <duyettaikhoan.h>
#include <thongtin_canhan.h>
#include <Docdulieu.h>

using namespace std;

bool duyettaikhoan() {
	fstream duyet("duyettaikhoan.txt");
	if (!duyet.is_open()) {
		cout << "Loi mo file";
		return false;
	}
	int tinh = 0;
	string str;
	int vitri[5];
	while (getline(duyet, str)) {
		if (str.empty()) continue;
		stringstream tach(str);
		int maso = 0;
		tach >> maso;
		int dem = 0;
		for (int i = 0; i<str.length(); i++) {// lấy vị trí gạch |
			if (str[i] == '|') {
				vitri[dem] = i;
				dem++;
			}
		}

		string ten;
		for (int i = vitri[0] + 1; i<vitri[1]; i++) {
			tinh = 1;
			ten += str[i];
		}
		system("cls");
		cout << ten << " muon them tai khoan.";
		system("pause");
		Thongtin_canhan(maso);
		system("cls");
		cout << "Ban co muon them nguoi dung nay vao he thong(y/n): ";
		string y;
		cin >> y;

		if (y == "y") {
			xoaduyet(maso);
			cout << "Nguoi dung nay da duoc them vao he thong thanh cong" << endl;
			system("pause");

		}
		else {
			xoachucnang(maso);
			xoadangnhap(maso);
			xoathongtin(maso);
			xoaduyet(maso);
			cout << "Nguoi dung khong duoc dang ki vao he thong" << endl;
			system("pause");

		}
		break;
	}
	if (tinh == 0) {
		cout << "Khong co nguoi dung nao dang ki tai khoan" << endl;
		system("pause");
	}
	duyet.close();
	return true;
}

bool xoachucnang(int maso) {
	fstream file("chucnang.txt");
	if (!file.is_open()) {
		cout << "Loi mo file";
		return false;
	}

	fstream file1("trong.txt");
	if (!file1.is_open()) {
		cout << "Loi mo file";
		return false;
	}

	string str;
	while (getline(file, str)) {
		if (str.empty()) continue;
		int ms;
		stringstream tach(str);
		tach >> ms;
		if (ms != maso) {
			file1 << str << endl;
		}
	}
	file1.close();
	file.close();
	string bien;
	fstream file2("trong.txt");
	ofstream xoa("chucnang.txt");
	fstream nhap("chucnang.txt");
	if (!nhap.is_open()) {
		cout << "Loi mo file";
		return false;
	}
	while (getline(file2, bien)) {
		nhap << bien << endl;
	}
	ofstream xoa1("trong.txt");
	nhap.close();
	file2.close();

	return true;
}

bool xoadangnhap(int maso) {
	fstream file("dangnhap.txt");
	if (!file.is_open()) {
		cout << "Loi mo file";
		return false;
	}

	fstream file1("trong.txt");
	if (!file1.is_open()) {
		cout << "Loi mo file";
		return false;
	}

	string str;
	while (getline(file, str)) {
		if (str.empty()) continue;
		int ms;
		stringstream tach(str);
		tach >> ms;
		if (ms != maso) {
			file1 << str << endl;
		}
	}
	file1.close();
	file.close();
	string bien;
	fstream file2("trong.txt");
	ofstream xoa("dangnhap.txt");
	fstream nhap("dangnhap.txt");
	if (!nhap.is_open()) {
		cout << "Loi mo file";
		return false;
	}
	while (getline(file2, bien)) {
		nhap << bien << endl;
	}
	ofstream xoa1("trong.txt");
	nhap.close();
	file2.close();

	return true;
}

bool xoathongtin(int maso) {
	fstream file("thongtin_nguoidung.txt");
	if (!file.is_open()) {
		cout << "Loi mo file";
		return false;
	}

	fstream file1("trong.txt");
	if (!file1.is_open()) {
		cout << "Loi mo file";
		return false;
	}

	string str;
	while (getline(file, str)) {
		if (str.empty()) continue;
		int ms;
		stringstream tach(str);
		tach >> ms;
		if (ms != maso) {
			file1 << str << endl;
		}
	}
	file1.close();
	file.close();
	string bien;
	fstream file2("trong.txt");
	ofstream xoa("thongtin_nguoidung.txt");
	fstream nhap("thongtin_nguoidung.txt");
	if (!nhap.is_open()) {
		cout << "Loi mo file";
		return false;
	}
	while (getline(file2, bien)) {
		nhap << bien << endl;
	}
	ofstream xoa1("trong.txt");
	nhap.close();
	file2.close();

	return true;
}

bool xoaduyet(int maso) {
	fstream file("duyettaikhoan.txt");
	if (!file.is_open()) {
		cout << "Loi mo file";
		return false;
	}

	fstream file1("trong.txt");
	if (!file1.is_open()) {
		cout << "Loi mo file";
		return false;
	}

	string str;
	while (getline(file, str)) {
		if (str.empty()) continue;
		int ms;
		stringstream tach(str);
		tach >> ms;
		if (ms != maso) {
			file1 << str << endl;
		}
	}
	file1.close();
	file.close();
	string bien;
	fstream file2("trong.txt");
	ofstream xoa("duyettaikhoan.txt");
	fstream nhap("duyettaikhoan.txt");
	if (!nhap.is_open()) {
		cout << "Loi mo file";
		return false;
	}
	while (getline(file2, bien)) {
		nhap << bien << endl;
	}
	ofstream xoa1("trong.txt");
	nhap.close();
	file2.close();

	return true;
}

