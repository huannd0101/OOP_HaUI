#include <iostream>
#include <iomanip>
using namespace std;

class PHUONGTRINH{
	private:
		double a,b,c,d;
	public:
		PHUONGTRINH(){
			a = b = c = d = 0;
		}
		
		void nhap(){
			cout << "nhap a,b,c,d: ";
			cin >> a >> b >> c >> d;
		}
		
		PHUONGTRINH operator -- (){
			double tg[5] = {a,b,c,d};
			for(int i = 0 ; i < 5; i++){
				for(int j = i + 1 ; j < 5; j++){
					if(tg[i] < tg[j])
						swap(tg[i], tg[j]);
				}	
			}
			
			a = tg[0];
			b = tg[1];
			c = tg[2];
			d = tg[3];	
			return *this;		
		}
		
		friend ostream &operator << (ostream &os, PHUONGTRINH pt){
			os << pt.a << "x3 + " << pt.b << "x2 + " << pt.c << "x + " << pt.d;
			return os;
		}
};
int main(){
	PHUONGTRINH a;
	a.nhap();
	a = --a;
	cout << a;
	return 0;
}
