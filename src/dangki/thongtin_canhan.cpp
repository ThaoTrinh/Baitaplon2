#include <thongtin_canhan.h>
#include <Docdulieu.h>

using namespace std;

bool Thongtin_canhan(vector<thongtin_nguoidung>& Dangki_taikhoan,vector<Nguoidung>& Dangnhap, Nguoidung & Ngdung_dangnhap){
	system("cls");
	fstream FILE("thongtin_nguoidung.txt");
	if (!FILE.is_open()){
		cout << "Loi mo file";
		return false;
	}

	string bien;
	int bien1;
	int vitri[9];
	string bien2, bien3, bien4,bien5, bien6;

	while(getline(FILE,bien)){
		if(bien.empty())
			continue;
		stringstream tach(bien);
		tach>>bien1;
		if(bien1!=Ngdung_dangnhap.Maso) 
			continue;
		
		// gặp hàng đúng người dùng				
		int dem=0;
		for(int i=0;i<bien.length();i++){// lấy vị trí gạch |
			if(bien[i]=='|'){
				vitri[dem]=i;
				dem++;
			}
		}

		// sao không tính hết rồi cout ra một chỗ,
		// đừng để chung vô, nhìn rối con mắt
		// còn tại sao lúc trước cout khoogn được là do
		// thiếu bit cuối, \0

		cout<<"Thong tin ca nhan cua ban la: "<<endl;
		cout<<"Ma so: "<<bien1<<endl;
		cout<<"Ho va ten: ";
			char ten[200];
			for(int i=vitri[0]+1;i<vitri[1];i++){
				ten[i]=bien[i];
				cout<<ten[i];
			}
		cout<<endl;

		cout << "So CMND: ";
		char cmnd[12];
		int tinh7 = 0;
		for (int i = vitri[1] + 1; i < vitri[2];i++){
			cmnd[tinh7] = bien[i];
			cout << cmnd[tinh7];
			tinh7++;
		}
		cout << endl;

		cout << "Nam sinh: ";
		char namsinh[6];
		int tinh = 0;
		for (int i = vitri[2] + 1; i < vitri[3]; i++) {
			namsinh[tinh] = bien[i];
			cout << namsinh[tinh];
			tinh++;
			}
		cout<<endl;

		cout << "Gioi tinh: ";
		char gioitinh[5];
		int tinh8 = 0;
		for (int i = vitri[3] + 1; i < vitri[4];i++){
			gioitinh[tinh8] = bien[i];
			cout << gioitinh[tinh8];
			tinh8++;
		}
		cout << endl;

		cout << "Dia chi: ";
		char diachi[50];
		int tinh1=0;
		for(int i=vitri[4]+1;i<vitri[5];i++){
			diachi[tinh1]=bien[i];
			cout<<diachi[tinh1];
			tinh1++;
		}
		cout<<endl;

		cout<<"Noi cong tac: ";
		char truong[60];
		int tinh2=0;
		for(int i=vitri[5]+1;i<vitri[6];i++){
			truong[tinh2]=bien[i];
			cout<<truong[tinh2];
			tinh2++;
		}
		cout<<endl;

		cout<<"Khoa: ";
		char khoa[50];
		int tinh3=0;
		for(int i=vitri[6]+1;i<vitri[7];i++){
			khoa[tinh3]=bien[i];
			cout<<khoa[tinh3];
			tinh3++;
		}
		cout<<endl;
	}
	FILE.close();
	system("pause");
	return true;


}