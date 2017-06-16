#include <themsach.h>
using namespace std;

void Them_Sach() {
	sSach sach;
	string line;
	ifstream fin("sach.txt", ios::out);
	ofstream fout("sach.txt", ios::app);
	sach.STT = 0;
	while (fin.is_open()) {
		system("cls");
		while (!fin.eof()) {
			getline(fin, line);
			if (!line.empty()) {
				sach.STT++;
			}
		}
		fout << endl;
		fout << sach.STT << "|";
		cout << ".* THEM SACH *." << endl;
		cout << "Moi ban nhap thong tin sach: " << endl;

		cin.ignore();
		cout << "Ten sach: "; getline(cin, sach.Ten_Sach);
		fout << sach.Ten_Sach << "|";

		cout << "Tac gia: "; getline(cin, sach.Tac_Gia);
		fout << sach.Tac_Gia << "|";

		cout << "The loai: "; getline(cin, sach.The_Loai);
		fout << sach.The_Loai << "|";

		cout << "So luong: "; cin >> sach.So_Luong;
		fout << sach.So_Luong << "|";

		char choice;
		cout << "Ban co muon nhap them sach nua khong?(y/n)";
		cin >> choice;
		if (choice == 'y') {
			sach.STT++;
			continue;
		}
		else {
			break;
		}
	}
}
