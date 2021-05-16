#include<iostream>
#include<iomanip>
using namespace std;

class PHIEU;

class HANG {
private:
    char tenHang[30];
    float donGia;
    int soLuong;
public: 
    void Nhap();
    void Xuat();
    friend class PHIEU;
};

void HANG::Nhap(){
    cout << "Nhap ten hang: "; fflush(stdin); gets(tenHang);
    cout << "Nhap don gia : "; cin >> donGia;
    cout << "Nhap so luong: "; cin >> soLuong;
}

void HANG::Xuat(){
    cout << left << setw(20) << tenHang << setw(15) << donGia << setw(15) << soLuong << setw(15) << soLuong*donGia << endl;
}

class NCC {
private:
    char maNCC[30];
    char tenNCC[30];
    char diaChi[30];
public: 
    void Nhap();
    void Xuat();
};

void NCC::Nhap(){
    cout << "Nhap ma NCC     : "; fflush(stdin); gets(maNCC);
    cout << "Nhap ten NCC    : "; fflush(stdin); gets(tenNCC);
    cout << "Nhap dia chi NCC: "; fflush(stdin); gets(diaChi);
}

void NCC::Xuat(){
    cout << "Ma NCC: " << left << setw(32) << maNCC << "Ten NCC: " << tenNCC << endl;
    cout << "Dia chi: " << diaChi << endl;
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
    DATE ngayLap;
    NCC ncc;
    HANG *x;
    int n;
public: 
    void Nhap();
    void Xuat();
};

void PHIEU::Nhap(){
    cout << "Nhap ma phieu: "; fflush(stdin); gets(maPhieu);
    ngayLap.Nhap();
    ncc.Nhap();
    cout << "Nhap so hang: "; cin >> n;
    x = new HANG[n];
    for(int i=0; i<n; i++){
        cout << "\tNhap thong tin hang thu " << i + 1 << endl;
        x[i].Nhap();
    }
}

void PHIEU::Xuat(){
    double s = 0;
    cout << "\n\n\t\t\tPHIEU NHAP HANG" << endl;
    cout << "Ma phieu: " << left << setw(30) << maPhieu << "Ngay lap: ";
    ngayLap.Xuat();
    ncc.Xuat();
    cout << left << setw(20) << "Ten hang" << setw(15) << "Don gia" << setw(15) << "So luong" << setw(15) << "Thanh tien" << endl;
    for(int i=0; i<n; i++){
        s += x[i].soLuong * x[i].donGia;
        x[i].Xuat();
    }
    cout << right << setw(50) << "Cong thanh tien: " << s;
}

int main(){
    PHIEU a;
    
    a.Nhap();
    a.Xuat();

    return 0;
}