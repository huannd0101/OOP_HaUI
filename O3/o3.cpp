#include<iostream>
using namespace std;

template<class T> class Matrix {
private:    
    T **a;
    int n, m;
public:
    void input();
    void output();
    void ChuyenVi(Matrix x, Matrix &temp);
    friend int main();
};

template<class T> void Matrix<T>::input(){
    cout << "Nhap n = ";    cin >> n;
    cout << "Nhap m = ";    cin >> m;
    a = new T*[n];
    for(int i=0; i<n; i++)
        a[i] = new T[m];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cout << "Nhap a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
}

template<class T> void Matrix<T>::output(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> void Matrix<T>::ChuyenVi(Matrix<T> x, Matrix<T> &temp){
    temp.m = x.m; 
    temp.n = x.n; 
    temp.a = new T*[temp.n];
    for(int i=0; i<x.n; i++)
        temp.a[i] = new T[temp.m];

    for(int j=0; j<x.m; j++){
        for(int i=0; i<x.n; i++){
            temp.a[i][j] = x.a[j][i];
        }
    }
}

int main(){
    Matrix<double> a, tempA;
    Matrix<long> b, tempB;

    cout << "Nhap ma tran kieu double: " << endl;
    a.input();
    cout << "Ma tran vua nhap" << endl;
    a.output();

    a.ChuyenVi(a, tempA);
    
    cout << "\nMa tran chuyen vi: " << endl;
    tempA.output();

    cout << "\n--------------------------------\n";

    cout << "Nhap ma tran kieu long: " << endl;
    b.input();
    cout << "Ma tran vua nhap" << endl;
    b.output();

    b.ChuyenVi(b, tempB);
    
    cout << "\nMa tran chuyen vi: " << endl;
    tempB.output();

    return 0;
}