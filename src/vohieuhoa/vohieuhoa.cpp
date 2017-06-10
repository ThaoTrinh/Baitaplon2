#include <vohieuhoa.h>

using namespace std;

bool vohieuhoa(Nguoidung & Ngdung_dangnhap){
	system("cls");
	fstream file("vohieuhoa.txt");
	if(!file.is_open()) {
		cout<<"Loi mo file";
		return false;
	}

	file<<Ngdung_dangnhap.Maso<<endl;
	file.close();
	return true;
}

bool kichhoat(Nguoidung &Ngdung_dangnhap){
	fstream file("vohieuhoa.txt");
	if(!file.is_open()){
		cout<<"Loi mo file";
		return false;
	}

	string bien= "";
	fstream file1("trong.txt");
	if(!file1.is_open()){
		cout<<"Loi mo file";
		return false;
	}

	while(getline(file,bien)){
		if(bien.empty()) continue;

		int maso;
		stringstream tach(bien);
		tach>>maso;

		if(maso==Ngdung_dangnhap.Maso) continue;
		file1<<bien;
	}

	ofstream xoa("vohieuhoa.txt");
	if(!xoa.is_open()){
		cout<<"Loi mo file ";
		return false;
	}

	fstream ghi("vohieuhoa.txt");
	if(!ghi.is_open()){
		cout<<"Loi mo file";
		return false;
	}

	string str;
	while(getline(file1,str)){
		if(str.empty()) continue;
		ghi<<str<<endl;
	}

	ofstream xoa1("trong.txt");
	if(!xoa1.is_open()){
		cout<<"Loi mo file ";
		return false;
	}

	ghi.close();
	file1.close();
	file.close();
	return true;
}

bool davohieuhoa(Nguoidung &Ngdung_dangnhap){
	system("cls");
	fstream file("vohieuhoa.txt");
	if(!file.is_open()) {
		cout<<"Loi mo file";
		return false;
	}
	string bien ="";
	while(getline(file,bien)){
		if(bien.empty()) continue;
		int maso=0;
		stringstream tach(bien);
		tach>>maso;
		if(maso!=Ngdung_dangnhap.Maso) continue;
		
		else{
			cout<<"Tai khoan cua ban da bi vo hieu hoa"<<endl;
			cout<<"Ban co muon bo che do vo hieu hoa(y/n)?  ";
			//cin.ignore();
			string y;
			cin>>y;
			if(y=="y"){
				if(!kichhoat(Ngdung_dangnhap)){
					cout<<"Khong the thuc hien"<<endl;
				}
			}
			 
			system("pause");
		}
		kiemtra=false;
	}
	
	return true;
}