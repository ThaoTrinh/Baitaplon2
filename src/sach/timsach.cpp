#include <insach.h>
#include <Timsach.h>
#include <nhapphieu.h>
#include <phieumuon.h>
using namespace std;

bool timsach_theoten(Nguoidung &Ngdung_dangnhap, vector<string>SachGiaoTrinh, sach &Giaotrinh) {
	system("cls");
	fstream FILE2("sach.txt");
	if (!FILE2.is_open()) {
		cout << "Loi mo file";
		return false;
	}
	string masach;
	string tukhoa;
	string tensach;
	string tensachthuong;
	string bien;
	int vitri[8];
	int select;
	cout << "Nhap tu khoa:" << " ";
	cin.ignore();
	getline(cin, tukhoa);

	bool timthay = false;
	cout << "Danh sach tim duoc" << endl;
	cout << "*--------------------------------------------------------------------------------------------------*" << endl;
	//----------------------Doc file SachVanHoc.txt----------------------------------
	while (getline(FILE2, bien)) {
		if (bien.empty())
			continue;
		int dem = 0;
		for (int i = 0; i < bien.length(); i++) {// lấy vị trí gạch |

			if (bien[i] == '|') {
				vitri[dem] = i;
				dem++;
			}
		}
		masach = bien.substr(0, vitri[0]);
		tensach = bien.substr(vitri[0] + 1, (vitri[1] - vitri[0] - 1));
		char* c = new char[tensach.size() + 1];
		copy(tensach.begin(), tensach.end(), c);
		c[tensach.size()] = '\0';
		tensachthuong = strlwr(c);
		for (int i = 0; i < tensachthuong.length(); i++)//tensach
		{
			for (int j = 0; j < tukhoa.length(); j++)
			{
				if (tukhoa[j] == tensachthuong[i])//tensach
				{
					int sosanh = tensachthuong.compare(i, tukhoa.length(), tukhoa);//tensach
					if (sosanh == 0)
					{
						timthay = true;
						cout << masach << setfill(' ') << setw(60-masach.length()) << tensach << endl;
						//break;
					}
					else
					{
						continue;
					}
				}
			}
		}
		//break;
	}
	cout << "*--------------------------------------------------------------------------------------------------*" << endl;
	LuaChonMuonSach(Ngdung_dangnhap, SachGiaoTrinh, Giaotrinh);
	if (timthay == false) {
		cout << "Khong tim thay sach" << endl;
	}

	FILE2.close();
	system("pause");
	return true;
}

bool timsach_theloai(Nguoidung &Ngdung_dangnhap, vector<string>SachGiaoTrinh, sach &Giaotrinh) {
	system("cls");
	fstream FILE2("sach.txt");
	if (!FILE2.is_open()) {
		cout << "Loi mo file";
		return false;
	}
	string masach;
	string tukhoa;
	string theloai;
	string theloaithuong;
	string tensach_tl;
	string bien;
	int vitri[8];
	int select;
	cout << "Nhap tu khoa:" << " ";
	cin.ignore();
	getline(cin, tukhoa);

	bool timthay = false;
	cout << "Danh sach tim duoc" << endl;
	cout << "*--------------------------------------------------------------------------------------------------*" << endl;
	while (getline(FILE2, bien)) {
		if (bien.empty())
			continue;
		int dem = 0;
		for (int i = 0; i < bien.length(); i++) {// lấy vị trí gạch |

			if (bien[i] == '|') {
				vitri[dem] = i;
				dem++;
			}
		}
		masach = bien.substr(0, vitri[0]);
		theloai = bien.substr(vitri[2] + 1, (vitri[3] - vitri[2] - 1));
		tensach_tl = bien.substr(vitri[0] + 1, (vitri[1] - vitri[0] - 1));
		char* c = new char[theloai.size() + 1];
		copy(theloai.begin(), theloai.end(), c);
		c[theloai.size()] = '\0';
		theloaithuong = strlwr(c);
		for (int i = 0; i < theloaithuong.length(); i++)//tensach
		{
			for (int j = 0; j < tukhoa.length(); j++)
			{
				if (tukhoa[j] == theloaithuong[i])//tensach
				{
					int sosanh = theloaithuong.compare(i, tukhoa.length(), tukhoa);//tensach
					if (sosanh == 0)
					{
						timthay = true;
						cout << masach << setfill(' ') << setw(60-masach.length()) << tensach_tl << setfill(' ') << setw(30) << theloai << endl;
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	cout << "*--------------------------------------------------------------------------------------------------*" << endl;
	LuaChonMuonSach(Ngdung_dangnhap, SachGiaoTrinh, Giaotrinh);
	if (timthay == false) {
		cout << "Khong tim thay sach" << endl;
	}

	FILE2.close();
	system("pause");
	return true;
}




