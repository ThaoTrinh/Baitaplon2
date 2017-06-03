#include <Chucnang.h>
#include <Docdulieu.h>
#include <switch.h>
#include <Chucnag_hientai.h>
#include <Chucnang_tontai.h>
#include <file_chucnang.h>
using namespace std;

bool Themchucnang(vector<Nguoidung>& Dangnhap, Nguoidung& Ngdung_dangnhap) {
	
	// xuất chức năng hiện có
	Xuatchucnang(Dangnhap,Ngdung_dangnhap);

	//--------------------------------------------------
	cout << "Ban muon them chuc nang nao? " << endl;
	cout << "1.Doc gia" << endl
	     << "2.Thu thu" << endl
	     << "3.Quan li nguoi dung" << endl;
	cout << endl;
	//--------------------------------------------------

	
	while (true) {
		cout << "Lua chon cua ban la: ";
		int chon = 0;
		cin >> chon;
		if(chucnang_tontai(Ngdung_dangnhap,chon)){
			cout << "Chuc nang nay ban da co" << endl;
			cout << "Ban co muon chon chuc nang khac khong?(y/n) ";
			cin.ignore();
			string y;
			getline(cin, y);
			if (y == "y")
				continue;
			return false;
		}		

		if(!capnhat_themchucnang(Ngdung_dangnhap, chon)){
			cout << "Khong cap nhat duoc" << endl;
			cout << "Moi ban thu lai sau" << endl;
			system("pause");
			break;
		}
		return true;
	}
	return false;
}

bool Huychucnang(vector<Nguoidung>& Dangnhap, Nguoidung& Ngdung_dangnhap) {
	Xuatchucnang(Dangnhap,Ngdung_dangnhap);

	cout << "Ban muon huy chuc nang nao? " << endl;
	cout << "1.Doc gia" << endl
	     << "2.Thu thu" << endl
	     << "3.Quan li nguoi dung" << endl;
	cout << endl;
	while (true) {
		cout << "Lua chon cua ban la: ";
		int chon = 0;
		cin >> chon;
		if(!chucnang_tontai(Ngdung_dangnhap,chon)){
			cout << "Chuc nang nay chua duoc kich hoat nen khong the huy" << endl;
			cout << "Ban co muon chon chuc nang khac khong?(y/n) ";
			cin.ignore();
			string y;
			getline(cin, y);
			if (y == "y")
				continue;
			return false;
		}		

		if(!capnhat_huychucnang(Ngdung_dangnhap, chon)){
			cout << "Khong cap nhat duoc" << endl;
			cout << "Moi ban thu lai sau" << endl;
			system("pause");
			break;
		}
		return true;
	}
	return false;
}