#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;
using vvll = vector<vll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 4e18;
constexpr ll N = 2e5;

string substr(const string & s, ll l, ll r) {
    ll ind = l;
    ll rx = r;
    string res = "";
    while (ind <= rx && rx < s.length()) {
        if (s[ind] == ' ') rx++;
        else res += s[ind];
        ind++;
    }
    return res;
}

int main() {
    string pat;
    getline(cin, pat);
    ll npat = sz(pat);

    string input;
    getline(cin, input);
    ll ns = sz(input);

    vector<char> res(all(input));

    for (ll i = 0; i < ns; i++) {
        if (substr(input, i, i + npat - 1) == pat) {
            ll ind = i;
            ll unprob = i + npat;
            while (ind < unprob && ind < ns) {
                if (res[ind] == ' ') unprob++;
                else res[ind] = 'X';
                ind++;
            }
        }
    }

    for (ll i = 0; i < ns; i++) {
        if (res[i] == 'X') {
            if (i == 0 || res[i - 1] == ' ') {
                res[i] = '1';
            } else {
                res[i] = '0';
            }
        }
    }

    cout << string(all(res)) << '\n';
    return 0;
}