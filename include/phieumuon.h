#pragma once
#ifndef PHIEUMUON
#define PHIEUMUON

#include <thuvien_chuan.h>
std::string DocFileSachGiaoTrinh(Nguoidung &Ngdung_dangnhap, std::vector<std::string>& SachGiaoTrinh, sach &Giaotrinh);
std::string tenFileSachGiaoTrinh(Nguoidung &Ngdung_dangnhap, std::vector<std::string>& SachGiaoTrinh, sach &Giaotrinh);
void PhieuMuon(Nguoidung &Ngdung_dangnhap, std::vector<std::string>& SachGiaoTrinh, sach &Giaotrinh);
float LuaChonSach(Nguoidung &Ngdung_dangnhap, sach &Giaotrinh);
bool LuaChonMuonSach(Nguoidung &Ngdung_dangnhap, std::vector<std::string>& SachGiaoTrinh, sach &Giaotrinh);
int Select(Nguoidung &Ngdung_dangnhap, std::vector<std::string>& SachGiaoTrinh, sach &Giaotrinh);
#endif