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
	bool timthay = false;
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
		
		/*char* c = new char[hoten.size() + 1];
		copy(hoten.begin(),hoten.end(), c);
		c[hoten.size()] = '\0';
		string hotenthuong = strlwr(c);*/
		int maso;
		if(ten==hoten){
			maso=so;
			timthay = true;
			Thongtin_canhan(maso);
		}
		else continue;
		cout<<endl;
	}

	if (!timthay) {
		cout<<"Khong tim thay thong tin nguoi dung"<<endl;
		cout<<"Ban hay thu viet hoa chu cai dau"<<endl;
		system("pause");
	}

		file.close();
		//system("pause");
		return true;
}