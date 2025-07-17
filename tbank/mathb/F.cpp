#pragma gcc optimize ("O3,unroll-loops")
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

using namespace std;

ll fact(ll n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main() {
    string s;
    cin >> s;
    map<char, ll> cnt;
    for(char c : s) {
        if(cnt.count(c)) cnt[c]++;
        else cnt[c] = 1;
    }
    ll m = fact(s.size()), n = 1;
    for(auto c : cnt) {
        n *= fact(c.S);
    }

    cout << m / n << '\n';



}
