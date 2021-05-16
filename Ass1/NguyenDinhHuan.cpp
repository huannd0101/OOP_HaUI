#include<bits/stdc++.h>

using namespace std;
class Phieu;
class SanPham {
private:
    char maSP[10], tenSP[30];
    int soLuong;
    double donGia;
public:
    void nhap();
    void xuat();
    friend class Phieu;
    friend int countSP(Phieu a);
    friend void sortByPrice(Phieu a);
};

void SanPham::nhap(){
    cout << "Nhap ma SP: "; fflush(stdin);  gets(maSP);
    cout << "Nhap ten SP: "; fflush(stdin);  gets(tenSP);
    cout << "Nhap so luong: "; cin >> soLuong;
    cout << "Nhap don gia: "; cin >> donGia;
}

void SanPham::xuat(){
    cout << left << setw(15) << maSP << setw(25) << tenSP << setw(15) << soLuong << setw(15) << donGia << setw(15) << donGia*soLuong << endl; 
}

class NCC {
private:
    char maNCC[15], tenNCC[30], diaChi[30], sdt[15];
public:
    void nhap();
    void xuat();
};

void NCC::nhap(){
    cout << "Nhap ma NCC: "; fflush(stdin); gets(maNCC);
    cout << "Nhap ten NCC: "; fflush(stdin); gets(tenNCC);
    cout << "Nhap dia chi: "; fflush(stdin); gets(diaChi);
    cout << "Nhap so dien thoai: "; fflush(stdin); gets(sdt);
}

void NCC::xuat(){
    cout << left << "Ma NCC : " << setw(30) << maNCC << "Ten NCC: " << tenNCC << endl;
    cout << left << "Dia chi: " << setw(30) << diaChi << "SDT: " << sdt << endl;
}

class Phieu {
private:
    char maPhieu[15], ngayLap[15];
    NCC ncc;
    SanPham *sp;
    int n;
public:
    void nhap();
    void xuat();
    friend int countSP(Phieu a);
    friend void sortByPrice(Phieu a);
};

void Phieu::nhap(){
    cout << "Nhap ma phieu: "; fflush(stdin);   gets(maPhieu);
    cout << "Nhap ngay lap: "; fflush(stdin);   gets(ngayLap);
    ncc.nhap();
    cout << "Nhap so luong san pham: "; cin >> n;
    sp = new SanPham[n];
    for(int i=0; i<n; i++){
        cout << "Nhap thong tin san pham thu: " << i + 1 << endl;
        sp[i].nhap();
    }
}

void Phieu::xuat(){
    cout << "\nDai hoc Victory" << endl;
    cout << "\t\t\t\tPHIEU NHAP VAN PHONG PHAM" << endl;
    cout << left << "Ma phieu: " << setw(30) << maPhieu << "Ngay lap: " << ngayLap << endl;
    ncc.xuat();
    cout << left << setw(15) << "Ma SP" << setw(25) << "Ten SP" << setw(15) << "So luong" << setw(15) << "Don gia" << setw(15) << "Thanh tien" << endl; 
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += sp[i].donGia * sp[i].soLuong;
        sp[i].xuat();
    }
    cout << left << setw(70) << "TONG" << sum;
}

int countSP(Phieu a){
    int cnt = 0;
    for(int i=0; i<a.n; i++)
        if(a.sp[i].soLuong < 80)
            cnt++;
    return cnt;
}

void sortByPrice(Phieu a){
    for(int i=0; i<a.n-1; i++){
        for(int j=a.n-1; j>i; j--){
            if(a.sp[j-1].donGia > a.sp[j].donGia){
                SanPham temp = a.sp[j-1];
                a.sp[j-1] = a.sp[j];
                a.sp[j] = temp;
            }
        }
    }
}

int main(){
    Phieu a;
    a.nhap();

    cout << "\nSo san pham co so luong nhap nho hon 80 la: " << countSP(a) << endl;
    
    sortByPrice(a);

    a.xuat();
    return 0;
}


