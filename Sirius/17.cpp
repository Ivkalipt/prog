// Наибольшее число
// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options


#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define F first
#define S second

using namespace std;

template <typename T>
std::string toString(T val)
{
    std::ostringstream oss;
    oss<< val;
    return oss.str();
}

int main() {
    string s, ans = "";
    // ll n = s.size();
    getline(cin, s);
    vll cnt(10, 0);
    for(auto c:s) {
        if('0' <= c && c <= '9') {
            ++cnt[c-'0'];
        }
    }
    
    for(ll i = 9; i > -1; i--) {
        for(ll j = 0; j < cnt[i]; j++) {
            ans += toString(i);
        }
    }
    if(ans.size() == 0) {
        cout << -1;
    }
    else {
        cout << ans;
    }
    cout << "\n";
    return 0;
}