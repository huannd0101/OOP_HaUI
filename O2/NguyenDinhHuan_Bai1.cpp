#include<iostream>
#include<string.h>
using namespace std;

class NSX {
private:
    char TenNSX[30], DiaChi[30];
public:
    void Nhap();
    void Xuat();
};

void NSX::Nhap(){
    cout << "Nhap ten nsx: "; fflush(stdin);    gets(TenNSX);
    cout << "Nhap dia chi nsx: "; fflush(stdin);    gets(DiaChi);
}

void NSX::Xuat(){
    cout << "Ten nsx: " << TenNSX << endl;
    cout << "Dia chi nsx: " << DiaChi << endl;
}

/////////////////
class HANG {
protected:
    char TenHang[30];
    NSX x;
    double DonGia;
public: 
    void Nhap();
    void Xuat();
    HANG();
};

void HANG::Nhap(){
    cout << "Nhap ten hang: "; fflush(stdin);   gets(TenHang);
    x.Nhap();
    cout << "Nhap don gia: "; cin >> DonGia;
}

void HANG::Xuat(){
    cout << "Ten hang: " << TenHang << endl;
    x.Xuat();
    cout << "Don gia: " << DonGia << endl;
}

HANG::HANG(){
    strcpy(TenHang, "");
    DonGia = 0;
}

///////////
class DATE {
private:
    int D, M, Y;
public:
    void Nhap();
    void Xuat();
};

void DATE::Nhap(){
    cout << "Nhap ngay : "; cin >> D;
    cout << "Nhap thang: "; cin >> M;
    cout << "Nhap nam  : "; cin >> Y;
}

void DATE::Xuat(){
    cout << D << "/" << M <<  "/" << Y;
}

////////////////////
class TIVI : public HANG{
private:
    double KichThuoc;
    DATE NgayNhap;
public:
    void Nhap();
    void Xuat();
    TIVI();
};

TIVI::TIVI() : HANG() {
    KichThuoc = 0;
}

void TIVI::Nhap(){
    HANG::Nhap();
    cout << "Nhap kich thuoc: "; cin >> KichThuoc;
    NgayNhap.Nhap();
}

void TIVI::Xuat(){
    HANG::Xuat();
    cout << "Kich thuoc: " << KichThuoc << endl;
    cout << "Ngay nhap: ";
    NgayNhap.Xuat();
}

int main(){
    TIVI a;
    a.Nhap();
    cout << "\n-----------Thong tin tivi--------------" << endl;
    a.Xuat();
    return 0;
}

