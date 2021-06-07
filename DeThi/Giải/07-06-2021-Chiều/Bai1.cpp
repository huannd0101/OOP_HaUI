#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std; 

class Nguoi {
protected:
  char HoTen[30];
  int Tuoi;
  char GioiTinh[30];
public:
  void Nhap();
  void Xuat();
};

class NhanVien: public Nguoi{
private:
  char MaNV[30], ChucVu[30];
  double Luong;
public: 
  void Nhap();
  void Xuat();
};

class CongTy {
private:
  char MaCT[30], DiaChi[30];
  NhanVien *x;
  int n;
public:
  void Nhap();
  void Xuat();
};

void Nguoi::Nhap(){
  cout << "Nhap ho ten: "; fflush(stdin); gets(HoTen);
  cout << "Nhap tuoi: "; cin >> Tuoi;
  cout << "Nhap gioi tinh: "; fflush(stdin); gets(GioiTinh);
}
void Nguoi::Xuat(){
  cout << left << setw(30) << HoTen << setw(15) << Tuoi << setw(30) << GioiTinh;
}

void NhanVien::Nhap(){
  Nguoi::Nhap();
  cout << "Nhap ma nv: "; fflush(stdin); gets(MaNV);
  cout << "Nhap chuc vu: "; fflush(stdin); gets(ChucVu);
  cout << "Nhap luong: "; cin >> Luong;
}
void NhanVien::Xuat(){
  Nguoi::Xuat();
  cout << left << setw(30) << MaNV << setw(30) << ChucVu << setw(15) << Luong << endl;
}

void CongTy::Nhap(){
  cout << "Nhap ma CT: "; fflush(stdin); gets(MaCT);
  cout << "Nhap dia chi: "; fflush(stdin); gets(DiaChi);
  cout << "Nhap so luong nhan vien: "; cin >> n;
  x = new NhanVien[n];
  for(int i=0; i<n; i++){
    cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
    x[i].Nhap();
  }
}

void CongTy::Xuat() {
  cout << "\nMa CT: " << MaCT << endl;
  cout << "Dia Chi: " << DiaChi << endl;
  cout << left << setw(30) << "Ho Ten" << setw(15) << "Tuoi" << setw(30) << "Gioi Tinh" << setw(30) << "Ma NV" << setw(30) << "Chuc Vu" << setw(15) << "Luong" << endl;
  for(int i=0; i<n; i++){
    x[i].Xuat();
  }
}

int main() {
  CongTy a;
  a.Nhap();

  a.Xuat();
  return 0;
}