#include<bits/stdc++.h>
using namespace std;
class LOPHOC;
class NGUOI {
private:
    char hoTen[30], ngaySinh[15], queQuan[30];
public:
    void nhap();
    void xuat();
};

void NGUOI::nhap(){
    cout << "Nhap ho ten: ";    fflush(stdin);  gets(hoTen);
    cout << "Nhap ngay sinh: ";    fflush(stdin);  gets(ngaySinh);
    cout << "Nhap que quan: ";    fflush(stdin);  gets(queQuan);
}

void NGUOI::xuat(){
    cout << left << setw(20) << hoTen << setw(15) << ngaySinh << setw(20) << queQuan;
}

class SINHVIEN: public NGUOI {
private:
    char maSV[20], nghanh[30];
    int khoaHoc;
public:
    void nhap();
    void xuat();
    friend int demSinhVienBangKhoa(LOPHOC a, int khoaHoc);
};

void SINHVIEN::nhap(){
    NGUOI::nhap();
    cout << "Nhap ma sinh vien: ";  fflush(stdin);  gets(maSV);
    cout << "Nhap nghanh: ";  fflush(stdin);  gets(nghanh);
    cout << "Nhap khoa hoc: "; cin >> khoaHoc;
}

void SINHVIEN::xuat(){
    NGUOI::xuat();
    cout << left << setw(20) << maSV << setw(20) << nghanh << setw(15) << khoaHoc << endl;
}

class LOPHOC {
private:
    char maLH[20], tenLH[30], ngayMo[15];
    SINHVIEN *x;
    int n;
    NGUOI giaoVien;
public:
    void nhap();
    void xuat();
    friend int demSinhVienBangKhoa(LOPHOC a, int khoaHoc);
};

void LOPHOC::nhap(){
    cout << "Nhap ma lop: "; fflush(stdin); gets(maLH);
    cout << "Nhap ten lop: "; fflush(stdin); gets(tenLH);
    cout << "Nhap ngay mo: "; fflush(stdin); gets(ngayMo);
    cout << "Nhap so sinh vien: "; cin >> n;
    x = new SINHVIEN[n];
    for(int i=0; i<n; i++){
        cout << "Nhap sinh vien thu " << i + 1 << endl;
        x[i].nhap();
    }
    cout << "Nhap thong tin giao vien: " << endl;
    giaoVien.nhap();
}

void title(){
    cout << left << setw(20) << "Ho ten" << setw(15) << "Ngay sinh" << setw(20) << "Que quan" << setw(20) << "Ma SV" << setw(20) << "Nghanh" << setw(15) << "Khoa hoc" << endl;;
}

void LOPHOC::xuat(){
    cout << "Ma lop: " << maLH << endl;
    cout << "Ten lop: " << tenLH << endl;
    cout << "Ngay mo: " << ngayMo << endl;
    title();
    for(int i=0; i<n; i++)
        x[i].xuat();
    cout << "Thong tin giao vien: " << endl;
    cout << left << setw(20) << "Ho ten" << setw(15) << "Ngay sinh" << setw(20) << "Que quan" << endl;
    giaoVien.xuat();
}

int demSinhVienBangKhoa(LOPHOC a, int khoaHoc){
    int cnt = 0;
    for(int i=0; i<a.n; i++)
        if(a.x[i].khoaHoc == khoaHoc)
            cnt++;
    return cnt;
}

int main(){
    LOPHOC a;
    a.nhap();
    a.xuat();

    cout << "\nCo " << demSinhVienBangKhoa(a, 11) << " sinh vien khoa 11" << endl;
    return 0;
}