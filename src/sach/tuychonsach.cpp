#include <tuychonsach.h>

using namespace std;
int timkiem() {
	system("cls");
	cout << "1. Tim kiem theo ten." << endl;
	cout << "2. Tim kiem theo the loai." << endl;
	cout << "3. Quay lai." << endl;
	cout << "Lua chon cua ban la: ";
	int chon;
	cin >> chon;
	while (chon < 0 || int(chon) != chon || chon > 4)
	{
		cout << "Khong hop le !! Vui long nhap dung lua chon: ";
		cin >> chon;
	}
	return chon;
}