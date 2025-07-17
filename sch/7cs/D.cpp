#include <unordered_set>
#pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

const ll inf = 1e9 + 7;

vector<bool> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    for(ll i = 2; i <= n; i++) {
        if(is_prime[i]) {
            for(ll j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

string s;
vector<bool> used;
vll ans;
unordered_set<ll> used2; 

void rec(ll pos, ll n, string & cur, ll & cnt, vector<bool> & is_prime) {
    if(pos == n) return;
    for(ll i = 0; i < n; i++) {
        if(!used[i]) {
            used[i] = 1;
            cur.push_back(s[i]);
            used2.insert(stoi(cur));
            rec(pos + 1, n, cur, cnt, is_prime);
            cur.pop_back();
            used[i] = 0;
        }
    }
}

int main() {
    cin >> s;
    ll n = s.size();
    used.resize(n);
    vector<bool> used(n, 0), is_prime = sieve(1e7);
    string cur = "";
    ll cnt = 0;
    rec(0, n, cur, cnt, is_prime);
    for(ll c : used2) {
        if(c > 1) {
            cnt += is_prime[c];
        }
    }
    cout << cnt << '\n';
}
