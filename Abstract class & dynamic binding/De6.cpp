#include<bits/stdc++.h>
using namespace std;
class Student;
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

class School {
private:    
    char tenTruonng[30], diaChi[30];
    Person hieuTruong;
public:
    friend class Student;
    friend void displayTenTruong (Student *a, int n);
};

class Student: public Person{
private:
    char lop[15], nghanh[30];
    School truong;
public:
    void input();
    void output();
    friend void displayTenTruong (Student *a, int n);
    friend void sortByAge(Student *a, int n);
    friend void insert(Student *&a, int &n, Student x, int pos);
};

void Student::input(){
    Person::input();
    cout << "Nhap lop: "; fflush(stdin); gets(lop);
    cout << "Nhap nghanh: ";  gets(nghanh);
    cout << "Nhap ten truong: "; gets(truong.tenTruonng);
    cout << "Nhap dia chi: "; gets(truong.diaChi);
    cout << "Nhap thong tin hieu truong: " << endl;
    truong.hieuTruong.input();
}
void Student::output(){
    Person::output();
    cout << left << setw(15) << lop << setw(20) << nghanh << setw(20) << truong.tenTruonng << setw(20) << truong.diaChi;
    truong.hieuTruong.output();
    cout << endl;   
}

void displayTenTruong (Student *a, int n){
    for(int i=0; i<n; i++){
        if(stricmp(a[i].truong.tenTruonng, "DHCNHN") == 0)
            a[i].output();
    }
    cout << endl;
}

void sortByAge(Student *a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>i; j--){
            if(a[j-1].age > a[j].age){
                Student temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void insert(Student *&a, int &n, Student x, int pos){
    a = (Student*) realloc(a, (n+1)*sizeof(Student));
    for(int i=n; i>=pos-1; i--)
        a[i] = a[i-1];
    a[pos-1] = x;
    n++;
}

int main(){
    int n;
    cin >> n;
    Student *a = new Student[n];
    for(int i=0; i<n; i++){
        cout << "Nhap thong tin student " << i + 1 << endl;
        a[i].input();
    }

    for(int i=0; i<n; i++){
        a[i].output();
    }
    cout << endl;

    displayTenTruong(a, n);

    int pos;
    cin >> pos;
    Student x;
    x.input();
    insert(a, n, x, pos);

    cout << endl;
    for(int i=0; i<n; i++){
        a[i].output();
    }

    return 0;
}