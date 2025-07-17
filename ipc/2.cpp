#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    ll p, s, t1, t2, t3, t4, t5, cnt=0;
    vector<ll> m, n;
    
    cin >> p >> s;
    vector<ll> a(p);
    for(ll i = 0; i < p; i++) {
        cin >> t1;
        m.push_back(t1);
    }
    for(ll i = 0; i < s; i++) {
        cin >> t1 >> t2 >> t3 >> t4 >> t5;
        a[t1-1] += 1;
        a[t2-1] += 1;
        a[t3-1] += 1;
        a[t4-1] += 1;
        a[t5-1] += 1;
    }
    for(ll i = 0; i < p; i++) {
        if(m[i] <= a[i]) {
            cnt += m[i];
        }
        else
        {
            cnt += a[i];
        }
    }
    cout << cnt;

}