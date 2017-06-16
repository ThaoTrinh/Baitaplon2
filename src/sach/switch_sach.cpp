#include <switch_sach.h>
#include <insach.h>
#include <tuychonsach.h>
#include <timsach.h>

using namespace std;

void Switch_timkiem(Nguoidung &Ngdung_dangnhap, vector<string>SachGiaoTrinh, sach & Giaotrinh) {
	system("cls");
	while (true) {
		switch (timkiem()) {
		case 1:
			timsach_theoten(Ngdung_dangnhap, SachGiaoTrinh, Giaotrinh);
			break;
		case 2:
			timsach_theloai(Ngdung_dangnhap, SachGiaoTrinh, Giaotrinh);
			break;
		case 3:
			return;
		}
	}
}