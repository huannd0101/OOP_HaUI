#include<bits/stdc++.h>
#include<fstream>
using namespace std;

class HANG {
private:
    char maH[15], tenH[30];
    double dg;
    int sl, nam;
public: 
    HANG();
    HANG(char *maH, char *tenH, double dg, int sl, int nam);
    friend istream &operator>> (istream &is, HANG &x);
    friend ostream &operator << (ostream &os, HANG x);
    friend void writeToFile(HANG *a, int n, char *fileName);
    friend bool checkHang(HANG *a, int n, char *name);
    friend void sortByPrice(HANG *a, int n);
    friend void deleteByMaHang(HANG *&a, int &n, char *maH);
    friend void deleteAllByPrice(HANG *&a, int &n, double price);
    friend void deleteHangByPosition(HANG *&a, int &n, int pos);
};

HANG::HANG(){
    strcpy(maH, "");
    strcpy(tenH, "");
    dg = 0;
    sl = 0;
    nam = 0;
}

HANG::HANG(char *maH, char *tenH, double dg, int sl, int nam){
    strcpy(this->maH, maH);
    strcpy(this->tenH, tenH);
    this->dg = dg;
    this->sl = sl;
    this->nam = nam;
}

istream &operator>> (istream &is, HANG &x){
    cout << "Nhap ma hang : ";  fflush(stdin);   gets(x.maH);
    cout << "Nhap ten hang: ";  gets(x.tenH);
    cout << "Nhap don gia : ";  cin >> x.dg;
    cout << "Nhap so luong: ";  cin >> x.sl;
    cout << "Nhap nam     : ";  cin >> x.nam;
    return is;
}

ostream &operator<< (ostream &os, HANG x){
    cout << left << setw(20) << x.maH << setw(20) << x.tenH << setw(15) << x.dg << setw(15) << x.sl << setw(15) << x.nam;
    return os;
}

void title(){
    cout << left << setw(20) << "Ma Hang" << setw(20) << "Ten Hang" << setw(15) << "Don Gia" << setw(15) << "So Luong" << setw(15) << "Nam" << endl;
}

void writeToFile(HANG *a, int n, char *fileName){
    // ofstream f(fileName, ios::app);
    fstream f(fileName, ios::out);
    for(int i=0; i<n; i++)
        f << left << setw(20) << a[i].maH << setw(20) << a[i].tenH << setw(15) << a[i].dg << setw(15) << a[i].sl << setw(15) << a[i].nam << endl;
    f << endl;
    f.close();
}

void input(HANG *a, int n){
    for(int i=0; i<n; i++){
        cout << "Nhap hang thu " << i + 1 << endl;
        cin >> a[i];
    }
}

void output(HANG *a, int n){
    title();
    for(int i=0; i<n; i++)
        cout << a[i] << endl;
}

bool checkHang(HANG *a, int n, char *name){
    for(int i=0; i<n; i++)
        if(stricmp(a[i].tenH, name) == 0)
            return true;
    return false;
}

void sortByPrice(HANG *a, int n){
    for(int i=0; i<n-1; i++)
        for(int j=n-1; j > i; j--)
            if(a[j-1].dg > a[j].dg){
                HANG temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
}

void deleteHangByPosition(HANG *&a, int &n, int pos){
    for(int j=pos; j<n-1; j++)
        a[j] = a[j+1];
    n--;
    a = (HANG*)realloc(a, n*sizeof(HANG));
}

void deleteByMaHang(HANG *&a, int &n, char *maH){
    bool ok = false;
    for(int i=0; i<n; i++){
        if(stricmp(maH, a[i].maH) == 0){
            deleteHangByPosition(a, n, i);
            break;
        }
    }
}

void deleteAllByPrice(HANG *&a, int &n, double price){
    for(int i=0; i<n; i++){
        while(a[i].dg < 20 && i<n)
            deleteHangByPosition(a, n, i);
    }
}

void insertHangToArray(HANG *&a, int &n, HANG x, int pos){
    if(pos < 1 || pos > n){
        cout << "Pos khong hop le";
        return;
    }
    n++;
    a = (HANG*)realloc(a, n*sizeof(HANG));
    for(int i=n-1; i>=pos; i--)
        a[i] = a[i-1];
    a[pos-1]=x;
}

int main() {
    int n;
    cin >> n;
    HANG *a = new HANG[n];
    input(a, n);    
    // output(a, n);
    writeToFile(a, n, "HANGNHAP.DAT");

    if(checkHang(a, n, "IPHONE 12"))
        cout << "\nIPHONE 12 co trong danh sach" << endl;
    else
        cout << "\nIPHONE 12 khong co trong danh sach" << endl;

    sortByPrice(a, n);
    writeToFile(a, n, "HANGSORT.TXT");

    deleteByMaHang(a, n, "H005");
    writeToFile(a, n, "HANGREMOVE.TXT");

    deleteAllByPrice(a, n, 20);
    writeToFile(a, n, "HANGREMOVE.TXT");

    int pos;
    cout << "Nhap pos to insert: ";
    cin >> pos;
    HANG temp;
    cin >> temp;

    insertHangToArray(a, n, temp, pos);

    output(a, n);

    return 0;
}