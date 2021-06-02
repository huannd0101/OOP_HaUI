#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string.h>

using namespace std;
//Câu 1:

// class NhanSu {
// protected:
//   char hoTen[50];
//   char gioiTinh[5];
//   int ngaySinh, thangSinh, namSinh;
//   char diaChi[100];
// };

// class CongChuc: public NhanSu{
// private:
//   char nghanhNghe[20];
//   int namVaoCQ;
//   char trinhDo[50];
//   float heSoLuong;
//   float phuCap;
// public:
//   void nhap();
//   void xuat();
//   float thuNhap();
//   friend void XuatDanhSachThuNhapThap(CongChuc *a, int n);
//   friend void SortByName(CongChuc *a, int n);
// };

// void CongChuc::nhap(){
//   cout << "Nhap ten: "; fflush(stdin); gets(this->hoTen);
//   cout << "Nhap gioi tinh: "; gets(this->gioiTinh);
//   cout << "Nhap ngay sinh: "; cin >> this->ngaySinh;
//   cout << "Nhap thang sinh: "; cin >> this->thangSinh;
//   cout << "Nhap nam sinh: "; cin >> this->namSinh;
//   cout << "Nhap dia chi: "; fflush(stdin); gets(this->diaChi);
//   cout << "Nhap nghanh nghe: "; gets(this->nghanhNghe);
//   cout << "Nhap nam vao CQ: "; cin >> this->namVaoCQ;
//   cout << "Nhap trinh do: "; fflush(stdin); gets(this->trinhDo);
//   cout << "Nhap he so luong: "; cin >> this->heSoLuong;
//   cout << "Nhap phu cap: "; cin >> this->phuCap;
// }

// void CongChuc::xuat(){
//   cout << left << setw(30) << this->hoTen << setw(15) << this->gioiTinh << setw(2) << this->ngaySinh 
//     << "/" << setw(2) << this->thangSinh << "/" << setw(9) << this->namSinh << setw(30) << this->diaChi
//     << setw(30) << this->nghanhNghe << setw(15) << this->namVaoCQ << setw(30) << this->trinhDo 
//     << setw(15) << this->heSoLuong << setw(15) << this->phuCap << endl;
// }

// float CongChuc::thuNhap(){
//   return this->heSoLuong*830 + this->phuCap;
// }

// void title(){
//     cout << endl << left << setw(30) << "Ho ten" << setw(15) << "Gioi tinh" << setw(15) << "Ngay sinh" << setw(30) 
//     << "Dia chi" << setw(30) << "Nghanh nghe" << setw(15) << "Nam vao CQ" << setw(30) << "Trinh do"
//     << setw(15) <<"He so luong" << setw(15) << "Phu cap" << endl;
// }

// void NhapDanhSach(CongChuc *a, int n){
//   for(int i=0; i<n; i++){
//     cout << "Nhap thong tin cong chuc thu " << i + 1 << endl;
//     a[i].nhap();
//   }
// }

// void XuatDanhSach(CongChuc *a, int n){
//   for(int i=0; i<n; i++){
//     a[i].xuat();
//   }
// }

// void XuatDanhSachThuNhapThap(CongChuc *a, int n){
//   //find min thu nhap
//   float min = a[0].thuNhap();
//   for(int i=1; i<n; i++){
//     if(a[i].thuNhap() < min)
//       min = a[i].thuNhap();
//   }
//   //show
//   for(int i=0; i<n; i++){
//     if(a[i].thuNhap() == min){
//       a[i].xuat();
//     }
//   }
// }

// void SortByName(CongChuc *a, int n){
//   for(int i=0; i<n-1; i++){
//     for(int j=n-1; j>i; j--){
//       if(stricmp(a[j-1].hoTen, a[j].hoTen) < 0){
//         CongChuc temp = a[j-1];
//         a[j-1] = a[j];
//         a[j] = temp;
//       }
//     }
//   }
// }


// int main(){
//   int n;
//   cout << "Nhap n = ";
//   do {
//     cin >> n;
//     if(n >= 50 || n <= 0)
//       cout << "Nhap lai n = ";
//   }while(n >= 50 || n <= 0);

//   CongChuc *a = new CongChuc[n];

//   NhapDanhSach(a, n);

//   title();
//   XuatDanhSachThuNhapThap(a, n);
//   //
//   SortByName(a, n);
//   title();
//   XuatDanhSach(a, n);

//   return 0;
// }

//Câu 2:
class ThoiGian {
private:
  int gio, phut, giay;
public:
  ThoiGian();
  ThoiGian(int gio, int phut, int giay);
  ThoiGian operator-(ThoiGian a);
  friend istream &operator>>(istream &is, ThoiGian &tg);
  friend ostream &operator<<(ostream &os, ThoiGian tg);
};

ThoiGian::ThoiGian(){
  gio = phut = giay = 0;
}

ThoiGian::ThoiGian(int gio, int phut, int giay){
  this->gio = gio;
  this->phut = phut;
  this->giay = giay;
}

ThoiGian ThoiGian::operator-(ThoiGian a){
  ThoiGian temp;
  temp.gio = this->gio - a.gio;
  temp.phut = this->phut - a.phut;
  temp.giay = this->giay - a.giay;
  return temp;
}

istream &operator>>(istream &is, ThoiGian &tg){
  cout << "Nhap gio : "; is >> tg.gio;
  cout << "Nhap phut: "; is >> tg.phut;
  cout << "Nhap giay: "; is >> tg.giay;
  return is;
}

ostream &operator<<(ostream &os, ThoiGian tg){
  os << tg.gio << ":" << tg.phut << ":" << tg.giay << endl;
  return os;
}

int main(){
  ThoiGian a, b;
  cout << "Nhap thoi gian a" << endl;
  cin >> a;
  cout << "Nhap thoi gian b" << endl;
  cin >> b;

  cout << "Hieu a - b = " << a - b << endl;

  return 0;
}