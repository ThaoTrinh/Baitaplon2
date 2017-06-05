#include <MuonSach.h>
#include <DocFile.h>
using namespace std;
void Muonsach() {
	float luachon;
	cout << "1. Tim kiem theo ten." << endl;
	cout << "2. Hien thi danh sach theo the loai." << endl;
	cout << "3. Quay lai." << endl;
	HienThiDanhSachCacLoaiSach();
}

void DuyetYeuCauMuonSach() {
	ofstream fileDuyetYeuCau;
	fileDuyetYeuCau.open("DuyetYeuCauMuonSach.txt");
	string y;
	cout << "Ban co dong y duyet yeu cau muon sach cua tai khoan ( ) khong (y/n) " << endl;
	cin.ignore();
	getline(cin, y);
	while (y != "y" && y != "n")
	{
		cout << "Error!!Vui long nhap dung ki tu !" << endl;
		getline(cin, y);
	}
	if (y == "n") // Tức là không đồng ý và quay trở lại màn hình chính
	{
		kiemtra = false;
		_getch();
		//Quay lại màn hình
	}
	if (y == "y")  // Nếu đồng ý thì duyệt yêu cầu mượn sách và người dùng sẽ nhận được thông báo
	{
		fileDuyetYeuCau << y << endl;
		cout << "Ban da duyet yeu cau muon sach..." << endl;
	}
	fileDuyetYeuCau.close();
	_getch();
}

void HienThiDanhSachCacLoaiSach() {
	vector<string> List_DanhSach_Lattrang;
	int SoThuTu;
	float luachon, luachon_theloai;
	cout << "Nhap lua chon: "; cin >> luachon;
	while (luachon < 0 || int(luachon) != luachon || luachon > 3)
	{
		cout << "Khong hop le !! Vui long nhap dung lua chon: ";
		cin >> luachon;
	}
	switch (int(luachon))
	{
	case 1:
	{
		//code tìm kiếm theo từ khóa
		break;
	}
hienthi:case 2:
{
	system("cls");
	cout << "Cac the loai sach." << endl;
	cout << "1. Sach, giao trinh on tap." << endl;
	cout << "2. Tac pham van hoc Viet Nam." << endl;
	cout << "3. Khoa hoc tu nhien va ki thuat." << endl;
	cout << "4. Quay lai." << endl;
	cout << "Moi ban chon the loai de hien thi danh sach cac loai sach: ";
	cin >> luachon_theloai;
	while (luachon_theloai < 0 || int(luachon_theloai) != luachon_theloai || luachon_theloai > 4)
	{
		cout << "Khong hop le !! Vui long nhap dung lua chon: ";
		cin >> luachon_theloai;
	}
	switch (int(luachon_theloai))
	{
	case 1:
	{
		system("cls");
		Doc_file_SachGiaoTrinh();
		char q;
		cout << "*-------------------------------------------------------------------------------------*" << endl;
		cout << "Neu ban muon sach thi nhan y de dong y và viet phieu muon." << endl;
		cin >> q;
		if (q == 'q')
		{
			system("cls");
			goto hienthi;
		}
		if (q == 'y')
		{
			system("cls");
			Doc_file_SachGiaoTrinh();
			cout << "Nhap so thu tu cho loai sach ma ban muon muon: "; cin >> SoThuTu;
			VietPhieuMuonSach();
			cout << "Yeu cau muon sach cua ban da duoc gui di..." << endl;
			cout << "Nhan phim enter de quay lai man hinh chinh." << endl;
			_getch();
			return;
		}
		break;
	}
	case 2:
	{
		system("cls");
		Doc_file_SachVanHoc();
		char q;
		cout << "***************************************************************************************" << endl;
		cout << setw(50) << "" << "Nhan phim q de quay lai." << endl;
		cout << "Neu ban muon sach thi nhan y de dong y và viet phieu muon." << endl;
		cin >> q;
		if (q == 'q')
		{
			system("cls");
			goto hienthi;
		}
		if (q == 'y')
		{
			system("cls");
			Doc_file_SachVanHoc();
			cout << "Nhap so thu tu cho loai sach ma ban muon muon: "; cin >> SoThuTu;
			VietPhieuMuonSach();
			cout << "Yeu cau muon sach cua ban da duoc gui di..." << endl;
			cout << "Nhan phim enter de quay lai man hinh chinh." << endl;
			_getch();
			return;

		}
		break;
	}
	case 3:
	{
		system("cls");
		Doc_file_SachKHTN();
		char q;
		cout << "*-------------------------------------------------------------------------------------*" << endl;
		cout << setw(50) << "" << "Nhan phim q de quay lai." << endl;
		cout << "Neu ban muon sach thi nhan y de dong y và viet phieu muon." << endl;
		cin >> q;
		if (q == 'q')
		{
			system("cls");
			goto hienthi;
		}
		if (q == 'y')
		{
			system("cls");
			Doc_file_SachKHTN();
			cout << "Nhap so thu tu cho loai sach ma ban muon muon: "; cin >> SoThuTu;
			VietPhieuMuonSach();
			cout << "Yeu cau muon sach cua ban da duoc gui di..." << endl;
			cout << "Nhan phim enter de quay lai man hinh chinh." << endl;
			_getch();
			return;
		}
		break;
	}
	case 4:
	{
		system("cls");
		Muonsach();
		break;
	}
	}
}
case 3:
{
	return;
}
	}
	return;
}

bool VietPhieuMuonSach() {
	cout << "*---------------Vui long nhap phieu muon---------------*" << endl;
	int date, month, year;
	cout << "***** Nhap ngay muon (dd/mm/yyyy) *****" << endl;
	cout << "+) Ngay: "; cin >> date;
	cout << "+) Thang: "; cin >> month;
	cout << "+) Nam: "; cin >> year;

	ofstream File_PhieuMuonSach;
	File_PhieuMuonSach.open("Phieu muon sach.txt");
	File_PhieuMuonSach << "Ngay muon: " << date << "/" << month << "/" << year << endl;
	File_PhieuMuonSach << "Nguoi muon: " << endl; //Chỗ này là truyền cái tài khoản vào

	File_PhieuMuonSach.close();
	system("cls");
	cout << "*---------------------PHIEU MUON SACH-----------------------" << endl;
	cout << "Nguoi muon: " << endl; //Chỗ này là truyền cái tài khoản vào
	cout << "Ngay muon: " << date << "/" << month << "/" << year << endl;
	cout << "Thoi gian muon toi da la 7 ngay." << endl;
	return true;
}