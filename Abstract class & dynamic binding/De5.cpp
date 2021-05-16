#include<bits/stdc++.h>
using namespace std;

void title(){
    cout << left << setw(20) << "Name" << setw(15) << "age" << setw(20) << "Tien su" << setw(20) << "Chuan doan" << setw(20) << "Ten benh vien" << setw(20) << "Dia chi" << setw(20) << "Ten giam doc" << setw(15) << "Tuoi GD" << endl;
}
class BenhNhan;
class Person {
protected:
    char name[30];
    int age;
public:
    void input();
    void output();
};

void Person::input(){
    cout << "Nhap name: "; fflush(stdin); gets(name);
    cout << "Nhap age: "; cin >> age;
}
void Person::output(){
    cout << left << setw(20) << name << setw(15) << age;
}


class Hospital {
private:
    char tenBenhVien[30], diaChi[30];
    Person giamDoc;
public:
    friend class BenhNhan;
    friend void displayBachMai(BenhNhan *a, int n);
};

class BenhNhan: public Person{
private:
    char tienSu[30], chuanDoan[30];
    Hospital benhVien;
public:
    void input();
    void output();
    friend void displayBachMai(BenhNhan *a, int n);
    friend void displayByAge(BenhNhan *a, int n);
    friend void deleteByTienSu(BenhNhan *&a, int &n);
};

void BenhNhan::input(){
    Person::input();
    cout << "Nhap tien su: "; fflush(stdin);    gets(tienSu);
    cout << "Nhap chuan doan: ";    gets(chuanDoan);
    cout << "Nhap ten benh vien: ";   gets(benhVien.tenBenhVien);
    cout << "Nhap dia chi: ";   gets(benhVien.diaChi);
    benhVien.giamDoc.input();
}
void BenhNhan::output(){
    Person::output();
    cout << left << setw(20) << tienSu << setw(20) << chuanDoan << setw(20) <<
        benhVien.tenBenhVien << setw(20) << benhVien.diaChi;
    benhVien.giamDoc.output();
    cout << endl;
}

void displayBachMai(BenhNhan *a, int n){
    title();
    for(int i=0; i<n; i++){
        if(stricmp(a[i].benhVien.tenBenhVien, "bach mai") == 0)
            a[i].output();
    }
}

void displayByAge(BenhNhan *a, int n){
    title();
    for(int i=0; i<n; i++){
        if(a[i].age >= 20 && a[i].age <= 45)
            a[i].output();
    }
}

void deleteByTienSu(BenhNhan *&a, int &n){
    for(int i=0; i<n; i++){
        while(i < n && stricmp(a[i].tienSu, "BenhTim") == 0){
            for(int j=i; j<n-1; j++)
                a[j] = a[j+1];
            n--;
        }
    }
    a = (BenhNhan*) realloc(a, n*sizeof(int));
}

int main(){
    int n;
    cin >> n;
    BenhNhan *a = new BenhNhan[n];
    //input
    for(int i=0; i<n; i++){
        cout << "Nhap thong tin benh nhan thu: " << i + 1 << endl;
        a[i].input();
    }

    //output
    title();
    for(int i=0; i<n; i++)
        a[i].output();

    displayBachMai(a, n);

    displayByAge(a, n);

    deleteByTienSu(a, n);
    title();
    for(int i=0; i<n; i++)
        a[i].output();

    return 0;
}