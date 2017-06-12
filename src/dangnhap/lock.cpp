#include <lock.h>

using namespace std;

bool lock(Nguoidung & Ngdung_dangnhap,int dem){

	if(dem==1){
		cout<<"Ban con lai 2 lan dang nhap"<<endl;
	}

	if(dem==2){
		cout<<"Ban con lai 1 lan dang nhap"<<endl
			<<"Neu dang nhap sai 1 lan nua tai khoan cua ban se bi khoa"<<endl;
	}

	if (dem==3){
		cout<<"Ban da dang nhap sai qua so lan quy dinh tai khoan cua ban da bi khoa."<<endl
			<<"De mo khoa tai khoan vui long den muc yeu cau mo khoa de gui thong bao mo khoa den nguoi quan li"<<endl;
	fstream file("lock.txt");
	if(!file.is_open()){
		cout<<"Loi mo file ";
		return false;
	}

	file<<endl;
	file <<Ngdung_dangnhap.Maso<<"	"<<Ngdung_dangnhap.Biethieu;
	
	file.close();
	}

	return true;
}

bool Yeucau_mokhoa(Nguoidung & Ngdung_dangnhap){
	 fstream file("mokhoa.txt");

	 if(!file.is_open()){
		 cout<<"Loi mo file";
		 return false;
	 }

	 file<<endl;
	 file <<Ngdung_dangnhap.Maso<<"	"<<Ngdung_dangnhap.Biethieu;
	
	 file.close();
	 return true;
}

bool Docyeucau_mokhoa(){
	fstream file ("mokhoa.txt");
	 if(!file.is_open()){
		 cout<<"Loi mo file";
		 return false;
	 }

	 string bien = "";
	 while (getline(file,bien)){
		 if(bien.empty()) continue;

		 stringstream tach(bien);
		 int maso;
		 string biethieu;
		 tach>>maso>>biethieu;

		 fstream FILE1("trong.txt");
		  while (getline(file,bien)){
			 if(bien.empty()) continue;
			 string bien2;
			 stringstream tach2(bien2);
			 int maso2;
			 //string biethieu1;
			 tach2>>maso2;
			 if(maso2==maso) continue;
			 FILE1<<bien2<<endl;
		  }
		  

		  ofstream xoa("mokhoa.txt");
			if (!xoa.is_open()) {
				cout << "Loi mo file";
			}

		fstream ghi("mokhoa.txt");
		string bienmoi;
			while(getline(FILE1,bienmoi)){
				if(bienmoi.empty()) continue;
					ghi<<bienmoi<<endl;
			}

		ofstream xoa1("trong.txt");
			if (!xoa1.is_open()) {
				cout << "Loi mo file";
			}

		ghi.close();
		FILE1.close();

		 cout<<biethieu<<"	muon yeu cau mo khoa tai khoan"<<endl;
		 cout<<"Dong y mo khoa tai khoan (y/n)? "<<endl;
		 cin.ignore();
		 string y;
		 if(y!="y"){
			 break;
		 }


		 fstream mofile("lock.txt");

		 fstream FILE("trong.txt");
		  while (getline(mofile,bien)){
			 if(bien.empty()) continue;
			 string bien1;
			 stringstream tach1(bien1);
			 int maso1;
			 //string biethieu1;
			 tach1>>maso1;
			 if(maso1==maso) continue;
			 FILE<<bien1<<endl;
		  }

		  ofstream xoafile("lock.txt");
			if (!xoafile.is_open()) {
				cout << "Loi mo file";
			}

		while(getline(FILE,bien)){
			 if(bien.empty()) continue;
			 mofile<<bien<<endl;
		}
		   ofstream xoatrong("trong.txt");
			if (!xoatrong.is_open()) {
				cout << "Loi mo file";
			}

		  mofile.close();
		  FILE.close();
	 }
}