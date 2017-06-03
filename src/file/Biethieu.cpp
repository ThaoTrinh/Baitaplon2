#include <biethieu.h>

using namespace std;

bool biethieu(int bien1){
	fstream file("dangnhap.txt");
	if (!file.is_open()){
		cout << "Loi mo file";
		return false;
	}

	string chuoi;
	while(getline(file,chuoi)){
		if(chuoi.empty()) continue;

		stringstream tachbien(chuoi);
		int mso;
		string tk,mk, bhieu;
		tachbien>>mso>>tk>>mk>>bhieu;
		if(mso!=bien1) continue;
		else{
			cout<<bhieu;
		}
	}

	return true;
}