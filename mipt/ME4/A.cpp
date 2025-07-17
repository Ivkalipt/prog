#include <iomanip>
#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

const ll inf = 1e9 + 7;

int main() {
    ld a, b, c, v0, v1, v2;
    cin >> a >> b >> c >> v0 >> v1 >> v2;
    ld ans = min({
        a / v0 + c / v1 + b / v2,
        b / v0 + c / v1 + a / v2,
        a / v0 + a / v1 + b / v0 + b / v1,
        a / v0 + c / v1 + c / v2 + a / v2,
        b / v0 + c / v1 + c / v2 + b / v2,
        a / v0 + c / v1 + b / v1 + b / v0 + b / v1,
        b / v0 + c / v1 + a / v1 + a / v0 + a / v1
            });
    cout << setprecision(30) << ans << '\n';
    /*vector<ld> ans = {
        a / v0 + c / v1 + b / v2,
        b / v0 + c / v1 + a / v2,
        a / v0 + a / v1 + b / v0 + b / v1,
        a / v0 + c / v1 + c / v2 + a / v2,
        b / v0 + c / v1 + c / v2 + b / v2,
        a / v0 + c / v0 + c / v1 + a / v2,
        b / v0 + c / v0 + c / v1 + b / v2
            };
    for(ld c : ans) cout << c << '\n';*/
}
