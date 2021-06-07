#include<iostream>

using namespace std;

class NhiThuc {
private:
  double a, b;
public:
  NhiThuc();
  NhiThuc(double a, double b);
  ~NhiThuc();
  NhiThuc operator-();
  friend istream &operator>>(istream &is, NhiThuc &x);
  friend ostream &operator<<(ostream &os, NhiThuc x);
};

NhiThuc::NhiThuc() {
  a = 0;
  b = 0;
}

NhiThuc::NhiThuc(double a, double b) {
  this->a = a;
  this->b = b;
}

NhiThuc::~NhiThuc() {
  a = 0;
  b = 0;
}

NhiThuc NhiThuc::operator-() {
  this->a = -a;
  this->b = -b;
  return *this;
}

istream &operator>>(istream &is, NhiThuc &x) {
  cout << "Nhap a = ";  is >> x.a;
  cout << "Nhap b = ";  is >> x.b;
  return is;
}

ostream &operator<<(ostream &os, NhiThuc x){
  os << x.a << "x + " << x.b;
  return os;
}

int main(){
  NhiThuc a;

  cout << "Nhap thong tin nhi thuc: " << endl;
  cin >> a;

  cout << "Nhi thuc vua nhap: " << a << endl;

  a = -a;

  cout << "Nhi thuc vua doi dau: " << a << endl;

  return 0;
}
