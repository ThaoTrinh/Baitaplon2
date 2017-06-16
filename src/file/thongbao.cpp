#include <thongbao.h>

using namespace std;

bool Xemthongbao(Nguoidung & Ngdung_dangnhap){
	system("cls");
	fstream file("thongbaotrasach.txt");
	if(!file.is_open()){
		cout<<"Loi mo file"<<endl;
		return false;
	}
	cout<<"Ban co cac thong bao: "<<endl;
	cout<<"*---------------------------------------------------------------*"<<endl;
	string bien="";
	int vitri[7];
	int tinh=0;
	while(getline(file,bien)){
		if(bien.empty()) continue;
		int maso=0;
		stringstream tach(bien);
		tach>>maso;
		if(maso!=Ngdung_dangnhap.Maso) continue;

		int dem=0;
		for(int i=0;i<bien.length();i++){// lấy vị trí gạch |
			if(bien[i]=='|'){
				vitri[dem]=i;
				dem++;
			}
		}
		
		string tensach="";
		for(int i=vitri[0]+1;i<vitri[1];i++){
			tensach +=bien[i];
			tinh++;
		}

		string ngay="";
		for(int i=vitri[2]+1;i<vitri[3];i++){
			ngay +=bien[i];
		}

		string muon="";
		for(int i=vitri[3]+1;i<vitri[4];i++){
			muon +=bien[i];
		}
		
		if(muon=="n"){
			cout<<"Ban khong duoc chap nhan muon sach: "<<tensach<<endl;
		}
		else{
			cout<<"Ban da duoc muon quyen: "<<tensach<<endl;
			cout<<"Ngay ban phai tra sach la: "<<ngay<<endl;
		}

		cout<<"*---------------------------------------------------------------*"<<endl;
		continue;

	}

	if(tinh==0){
		cout<<"Ban khong co thong bao nao"<<endl;
	}
	file.close();
	system("pause");
	return true;
}
