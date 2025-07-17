#include <bits/stdc++.h>
 
#define ll      long long
#define vll     vector<ll>
#define vvll    vector<vll>
#define pll     pair<ll, ll>
#define F       first
#define S       second
#define all(a)  a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vll a(1 << n);
    for (auto & x : a) cin >> x;
    sort(all(a));
    queue<ll> q;
    q.push(a.back());
    a.pop_back();
    while(!a.empty()) {
        ll v = a.back();
        a.pop_back();
    }
}
