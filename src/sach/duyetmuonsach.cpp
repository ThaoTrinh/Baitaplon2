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
			char str[50];
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
			char str[50];
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
			ifstream itam("tam.txt", ios::app);
			ofstream otam("tam.txt", ios::app);
			otam << line << endl;
			itam.close();
			otam.close();
		}
		else {
			ifstream itam("tam.txt", ios::app);
			ofstream otam("tam.txt", ios::app);
			otam << line << endl;
			itam.close();
			otam.close();
		}
	}
	isach.close();
	osach.close();
	remove("sach.txt");
	rename("tam.txt", "sach.txt");
}

string ngay_tra_sach(string& bien) {
	string masach;
	string tensach;

	char ngay_str[4], thang_str[4], nam_str[10];
	int ngay, thang, nam;
	int vitri[8];
	int vitri_gach[8];
	
	int dem = 0;
	for (int i = 0; i < bien.length(); i++)//lay vi tri gach / 
	{
		if (bien[i] == '/')
		{
			vitri[dem] = i;
			dem++;
		}
	}
	int dem2 = 0;
	for (int i = 0; i < bien.length(); i++) //lay vi tri gach |
	{
		if (bien[i] == '|')
		{
			vitri_gach[dem2] = i;
			dem2++;
		
		}
	}
	//tach bien ngay/thang/nam
	/*ngay_str = bien.substr(vitri_gach[2] + 1, vitri[0] - vitri_gach[2] - 1);*/
	for (int i = vitri_gach[2] + 1; i < vitri[0]; i++) {
		ngay_str[i - vitri_gach[2] - 1] = bien[i];
	}

	
	/*thang_str = bien.substr(vitri[0] + 1, vitri[1] - vitri[0] - 1);*/
	for (int i = vitri[0] + 1; i < vitri[1]; i++) {
		thang_str[i - vitri[0] - 1] = bien[i];
	}
	
	
	/*nam_str = bien.substr(vitri[1] + 1, vitri_gach[3] - vitri[1] - 1);*/
	for (int i = vitri[1] + 1; i < vitri_gach[3]; i++) {
		nam_str[i - vitri[1] - 1] = bien[i];
	}
	
	//doi bien string sang int
	ngay = atoi(ngay_str);
	thang = atoi(thang_str); 
	nam = atoi(nam_str); 
	string thoi_gian;
	if (ngay == 31 || ngay == 30)
	{
		if (thang == 1)
		{
			itoa(nam, nam_str, 10);
			string year(nam_str);
			thoi_gian = "28/2/" + year;
		}
		if (thang < 12 && thang>2) 
		{	
			itoa(nam, nam_str, 10);
			string year(nam_str);
			thang += 1;
			itoa(thang, thang_str, 10);
			string month(thang_str);
			thoi_gian = "30/" + month + year;
		}

		if (thang == 12) {
			itoa(nam + 1, nam_str, 10);
			string year(nam_str);
			thoi_gian = "30/1/" + year;
		}

	}

	else if (ngay<30)
	{
		if (thang == 1 && ngay == 29) {
			itoa(nam, nam_str, 10);
			string year(nam_str);
			thoi_gian = "28/2/" + year;
		}
		else if (thang == 12) {
			itoa(ngay, ngay_str, 10);
			itoa(nam, nam_str, 10);
			string day(ngay_str), year(nam_str);
			thoi_gian = day + "/1/" + year;
		}
		else if (thang >= 2 && thang < 12) {
			itoa(ngay, ngay_str, 10);
			string day(ngay_str);
			itoa(nam, nam_str, 10);
			string year(nam_str);
			itoa(thang + 1, thang_str, 10);
			string month(thang_str);
			thoi_gian = day + "/" + month + "/" + year;
		}
	}
	return thoi_gian;
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
			string bien = line;
			
			line = NGUOI_MUON.ma_so + "|" + NGUOI_MUON.ten_sach + "|" + amount + "|" + ngay_tra_sach(bien) + "|y|";
			fout2 << endl;        //Ghi vao file thongbaotrasach.txt
			fout2 << line;
			fin2.close();
			fout2.close();
			ifstream fin_tam("tam.txt", ios::app);
			ofstream fout_tam("tam.txt", ios::in);
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
			ifstream itam("tam.txt");
			ofstream otam("tam.txt");
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
	rename("tam.txt", "PhieuMuonSach.txt");
	system("pause");
}

