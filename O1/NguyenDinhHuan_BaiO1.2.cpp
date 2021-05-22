#include<iostream>
#include<iomanip>
using namespace std;
class PHIEU;
class MON {
private:
    char tenMon[30];
    int soTrinh;
    float diem;
public:
    void Nhap();
    void Xuat();
    friend class PHIEU;
    friend void Bonus1(PHIEU a);
};

void MON::Nhap(){
    cout << "Nhap ten mon : "; fflush(stdin); gets(tenMon);
    cout << "Nhap so trinh: "; cin >> soTrinh;
    cout << "Nhap diem    : "; cin >> diem;
}

void MON::Xuat(){
    cout << setw(25) << left << tenMon << setw(15) << soTrinh << setw(15) << diem << endl;  
}

class SINHVIEN {
private:
    char maSV[30];
    char tenSV[30];
    char lop[15];
    int khoa;
public: 
    void Nhap();
    void Xuat();
};

void SINHVIEN::Nhap(){
    cout << "Nhap MSV : "; fflush(stdin); gets(maSV);
    cout << "Nhap ten : "; fflush(stdin); gets(tenSV);
    cout << "Nhap lop : "; fflush(stdin); gets(lop);
    cout << "Nhap khoa: "; cin >> khoa;
}

void SINHVIEN::Xuat(){
    cout << "MSV: " << setw(20) << maSV << "\tTen sinh vien: " << tenSV << endl;
    cout << "Lop: " << setw(20) << lop <<  "\tKhoa: " << khoa << endl;
}

class PHIEU{
private:
    SINHVIEN sv;
    MON *x;
    int n;
public:
    void Nhap();
    void Xuat();
    friend void Bonus1(PHIEU a);
    friend void Bonus2(PHIEU a);
};

void PHIEU::Nhap(){
    sv.Nhap();
    cin.ignore();
    cout << "Nhap so mon: ";    cin >> n;
    x = new MON[n];
    for(int i=0; i<n; i++){
        cout << "\nNhap mon thu " << i + 1 << endl;
        x[i].Nhap();
    }
}

void PHIEU::Xuat(){
    float s = 0;
    cout << "\n\n\t\t\tPHIEU BAO DIEM" << endl;
    sv.Xuat();
    cout << "Bang diem: " << endl;
    cout << setw(25) << left << "Ten mon" << setw(15) << "So trinh" << setw(15) << "Diem" << endl;
    for(int i=0; i<n; i++){
        x[i].Xuat();
        s += x[i].diem;
    }
    cout << right << setw(40) << "Diem trung binh: " << s/n;
}

void Bonus1(PHIEU a){
    cout << "\n\n==========================Bonus 1==============================" << endl;
    cout << setw(25) << left << "Ten mon" << setw(15) << "So trinh" << setw(15) << "Diem" << endl;
    for(int i=0; i<a.n; i++){
        if(a.x[i].soTrinh > 3)
            a.x[i].Xuat();
    }
}

void Bonus2(PHIEU a){
    cout << "\n==========================Bonus 2==============================" << endl;
    int pos;
    cout << "Nhap vi tri chen: ";   
    do {
        cin >> pos;
        if(pos < 1 || pos > a.n + 1)
            cout << "Nhap lai vi tri: ";
    }while(pos < 1 || pos > a.n + 1);
    MON temp;
    temp.Nhap();
    a.n++;
    for(int i=a.n-1; i>=pos-1; i--)
        a.x[i] = a.x[i-1];
    a.x[pos-1] = temp;
    
    a.Xuat();
}

int main(){
    PHIEU a;

    a.Nhap();
    a.Xuat();

    Bonus1(a);

    Bonus2(a);
    return 0;
}