#include <insach.h>
#include <Timsach.h>

using namespace std;

void timsach_theoten() {
	system("cls");
	fstream FILE("SachVanHoc.txt");
	fstream FILE1("SachKhoaHocTuNhien_KyThuat.txt");
	fstream FILE2("SachGiaoTrinh.txt");
	if (!FILE.is_open()) {
		cout << "Loi mo file";
		return;
	}

	char tukhoa[50];
	char tensach[50];
	char *p;
	string bien;
	int vitri[5];
	while (getline(FILE, bien)) {
		if (bien.empty())
			continue;
		for (int i = 0;i < bien.length();i++) {// lấy vị trí gạch |
			int dem = 0;
			if (bien[i] == '|') {
				vitri[dem] = i;
				dem++;
			}
			for (int i = vitri[0] + 1; i < vitri[1]; i++)
			{
				for (int j = 0; j < 50; j++)
				{
					tensach[j] = bien[i];
				}
			}
			cout << "Nhap tu khoa:" << " ";
			cin.getline(tukhoa, 255);
			p = strstr(tensach, tukhoa);
			if ((p - tensach) != 0)
			{
				cout << tensach << endl;
			}
		}
	}
	while (getline(FILE1, bien)) {
		if (bien.empty())
			continue;
		for (int i = 0;i < bien.length();i++) {// lấy vị trí gạch |
			int dem = 0;
			if (bien[i] == '|') {
				vitri[dem] = i;
				dem++;
			}
			for (int i = vitri[0] + 1; i < vitri[1]; i++)
			{
				for (int j = 0; j < 50; j++)
				{
					tensach[j] = bien[i];
				}
			}
			cout << "Nhap tu khoa:" << " ";
			cin.getline(tukhoa, 255);
			p = strstr(tensach, tukhoa);
			if ((p - tensach) != 0)
			{
				cout << tensach << endl;
			}
		}
	}
			while (getline(FILE2, bien)) {
				if (bien.empty())
					continue;
				for (int i = 0;i < bien.length();i++) {// lấy vị trí gạch |
					int dem = 0;
					if (bien[i] == '|') {
						vitri[dem] = i;
						dem++;
					}
					for (int i = vitri[0] + 1; i < vitri[1]; i++)
					{
						for (int j = 0; j < 50; j++)
						{
							tensach[j] = bien[i];
						}
					}
					cout << "Nhap tu khoa:" << " ";
					cin.getline(tukhoa, 255);
					p = strstr(tensach, tukhoa);
					if ((p - tensach) != 0)
					{
						cout << tensach << endl;
					}
				}

				FILE.close();
				system("pause");
				return;
			}
		}


	