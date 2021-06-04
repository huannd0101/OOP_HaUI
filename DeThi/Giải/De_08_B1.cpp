#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class CONGDAN{
	protected:
		char soTheCanCuoc[30];
		char hoTen[30];
		int namSinh;
		char gioiTinh[5];
	public:
		void nhap(){
			fflush(stdin);
			cout << "nhap so the can cuoc: ";
			gets(soTheCanCuoc);
			cout << "nhap ho ten: ";
			gets(hoTen);
			cout << "nhap nam sinh: ";
			cin >> namSinh;
			fflush(stdin);
			cout << "nhap gioi tinh: ";
			gets(gioiTinh);
			
		}
	
		void xuat(){
			cout << setw(10) << soTheCanCuoc<< setw(20) << hoTen;
			cout << setw(10) << namSinh << setw(10) << gioiTinh;
		}
};

class CANBO : public CONGDAN{
	private:
		int heSoLuong;
		int tienPhuCap;
	public:
		void nhap(){
			CONGDAN::nhap();
			cout << "nhap he so luong: ";
			cin >> heSoLuong;
			cout << "nhap tien phu cap: ";
			cin >> tienPhuCap;
		}
		
		void xuat(){
			CONGDAN::xuat();
			cout << setw(15) << heSoLuong << setw(15) << tienPhuCap << endl;
		}
		friend void hienThiNamVaLuong10Cu(CANBO *cb, int n);
};

void hienThiNamVaLuong10Cu(CANBO *cb, int n){
	long long thuNhap;
	for(int i = 0 ; i < n ; i++){
		thuNhap = cb[i].heSoLuong * 1390000 + cb[i].tienPhuCap;
		if(strcmp(cb[i].gioiTinh, "nam") == 0 && thuNhap > 10000000){
			cb[i].xuat();
		}
	}
}
int main(){
	int n;
	cout << "nhap n: ";
	cin >> n;
	
	CANBO *cb = new CANBO [100];
	for(int i = 0 ; i < n; i++){
		cb[i].nhap();
	}
	
	hienThiNamVaLuong10Cu(cb,n);
	
	return 0;	
}
