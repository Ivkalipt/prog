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

void rec(ll k, vll & cur) {
    if(cur.size() == 4 && k != 0) return;
    else if(cur.size() == 4 && k == 0) {
        for(ll c : cur) cout << c << ' ';
        cout << '\n';
        exit(0);
    }
    /*for(ll c : cur) cout << c << ' ';
    cout << '\n' << cur.size() << ' ' << k << '\n';*/

    for(ll i = 0; i * i <= k; i++) {
        cur.push_back(i);
        rec(k - i * i, cur);
        cur.pop_back();
    }
}

int main() {
    ll n;
    cin >> n;
    vll cur;
    rec(n, cur);
    for(ll c : cur) cout << c << ' ';
    cout << '\n';

}

