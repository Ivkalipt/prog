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

ll inf = 1e9 + 7;

bool ifsogl(char c) {
    if(c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u') return true;
    return false;

}

int main() {
    fastio;
    string s;
    cin >> s;
    while(s != "end") {
        bool f1 = 0, f2 = 1, f3 = 1;
        for(ll i = 0; i < s.size(); i++) {
            if(ifsogl(s[i])) f1 = 1;
            if(i > 1) {
                if(ifsogl(s[i]) == ifsogl(s[i - 1]) && ifsogl(s[i - 1]) == ifsogl(s[i - 2])) f2 = 0;
            }
            if(i > 0) {
                if(s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o') f3 = 0;
            }
        }
        if(f1 && f2 && f3) cout << "'" << s << "' is acceptable.\n";
        else cout << "'" << s << "' is not acceptable.\n";
        cin >> s;

    }
}
