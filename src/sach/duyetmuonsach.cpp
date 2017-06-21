#include <DuyetMuonSach.h>

using namespace std;

NguoiMuon Xu_li_dong(string line, NguoiMuon& NGUOI_MUON) {
	if (!line.empty()) {
		string basic = "|";

		int k = 0; // dung de luu gia tri found
				   //Lay ma so
		size_t found = line.find(basic);

		if (found != std::string::npos) {
			for (int i = 0; i < found; i++) {
				NGUOI_MUON.ma_so += line[i];
			}
		}

		k = found + 1;
		//Lay ten sinh vien
		found = line.find(basic, found + 1);

		if (found != std::string::npos) {
			for (int i = k; i < found; i++) {
				NGUOI_MUON.biet_hieu += line[i];
			}
		}

		k = found + 1;
		//Lay ten sach
		found = line.find(basic, found + 1);

		if (found != std::string::npos) {
			for (int i = k; i < found; i++) {
				NGUOI_MUON.ten_sach += line[i];
			}
		}

		k = found + 1;
		//Lay thoi gian muon
		found = line.find(basic, found + 1);

		if (found != std::string::npos) {
			for (int i = k; i < found; i++) {
				NGUOI_MUON.thoi_gian_muon += line[i];
			}
		}
		k = found + 1;

		//Lay so luong sach muon
		found = line.find(basic, found + 1);

		if (found != std::string::npos) {
			char str[2];
			for (int i = k; i < found; i++) {
				str[i - k] = line[i];
			}
			NGUOI_MUON.so_luong = atoi(str);
		}
		string str = "|n|";
		if (line.find(str) != std::string::npos) {
			NGUOI_MUON.status = line[line.find(str) + 2];
		}
		return NGUOI_MUON;
	}
}

void sua_so_luong_sach(NguoiMuon NGUOI_MUON) {
	ifstream isach("sach.txt", ios::out);
	ofstream osach("sach.txt", ios::in);
	//Mo file sach.txt va lay du lieu
	string line;
	while (getline(isach, line)) {
		sSach sach;
		//lay vi tri cua "|"
		string basic = "|";

		int k = 0; // dung de luu gia tri found
				   //Lay ma so
		size_t found = line.find(basic);

		if (found != std::string::npos) {
			for (int i = 0; i < found; i++) {
				sach.STT += line[i];
			}
		}

		k = found + 1;
		//Lay ten sinh vien
		found = line.find(basic, found + 1);

		if (found != std::string::npos) {
			for (int i = k; i < found; i++) {
				sach.Ten_Sach += line[i];
			}
		}

		k = found + 1;
		//Lay ten sach
		found = line.find(basic, found + 1);

		if (found != std::string::npos) {
			for (int i = k; i < found; i++) {
				sach.Tac_Gia += line[i];
			}
		}

		k = found + 1;
		//Lay thoi gian muon
		found = line.find(basic, found + 1);

		if (found != std::string::npos) {
			for (int i = k; i < found; i++) {
				sach.The_Loai += line[i];
			}
		}
		k = found + 1;

		//Lay so luong sach 
		found = line.find(basic, found + 1);

		if (found != std::string::npos) {
			char str[10];
			for (int i = k; i < found; i++) {
				str[i - k] = line[i];
			}
			sach.So_Luong = atoi(str); //Chuyen string ->int
		}
					
		if (sach.Ten_Sach == NGUOI_MUON.ten_sach) {
			//Giam so luong sach
			sach.So_Luong -= NGUOI_MUON.so_luong;

			//Chuyen so luong int ->string
			char amount[5];
			itoa(sach.So_Luong, amount, 10);

			//Ghi lai dong do trong file sach.txt
			line = line.replace(k, found - k, amount);
			ifstream itam("trong.txt", ios::app);
			ofstream otam("trong.txt", ios::app);
			otam << line << endl;
			itam.close();
			otam.close();
		}
		else {
			ifstream itam("trong.txt", ios::app);
			ofstream otam("trong.txt", ios::app);
			otam << line << endl;
			itam.close();
			otam.close();
		}
	}
	isach.close();
	osach.close();
	remove("sach.txt");
	rename("trong.txt", "sach.txt");
}

void duyet_muon_sach() {

	ifstream fin("PhieuMuonSach.txt", ios::app);
	ofstream fout("PhieuMuonSach.txt", ios::in);
	
	system("cls");
	string line;
	cout << ".* DUYET MUON SACH *." << endl;
	while (getline(fin, line)) {
		//Xu ly dong dau vao
		NguoiMuon NGUOI_MUON;
		Xu_li_dong(line, NGUOI_MUON);

		char choice;
		//In ra phieu duyet
		cout << string(" ", 2) << "Ma so: " << NGUOI_MUON.ma_so << endl;
		cout << string(" ", 2) << "Biet hieu: " << NGUOI_MUON.biet_hieu << endl;
		cout << string(" ", 2) << "Ten sach muon: " << NGUOI_MUON.ten_sach << endl;
		cout << string(" ", 2) << "Thoi gian dang ki muon: " << NGUOI_MUON.thoi_gian_muon << endl;
		cout << string(" ", 2) << "So luong: " << NGUOI_MUON.so_luong << endl;
		cout << string(" ", 2) << "Ban co dong y cho sinh vien muon sach khong?(y/n)";
		cin >> choice;

		//Lua chon de ghi vao file

		if (choice == 'y') {

			//Chinh sua file nguon sach.txt

			sua_so_luong_sach(NGUOI_MUON);
			/*size_t found = line.find("|n|");
			line = line.replace(found+1, 1, "y");*/
			
			cout << "Duyet thanh cong!!!" << endl;

			//Chuyen sang file thongbaotrasach.txt
			ifstream fin2("thongbaotrasach.txt", ios::app);
			ofstream fout2("thongbaotrasach.txt", ios::app);
			char amount[5];
			itoa(NGUOI_MUON.so_luong, amount, 10);
			line = NGUOI_MUON.ma_so + "|" + NGUOI_MUON.ten_sach + "|" + amount + "|" + NGUOI_MUON.thoi_gian_muon + "|y|";
			fout2 << endl;        //Ghi vao file thongbaotrasach.txt
			fout2 << line;
			fin2.close();
			fout2.close();
			ifstream fin_tam("trong.txt", ios::app);
			ofstream fout_tam("trong.txt", ios::in);
			line = line.replace(line.find(line), line.length(), "");
			fout_tam << line;      //Luu vao file tam.txt
			fin_tam.close();
			fout_tam.close();
		}
		else {
			ifstream fin2("thongbaotrasach.txt", ios::app);
			ofstream fout2("thongbaotrasach.txt", ios::app);
			char amount[5];
			itoa(NGUOI_MUON.so_luong, amount, 10);
			line = NGUOI_MUON.ma_so + "|" + NGUOI_MUON.ten_sach + "|" + amount + "|" + NGUOI_MUON.thoi_gian_muon + "|n|";
			fout2 << endl;
			fout2 << line;     //Ghi vao file thongbaotrasach.txt
			fout2.close();
			fin2.close();
			ifstream itam("trong.txt");
			ofstream otam("trong.txt");
			line = line.replace(line.find(line), line.length(), "");
			otam << line;   //Luu vao file tam.txt
			itam.close();
			otam.close();
		}
		cout << endl;
	}

	cout << "Da het yeu cau muon sach!" << endl;

	fin.close();
	fout.close();
	remove("PhieuMuonSach.txt");
	rename("trong.txt", "PhieuMuonSach.txt");
	system("pause");
}

