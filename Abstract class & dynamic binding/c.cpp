#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin >> a;
    int money = 0;
    if(a < 50) {
        money = a * 1500;
    }else if(a < 100){
        money = 49*1500 + (a-49) * 25000;
    }else if(a < 150){
        money = 49*1500 + 50 * 25000 + (a-99) * 35000;
    }else if(a < 200) {
        money = 49*1500 + 50 * 25000 + 40 * 35000 + (a-149) * 40000;
    }else {
        money = 49*1500 + 50 * 25000 + 40 * 35000 + 50 * 40000 + (a - 199) * money = 49*1500 + 50 * 25000 + 40 * 35000 + (a-149) * 40000;;
    }

    cout << money;
}