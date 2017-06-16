﻿#include <switch_nguoidung.h>
#include <tuychon.h>
#include <switch_sach.h>
#include <nhapphieu.h>
#include <thongtin_canhan.h>
#include <switch.h>
#include <file_chucnang.h>
#include <timkiem_nguoidung.h>
#include <quen_matkhau.h>
#include <thongbao.h>
using namespace std;

void Switch_docgia(vector<thongtin_nguoidung>& Dangki_taikhoan,vector<Nguoidung>& Dangnhap,Nguoidung & Ngdung_dangnhap,vector<string>SachGiaoTrinh,sach & Giaotrinh){

	// tiếp tục lỗi tốc độ
	// break ra khỏi hàm switch
	// thì chạy ra khỏi câu gọi hàm ở trên
	// rồi chạy tiếp tới break
	// thoát khỏi lần gọi hàm ở main
	// gặp while true chạy lại
	// vì kiemtra và tuychon không thay đổi
	// nên gọi hàm switch ở trên
	///// từ đó mới hiện lại màn hình chọn chức năng

	while(true) {
		switch(Tuychon_docgia(Dangnhap,Ngdung_dangnhap)){
			case 1:
				Switch_timkiem(Ngdung_dangnhap,SachGiaoTrinh,Giaotrinh);
				break;
			case 2:
				Switch_timkiem(Ngdung_dangnhap,SachGiaoTrinh,Giaotrinh);
				//Nhapphieumuonsach(SachGiaoTrinh);
				break;
			case 3:break;
			case 4:{
				if(!Thongtin_canhan(Ngdung_dangnhap.Maso)){
					cout<<"Khong tim thay thong tin"<<endl;	
					system("pause");
				}
				break;
			}
			case 5:
				if(!Xemthongbao(Ngdung_dangnhap)){
					cout<<"Loi file"<<endl;
				}
				break;
			case 6:
				Caidat_switch(Dangnhap,Ngdung_dangnhap);
				break;
			case 7:
				//system("pause");
				return;
		}// switch
	}
}// đóng hàm

void Switch_thuthu(vector<thongtin_nguoidung>& Dangki_taikhoan,vector<Nguoidung>& Dangnhap,Nguoidung & Ngdung_dangnhap){

	while(true) {		
		switch(Tuychon_thuthu(Dangnhap,Ngdung_dangnhap)){
			case 1:
				
				break;
			case 2:
				
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				Caidat_switch(Dangnhap,Ngdung_dangnhap);
				break;
			case 9:{
				if(!Thongtin_canhan(Ngdung_dangnhap.Maso)){
					cout<<"Khong tim thay thong tin"<<endl;	
				}
					break;
			}
			case 10:
				return ;
		}
	}
}

void Switch_quanli(vector<thongtin_nguoidung>& Dangki_taikhoan,vector<Nguoidung>& Dangnhap,Nguoidung & Ngdung_dangnhap){

	while (true) {
		switch(Tuychon_Quanli(Dangnhap,Ngdung_dangnhap)){
		case 1:
			if(!file_themchucnang()){
				cout<<"Loi chuc nang"<<endl;
			}
			
			break;
		case 2:
			if(!file_huychucnang()){
				cout<<"Loi chuc nang"<<endl;
			}
			//file_huychucnang();
			break;
		case 3:
			Caidat_switch(Dangnhap,Ngdung_dangnhap);
			break;
		case 4:{
			if(!Thongtin_canhan(Ngdung_dangnhap.Maso)){
				cout<<"Khong tim thay thong tin"<<endl;	
			}
			break;
		}
		case 5:
			cin.ignore();
			if(!timnguoidung()){
				cout<<"Khong the lay du lieu"<<endl;
			}
			break;
		case 6:
			if(!resetmatkhau()){
				cout<<"Khong the lay du lieu"<<endl;
			}
			break;
		case 7:
			return ;
		}
	}
}
