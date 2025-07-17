#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    vector<vector<ll>> a;
    ll n, t;
    bool flag = 0;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> t;
        for(ll j = 0; j < a.size(); j++) {
            if (a[j].back() > t) {
                a[j].push_back(t);
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            a.push_back({t});
        }
        flag = 0;
    }
    cout << a.size();
}