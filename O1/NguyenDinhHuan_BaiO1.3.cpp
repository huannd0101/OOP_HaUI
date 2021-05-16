#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class PHIEU;
class TAISAN {
private:
    char ten[30];
    int soLuong;
    char tinhTrang[30];
public:
    void Nhap();
    void Xuat();
    friend class PHIEU;
    friend void Bonus1(PHIEU a);
    friend void Bonus2(PHIEU a);
};

void TAISAN::Nhap(){
    cout << "Nhap ten tai san: "; fflush(stdin); gets(ten);
    cout << "Nhap so luong   : "; cin >> soLuong;
    cout << "Nhap tinh trang : "; fflush(stdin); gets(tinhTrang);
}

void TAISAN::Xuat(){
    cout << setw(25) << left << ten 
        << setw(15) << soLuong << setw(30) << tinhTrang << endl;
}

class NHANVIEN {
private:
    char ten[30];
    char chucVu[30];
public:
    void Nhap();
    void Xuat();
};

void NHANVIEN::Nhap(){
    cout << "Nhap ten nhan vien: "; fflush(stdin); gets(ten);
    cout << "Nhap chuc vu      : "; fflush(stdin); gets(chucVu);
}

void NHANVIEN::Xuat(){
    cout << "Nhan vien kiem ke: " << setw(25) 
        << right << ten << "\tChuc vu: " << chucVu << endl;
}

class PHONG {
private:
    char tenPhong[30];
    char maPhong[30];
    char truongPhong[30];
public:
    void Nhap();
    void Xuat();
};

void PHONG::Nhap(){
    cout << "Nhap ten phong   : "; fflush(stdin); gets(tenPhong);
    cout << "Nhap ma phong    : "; fflush(stdin); gets(maPhong);
    cout << "Nhap truong phong: "; fflush(stdin); gets(truongPhong);
}

void PHONG::Xuat(){
    cout << "Kiem ke tai phong: " << setw(25) << right << tenPhong << "\tMa phong: " 
        << maPhong << endl << "Truong phong: " << truongPhong << endl;
}

class DATE {
private:    
    int D, M, Y;
public:
    void Nhap();
    void Xuat();
};

void DATE::Nhap(){
    cout << "Nhap date : "; cin >> D;
    cout << "Nhap month: "; cin >> M;
    cout << "Nhap year : "; cin >> Y;
}

void DATE::Xuat(){
    cout << left << D << "/" << M << "/" << Y << endl;
}

class PHIEU {
private:
    char maPhieu[30];
    DATE ngay;
    NHANVIEN nhanVien;
    PHONG phong;
    TAISAN *x;
    int n;
public:
    void Nhap();
    void Xuat();
    friend void Bonus1(PHIEU a);
    friend void Bonus2(PHIEU a);
};

void PHIEU::Nhap(){
    cout << "Nhap ma phieu: "; fflush(stdin); gets(maPhieu);
    ngay.Nhap();
    nhanVien.Nhap();
    phong.Nhap();
    cout << "Nhap so luong tai san: ";  cin >> n;
    x = new TAISAN[n];
    for(int i=0; i<n; i++){
        cout << "Nhap tai san thu " << i + 1 << endl;
        x[i].Nhap();
    }
}

void PHIEU::Xuat(){
    cout << "\n\n\t\t\tPHIEU KIEM KE TAI SAN" << endl;
    cout << "Ma phieu: " << setw(34) << right << maPhieu << "\tNgay kiem ke: ";
    ngay.Xuat();
    nhanVien.Xuat();
    phong.Xuat();
    int s = 0;
    cout << setw(25) << left << "Ten tai san" 
        << setw(15) << "So luong" << setw(30) << "Tinh trang" << endl;
    for(int i=0; i<n; i++){
        s += x[i].soLuong;
        x[i].Xuat();
    }
    cout << "\nSo tai san da kiem ke: " << n << "\t Tong so luong: " << s;
}

void Bonus1(PHIEU a){
    for(int i=0; i<a.n; i++){
        if(stricmp(a.x[i].ten, "May vi tinh") == 0){
            a.x[i].soLuong = 20;
        }
    }
}

void Bonus2(PHIEU a){
    for(int i=0; i<a.n-1; i++)
        for(int j=a.n-1; j>i; j--)
            if(a.x[j-1].soLuong > a.x[j].soLuong){
                TAISAN temp = a.x[j-1];
                a.x[j-1] = a.x[j];
                a.x[j] = temp;
            }
}

int main(){
    PHIEU a;
    a.Nhap();
    cout << "\n\n-------------------------PHIEU VUA NHAP------------------------" << endl;
    a.Xuat();
    cout << "\n\n----------------------------BONUS 1----------------------------" << endl;
    Bonus1(a);
    a.Xuat();
    cout << "\n\n----------------------------BONUS 2----------------------------" << endl;
    Bonus2(a);
    a.Xuat();
    return 0;
}