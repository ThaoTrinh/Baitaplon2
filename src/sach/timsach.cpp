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

	/*char tukhoa[50];*/
	string tukhoa;
	string tensach;
	char *p=0;
	string bien, bien1, bien2;
	int vitri[6];
	cout << "Nhap tu khoa:" << " ";
	cin.ignore();
	getline(cin, tukhoa);
	/*cin.ignore();
	cin.getline(tukhoa, 50);*/
	//Doc file  SachVanHoc.txt
	
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
			cout << vitri[0] << " " << vitri[1];
		
			for (int i = vitri[0] + 1; i < vitri[1]; i++)
			{
				
					tensach+= bien[i];
				
			}
			cout << tensach << endl;
			//string tensachmoi = tensach;
			/*for (int i = 0; i < tensach.length(); i++)
			{
				for (int j = 0; j < tukhoa.length(); j++)
				{
					if (tukhoa[j]==tensach[i])
					{
						
						int sosanh = tensach.compare(i, tukhoa.length(), tukhoa);
						if (sosanh==0)
						{
							cout << tensach << endl;
							break;
						}
						else
						{
							continue;
						}
					}
				}
			}*/
			/*p = strstr(tensach, tukhoa);
			if ((p - tensach) != 0)
			{
				cout << tensach << endl;
			}*/
		
	}
	//Doc file SachKhoaHocTuNhien_KyThuat.txt
	//while (getline(FILE1, bien1)) {
	//	if (bien1.empty())
	//		continue;
	//	for (int i = 0;i < bien1.length();i++) {// lấy vị trí gạch |
	//		int dem = 0;
	//		if (bien1[i] == '|') {
	//			vitri[dem] = i;
	//			dem++;
	//		}
	//		for (int i = vitri[0] + 1; i < vitri[1]; i++)
	//		{
	//			for (int j = 0; j < 50; j++)
	//			{
	//				tensach[j] = bien1[i];
	//			}
	//		}
	//		
	//		if ((p - tensach) != 0)
	//		{
	//			cout << tensach << endl;
	//		}
	//	}
	//}
	////Doc file SachGiaoTrinh.txt
	//while (getline(FILE2, bien2)) {
	//	if (bien2.empty())
	//		continue;
	//	for (int i = 0;i < bien2.length();i++) {// lấy vị trí gạch |
	//		int dem = 0;
	//		if (bien2[i] == '|') {
	//			vitri[dem] = i;
	//			dem++;
	//		}
	//		for (int i = vitri[0] + 1; i < vitri[1]; i++)
	//		{
	//			for (int j = 0; j < 50; j++)
	//			{
	//				tensach[j] = bien2[i];
	//			}
	//		}
	//		
	//		p = strstr(tensach, tukhoa);
	//		if ((p - tensach) != 0)
	//		{
	//			cout << tensach << endl;
	//		}
	//	}

		FILE.close();
		FILE1.close();
		FILE2.close();
		system("pause");
		return true;
	}




