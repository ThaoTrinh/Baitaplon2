#include <themsach.h>
using namespace std;

void Them_Sach() {
	bool check = true;
	do {
		sSach sach;
		string line;
		int test = 0;		//Test sach da them vao co trong thu vien chua
		ifstream fin("sach.txt", ios::app);
		ofstream fout("sach.txt", ios::app);
		system("cls");
		cout << ".* THEM SACH *." << endl;
		cout << "Moi ban nhap thong tin sach: " << endl;

		cin.ignore();
		cout << "Ten sach: "; getline(cin, sach.Ten_Sach);
		cout << "Tac gia: "; getline(cin, sach.Tac_Gia);
		cout << "The loai: "; getline(cin, sach.The_Loai);

		sach.STT = 0;
		while (getline(fin, line)) {					//kiem tra sach them vao da co trong thu vien chua
			string TenSach, TacGia, TheLoai;
			if (line.empty()) continue;
			sach.STT++;
			char index[5];
			int dem = 0;
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == '|') {
					index[dem] = i;
					dem++;
				}
			}
			for (int i = index[0] + 1; i < index[1] ; i++) {
				TenSach += line[i];
			}
			for (int i = index[1] + 1; i < index[2]; i++) {
				TacGia += line[i];
			}
			for (int i = index[2] + 1; i < index[3]; i++) {
				TheLoai += line[i];
			}
			if (TenSach == sach.Ten_Sach && TacGia == sach.Tac_Gia && TheLoai==sach.The_Loai) {
				cout << endl;
				cout << "Trong thu vien da co sach ban them. " << endl;
				char SoLuong[2];
				for (int i = index[3] + 1; i < index[4]; i++) {
					SoLuong[i - index[3] - 1] = line[i];			//Lay ra so luong sach trong kho
				}

				cout << "Moi ban nhap so luong: ";
				cin >> sach.So_Luong;
				ifstream in("trong.txt", ios::app);
				ofstream out("trong.txt", ios::app);
				sach.So_Luong += atoi(SoLuong);
				char amount[10];
				itoa(sach.So_Luong, amount, 10);
				line = line.replace(index[3] + 1, index[4] - index[3] - 1, amount);
				out << line << endl;
				in.close();
				out.close();
				test = 1;			//Sach can them co trong thu vien
			}
			else {
				ifstream in("trong.txt", ios::app);
				ofstream out("trong.txt", ios::app);
				out << line << endl;
				in.close();
				out.close();
			}
		}			
		if (test == 0) {					//Sach chua co trong thu vien. Tao moi danh sach.
			cout << endl;
			cout << "Day la sach moi chua co trong thu vien." << endl;
			cout << "Moi ban nhap so luong: ";
			cin >> sach.So_Luong;
			ifstream in("trong.txt", ios::app);
			ofstream out("trong.txt", ios::app);
			out << sach.STT << "|" << sach.Ten_Sach << "|" << sach.Tac_Gia << "|" << sach.The_Loai << "|" << sach.So_Luong << "|" << endl;
			in.close();
			out.close();
		}
		fin.close();
		fout.close();
		remove("sach.txt");
		rename("trong.txt", "sach.txt");
		char choice;
		cout << "Ban co muon nhap them sach nua khong?(y/n)";
		cin >> choice;
		if (choice == 'y') {
			check = true;
			continue;
		}
		else {
			check = false;
			break;
		}
	} while (check == true);
}
