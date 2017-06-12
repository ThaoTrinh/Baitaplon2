#include <insach.h>
#include <Timsach.h>

using namespace std;

bool timsach_theoten() {
	system("cls");
	fstream FILE("SachVanHoc.txt");
	fstream FILE1("SachKhoaHocTuNhien_KyThuat.txt");
	fstream FILE2("SachGiaoTrinh.txt");
	if (!FILE.is_open()) {
		cout << "Loi mo file";
		return false;
	}
	string masach;
	string tukhoa;
	string tensach;
	string bien;
	int vitri[6];
	cout << "Nhap tu khoa:" << " ";
	cin.ignore();
	getline(cin, tukhoa);
	
	//----------------------Doc file SachVanHoc.txt----------------------------------
	bool timthay=false;
	cout << "--------------------Danh sach tim duoc----------------------" << endl;
	while (getline(FILE, bien)) {
		if (bien.empty())
			continue;
		int dem = 0;
		for (int i = 0;i < bien.length();i++) {// lấy vị trí gạch |
			
			if (bien[i] == '|') {
				vitri[dem] = i;
				dem++;
			}
		}
		masach = bien.substr(0, vitri[0]);
		tensach = bien.substr(vitri[0] + 1, (vitri[1] - vitri[0] - 1));
		for (int i = 0; i < tensach.length(); i++)
		{
			for (int j = 0; j < tukhoa.length(); j++)
			{
				if (tukhoa[j]==tensach[i])
				{	
					int sosanh = tensach.compare(i, tukhoa.length(), tukhoa);
					if (sosanh==0)
					{
						timthay = true;
						cout <<masach<<" "<< tensach << endl;
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	while (getline(FILE1, bien)) {
		if (bien.empty())
			continue;
		int dem = 0;
		for (int i = 0;i < bien.length();i++) {// lấy vị trí gạch |

			if (bien[i] == '|') {
				vitri[dem] = i;
				dem++;
			}
		}
		masach = bien.substr(0, vitri[0]);
		tensach = bien.substr(vitri[0] + 1, (vitri[1] - vitri[0] - 1));
		for (int i = 0; i < tensach.length(); i++)
		{
			for (int j = 0; j < tukhoa.length(); j++)
			{
				if (tukhoa[j] == tensach[i])
				{
					int sosanh = tensach.compare(i, tukhoa.length(), tukhoa);
					if (sosanh == 0)
					{
						timthay = true;
						cout << masach << " " << tensach << endl;
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	while (getline(FILE2, bien)) {
		if (bien.empty())
			continue;
		int dem = 0;
		for (int i = 0;i < bien.length();i++) {// lấy vị trí gạch |

			if (bien[i] == '|') {
				vitri[dem] = i;
				dem++;
			}
		}
		masach = bien.substr(0, vitri[0]);
		tensach = bien.substr(vitri[0] + 1, (vitri[1] - vitri[0] - 1));
		for (int i = 0; i < tensach.length(); i++)
		{
			for (int j = 0; j < tukhoa.length(); j++)
			{
				if (tukhoa[j] == tensach[i])
				{
					int sosanh = tensach.compare(i, tukhoa.length(), tukhoa);
					if (sosanh == 0)
					{
						timthay = true;
						cout << masach << " " << tensach << endl;
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	
	
	
	if (timthay==false) {
		cout << "Khong tim thay sach" << endl;
	}
		FILE.close();
		FILE1.close();
		FILE2.close();
		system("pause");
		return true;
	}




