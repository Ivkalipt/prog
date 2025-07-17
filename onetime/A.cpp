#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

void crocodilobombardiro() {
    string s, p;
    cin >> s >> p;
    if(s[0] != p[0]) {
        cout << "NO\n";
        return;
    }
    ll n = s.size(), m = p.size();
    s += 'K', p += 'K';
    ll l = 0, r = 0, cntl = 1, cntr = 1;
    while(l < n && r < m) {
        if(s[l + 1] == p[r + 1]) l++, r++, cntl++, cntr++;
        else {
            if(p[r] != s[l + 1]) {
                while(p[r + 1] != s[l + 1]) r++, cntr++;
                if(cntr > cntl * 2) {
                    cout << "NO\n";
                    return;
                }
                cntr = 0, cntl = 0;
            }
            else {
                cout << "NO\n";
                return;
            }
        }
    }
    if(r < m - 1) {
        cout << "NO\n";
        return;

    }
    cout << "YES\n";
}

int main() {
    fastio;
    ll t;
    cin >> t;
    while (t--) crocodilobombardiro();
    return 0;
}
