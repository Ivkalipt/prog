#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    ll n;
    vector<ll> a;
    cin >> n;
    if(n < 4) {
        if(n==1) cout << 1;
        else cout << "NO SOLUTION";
        return 0;
    }
    for(ll i = 2; i <= n; i+=2) {
        a.push_back(i);
    }
    for(ll i = 1; i <= n; i+=2) {
        a.push_back(i);
    }
    for(auto &c:a) {
        cout << c << " ";
    }
    return 0;
}