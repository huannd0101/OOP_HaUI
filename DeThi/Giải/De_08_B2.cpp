#include <iostream>
using namespace std;

int ucln(int a, int b){
	if (b == 0) return a;
	return ucln(b, a % b);
}

class PHANSO{
	private:
		int tu,mau;
	public:
		PHANSO(){
			tu = 0;
			mau = 1;
		}
		
		void nhap(){
			cout << "nhap tu so: ";
			cin >> tu;
			cout << "nhap mau so: ";
			cin >> mau;
		}
		
		PHANSO operator -- (){
			tu = tu / ucln(tu,mau);
			mau  = mau / ucln(tu,mau);
			return *this;
		}
		
		friend ostream &operator << (ostream &os, PHANSO a){
			os << a.tu << "/" << a.mau;
			return os;
		} 
};


int main(){
	PHANSO a;
	a.nhap();
	a = --a;
	cout << a;
	return 0;
}
