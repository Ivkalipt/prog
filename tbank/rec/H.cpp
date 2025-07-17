// #pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc push_options
// #pragma gcc pop_options
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define f first
#define s second
#define all(a) a.begin(), a.end() 

using namespace std;

void rec(ll n, ll k, ll m, vll & cur) {
    if(k == 1) {
        for(ll i = 0; i < cur.size(); i++) { 
            cout << cur[i];
            if(i != cur.size() - 1)
                cout << '*';
        }
        cout << '\n';
        return;
    }
    for(ll i = max(m, cur.empty() ? 0 : cur.back()); i <= k; i++) {
        if(k % i == 0) {
            cur.push_back(i);
            rec(n, k / i, m, cur);
            cur.pop_back();
        }
    }
}

int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    vll cur;
    rec(n, n, m, cur);
}
