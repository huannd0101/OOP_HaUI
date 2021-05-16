#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class TRUONGDH;
class BAN {
    char MaBan[30], TenBan[30], NgayThanhLap[15];
public:
    friend class TRUONGDH;
};

class KHOA {
    char MaKhoa[30], TenKhoa[30], TruongKhoa[30];
public:
    friend class TRUONGDH;
    friend void bonus1(TRUONGDH &a, char *maKhoa);
};

class TRUONG {
    char MaTruong[30], TenTruong[30], DiaChi[30];
public:
    void Nhap();
    void Xuat();
};

void TRUONG::Nhap(){
    cout << "Nhap ma truong : "; fflush(stdin); gets(MaTruong);
    cout << "Nhap ten truong: "; fflush(stdin); gets(TenTruong);
    cout << "Nhap dia chi   : "; fflush(stdin); gets(DiaChi);
}

void TRUONG::Xuat(){
    cout << "Ma truong : " << MaTruong << endl;
    cout << "Ten truong: " << TenTruong << endl;
    cout << "Dia chi   : " << DiaChi << endl;
}

class TRUONGDH : public TRUONG{
    KHOA *x;
    int n;
    BAN *y;
    int m;
public:
    void Nhap();
    void Xuat();
    friend void bonus1(TRUONGDH &a, char *maKhoa);
};

void TRUONGDH::Nhap(){
    TRUONG::Nhap();
    cout << "Nhap so khoa: "; cin >> n;
    x = new KHOA[n];
    for(int i=0; i<n; i++){
        cout << "Nhap ma khoa: "; fflush(stdin); gets(x[i].MaKhoa);
        cout << "Nhap ten khoa: "; fflush(stdin); gets(x[i].TenKhoa);
        cout << "Nhap truong khoa: "; fflush(stdin); gets(x[i].TruongKhoa);
    }
    cout << "Nhap so ban: "; cin >> m;
    y = new BAN[m];
    for(int i=0; i<m; i++){
        cout << "Nhap ma khoa: "; fflush(stdin); gets(y[i].MaBan);
        cout << "Nhap ten khoa: "; fflush(stdin); gets(y[i].TenBan);
        cout << "Nhap truong khoa: "; fflush(stdin); gets(y[i].NgayThanhLap);
    }
}

void TRUONGDH::Xuat(){
    TRUONG::Xuat();
    cout << "------------------------------------Danh sach khoa-------------------------" << endl;
    cout << setw(30) << left << "Ma khoa" << setw(30) << "Ten khoa" << setw(30) << "Truong khoa" << endl;
    for(int i=0; i<n; i++)
        cout << setw(30) << left << x[i].MaKhoa << setw(30) << x[i].TenKhoa << setw(30) << x[i].TruongKhoa << endl;

    cout << "----------------------------------Danh sach ban--------------------------" << endl;
    cout << setw(30) << left << "Ma ban" << setw(30) << "Ten ban" << setw(30) << "Ngay thanh lap" << endl;
    for(int i=0; i<m; i++)
        cout << setw(30) << left << y[i].MaBan << setw(30) << y[i].TenBan << setw(30) << y[i].NgayThanhLap << endl;
}

void bonus1(TRUONGDH &a, char *maKhoa){
    //xóa khoa có mã KH01
    for(int i=0; i<a.n; i++){
        if(strcmpi(a.x[i].MaKhoa, maKhoa) == 0){
            for(int j = i; j < a.n - 1; j++)
                a.x[j] = a.x[j+1];
            a.n--;
        }
    }
}

int main(){
    TRUONGDH a;
    a.Nhap();
    cout << "\n\n---------------------Thong tin truong dai hoc vua nhap--------------------------" << endl;
    a.Xuat();
    bonus1(a, "KH01");
    cout << "\n\n-----------------------Thong tin truong dai hoc vua sua---------------------------" << endl;
    a.Xuat();
    return 0;
}