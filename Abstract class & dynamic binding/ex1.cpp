#include<bits/stdc++.h>
using namespace std;

class Hinh {
protected:
    int ms, vien;
public: 
    virtual void nhap();
    virtual void xuat();
};

void Hinh::nhap(){
}
void Hinh::xuat(){
    
}

class HCN:public Hinh {
private:
    float w, l;
public: 
    void nhap();
    void xuat();
};

void HCN::nhap(){
    cout << "Nhap mau: "; cin >> ms;
    cout << "Nhap vien: "; cin >> vien;
    cout << "Nhap dai: ";   cin >> l;
    cout << "Nhap rong: ";   cin >> w;
} 
void HCN::xuat(){
    cout << left << setw(15) << ms << setw(15) << vien;
    cout << left << setw(15) << l << setw(15) << w << endl;
} 

int main(){
    Hinh x;
    HCN y;

    Hinh *p;
    p = &y;
    p->nhap();

    p->xuat();
    
    return 0;
}
/*
    -xét tình huống:
        +) một sơ đồ lớp có kế thừa
        +) sử dụng 1 con trỏ thuộc vào lớp cha
    ---> kl: 
    1) O có thể trỏ tới các phương thức laop con
    2) nếu p truy xuất các phương thức thông thường thì được mặc định là truy xuất là lớp cha
    3) nếu p truy xuất các phương thức ảo thì class liên kết

    --phương thức ảo
    - cách định nghĩ: virtual thên virtual vào trước nguyên mẫu của khai báo các phương thức lớp cha

    --kết buộc động
    - kết buộc động: 1 lời gọi pt p->nhap();
    -
    -- Tính đa hìnhp
      8: ohuowng thức thuần ảo: là phương thức ảo và rỗng cơ sở c
*/