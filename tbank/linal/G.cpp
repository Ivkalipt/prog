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

ll inf = 1e16;

int main() {
    fastio;
    ll n;
    cin >> n;
    vll a(n), b(n), m(n), prefMin(n);
    for(ll & c : m) cin >> c;
    stack<pll> st;
    for(ll i = 0; i < n; i++) {
        pll sti = {m[i], i};
        while(!(st.empty() || st.top() < sti)) 
            st.pop();
        if(st.empty()) 
            a[i] = (i + 1) * m[i];
        else 
            a[i] = a[st.top().S] + (i - st.top().S) * m[i];
        st.push(sti);
    }
    st = stack<pll>();
    for(ll i = n - 1; i > -1; i--) {
        pll sti = {m[i], i};
        while(!(st.empty() || st.top() < sti)) 
            st.pop();
        if(st.empty()) 
            b[i] = (n - i) * m[i];
        else 
            b[i] = b[st.top().S] + (st.top().S - i) * m[i];
        st.push(sti);
    }
    vll ans(n);
    ll ind = 0, sum = 0;
    for(ll i = 0; i < n; i++) {
        ll s = a[i] + b[i] - m[i];
        if(s > sum) 
            sum = s, ind = i;
    }
    ans[ind] = m[ind];
    for(ll i = ind + 1; i < n; i++) 
        ans[i] = min(ans[i - 1], m[i]);
    for(ll i = ind - 1; i > -1; i--) 
        ans[i] = min(ans[i + 1], m[i]);
    for(ll & c : ans) cout << c << ' ';
    cout << '\n';


}
