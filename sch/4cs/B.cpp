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
// #define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

int main() {
    fastio;
    ll n;
    cin >> n;
    for(ll _ = 0; _ < n; _++) {
        string s;
        cin >> s;
        cout << "URL #" << _ + 1 << "\nProtocol = ";
        string t = "";
        ll ind;
        for(ll i = 0; s[i] != ':'; i++) {
            t += s[i];
            ind = i;
        }
        cout << t << '\n';
        t = "";
        ind += 4;
        bool f = 0;
        while(ind != s.size()) {
            if(s[ind] == ':') {
                f = 1;
                break;
            }
            if(s[ind] == '/') {
                break;
            }
            t += s[ind];
            ind++;
        }
        cout << "Host =     " << t << '\n';
        t = "";
        if(f) {
            ind++;
            while(ind != s.size()) {
                if(s[ind] == '/') {
                    break;
                }
                t += s[ind];
                ind++;
            }
        }
        cout << "Port =     " << (t.empty() ? "<default>" : t) << '\n';
        t = "";
        if(ind != s.size()) {
            ind++;
        }
        while(ind != s.size()) {
            t += s[ind];
            ind++;
        }
        cout << "Path =     " << (t.empty() ? "<default>" : t) << "\n\n";
    }
}
