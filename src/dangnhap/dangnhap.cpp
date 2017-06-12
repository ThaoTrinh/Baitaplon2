#include <dangnhap.h>
#include <Docdulieu.h>
#include <vohieuhoa.h>
using namespace std;

bool Log_in(vector<Nguoidung>& Dangnhap, Nguoidung& Ngdung_dangnhap) {
	system("cls");

	cout << "Ten dang nhap: "
	     << "\t";
	string tendangnhap;
	getline(cin, tendangnhap);
	cout << "Mat khau: "
	     << "\t";
	string matkhau;
	getline(cin, matkhau);
	for (int i = 0; i < Dangnhap.size(); i++) {

		if (tendangnhap == Dangnhap[i].Taikhoan) {

			if (matkhau == Dangnhap[i].Matkhau) {
				cout << "Dang nhap thanh cong" << endl;
				Ngdung_dangnhap.Maso     = i + 1;
				Ngdung_dangnhap.Taikhoan = Dangnhap[i].Taikhoan;
				Ngdung_dangnhap.Matkhau  = Dangnhap[i].Matkhau;
				Ngdung_dangnhap.Biethieu =Dangnhap[i].Biethieu;

				//ghi lai thoi gian dang nhap
				time_t now = time(0);
				char* dangnhap = ctime(&now);
				
				fstream file("lichsu_dangnhap.txt",ios::app);
				if(!file.is_open()){
					cout<<"loi mo file"<<endl;
					return false;
				}
				file<<Ngdung_dangnhap.Maso<<"	"<<"1	"<<dangnhap;

				file.close();
				// kiemtra = true;
				// break;
				return true;
			}
		}
	}

	return false;
}

void Dangnhapvao(vector<Nguoidung> &Dangnhap, Nguoidung &Ngdung_dangnhap){
	int dem=0;
	while (!kiemtra) {
		kiemtra = Log_in(Dangnhap, Ngdung_dangnhap);
		if (!kiemtra) {    
			dem++;
			cout << "Khong hop le ban co muon thu lai hay khong?(y/n) "<<endl;
			string y;
			getline(cin, y);
			if (y == "y")
				continue;
			return ;
		}
		
		//kiem tra nguoi dung hien tai dang co chuc nang nao de chuyen sang trang tiep theo chon chuc nang can thuc hien
		if (!Dulieu_chucnang(Dangnhap, Ngdung_dangnhap)) {
			cout << "Vai tro cua ban khong hop le";
			system("pause");
			return;
		}
	}
}