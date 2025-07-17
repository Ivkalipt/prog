#include <iostream>
#define ll long long

using namespace std;

int main() {
    ll s=0, k=0;
    string str;
    cin >> str;
    str = "0" + str + "0";
    for(ll i = 0; i < str.length()-1; i++) {
        s++;
        if(s>k) k=s;
        if(str[i] != str[i+1]) {
            s = 0;
        }
    }
    if(s>k) k=s;
    cout << k;
}