#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string.h>

using namespace std;
// Câu 1:

// class Nha {
// protected:
//   double dienTich;
//   int namXD;
//   double kinhPhiXD;
// };

// class NhaCaoTang: public Nha {
// private:
//   int soTang;
//   int soPhong;
// public:
//   void nhap();
//   void xuat();
//   friend void SortByDienTich(NhaCaoTang *a, int n);
//   friend void ShowBySoPhong(NhaCaoTang *a, int n, int soPhong);
// };

// void NhaCaoTang::nhap(){
//   cout << "Nhap dien tich: "; cin >> dienTich;
//   cout << "Nhap nam XD: "; cin >> namXD;
//   cout << "Nhap kinh phi: "; cin >> kinhPhiXD;
//   cout << "Nhap so tang: "; cin >> soTang;
//   cout << "Nhap so phong: "; cin >> soPhong;
// }

// void NhaCaoTang::xuat(){
//   cout << left << setw(15) << dienTich << setw(15) << namXD << setw(15) << kinhPhiXD
//     << setw(15) << soTang << setw(15) << soPhong << endl;
// }

// void title(){
//     cout << left << setw(15) << "Dien Tich" << setw(15) << "Nam SX" << setw(15) << "Kinh Phi"
//     << setw(15) << "So Tang" << setw(15) << "So Phong" << endl;
// }

// void NhapDanhSach(NhaCaoTang *a, int n){
//   for(int i=0; i<n; i++){
//     cout << "Nhap thong tin nha thu " << i+1 << endl;
//     a[i].nhap();
//   }
// }

// void XuatDanhSach(NhaCaoTang *a, int n){
//   for(int i=0; i<n; i++){
//     a[i].xuat();
//   }
// }

// void SortByDienTich(NhaCaoTang *a, int n){
//   for(int i=0; i<n-1; i++){
//     for(int j=n-1; j>i; j--){
//       if(a[j-1].dienTich < a[j].dienTich){
//         NhaCaoTang temp = a[j-1];
//         a[j-1] = a[j];
//         a[j] = temp;
//       }
//     }
//   }
// }

// void ShowBySoPhong(NhaCaoTang *a, int n, int soPhong){
//   for(int i=0; i<n; i++){
//     if(a[i].soPhong > soPhong){
//       a[i].xuat();
//     }
//   }
// }

// int main(){
//   int n;
//   cout << "Nhap n = ";
//   do {
//     cin >> n;
//     if(n <= 0 || n >= 20){
//       cout << "Nhap lai n = ";
//     }
//   }while(n <= 0 || n >= 20);

//   NhaCaoTang *a = new NhaCaoTang[n];
//   NhapDanhSach(a, n);
  
//   SortByDienTich(a, n);
//   title();
//   XuatDanhSach(a, n);

//   title();
//   ShowBySoPhong(a, n, 5);

//   return 0;
// }

//Câu 2:
class VecTor {
private:
  double x, y;
public:
  VecTor();
  VecTor(double x, double y);
  VecTor operator+(VecTor a);
  VecTor operator-(VecTor a);
  friend istream &operator>>(istream &is, VecTor &a);
  friend ostream &operator<<(ostream &os, VecTor a);
};

VecTor::VecTor(){
  x = y = 0;
}

VecTor::VecTor(double x, double y){
  this->x = x;
  this->y = y;
}

VecTor VecTor::operator+(VecTor a){
  VecTor temp;
  temp.x = this->x + a.x;
  temp.y = this->y + a.y;
  return temp;
}

VecTor VecTor::operator-(VecTor a){
  VecTor temp;
  temp.x = this->x - a.x;
  temp.y = this->y - a.y;
  return temp;
}

istream &operator>>(istream &is, VecTor &a){
  cout << "Nhap x = ";  is >> a.x;
  cout << "Nhap y = ";  is >> a.y;
  return is;
}

ostream &operator<<(ostream &os, VecTor a){
  os << "(" << a.x << ", " << a.y << ")" << endl;
  return os;
}

int main(){
  VecTor a, b;
  cout << "Nhap vector a" << endl;
  cin >> a;
  cout << "Nhap vector b" << endl;
  cin >> b;

  cout << "Tong a + b = " << a + b;
  cout << "Hieu a - b = " << a - b;

  return 0;
}