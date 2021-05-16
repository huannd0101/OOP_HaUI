#include<iostream>
#include<string.h>
using namespace std;

class FACULTY;
class STUDENT;

class SCHOOL {
private:
    char Name[30], Date[15];
public:
    friend class FACULTY;
    friend void PatchNameOfSchool(STUDENT &a);
};

class FACULTY {
private:
    char Name[30], Date[15];
    SCHOOL x;
public:
    void input();
    void output();
    friend class STUDENT;
    friend void PatchNameOfSchool(STUDENT &a);
};

void FACULTY::input(){
    cout << "Nhap name of faculty: "; fflush(stdin);    gets(Name);
    cout << "Nhap date of faculty: "; fflush(stdin);    gets(Date);
    cout << "Nhap name of school : "; fflush(stdin);    gets(x.Name);
    cout << "Nhap date of school : "; fflush(stdin);    gets(x.Date);
}

void FACULTY::output(){
    cout << "Name of faculty: " << Name << endl;
    cout << "Date of faculty: " << Date << endl;
    cout << "Name of school : " << x.Name << endl;
    cout << "Date of school : " << x.Date << endl;
}

class PERSON {
private:
    char Name[30], Birth[15], Address[30];
public: 
    void input();
    void output();
    PERSON();
};

PERSON::PERSON(){
    strcpy(Name, "");
    strcpy(Birth, "");
    strcpy(Address, "");
}

void PERSON::input(){
    cout << "Nhap name of person: "; fflush(stdin);   gets(Name);
    cout << "Nhap birth of person: "; fflush(stdin);   gets(Birth);
    cout << "Nhap address of person: "; fflush(stdin);   gets(Address);
}

void PERSON::output(){
    cout << "Name of person: " << Name << endl;
    cout << "Birth of person: " << Birth << endl;
    cout << "Address of person: " << Address << endl;
}

class STUDENT : public PERSON{
private:
    FACULTY y;
    char Class[15];
    double Score;
public:
    void input();
    void output();
    STUDENT();
    friend void PatchNameOfSchool(STUDENT &a);
};

STUDENT::STUDENT() : PERSON() {
    strcpy(Class, "");
    Score = 0;
}

void STUDENT::input(){
    PERSON::input();
    y.input();
    cout << "Nhap class: "; fflush(stdin);  gets(Class);
    cout << "Nhap score: "; cin >> Score;
}

void STUDENT::output(){
    PERSON::output();
    y.output();
    cout << "Class: " << Class << endl;
    cout << "Score: " << Score << endl;
}

void PatchNameOfSchool(STUDENT &a){
    strcpy(a.y.x.Name, "DHCNHN");
}

int main(){
    STUDENT a;
    a.input();
    cout << "\n--------------------Thong tin student---------------------" << endl;
    a.output();
    PatchNameOfSchool(a);
    cout << "\n-------------Thong tin student sau khi sua----------------" << endl;
    a.output();
    return 0;
}