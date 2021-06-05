#include<bits/stdc++.h>
using namespace std;
class PHIEU;
class HANG
{
private:
    char Tenhang[50];
    double Dongia;
    int Soluong;

public:
    void nhap();
    void xuat();
    friend class PHIEU;
};

void HANG::nhap()
{
    cout << "Nhap ten hang: ";
    fflush(stdin);
    gets(Tenhang);
    cout << "Nhap don gia: ";
    cin >> Dongia;
    cout << "Nhap so luong: ";
    cin >> Soluong;
}
void HANG::xuat()
{
    cout << Tenhang << setw(30) << Dongia << setw(30) << Soluong << setw(30);
}
class PHIEU
{
private:
    char Maphieu[50];
    char Khachhang[50];
    char Ngaylap[50];
    HANG *a;
    int n;
public:
    void nhap();
    void xuat();
};

void PHIEU::nhap()
{
    cout << "Nhap ma phieu: ";
    fflush(stdin);
    gets(Maphieu);
    cout << "Nhap khach hang: ";
    fflush(stdin);
    gets(Khachhang);
    cout << "Nhap ngay lap: ";
    fflush(stdin);
    gets(Ngaylap);
    cout << "Nhap so luong hang: ";
    cin >> n;
    a = new HANG[n];
    for(int i=0; i <n ; i++)
        a[i].nhap();
}
void PHIEU::xuat()
{
    double tongtien = 0;
    for(int i=0;i <n; i++)
        tongtien += a[i].Soluong * a[i].Dongia;
    cout << "Ma phieu: " << Maphieu << setw(30) << "Khach hang: " << Khachhang << endl;
    cout << "Ngay lap: " << Ngaylap << setw(30) << "Tong thanh tien: " << tongtien << endl;
    cout << "Ten hang " << setw(30) << "Don gia" << setw(30) << "So luong" << setw(30) << "Thanh tien" << endl;
    for(int i=0; i <n; i++)
    {
        a[i].xuat();
        cout << a[i].Dongia*a[i].Soluong << endl;
    }
}
int main()
{
    PHIEU x;
    x.nhap();
    x.xuat();
    return 0;
}