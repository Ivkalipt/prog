#pragma gcc optimize ("o3,unroll-loops")
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

const ll inf = 1e9 + 7;


void rec(ll pos, ll n, vector<string> & cur, vector<string> & a, vector<bool> & used, set<string> & nums) {
    if(pos == n) {
        string s;
        for(string & c : cur) s += c;
        nums.insert(s);
        return;
    }
    for(ll i = 0; i < n; i++) {
        if(!used[i]) {
            used[i] = 1;
            cur.push_back(a[i]);
            rec(pos + 1, n, cur, a, used, nums);
            cur.pop_back();
            used[i] = 0;
        }
    }
}

int main() {
    ll n;
    cin >> n;
    vector<bool> used(n);
    set<string> nums;
    vector<string> a(n);
    for(string & c : a) cin >> c;
    vector<string> cur; 
    rec(0, n, cur, a, used, nums);
    cout << nums.size() << '\n';
}
