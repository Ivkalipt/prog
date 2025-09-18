#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using u64 = unsigned long long;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

int main() {
    string s;
    vector<pair<string, ll>> lines;
    vll level = {0};
    bool flag = false;
    bool used[101];

    do {
        getline(cin, s);
        ll cnt_ws = 0;
        for (; cnt_ws < sz(s); cnt_ws++)
            if (s[cnt_ws] != ' ')
                break;
        lines.emplace_back(s, cnt_ws);
    } while (s != "exit()");

    for (ll i = 0; i < sz(lines); i++) {
        s = lines[i].F;
        ll cnt_ws = lines[i].S;

        if (flag) {
            if (level.empty() || cnt_ws <= level.back()) {
                cout << i+1 << '\n';
                return 0;
            }
            level.push_back(cnt_ws);
            flag = false;
        }

        string rest = s.substr(cnt_ws);
        while (!rest.empty() && rest.back() == ' ') {
            rest.pop_back();
        }
        if (rest == "else:") {
            bool found_if = false;
            for (ll j = i - 1; j >= 0; j--) {
                string prev_s = lines[j].F;
                ll prev_ws = lines[j].S;
                
                string prev_rest = prev_s.substr(prev_ws);
                while (!prev_rest.empty() && prev_rest.back() == ' ') {
                    prev_rest.pop_back();
                }
                if (prev_rest.size() >= 3 && prev_rest.substr(0, 3) == "if " && prev_rest.back() == ':') {
                    if (prev_ws == cnt_ws && !used[j]) {
                        found_if = true;
                        used[j] = true;
                        break;
                    }
                }
            }
            if (!found_if) {
                cout << i+1 << '\n';
                return 0;
            }
            flag = true;
        }

        string if_rest = s.substr(cnt_ws);
        while (!if_rest.empty() && if_rest.back() == ' ') {
            if_rest.pop_back();
        }
        if (if_rest.size() >= 3 && if_rest.substr(0, 3) == "if " && if_rest.back() == ':') {
            flag = true;
        }

        while (!level.empty() && cnt_ws != level.back()) {
            level.pop_back();
        }
        if (level.empty()) {
            cout << i+1 << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
}
