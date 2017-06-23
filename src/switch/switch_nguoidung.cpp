#include <switch_nguoidung.h>
#include <tuychon.h>
#include <switch_sach.h>
#include <nhapphieu.h>
#include <thongtin_canhan.h>
#include <switch.h>
#include <file_chucnang.h>
#include <timkiem_nguoidung.h>
#include <themsach.h>
#include <DuyetMuonSach.h>
#include <thongbao.h>
#include <TraSach.h>
#include <DuyetMuonSach.h>
#include <duyettaikhoan.h>
#include <quen_matkhau.h>
#include <DuyetTraSach.h>
using namespace std;

void Switch_docgia(vector<thongtin_nguoidung>& Dangki_taikhoan, vector<Nguoidung>& Dangnhap, Nguoidung & Ngdung_dangnhap, vector<string>SachGiaoTrinh, sach &Giaotrinh) {

	// tiếp tục lỗi tốc độ
	// break ra khỏi hàm switch
	// thì chạy ra khỏi câu gọi hàm ở trên
	// rồi chạy tiếp tới break
	// thoát khỏi lần gọi hàm ở main
	// gặp while true chạy lại
	// vì kiemtra và tuychon không thay đổi
	// nên gọi hàm switch ở trên
	///// từ đó mới hiện lại màn hình chọn chức năng

	while (true) {
		switch (Tuychon_docgia(Dangnhap, Ngdung_dangnhap)) {
		case 1:
			Switch_timkiem(Ngdung_dangnhap, SachGiaoTrinh, Giaotrinh);
			break;
		case 2:
			Tra_Sach(Ngdung_dangnhap);
			break;
		case 3:
		{
			if (!Thongtin_canhan(Ngdung_dangnhap.Maso)) {
				cout << "Khong tim thay thong tin" << endl;
				system("pause");
			}
			break;
		}
		case 4:
		{
			Xemthongbao(Ngdung_dangnhap);
			break;
		}
		case 5:
		{
			Caidat_switch(Dangnhap, Ngdung_dangnhap);
			break;
		}
		case 6:
			return;

		}// switch
	}
}

void Switch_thuthu(vector<thongtin_nguoidung>& Dangki_taikhoan, vector<Nguoidung>& Dangnhap, Nguoidung & Ngdung_dangnhap) {

	while (true) {
		switch (Tuychon_thuthu(Dangnhap, Ngdung_dangnhap)) {
		case 1:
			Them_Sach();
			break;
		case 2:
			duyet_muon_sach();
			break;
		case 3:
			duyet_tra_sach();
			break;
		case 4:
			Caidat_switch(Dangnhap, Ngdung_dangnhap);
			break;
		case 5:
			if (!Thongtin_canhan(Ngdung_dangnhap.Maso)) {
				cout << "Khong tim thay thong tin" << endl;
			}
			break;
		case 6:
			return;
		}
	}
}

void Switch_quanli(vector<thongtin_nguoidung>& Dangki_taikhoan, vector<Nguoidung>& Dangnhap, Nguoidung & Ngdung_dangnhap) {

	while (true) {
		switch (Tuychon_Quanli(Dangnhap, Ngdung_dangnhap)) {
		case 1:
			if (!file_themchucnang()) {
				cout << "Loi chuc nang" << endl;
			}

			break;
		case 2:
			if (!file_huychucnang()) {
				cout << "Loi chuc nang" << endl;
			}
			//file_huychucnang();
			break;
		case 3:
			if (!duyettaikhoan()) {
				cout << "Loi chuc nang" << endl;
			}
			break;
		case 4:
			Caidat_switch(Dangnhap, Ngdung_dangnhap);
			break;
		case 5: {
			if (!Thongtin_canhan(Ngdung_dangnhap.Maso)) {
				cout << "Khong tim thay thong tin" << endl;
			}
			break;
		}
		case 6:
			cin.ignore();
			if (!timnguoidung()) {
				cout << "Khong the lay du lieu" << endl;
			}
			break;
		case 7:
			if (!resetmatkhau()) {
				cout << "Loi chuc nang" << endl;
			}
		case 8:
			return;
		}
	}
}
