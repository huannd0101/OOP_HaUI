#include <iostream>
#include <iomanip>

using namespace std;

class DieuHoa;
class SanPham
{
protected:
    int MaSP;
    char TenSP[20];
    char NgayNhap[20];

public:
    void Nhap();
    void Xuat();
    friend void TimKiem(DieuHoa *arr, int n);
};

void SanPham::Nhap()
{
    cout << "Nhap Ma SP: ";
    cin >> MaSP;
    cout << "Nhap Ten SP: ";
    fflush(stdin);
    gets(TenSP);
    cout << "Nhap Ngay Nhap: ";
    fflush(stdin);
    gets(NgayNhap);
}

void SanPham::Xuat()
{
    cout << setw(20) << MaSP;
    cout << setw(20) << TenSP;
    cout << setw(20) << NgayNhap;
}

class DieuHoa : public SanPham
{
    float CongSuat;
    char TenHSX[20];
    float GiaBan;

public:
    void Nhap();
    void Xuat();
    friend void TimKiem(DieuHoa *arr, int n);
};

void DieuHoa::Nhap()
{
    SanPham::Nhap();
    cout << "Nhap Cong Suat: ";
    cin >> CongSuat;
    cout << "Nhap Ten HSX: ";
    fflush(stdin);
    gets(TenHSX);
    cout << "Nhap Gia Ban: ";
    cin >> GiaBan;
}
void DieuHoa::Xuat()
{
    SanPham::Xuat();
    cout << setw(20) << CongSuat;
    cout << setw(20) << TenHSX;
    cout << setw(20) << GiaBan << endl;
}

void Nhap(DieuHoa *&arr, int &n)
{
    cout << "Nhap so luong dieu hoa: ";
    cin >> n;
    arr = new DieuHoa[n];
    for (int i = 0; i < n; i++)
        arr[i].Nhap();
}

void Xuat(DieuHoa *arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i].Xuat();
}

void TimKiem(DieuHoa *arr, int n)
{
    int minPrice = arr[0].GiaBan;
    for (int i = 0; i < n; i++)
        if (arr[i].GiaBan < minPrice)
            minPrice = arr[i].GiaBan;

    int amount = 0;
    for (int i = 0; i < n; i++)
        if (arr[i].GiaBan == minPrice && strcmp(arr[i].TenHSX, "ELECTROLUX") == 0)
        {
            amount++;
            arr[i].Xuat();
        }

    if (!amount)
        cout << "Khong co dieu hoa thoa man y/c";
}

int main()
{
    DieuHoa *arr;
    int n;
    Nhap(arr, n);
    Xuat(arr, n);
    cout << "\n---------------------------\n";
    TimKiem(arr, n);
    return 0;
}