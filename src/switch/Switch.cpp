#include <switch.h>
#include <Chucnang.h>
#include <Doi_matkhau.h>
#include <lichsu_dangnhap.h>
#include <tuychon.h>
#include <switch_nguoidung.h>
#include <vohieuhoa.h>

using namespace std;

int Caidat(){
	system("cls");

	cout<<"Moi ban chon tuy chon: "<<endl;
	cout<<"1.	Them chuc nang"<<endl;
	cout<<"2.	Huy chuc nang"<<endl;
	cout<<"3.	Doi mat khau"<<endl;
	cout<<"4.	Quay lai"<<endl;

	cout<<"Lua chon cua ban la: ";
	int chon;
	cin>>chon;
	while (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Loi nhap lua chon. Vui long nhap lai: ";
		cin >> chon;

	}
	return chon;

}


void Caidat_switch(vector<Nguoidung>& Dangnhap, Nguoidung & Ngdung_dangnhap){

	while(true){
		switch(Caidat()){
			case 1:
				Themchucnang(Dangnhap,Ngdung_dangnhap);
				break;
			case 2:
				Huychucnang(Dangnhap,Ngdung_dangnhap);
				break;
			//case 3:break;
			case 3:
				cin.ignore();
				if(!Doimatkhau(Dangnhap,Ngdung_dangnhap))
					tuychinh=false;
				break;
			case 4:
				//quay lại cái switch ở trên
				/*tuychinh=false;
				break;*/
				return;
		}// hết switch
	}// hết while
}// hết hàm



void Switch_Chucnang(vector<thongtin_nguoidung>& Dangki_taikhoan,vector<Nguoidung>& Dangnhap,Nguoidung & Ngdung_dangnhap,vector<string>SachGiaoTrinh,sach & Giaotrinh){

	switch(Tuychon_chucnang(Dangnhap,Ngdung_dangnhap)){
		case 1:{
			if (Ngdung_dangnhap.ngdung.docgia==1){
				Switch_docgia(Dangki_taikhoan,Dangnhap,Ngdung_dangnhap,SachGiaoTrinh,Giaotrinh);
				break;			
			}
			
			cout<<"Chuc nang cua ban chua duoc kich hoat."<<endl;
			cout<<"Ban co muon chon chuc nang khac"<<endl;
			cin.ignore();
			string y;
			getline(cin,y);
			if(y =="y")
				break;
			return;

			
		 }// case docgia

		// thủ thư
		case 2:{
			if(Ngdung_dangnhap.ngdung.thuthu==2){
				Switch_thuthu(Dangki_taikhoan,Dangnhap,Ngdung_dangnhap);
				break;
			}
			
			cout<<"Chuc nang cua ban chua duoc kich hoat."<<endl;
			cout<<"Ban co muon chon chuc nang khac"<<endl;
			cin.ignore();
			string y;
			getline(cin,y);
			if(y =="y")
				break;
			return;
		 }// case thủ thư
	
		// quản lý
		case 3:{
			if(Ngdung_dangnhap.ngdung.quanli==3){
				Switch_quanli(Dangki_taikhoan,Dangnhap,Ngdung_dangnhap);
				break;
			}

			cout<<"Chuc nang cua ban chua duoc kich hoat."<<endl;
			cout<<"Ban co muon chon chuc nang khac"<<endl;
			cin.ignore();
			string y;
			getline(cin,y);
			if(y =="y")
				break;
			return;
		 }// case quản lý

		// lịch sử đăng nhập
		case 4:
			if(!dangnhap_lichsu(Ngdung_dangnhap)){
				cout<<"Khong thuc hien duoc"<<endl;
			}
			system("pause");
			break;

		// đăng xuất
		case 5: {
			cout<<"Neu vo hieu hoa tai khoan ban khong the truy cap bat ki tuy chon nao"<<endl;
			cout<<"Ban muon vo hieu hoa tai khoan? (y/n)"<<endl;
			cin.ignore();
			string y;
			cin>>y;
			if(y=="y"){
				if(!vohieuhoa(Ngdung_dangnhap)){
					cout<<"Khong thuc hien duoc chuc nang nay"<<endl;
				}
				cout<<"Ban da vo hieu hoa tao khoan thanh cong"<<endl;
			}
			system("pause");
			kiemtra=false;
			return;
			break;
		}
		case 6:
			
			kiemtra=false;
			// nên hàm while sẽ chạy if (!kiemtra)
			// nên sẽ chạy lại màn hình chính

			time_t now = time(0);
			char* dangxuat = ctime(&now);
	
			fstream file("lichsu_dangnhap.txt",ios::app);
			if(!file.is_open()){
				cout<<"loi mo file"<<endl;
					
			}
			file<<Ngdung_dangnhap.Maso<<"	"<<"0	"<<dangxuat;

			file.close();
			return; 
	}// hết switch
}// hết hàm


