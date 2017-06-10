#include <timkiem_nguoidung.h>
#include <thongtin_canhan.h>

using namespace std;

bool timnguoidung(){// không bị lỗi nếu release VS 10
	system("cls");
	cout<<"Nhap ho va ten nguoi can tim kiem: ";
	string ten;
	getline(cin,ten);

	fstream file("ten.txt");
	if (!file.is_open()){
		cout << "Loi mo file";
		return false;
	}

	string bien;
	while(getline(file,bien)){

		if (bien.empty())
			continue;

		stringstream tach(bien);
		int so;
		string bien2;
		tach>>so;
		//cout<<so;
		int vitri[2];
		int dem=0;
		for(int i=0;i<bien.length();i++){// lấy vị trí gạch |
			if(bien[i]=='|'){
				vitri[dem]=i;
				dem++;
			}
		}

		string hoten = "";
		int dem1=0;
		for(int i=vitri[0]+1;i<vitri[1];i++){
			hoten += bien[i];
			dem1++;
		}
		int maso;
		if(ten==hoten){
			maso=so;
			
		}
		else continue;
		//cout<<maso;
		//cin.ignore();
		/*if(!laythongtin(maso)){
			cout<<"Khong tim thay nguoi dung"<<endl;
		}*/
		Thongtin_canhan(maso);
		cout<<endl;
	}
		file.close();
		//system("pause");
		return true;
}