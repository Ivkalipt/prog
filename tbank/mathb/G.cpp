// #pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e16;

ll phi(ll n) {
    ll res = n;
    for(ll i = 2; i * i <= n; i++)
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            res -= res / i;
        }
    if(n > 1)
        res -= res / n;
    return res;
}

int main() {
    ll n;
    cin >> n;
    ll res = 0;
    for(ll i = 1; i <= n; i++) {
        res += phi(1) * i + (i != 1 ? phi(i) * 1 : 0);
        cout << res << '\n';
        for(ll j = 2; j * j <= i; j++) {
            if(j * j == i) {
                res += phi(j) * j;
            }
            else {
                res += phi(j) * i / j + phi(i / j) * j;
            }
        }
    }
    cout << res << '\n';

}
