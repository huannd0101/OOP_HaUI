#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;
class Phieu;

class DonVi {
private:
  char MaDonVi[30];
  char TenDonVi[30];
  char DiaChiDonVi[30];
  char TruongDonVi[30];
public:
  void Nhap();
  void Xuat();
};

class TaiSan {
private:
  char MaTaiSan[30];
  char TenTaiSan[30];
  char DonViTinh[30];
  int GiaTri;
public:
  void Nhap();
  void Xuat();
  friend class Phieu;
};

class Phieu {
private:
  char NgayLap[30];
  char NguoiLap[30];
  DonVi donVi;
  TaiSan *taiSans;
  int n;
public:
  void Nhap();
  void Xuat();
};

void DonVi::Nhap(){
  cout << "Nhap ma don vi     : "; fflush(stdin);  gets(MaDonVi);
  cout << "Nhap ten don vi    : "; fflush(stdin);  gets(TenDonVi);
  cout << "Nhap dia chi don vi: "; fflush(stdin);  gets(DiaChiDonVi);
  cout << "Nhap truong don vi : "; fflush(stdin);  gets(TruongDonVi);
}

void DonVi::Xuat() {
  cout << "Ma don vi: " << left << setw(35) << MaDonVi << "Ten don vi: " << TenDonVi << endl;
  cout << "Dia chi don vi: " << left << setw(30) << DiaChiDonVi << "Truong don vi: " << TruongDonVi << endl;
}

void TaiSan::Nhap(){
  cout << "Nhap ma tai san : "; fflush(stdin); gets(MaTaiSan);
  cout << "Nhap ten tai san: "; fflush(stdin); gets(TenTaiSan);
  cout << "Nhap don vi tinh: "; fflush(stdin); gets(DonViTinh);
  cout << "Nhap gia tri    : "; cin >> GiaTri;
}

void TaiSan::Xuat(){
  cout << left << setw(30) << MaTaiSan << setw(30) << TenTaiSan << setw(30) << DonViTinh << setw(15) << GiaTri << endl;
}

void Phieu::Nhap(){
  cout << "Nhap ngay lap : "; fflush(stdin); gets(NgayLap);
  cout << "Nhap nguoi lap: "; fflush(stdin); gets(NguoiLap);
  donVi.Nhap();
  cout << "Nhap so luong tai san: ";  cin >> n;
  taiSans = new TaiSan[n];
  for(int i=0; i<n; i++){
    cout << "Nhap thong tin tai san thu " << i + 1 << endl;
    taiSans[i].Nhap();
  }
}

void Phieu::Xuat(){
  cout << "\nTONG CONG TY ABC" << endl;
  cout << "\t\t\t\tBANG THONG KE TAI SAN" << endl;
  cout << "Ngay lap: " << setw(36) << left << NgayLap << "Nguoi lap: " << NguoiLap << endl;
  donVi.Xuat();
  cout << "Chi tiet:" << endl;
  int s = 0;
  cout << left << setw(30) << "Ma tai san" << setw(30) << "Ten tai san" << setw(30) << "Don vi tinh" << setw(15) << "Gia tri" << endl;
  for(int i=0; i<n; i++){
    taiSans[i].Xuat();
    s += taiSans[i].GiaTri;
  }
  cout << "Tong so luong thiet bi" << setw(70) << right << s << endl;
  cout << setw(30) << "Gam doc" << setw(30) << "Phong quan ly" << setw(30) << "Nguoi lap" << endl;
}

int main(){
  Phieu a;
  a.Nhap();

  a.Xuat();

  return 0;
}
