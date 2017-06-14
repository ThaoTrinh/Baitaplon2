#include <quen_matkhau.h>
using namespace std;

bool quenmatkhau(){
	
	system("cls");
	cout<<"Ban quen mat khau cua minh?"<<endl;
	cout<<"Ban co muon gui yeu cau den nguoi quan li de reset lai mat khau(y/n): ";
	string y;
	cin>>y;
	if(y!="y"){
		kiemtra=false;
		return false;
	}
	cin.ignore();

	cout<<"Nhap ten cua ban: ";
	string ten;
	getline(cin,ten);
	cout<<"Nhap ma so sinh vien: ";
	string mssv;
	getline(cin,mssv);
	cout<<"Nhap ten tai khoan: ";
	string taikhoan;
	getline(cin,taikhoan);

	fstream file("quenmatkhau.txt");
	if(!file.is_open()){
		cout<<"Loi mo file: "<<endl;
		return false;
	}

	file<<"|"<<ten<<"|"<<mssv<<"|"<<taikhoan<<"|"<<endl;
	file.close();
	return true;
}

bool resetmatkhau(){
	system("cls");
	fstream file("quenmatkhau.txt");
	if(!file.is_open()){
		cout<<"Loi mo file: "<<endl;
		return false;
	}
	string bien;
	int vitri[5];
	int tinh=0;
	while(getline(file,bien)){
	//getline(file,bien);
		if(bien.empty()) continue;
		
	int dem=0;
		
		for(int i=0;i<bien.length();i++){// lấy vị trí gạch |
			if(bien[i]=='|'){
				vitri[dem]=i;
				dem++;
			}
			tinh++;
		}
		string hoten;
		for(int i=vitri[0]+1;i<vitri[1];i++){
			hoten+=bien[i];
		}
		string tentaikhoan;
		for(int i=vitri[2]+1;i<vitri[3];i++){
			tentaikhoan+=bien[i];
		}
			cout<<hoten<<" muon reset lai mat khau "<<endl;
			cout<<"Ban co dong y(y/n)?: ";
			string y;
			cin>>y;
			
			if(y!="y"){
				cout<<"Tai khoan nguoi dung reset khong duoc chap thuan"<<endl;
				cout<<"Gui mail thong bao den nguoi dung thanh cong"<<endl;
				cout<<"Nhan enter de quay lai"<<endl;
				//break;
			}
			else{
				srand(time(NULL));
				string matkhaumoi="";
					for(int i=0;i<5;i++){
						matkhaumoi+=rand()%26+97;
					}
				string str;
				fstream file2("dangnhap.txt");
				int maso;
				string taikhoan;
				string matkhau;
				string biethieu;
				fstream file3("trong.txt");
				while(getline(file2,str)){
				
					if(str.empty()) continue;
					stringstream tach(str);
					tach>>maso>>taikhoan>>matkhau>>biethieu;
					if(tentaikhoan==taikhoan){
						file3<<maso<<"	"<<taikhoan<<"	"<<matkhaumoi<<"	"<<biethieu<<endl;
						continue;
					
					}
					file3<<str<<endl;
				}
				file2.close(); 
				file3.close();
				fstream file4("trong.txt");
				ofstream xoa("dangnhap.txt");
				fstream ghi("dangnhap.txt");
				string str1;
				while(getline(file4,str1)){
						ghi<<str1<<endl;
				}
				ofstream xoa1("trong.txt");
				ghi.close();
				file4.close();

				cout<<"Gui mail thong bao den nguoi dung thanh cong"<<endl;
				cout<<"Nhan enter de quay lai"<<endl;
				
			}

			ofstream file1("quenmatkhau.txt");
					if(!file1.is_open()){
						cout<<"Loi mo file: "<<endl;
						return false;
					}
				while(getline(file,bien)){
					file1<<bien<<endl;
				}
			break;
	}
	if (tinh==0){
		cout<<"Khong co yeu cau reset mat khau"<<endl;		
	}
	file.close();
	system("pause");
	return true;
}