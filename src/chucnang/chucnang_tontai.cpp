#include <chucnang_tontai.h>

using namespace std;

bool chucnang_tontai(Nguoidung& Ngdung_dangnhap, int chon){

	if (chon == Ngdung_dangnhap.ngdung.docgia ||
		chon == Ngdung_dangnhap.ngdung.thuthu ||
		chon == Ngdung_dangnhap.ngdung.quanli)
	{
		
		return true;

	}
	return false;
}

