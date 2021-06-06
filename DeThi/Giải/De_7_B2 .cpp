#include <bits/stdc++.h>
using namespace std;

class Array
{
    private:
        double *a;
        int n;

    public:
        Array();
        void XUAT();
        Array operator-- ();
        friend istream &operator>>(istream &input, Array &obj1);
};

Array::Array()
{
    this->a = NULL;
    this->n = 0;
}

void Array::XUAT()
{
    for(int i = 0 ; i < n ; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

Array Array::operator--()
{
    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(a[j] < a[j + 1])
            {
                double temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    return *this;
}

istream &operator>>(istream &input, Array &obj1)
{
    cout << "Nhap N: ";
    input >> obj1.n;

    obj1.a = new double[obj1.n];

    cout << "Nhap Day So: ";
    for(int i = 0 ; i < obj1.n ; i++)
    {
        input >> obj1.a[i];
    }
    return input;
}

int main()
{
    Array array1;
    cout << "Nhap Mang 1: " << endl;
    cin >> array1;

    cout << "Mang Truoc Khi Sap Xep: "; array1.XUAT();
    
    --array1;

    cout << "Mang Sau Khi Sap Xep: "; array1.XUAT();
    return 0;
}