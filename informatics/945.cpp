// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options


#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define vstr vector<string>
#define vvll vector<vector<ll>>
#define vvstr vector<vector<string>>
#define F first
#define S second
#define bpStart for(ll i = 1; i < 8; i++) { for(ll j = 0; j < 8; j++) {
#define bpEnd } }

using namespace std;

int main() {
    ll x, y, s = 0;
    cin >> y >> x;
    vvll b(8, vll(8, 0));
    x--; y--;
    b[x][y] = 1;
    bpStart
    if(j == 0) {
        b[i][j] = b[i-1][1];
    }
    else if(j == 7) {
        b[i][j] = b[i-1][6];
    }
    else {
        b[i][j] = b[i-1][j-1] + b[i-1][j+1];
    }
    if(i == x && j == y) {
        b[x][y] = 1;
    }
    bpEnd
    for(ll i = 0; i < 8; i++) {
        s += b[7][i];
    }
    cout << s;

}