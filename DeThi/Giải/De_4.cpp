#include<iostream>
#include<stdlib.h>

using namespace std;

//Câu 1:

// class Vector {
// private:
//   int n;
//   float *a;
// public:
//   Vector();
//   Vector(int n, float *a);
//   ~Vector();
//   friend istream &operator>>(istream &is, Vector &x);
//   friend ostream &operator<<(ostream &os, Vector x);
//   float findMinOfVector();
//   float findMaxOfVector();
// };

// Vector::Vector(){
//   n = 0;
//   a = NULL;
// }

// Vector::Vector(int n, float *a){
//   this->n = n;
//   this->a = new float[n];
//   for(int i=0; i<n; i++){
//     this->a[i] = a[i];
//   }
// }

// Vector::~Vector(){
//   n = 0;
//   delete[] a;
// }

// istream &operator>>(istream &is, Vector &x){
//   cout << "Nhap n = ";
//   is >> x.n;
//   x.a = new float[x.n];
//   for(int i=0; i<x.n; i++){
//     cout << "Nhap a[" << i << "] = ";
//     is >> x.a[i];
//   }
//   return is;
// }

// ostream &operator<<(ostream &os, Vector x){
//   os << "So chieu: " << x.n << endl;
//   os << "Chieu: ";
//   for(int i=0; i<x.n; i++){
//     os << x.a[i] << " ";
//   }
//   os << endl;
//   return os;
// }

// float Vector::findMaxOfVector(){
//   float max = a[0];
//   for(int i=1; i<n; i++){
//     if(max < a[i]){
//       max = a[i];
//     }
//   }
//   return max;
// }

// float Vector::findMinOfVector(){
//   float min = a[0];
//   for(int i=1; i<n; i++){
//     if(min > a[i]){
//       min = a[i];
//     }
//   }
//   return min;
// }

// int main(){
//   Vector vt;
  
//   cout << "Nhap thong tin vt" << endl;
  
//   cin >> vt;
  
//   cout << vt;
//   cout << "Max: " << vt.findMaxOfVector() << endl;
//   cout << "Min: " << vt.findMinOfVector() << endl;

//   return 0;
// }

//--------------Câu 2:
#include<string.h>
#include<iomanip>

class Xe {
protected:
  char mauSon[30];
  char bienSo[30];
  char noiDangKy[30];
  int namDangKy;
public:
  Xe();
  Xe(char mauSOn[], char bienSo[], char noiDangKy[], int namDangKy);
  ~Xe();
  void Nhap();
  void Xuat();
};

class ChuSoHuu: public Xe{
private:
  char tenChuSoHuu[30];
  char chungMinhThu[30];
public:
  ChuSoHuu();
  ChuSoHuu(char tenChuSoHuu[], char chungMinhThu[]);
  ~ChuSoHuu();
  void Nhap();
  void Xuat();
};

Xe::Xe(){
  strcpy(mauSon, NULL);
  strcpy(bienSo, NULL);
  strcpy(noiDangKy, NULL);
  namDangKy = 0;
}

Xe::Xe(char mauSOn[], char bienSo[], char noiDangKy[], int namDangKy){
  strcpy(this->mauSon, mauSOn);
  strcpy(this->bienSo, bienSo);
  strcpy(this->noiDangKy, noiDangKy);
  this->namDangKy = namDangKy;
}

Xe::~Xe() {
  strcpy(mauSon, NULL);
  strcpy(bienSo, NULL);
  strcpy(noiDangKy, NULL);
  namDangKy = 0;
}

void Xe::Nhap(){
  cout << "Nhap mau son    : ";   fflush(stdin);   gets(mauSon);
  cout << "Nhap bien so    : ";   gets(bienSo);
  cout << "Nhap noi dang ky: ";   gets(noiDangKy);
  cout << "Nhap nam dang ky: ";   cin >> namDangKy;
}

void Xe::Xuat(){
  cout << left << setw(30) << mauSon << setw(30) << bienSo << setw(30) << noiDangKy 
    << setw(15) << namDangKy << endl;
}