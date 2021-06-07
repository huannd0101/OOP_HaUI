#include<iostream>
using namespace std;

class PTB2 {
private:
  double a, b, c;
public:
  friend istream &operator>>(istream &is, PTB2 &x);
  friend ostream &operator<<(ostream &os, PTB2 x);
  PTB2 operator-(PTB2 x);
  double operator--();
};

istream &operator>>(istream &is, PTB2 &x) {
  cout << "Nhap a: "; is >> x.a;
  cout << "Nhap b: "; is >> x.b;
  cout << "Nhap c: "; is >> x.c;
  return is;
}
ostream &operator<<(ostream &os, PTB2 x) {
  os << x.a << "x^2 + " << x.b << "x + " << x.c << endl;
  return os;
}

PTB2 PTB2::operator-(PTB2 x){
  PTB2 temp;
  temp.a = this->a - x.a;
  temp.b = this->b - x.b;
  temp.c = this->c - x.c;
  return temp;
}

double PTB2::operator--(){
  return (a+b+c)/3;
}

int main(){
  PTB2 P, Q, K;
  cout << "Nhap P" << endl;
  cin >> P; 
  cout << "Nhap Q" << endl;
  cin >> Q; 
  K = P - Q;

  cout << "Phuong trinh K: " << K << endl;
  cout << "Trung binh cong: " << --K;
  return 0;
}