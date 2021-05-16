#include<bits/stdc++.h>
using namespace std;

class PS {
private:
    double t, m;
public:
    PS();
    PS(double a, double b);
    PS operator *(PS x);
    double operator &();
    friend istream& operator >> (istream &is, PS &x);
    friend ostream& operator << (ostream &os, PS x);
};

PS::PS(){
    t = 0;
    m = 1;
}
PS::PS(double a, double b){
    t = a;
    m = b;
}

PS PS::operator*(PS x){
    PS temp;
    temp.t = this->t * x.t;
    temp.m = this->m * x.m;
    return temp;
}

double PS::operator&(){
    return t/m;
}

istream &operator>>(istream &is, PS &x){
    cout << "Nhap tu so : "; is >> x.t;
    cout << "Nhap mau so: "; is >> x.m;
    return is;
}

ostream &operator<<(ostream &os, PS x){
    os << x.t << "/" << x.m << endl;
    return os;
}

void writeToFile(char *fileName, PS x){
    ofstream f(fileName, ios::out);

    f << x;

    f.close();
}

int main(){
    PS ps1, ps2, ps3;
    cout << "Nhap phan so ps1: " << endl;
    cin >> ps1;

    cout << "Nhap phan so ps2: " << endl;
    cin >> ps2;

    ps3 = ps1 * ps2;

    writeToFile("PHANSO.txt", ps3);

    cout << &ps3;
    return 0;
}