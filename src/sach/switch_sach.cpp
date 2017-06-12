#include <switch_sach.h>
#include <insach.h>
#include <tuychonsach.h>
#include <timsach.h>

using namespace std;

void switchinsach(Nguoidung &Ngdung_dangnhap,vector<string>SachGiaoTrinh,sach &Giaotrinh){
	system("cls");

	while(true){
		switch(tuychoninsach()){
		case 1:
			if(!infilegiaotrinh(Ngdung_dangnhap,SachGiaoTrinh,Giaotrinh))
				cout<<"Khong the in"<<endl;
			break;
		case 2:
			if(!infilevanhoc()){
				cout<<"Khong the in"<<endl;
			}
			break;
		case 3:
			if(!infileKHTN()){
				cout<<"Khong the in"<<endl;
			}
			break;
		case 4:
			return;
		}
	}
}

void Switch_timkiem(Nguoidung &Ngdung_dangnhap,vector<string>SachGiaoTrinh,sach & Giaotrinh){
	system("cls");
	while(true){
		switch(timkiem()){
			case 1:
				//timsach();
				timsach_theoten();
				break;
			case 2:
				//tuychoninsach();
				switchinsach(Ngdung_dangnhap,SachGiaoTrinh,Giaotrinh);
				break;
			case 3:
				return;
		}
	}
}