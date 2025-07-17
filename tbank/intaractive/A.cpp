#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll interact(ll pos) {
    cout << "? " << pos << endl;
    cout.flush();
    ll num;
    cin >> num;
    return num;
}

void solve() {
    ll n;
    cin >> n;

    ll l = 1, r = n;
    ll ans = -1;

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (mid % 2 == 0) {
            if (mid - 1 >= 1) {
                ll a = interact(mid - 1);
                ll b = interact(mid);
                if (a == b) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                ans = interact(mid);
                break;
            }
        } else {
            if (mid + 1 <= n) {
                ll a = interact(mid + 1);
                ll b = interact(mid);
                if (a == b) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                ans = interact(mid);
                break;
            }
        }
    }

    if (ans == -1) {
        ans = interact(l);
    }

    cout << "! " << ans << endl;
    cout.flush();
}

int main() {
    solve();
    return 0;
}
