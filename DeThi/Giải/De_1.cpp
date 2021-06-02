#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
using namespace std;

//câu 1
// class CauThu;

// class Person {
// protected:
// 	char hoTen[50];
// 	int ngaySinh, thangSinh, namSinh;
// 	char queQuan[100];
// };

// class VanDongVien : public Person {
// protected:
// 	char boMon[30];
// 	float thuNhap;
// public: 
// 	friend void FindPersonByThuNhapMax(CauThu *a, int n);
// };

// class CauThu : public VanDongVien {
// private:
// 	char clb[100];
// 	char viTri[100];
// public:
// 	void nhap();
// 	void xuat();
// 	friend void SearchByCLB(CauThu *a, int n, char *cauLacBo);
// };

// void CauThu::nhap(){
// 	fflush(stdin);
// 	cout << "Nhap ho ten    : "; gets(this->hoTen);	
// 	cout << "Nhap ngay sinh : "; cin >> this->ngaySinh;	
// 	cout << "Nhap thang sinh: "; cin >> this->thangSinh;
// 	cout << "Nhap nam sinh  : "; cin >> this->namSinh;
// 	cout << "Nhap que quan  : "; fflush(stdin); gets(this->queQuan);
// 	cout << "Nhap bo mon    : "; gets(this->boMon);
// 	cout << "Nhap thu nhap  : "; cin >> this->thuNhap;
// 	cout << "Nhap clb       : "; fflush(stdin); gets(this->clb);
// 	cout << "Nhap vi tri       : "; fflush(stdin); gets(this->viTri);
// }

// void CauThu::xuat(){
// 	cout << left << setw(30) << this->hoTen << setw(2) << this->ngaySinh << "/" << setw(2) << this->thangSinh << "/" << setw(9) << this->namSinh 
// 		<< setw(30) << this->queQuan << setw(30) << this->boMon << setw(15) << this->thuNhap << setw(30) << this->clb << setw(30) << this->viTri << endl;	
// }

// void NhapDanhSach(CauThu *a, int n){
// 	for(int i=0; i<n; i++){
// 		cout << "Nhap thong tin cau thu thu " << i + 1 << endl;
// 		a[i].nhap();
// 	}
// }

// void SearchByCLB(CauThu *a, int n, char *cauLacBo){
// 	for(int i=0; i<n; i++){
// 		if(stricmp(a[i].clb, cauLacBo) == 0){
// 			a[i].xuat();	
// 		}
// 	}	
// }

// void FindPersonByThuNhapMax(CauThu *a, int n){
// 	//find max
// 	float max = a[0].thuNhap;
// 	for(int i=1; i<n; i++){
// 		if(a[i].thuNhap > max){
// 			max = a[i].thuNhap;	
// 		}
// 	}	
// 	//show
// 	for(int i=0; i<n; i++){
// 		if(a[i].thuNhap == max){
// 			a[i].xuat();
// 		}	
// 	}
// }

// int main(){
// 	int n;
// 	cout << "Nhap n = ";
// 	do {
// 		cin >> n;
// 		if(n <= 0 || n >= 50)
// 			cout << "Nhap lai n = ";
// 	}while(n <= 0 || n >= 50);

// 	CauThu *a = new CauThu[n];
	
// 	NhapDanhSach(a, n);
// 	cout << "\nCau thu o trong clb T&T" << endl;
// 	cout << left << setw(30) << "Ho Ten" << setw(15) << "Ngay Sinh" << setw(30) << "Que Quan" << setw(30) << "Bo Mon"
// 		<< setw(15) << "Thu Nhap" << setw(30) << "CLB" << setw(30) << "Vi Tri" << endl;
// 	SearchByCLB(a, n, "T&T");
	
	
// 	cout << "\nCau thu thu nhap cao nhat " << endl;
// 	cout << left << setw(30) << "Ho Ten" << setw(15) << "Ngay Sinh" << setw(30) << "Que Quan" << setw(30) << "Bo Mon"
// 		<< setw(15) << "Thu Nhap" << setw(30) << "CLB" << setw(30) << "Vi Tri" << endl;
// 	FindPersonByThuNhapMax(a, n);
	
//     return 0;
// }

//Câu 2:

class Diem {
private:
	double x, y, z;
public:
	Diem();
	Diem(double x, double y, double z);
	Diem operator+(Diem a);
	friend istream &operator>>(istream &is, Diem &a);
	friend ostream &operator<<(ostream &os, Diem a);
};

Diem::Diem(){
	x = y = x = 0;
}

Diem::Diem(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}

Diem Diem::operator+(Diem a){
	Diem temp;
	temp.x = this->x + a.x;
	temp.y = this->y + a.y;
	temp.z = this->z + a.z;
	return temp;
}

istream &operator>>(istream &is, Diem &a){
	cout << "Nhap x = "; is >> a.x;
	cout << "Nhap y = "; is >> a.y;
	cout << "Nhap z = "; is >> a.z;
	return is;
}

ostream &operator<<(ostream &os, Diem a){
	os << "(" << a.x << ", " << a.y << ", " << a.z << ")" << endl;
	return os;
}

int main(){
	Diem a, b;
	cout << "Nhap thong tin diem a" << endl;
	cin >> a;
	
	cout << "Nhap thong tin diem b" << endl;
	cin >> b;

	cout << "a + b = " << a + b;
	
	return 0;
}