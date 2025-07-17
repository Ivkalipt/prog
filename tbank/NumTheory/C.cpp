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

ll inf = 1e9 + 7;
int main()
{
    ll n;
    vll s1;
    cin >> n;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i != n)
                s1.push_back(i), s1.push_back(n / i);
            else
                s1.push_back(i);
        }
    }
    cout << s1.size() << '\n';
    sort(all(s1));
    for(ll c : s1) cout << c << ' ';
}
