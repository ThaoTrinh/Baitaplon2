#include <TraSach.h>
#include <nhapphieu.h>
using namespace std;

void Tra_Sach(Nguoidung &Ngdung_dangnhap) {
	system("cls");
	int tinh = 0;
	ifstream DocFileTraSach;
	DocFileTraSach.open("thongbaotrasach.txt", ios::in);
	if (!DocFileTraSach.is_open())
	{
		cout << "Khong tim thay du lieu..." << endl;
		return;
	}

	string str;

	unsigned int dongcanxoa = 0;
	bool luachon = false;
	while (getline(DocFileTraSach, str))
	{
		dongcanxoa++;
		if (str.empty()) continue;
		int maso = -1;
		stringstream tach(str);
		tach >> maso;
		if (maso != Ngdung_dangnhap.Maso) continue;

		string tensach, muon;
		int vitri[6];
		int dem = 0;
		for (int i = 0; i<str.length(); i++) {// lấy vị trí gạch |
			if (str[i] == '|') {
				vitri[dem] = i;
				dem++;
			}
		}

		for (int i = vitri[0] + 1; i < vitri[1]; i++) {
			tensach += str[i];
		}

		for (int i = vitri[3] + 1; i < vitri[4]; i++) {
			muon += str[i];
		}

		if (muon == "n") {
			continue;
		}
		else {
			tinh = 1;
			cout << "Ban muon tra sach: " << tensach << " (y/n): ";
			string y;
			cin >> y;
			if (y == "n") continue;

			else {
				cout << "Ban da tra sach thanh cong" << endl;
				fstream file("thongbaotrasach.txt", ios::in);
				if (!file.is_open()) {
					cout << "Loi mo file";
				}
				fstream file1("trong.txt", ios::out);
				if (!file1.is_open()) {
					cout << "Loi mo file1";
				}

				fstream file3("phieutrasach.txt", ios::out);
				if (!file3.is_open()) {
					cout << "Loi mo file1";
				}

				string bien;
				unsigned int dong = 0;
				while (getline(file, bien)) {
					dong++;
					if (dong == dongcanxoa) {
						ThoiGianMuonSach time;
						ThoiGianMuon(time.date, time.month, time.year);
					
						file3 << bien << time.date << "/" << time.month <<"/"<<time.year << "|" << endl;
					}
					else {
						file1 << bien << endl;
					}
				}
				file3.close();
				file1.close();
				file.close();

				ofstream xoa("thongbaotrasach.txt");
				fstream ghi("thongbaotrasach.txt", ios::out);
				if (!ghi.is_open()) {
					cout << "Loi mo file ghi";
				}
				fstream file2("trong.txt", ios::in);
				if (!file2.is_open()) {
					cout << "Loi mo file2";
				}

				while (getline(file2, bien)) {
					ghi << bien << endl;
				}
				ofstream xoa1("trong.txt");

				ghi.close();
				file2.close();

				luachon = true; break;
			}
		}
	}

	DocFileTraSach.close();

	////////////////////////////////////
	if (tinh == 0) {
		cout << "Ban khong co sach can tra" << endl;
	}
	system("pause");
}
