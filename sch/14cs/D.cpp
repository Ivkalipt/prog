#pragma gcc optimize ("o3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll inf = 1e18;

vll may = {2, 3, 5, 7};
bool f = 1;

bool isPrime(ll n) {
    if(n == 1) return false;
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void rec(ll pos, ll n, ll & cur) {
    if(pos == n) cout << cur << '\n', f = 0;
    for(ll i = 1; i <= 10; i++) {
        
        cur = 10 * cur + i;
        if(isPrime(cur)) rec(pos + 1, n, cur);
        cur /= 10;
    }
}

int main() {
    ll n;
    cin >> n;
    ll cur = 0;
    rec(0, n, cur);
    if(f) cout << "NO SOLUTION";
}
