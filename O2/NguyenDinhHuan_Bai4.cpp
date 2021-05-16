#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class BENHNHAN;

class NGUOI {
protected:
    char hoTen[30];
    int age;
public:
    void Nhap();
    void Xuat();
};

void NGUOI::Nhap(){
    cout << "Nhap ho ten: "; fflush(stdin); gets(hoTen);
    cout << "Nhap tuoi  : "; cin >> age;
}

void NGUOI::Xuat(){
    cout << left << setw(20) << hoTen << setw(10) << age;
}

class BENHVIEN {
private: 
    char tenBV[30], diaChi[30];
    NGUOI giamDoc;
public:
    friend class BENHNHAN;
};

class BENHNHAN: public NGUOI{
private:
    char ma[30], tienSu[30], chuanDoan[30];
    BENHVIEN benhVien;
public:
    void Nhap();
    void Xuat();
    friend int bonus1(BENHNHAN *a, int n);
    friend void bonus2(BENHNHAN *a, int n, char *ma);
};

void BENHNHAN::Nhap(){
    NGUOI::Nhap();
    cout << "Nhap ma        : "; fflush(stdin);    gets(ma);
    cout << "Nhap tien su   : "; fflush(stdin);    gets(tienSu);
    cout << "Nhap chuan doan: "; fflush(stdin);    gets(chuanDoan);
    cout << "Nhap ten benh vien: "; fflush(stdin); gets(benhVien.tenBV);
    cout << "Nhap dia chi: "; fflush(stdin); gets(benhVien.diaChi);
    cout << "Nhap thong tin giam doc: " << endl;
    benhVien.giamDoc.Nhap();
}

void BENHNHAN::Xuat(){
    NGUOI::Xuat();
    cout << left << setw(15) << ma << setw(20) << tienSu << setw(20) << chuanDoan << setw(20) << benhVien.tenBV 
        << setw(20) << benhVien.diaChi;
    benhVien.giamDoc.Xuat();
    cout << endl;
}

int bonus1(BENHNHAN *a, int n){
    int count = 0;
    for(int i=0;i<n; i++)
        if(a[i].age > 30)
            count++;
    return count;
}

void bonus2(BENHNHAN *a, int n, char *ma){
    for(int i=0; i<n; i++){
        if(stricmp(a[i].ma, ma) == 0){
            a[i].age = 20;
        }
    }
}

int main(){
    int n;
    cout << "Nhap so benh nhan: ";  cin >> n; cin.ignore();
    BENHNHAN *a = new BENHNHAN[n];
    for(int i=0; i<n; i++){
        cout << "\tNhap thong tin benh nhan thu " << i + 1 << endl;
        a[i].Nhap();
    }

    cout << "\n-----------------------------------Thong tin n benh nhan------------------------------" << endl;
    for(int i=0; i<n; i++)
        a[i].Xuat();
    
    cout << "\n\nCo " << bonus1(a, n) << " benh nhan tren 30 tuoi" << endl;

    bonus2(a, n, "BN01");

    cout << "\n----------------------Thong tin n benh nhan sau khi sua-------------------------------" << endl;
    for(int i=0; i<n; i++)
        a[i].Xuat();

    return 0;
}