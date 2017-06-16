#include <DuyetMuonSach.h>

using namespace std;

void Duyet() {
	system("cls");
	ifstream fin("PhieuMuonSach.txt", ios::app);
	ofstream fout("PhieuMuonSach.txt", ios::in);
	string line, basic = "|";
	int dem = 0;
	while (!fin.eof()) {
		getline(fin, line);
		int k = 0; // dung de luu gia tri found
				   //Lay ma so
		size_t found = line.find(basic);

		string ma_so;
		if (found != std::string::npos) {
			for (int i = 0; i < found; i++) {
				ma_so += line[i];
			}
		}
		k = found + 1;
		//Lay ten sinh vien
		found = line.find(basic, found + 1);

		string nguoi_muon;
		if (found != std::string::npos) {
			for (int i = k; i < found; i++) {
				nguoi_muon += line[i];
			}
		}
		k = found + 1;
		//Lay ten sach
		found = line.find(basic, found + 1);

		string ten_sach;
		if (found != std::string::npos) {
			for (int i = k; i < found; i++) {
				ten_sach += line[i];
			}
		}
		k = found + 1;
		//Lay thoi gian muon
		found = line.find(basic, found + 1);

		string thoi_gian_muon;
		if (found != std::string::npos) {
			for (int i = k; i < found; i++) {
				thoi_gian_muon += line[i];
			}
		}

		//Kiem tra da duoc duyet chua
		found = line.find("|n|");

		if (found != std::string::npos) {
			char choice;
			dem++;
			cout << ma_so << ". " << "Ten sinh vien: " << nguoi_muon << endl;
			cout << string(" ", ma_so.length() + 2) << "Ten sach muon: " << ten_sach << endl;
			cout << string(" ", ma_so.length() + 2) << "Thoi gian dang ki muon: " << thoi_gian_muon << endl;
			cout << string(" ", ma_so.length() + 2) << "Ban co dong y cho sinh vien muon sach khong?(y/n)";
			cin >> choice;
			if (choice == 'y') {
				line.replace(found, 3, "|y|");
				cout << "Duyet thanh cong!!!" << endl;
				fout << line << endl;
			}
			else {
				fout << line << endl;
			}
		}
		else {
			fout << line << endl;
			break;
		}
	}
	if (dem == 0) {
		cout << "Hien tai khong co yeu cau muon sach nao." << endl;
		system("pause");
	}
	fin.close();
	fout.close();
}
