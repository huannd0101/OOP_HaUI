#include<bits/stdc++.h>
using namespace std;
template<class T> class Mang {
    T *a;
    int n;
public:
    void nhap();
    void xuat();
};

template<class T> void Mang<T>::nhap(){
    cout << "Nhap n = ";    cin >> n;
    a = new T[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
}

template<class T> void Mang<T>::xuat(){
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
}

int main(){
    Mang<float> a;
    a.nhap();
    a.xuat();
    
    return 0;
}