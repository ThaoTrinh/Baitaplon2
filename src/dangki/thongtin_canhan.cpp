#include <thongtin_canhan.h>
#include <Docdulieu.h>

using namespace std;

bool Thongtin_canhan(int & maso){
	system("cls");
	fstream FILE("thongtin_nguoidung.txt");
	if (!FILE.is_open()){
		cout << "Loi mo file";
		return false;
	}

	string bien;
	int bien1;
	int vitri[12];
	string bien2, bien3, bien4,bien5, bien6;

	while(getline(FILE,bien)){
		if(bien.empty())
			continue;
		stringstream tach(bien);
		tach>>bien1;
		if(bien1!= maso) 
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
		//cout<<dem<<endl;
		cout<<"Thong tin cua nguoi dung la: "<<endl;
		cout<<"Ma so: "<<bien1<<endl;
		cout<<"Ho va ten: ";
			string ten;
			for(int i=vitri[0]+1;i<vitri[1];i++){
				ten+=bien[i];
			}
			cout<<ten<<endl;
			

		cout<<"Ma so sinh vien/nhanvien: ";
		string mssv;
		for(int i=vitri[1]+1;i<vitri[2];i++){
			mssv+=bien[i];
			
		}
		cout<<mssv<<endl;

		cout << "So CMND: ";
		string cmnd;
		for (int i = vitri[2] + 1; i < vitri[3];i++){
			cmnd+= bien[i];
		}
		cout<< cmnd<<endl;

		cout << "Nam sinh: ";
		string namsinh;
		for (int i = vitri[3] + 1; i < vitri[4]; i++) {
			namsinh += bien[i];

			}
		cout<<namsinh<<endl;

		cout << "Gioi tinh: ";
		string gioitinh;
		for (int i = vitri[4] + 1; i < vitri[5];i++){
			gioitinh += bien[i];
		}
		cout << gioitinh<<endl;

		cout << "Dia chi: ";
		string diachi;
		for(int i=vitri[5]+1;i<vitri[6];i++){
			diachi+=bien[i];
		}
		cout<<diachi<<endl;

		cout<<"Nghe nghiep: ";
		string nghe;
		for(int i=vitri[6]+1;i<vitri[7];i++){
			nghe+=bien[i];
		}
		cout<<nghe<<endl;

		cout<<"Noi cong tac: ";
		string truong;
		for(int i=vitri[7]+1;i<vitri[8];i++){
			truong+=bien[i];
		}
		cout<<truong<<endl;

		cout<<"Khoa: ";
		string khoa;
		for(int i=vitri[8]+1;i<vitri[9];i++){
			khoa +=bien[i];
		}
		cout<<khoa<<endl;

		cout<<"Dia chi email: ";
		string email;
		for(int i=vitri[9]+1;i<vitri[10];i++){
			email +=bien[i];
		}
		cout<<email<<endl;
	}


	FILE.close();
	system("pause");
	return true;


}


