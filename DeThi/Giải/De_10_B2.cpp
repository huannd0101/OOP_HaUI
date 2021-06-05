#include <iostream>

using namespace std;

class Array
{
private:
    int *val;
    int n;

public:
    Array();
    Array(int n);
    void Nhap();
    friend ostream &operator<<(ostream &os, Array arr);
    Array operator++();
};

Array::Array()
{
    val = NULL;
    n = 0;
}
Array::Array(int n)
{
    this->n = n;
    val = new int[n];
    for (int i = 0; i < n; i++)
        val[i] = 0;
}

Array Array::operator++()
{
    Array newArr(n);

    int minVal = val[0];
    bool hasEven = false;
    for (int i = 0; i < n; i++)
    {
        if (val[i] < minVal)
            minVal = val[i];
        if (val[i] % 2 == 0)
            hasEven = true;
    }

    for (int i = 0; i < n; i++)
        if (!hasEven)
            newArr.val[i] = val[i] + 2;
        else
            newArr.val[i] = val[i] + minVal;

    return newArr;
}

ostream &operator<<(ostream &os, Array arr)
{
    for (int i = 0; i < arr.n; i++)
        os << arr.val[i] << " ";
    return os;
}

void Array::Nhap()
{
    cout << "Nhap n: ";
    cin >> n;
    val = new int[n];
    for (int i = 0; i < n; i++)
        cin >> val[i];
}

int main()
{
    Array arrA, arrB(5);
    arrA.Nhap();
    cout << arrB << endl;
    cout << arrA << endl;
    cout << ++arrA;
    return 0;
}