#pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define v(a) vector<a>
#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

v(string) 

void rec(string s, ll n) {
    if(n == s.size()) {
        
    }
}

bool NextPermutation(ll n, string ){
    for (int i = n - 2; i >= 0; i--){
        if (a[i] < a[i + 1]){
        int min_val = a[i + 1];
        int min_id = i + 1;
        for (int j = i + 2; j < n; j++)
            if (a[j] > a[i] && a[j] < min_val){
                min_val = a[j];
                min_id = j;
            }
        swap(a[i], a[min_id]);
        sort(a.begin() + i+1, a.end());
        return 1;
        }
    }
    return 0;
}

int main()
{
    string s, t;
    cin >> s;
    t = s;
    sort(s.begin(), s.end());
    ll k = 0;
    while (NextPermutation()) {
        
        
    }
}