#include <iostream>
#include <iomanip>
using namespace std;

class HANG{
	private:
		char maHang[30];
		char tenHang[30];
		int donGia;
		int soLuong;	
	public:
		void nhap(){
			fflush(stdin);
			cout << "nhap ma hang: ";
			gets(maHang);
			cout << "nhap ten hang: ";
			gets(tenHang);
			cout << "nhap don gia: ";
			cin >> donGia;
			cout << "nhap so luong: ";
			cin >> soLuong;
		}
		
		void xuat(){
			cout << setw(10) << maHang << setw(15) << tenHang; 
			cout << setw(10) << donGia << setw(15) << soLuong;
			cout << setw(15) << donGia * soLuong << endl; 
		}
		
		friend class PHIEU;
};

class PHIEU{
	private:
		char maPhieu[30];
		char tenKhachHang[30];
		char ngayLap[30];
		HANG *a;
		int n;
	public:
		void nhap(){
			a = new HANG[200];
			cout << "nhap ma phieu: ";
			gets(maPhieu);
			cout << "nhap ten khach hang: ";
			gets(tenKhachHang);
			cout << "nhap ngay lap: ";
			gets(ngayLap);
			
			cout << "nhap so luong mat hang: ";
			cin >> n;
			
			
			for(int i = 0 ; i < n ; i++){
				a[i].nhap();
			}
		}
		
		void xuat(){
			long int tongTien = 0 ;
			for(int i = 0 ; i < n; i++){
				tongTien += a[i].donGia * a[i].soLuong;
			}
			
			cout << setw(20) << "PHIEU MUA HANG" << endl;
			cout << setw(10) << "Ma phieu: " << maPhieu;
			cout << setw(20) << "Khach hang: " << tenKhachHang << endl;
			
			cout << setw(10) << "Ngay thanh lap: " << ngayLap;
			cout << setw(20) << "Tong thanh tien: " << tongTien << endl;
			
			for(int i = 0 ; i < n ; i++){
				a[i].xuat();
			}
		}
};
int main(){
	PHIEU a;
	a.nhap();
	a.xuat();
	return 0;
}
