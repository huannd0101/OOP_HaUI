#include<iostream>
#include<fstream>
using namespace std;

class TamGiac {
private:
    float a, b, c;
public:
    double operator++();
    friend istream &operator >>(istream &is, TamGiac &x);
    friend ostream &operator <<(ostream &os, TamGiac x);
    friend void writeToFile(char *fileName, TamGiac x);
};

double TamGiac::operator++(){
    return this->a + this->b + this->c;
}

istream &operator >>(istream &is, TamGiac &x){
    cout << "Nhap a = ";    is >> x.a;
    cout << "Nhap b = ";    is >> x.b;
    cout << "Nhap c = ";    is >> x.c;
    return is;
}

ostream &operator <<(ostream &os, TamGiac x){
    os << "a = " << x.a << " \tb = " << x.b << "\tc = " << x.c << endl;
    os << "Chu vi " << ++x << endl;
    return os;
}

void writeToFile(char *fileName, TamGiac x){
    ofstream f(fileName, ios::app);
    f << x << endl;
    f.close();
}

int main(){
    TamGiac P, Q;
    cout << "Nhap tam giac Q" << endl;
    cin >> Q;
    cout << "Nhap tam giac P" << endl;
    cin >> P;
    writeToFile("D:/INOUT.txt", P);
    writeToFile("D:/INOUT.txt", Q);
    return 0;
}