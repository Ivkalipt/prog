#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll maxn = 2e5 + 1;
vector<ll> mem(maxn + 1, -1);

ll a[] = {0, 1, 3, 4, 10, 9, 7, 5, 2};

ll interact(ll pos) {
    if(mem[pos] != -1) return mem[pos];
    cout << "? " << pos << endl;
    cout.flush();
    ll num;
    cin >> num;
    // cout << a[pos] << '\n';
    mem[pos] = num;
    return num;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll res1, res2;
    ll l = 1, r = n;
    while(l != r) {
        ll m = (l + r) >> 1;
        res1 = interact(m);
        if(m + 1 <= n) {
            res2 = interact(m + 1);
            if(res1 < res2) l = m + 1;
            else r = m;
        }
        else {
            res2 = interact(m - 1);
            if(res1 > res2) l = m;
            else r = m - 1;
        }
    }
    // cout << "Вершина " << l << '\n';
    ll lx = 1, rx = l;
    while(lx <= rx) {
        ll m = (lx + rx) >> 1;
        ll res = interact(m);
        if(res == k) {
            cout << "! " << m << endl;
            return;
        }
        if(res > k) rx = m - 1;
        else lx = m + 1;
    }
    /*if(mem[lx] == k) {
        cout << "! " << lx << endl;
        return;
    }*/
    // cout << mem[lx] << ' ' << lx << '\n';
    lx = l, rx = n;
    while(lx <= rx) {
        ll m = (lx + rx) >> 1;
        ll res = interact(m);
        if(res == k) {
            cout << "! " << m << endl;
            return;
        }
        if(res > k) lx = m + 1;
        else rx = m - 1;
    }
}

int main() {
    solve();
    return 0;
}
