// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

bool compare(string a, string b) {
    v(string) g = {a, b};
    sort(a.begin(), a.end());
    if(g[0] == a) return false;
    return true;

}

bool comp(string a, string b) {
    if(a.size() < b.size()) return true;
    if(a.size() == b.size() && !compare(a, b)) return true;
    return false;
    
}



int main() {
    fastio;
    ll n;
    cin >> n;
    vector<string> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    sort(arr.begin(), arr.end(), comp);
    for(auto c:arr) cout << c << "\n";
    return 0;
}



