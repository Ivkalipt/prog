// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

class Q_min
{
private:
    stack<pll> s1, s2;
    ll el;
    ll temp2;

public:
    void push(ll n)
    {
        if(s1.empty()) s1.push({n, n});
        else s1.push({n, std::min(n, s1.top().S)});
    }
    void pop()
    {
        if(s2.empty()) {
            while(!s1.empty()) {
                el = s1.top().F;
                s1.pop();
                if(s2.empty()) s2.push({el, el});
                else s2.push({el, std::min(el, s2.top().S)});
            }
        }
        s2.pop();
    }

    ll front()
    {
        if(s2.empty()) {
            while(!s1.empty()) {
                el = s1.top().F;
                s1.pop();
                if(s2.empty()) s2.push({el, el});
                else s2.push({el, std::min(el, s2.top().S)});
            }
        }
        return s2.top().F;
    }

    ll size()
    {
        return s1.size() + s2.size();
    }

    bool empty()
    {
        return s1.size() + s2.size() == 0 ? true : false;
    }

    ll min() {
        if (s1.empty()) return s2.top().S;
        else if (s2.empty()) return s1.top().S;
        else return std::min(s1.top().S, s2.top().S);
    }
};

int main()
{
    fastio;
    Q_min q;
    ll n, t, k;
    cin >> n >> k;
    vll b(n);
    for(ll &c : b) cin >> c;
    for(ll i = 0; i < k; i++) {
        q.push(b[i]);
    }
    cout << q.min() << ' ';
    for(ll i = k; i < n; i++) {
        q.pop();
        q.push(b[i]);
        cout << q.min() << ' ';
    }
    
    return 0;
}
