#include <DuyetTraSach.h>

using namespace std;

void phat(int id, string tensach) {
	fstream icheck("dangnhap.txt");
	string line;
	while (getline(icheck, line)){
		Nguoidung NGUOI_DUNG;
		stringstream sline(line);
		sline >> NGUOI_DUNG.Maso >> NGUOI_DUNG.Taikhoan >> NGUOI_DUNG.Matkhau >> NGUOI_DUNG.Biethieu;
		if (NGUOI_DUNG.Maso == id) {
			cout << NGUOI_DUNG.Biethieu << " da tra sach qua han va bi dua vao danh sach phat." << endl;
		}
		continue;
	}

	icheck.close();
	
	fstream iphat("phat.txt");
	iphat << id << "|" << tensach << "|" << endl;
	iphat.close();
}

void so_sach(string tensach, int soluong) {
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

		if (sach.Ten_Sach == tensach) {
			//Giam so luong sach
			sach.So_Luong += soluong;
			
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

void duyet_tra_sach() {
	system("cls");
	ifstream in("phieutrasach.txt", ios::app);
	ofstream out("phieutrasach.txt", ios::app);
	if (!in.is_open()) {
		cout << "Loi mo file." << endl;
	}
	string line;
	while (getline(in, line)) {
		int luuvitri[10];
		int dem = 0;
		for (int i = 0; i < line.length(); i++) {		//Lay vi tri dau |
			if (line[i] == '|') {
				luuvitri[dem] = i; 
				dem++;	
			}
		}
		int luuvitri2[4];
		dem = 0;
		for (int i = 0; i < line.length(); i++) {		//Lay vi tri dau /
			if (line[i] == '/') {
				luuvitri2[dem] = i;
				dem++;
			}
		}
		char ddate[20];
		for (int i = luuvitri[2] + 1; i < luuvitri2[0]; i++) {		//Lay ra ngay deadline
			ddate[i - luuvitri[2] - 1] = line[i];
		}
		char dmonth[20];
		for (int i = luuvitri2[0] + 1; i < luuvitri2[1]; i++) {		//Lay ra thang deadline
			dmonth[i - luuvitri2[0] - 1] = line[i];
		}
		char dyear[40];
		for (int i = luuvitri2[1] + 1; i < luuvitri[3]; i++) {		//Lay ra nam deadline
			dyear[i - luuvitri2[1] - 1] = line[i];
		}
		char date[20];
		for (int i = luuvitri[4] + 1; i < luuvitri2[2]; i++) {		//Lay ra ngay tra
			date[i - luuvitri[4] - 1] = line[i];
		}
		char month[20];
		for (int i = luuvitri2[2] + 1; i < luuvitri2[3]; i++) {		//Lay ra thang tra
			month[i - luuvitri2[2] - 1] = line[i];
		}
		char year[40];
		for (int i = luuvitri2[3] + 1; i < luuvitri[5]; i++) {		//Lay ra nam tra
			year[i - luuvitri2[3] - 1] = line[i];
		}

		string tensach = "";
		char ch_soluong[2];
		int soluong;
		char id_str[10];
		for (int i = 0; i < luuvitri[0]; i++) {
			id_str[i] = line[i];
		}
		int id = atoi(id_str);
		for (int i = luuvitri[1] + 1; i < luuvitri[2]; i++) {
			ch_soluong[i - luuvitri[1] - 1] = line[i];
		}
		for (int i = luuvitri[0] + 1; i < luuvitri[1]; i++) {
			tensach += line[i];
		}
		if (atoi(year) > atoi(dyear)) {
			
			phat(id, tensach);
			
		}
		else if (atoi(month) > atoi(dmonth)) {
			
			phat(id, tensach);

		}
		else if (atoi(date) > atoi(ddate) && atoi(month) == atoi(dmonth) && atoi(year) == atoi(dyear)) {
			
			phat(id, tensach);
		}
		else {
			
			soluong = atoi(ch_soluong);

			cout << ".* DUYET MUON SACH *." << endl;
			cout << "Biet hieu nguoi dung: ";
			fstream icheck("dangnhap.txt");
			string line;
			while (getline(icheck, line)) {
				Nguoidung NGUOI_DUNG;
				stringstream sline(line);
				sline >> NGUOI_DUNG.Maso >> NGUOI_DUNG.Taikhoan >> NGUOI_DUNG.Matkhau >> NGUOI_DUNG.Biethieu;
				if (NGUOI_DUNG.Maso == id) {
					cout << NGUOI_DUNG.Biethieu << endl;
				}
				continue;
			}
			icheck.close();
			cout << "Ten sach: " << tensach << endl;
			cout << "So luong tra: " << soluong << endl;
			cout << "Moi ban xac nhan tra sach.(y/n) ";
			char choice;
			cin >> choice;
			if (choice == 'y') {
				so_sach(tensach, soluong);
				cout << "Duyet thanh cong." << endl;
			}
			else {
				cout << "Ban khong dong y duyet." << endl;
			}
			ifstream fin_tam("tam.txt", ios::app);
			ofstream fout_tam("tam.txt", ios::in);
			line = line.replace(line.find(line), line.length(), "");
			fout_tam << line;      //Luu vao file tam.txt
			fin_tam.close();
			fout_tam.close();

		}

	}
	cout << "Da het yeu cau tra sach!" << endl;
	in.close();
	out.close();
	remove("phieutrasach.txt");
	rename("tam.txt", "phieutrasach.txt");
	system("pause");
}