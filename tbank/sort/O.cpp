#pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define f first
#define s second
#define all(a) a.begin(), a.end() 
#define rall(a) a.rbegin(), a.rend()

using namespace std;

const ll inf = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    vll a(n);
    ll mini = inf;
    for(ll & c : a) {
        cin >> c;
        c = abs(c);
        if(c < mini) mini = c;
    }
    ll l = 0;
    vvll p(3);
    while(a[l] != mini) {
        p[0].push_back(a[l]);
        if(l != 0 && a[l] > a[l - 1]) {
            cout << 0 << '\n';
            exit(0);
        }
        l++;
    }
    while(a[l] == mini && l != a.size()) {
        p[1].push_back(a[l]);
        l++;
    }
    while(l != a.size()) {
        p[2].push_back(a[l]);
        if(a[l] < a[l - 1]) {
            cout << 0 << '\n';
            exit(0);
        }
        l++;
    }
    cout << (!mini ? 1LL << p[1].size() : p[1].size() + 1) % 998244353;
    /*for(ll i = 0; i < 3; i++) {
        for(ll c : p[i]) {
            cout << c << ' ';
        }
        cout << '\n';
    }*/
    
}
