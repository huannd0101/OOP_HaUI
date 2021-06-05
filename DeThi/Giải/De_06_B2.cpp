#include <iostream>
using namespace std;

class Complex {
private:
  double a, b;
public:
  Complex();
  Complex(double a, double b);
  friend istream &operator>>(istream &is, Complex &x);
  friend ostream &operator<<(ostream &os, Complex x);
  Complex operator+(Complex x);
};

Complex::Complex(){
  a = b = 0;
}

Complex::Complex(double a, double b){
  this->a = a;
  this->b = b;
}

istream &operator>>(istream &is, Complex &x){
  is >> x.a >> x.b;
  return is;
}

ostream &operator<<(ostream &os, Complex x){
  os << x.a << " + " << x.b << "i" << endl;
  return os;
}

Complex Complex::operator+(Complex x){
  Complex temp;
  temp.a = this->a + x.a;
  temp.b = this->b + x.b;
  return temp;
}

void NhapDanhSach(Complex *arr, int n){
  for(int i=0; i<n; i++){
    cout << "Nhap so phuc thu " << i << ": ";
    cin >> arr[i];
  }
}

Complex Sum(Complex *arr, int n){
  Complex s(0, 0);
  for(int i=0; i<n; i++){
    s = s + arr[i];
  }
  return s;
}

int main(){
  int n;
  cin >> n;
  
  Complex *arr = new Complex[n];

  NhapDanhSach(arr, n);

  cout << "Tong = " << Sum(arr, n);

  return 0;
}