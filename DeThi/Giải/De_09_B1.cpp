#include <iostream>
#include <iomanip>
using namespace std;
class XEMAY;
class NgayThangNam{
	private: 
		int ngay;
		int thang;
		int nam;
	friend class XE;
	friend void hienThiXeMayTheoNam(XEMAY *a, int n, int nam);
};

class XE{
	protected:
		char tenChuXe[30];
		char bienSo[20];
		char noiDangKi[30];
		NgayThangNam ngayDangKi;
		
	public:	
		void nhap(){
			fflush(stdin);
			cout << "nhap ten chu xe: ";
			gets(tenChuXe);
			cout << "nhap bien so: ";
			gets(bienSo);
			cout << "nhap noi dang ki: ";
			gets(noiDangKi);
			cout << "nhap ngay/thang/nam dang ki: ";
			cin >> ngayDangKi.ngay >> ngayDangKi.thang >> ngayDangKi.nam;
		}	
		
		void xuat(){
			cout << setw(10) << tenChuXe << setw(20) << bienSo;
			cout << setw(20) << noiDangKi << setw(20) << ngayDangKi.ngay << "/";
			cout << ngayDangKi.thang << "/" << ngayDangKi.nam;
		}
		
};

class XEMAY : public XE{
	private:
		double giaTien;
		char mauSon[30];
	public:
		void nhap(){
			XE::nhap();
			cout << "nhap gia tien: ";
			cin >> giaTien;
			fflush(stdin);
			cout << "nhap mau son: ";
			gets(mauSon);
		}
		
		void xuat(){
			XE::xuat();
			cout << setw(10) << giaTien << setw(15) << mauSon << endl;
		}
		friend void hienThiXeMayTheoNam(XEMAY *a, int n, int nam);
};

void hienThiXeMayTheoNam(XEMAY *a, int n, int nam){
	for(int i = 0 ; i < n; i++){
		if(a[i].ngayDangKi.nam == nam){
			a[i].xuat();
		}
	}
}
int main(){
	int n;
	cout << "nhap n: ";
	cin >> n;
	XEMAY *xemay = new XEMAY[100];
	
	for(int i = 0 ; i < n ; i++){
		xemay[i].nhap();
	}
	
	hienThiXeMayTheoNam(xemay,n,2016);
	return 0;	
}
