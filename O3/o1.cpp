#include<iostream>
#include<fstream>
using namespace std;

class ARRAY {
private:
    float *value;
    int n;
public:
    friend istream &operator >>(istream &is, ARRAY &a);
    friend ostream &operator <<(ostream &os, ARRAY a);
    void operator++();
    void operator--();
    friend void writeToFile(char *fileName, ARRAY a);
};

istream &operator >> (istream &is, ARRAY &a){
    cout << "Nhap n = ";    cin >> a.n;
    a.value = new float[a.n];
    for(int i=0; i<a.n; i++){
        cout << "Nhap a[" << i << "] = ";   cin >> a.value[i];
    }
    return is;
}

ostream &operator << (ostream &os, ARRAY a){
    for(int i=0; i<a.n; i++)
        os << a.value[i] << " ";
    return os;
}

void ARRAY::operator++(){
    for(int i=0; i<this->n - 1; i++)
        for(int j=this->n-1; j>i; j--)
            if(this->value[j-1] > this->value[j]){
                float temp = this->value[j-1];
                this->value[j-1] = this->value[j];
                this->value[j] = temp;
            }
}

void ARRAY::operator--(){
    for(int i=0; i<this->n - 1; i++)
        for(int j=this->n-1; j>i; j--)
            if(this->value[j-1] < this->value[j]){
                float temp = this->value[j-1];
                this->value[j-1] = this->value[j];
                this->value[j] = temp;
            }
}

void writeToFile(char *fileName, ARRAY a){
    ofstream f(fileName, ios::app);
    f << a << endl;
    f.close();
}

int main(){
    ARRAY a;
    
    cin >> a;
    
    ++a;
    writeToFile("D:/MANG.txt", a);
    cout << a << endl;
    
    --a;
    writeToFile("D:/MANG.txt", a);
    cout << a << endl;

    return 0;
}