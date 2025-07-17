// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>
#include <cctype>

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

struct person {
    string sch, lname, fname, birth;
    ll num;

};
bool cmp(person a, person b) {
    if(a.num != b.num) return a.num < b.num;
    if(a.sch != b.sch) return a.sch < b.sch;
    if(a.lname != b.lname) return a.lname < b.lname;
    return a.fname < b.fname;
}

/*bool cmp(string a, string b) {
    ll x, y;
    stringstream s1(a), s2(b);
    s1 >> x;
    s2 >> y;
    if(x < y) return true;
    else if(x > y) return false;
    else retu*/

int main() {
    ll n;
    cin >> n;
    string t;
    ll t2;
    vector<person> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i].lname >> a[i].fname >> a[i].num >> a[i].sch >> a[i].birth;
        //cout << t[1] << ' ' << t[2] << '\n';
    }
    sort(all(a), cmp);
    for(ll i = 0; i < n; i++) {
        cout << a[i].num << a[i].sch << ' ' << a[i].lname << ' ' << a[i].fname << ' ' << a[i].birth << '\n';
    }
}
