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
    ll sum = 1, cnt = 2;
    bool f = 0;
    
    string s;
    cin >> s;
    for(ll i = 0; i < s.size(); i++) {
        /*if(s[i] != '(' && s[i] != ')') {
            if(s[i] == '*' || s[i] == '+' || s[i] == '-') {
                sym = s[i];
                string t = "";
                i++;
                while(i != s.size() && s[i] != ')') {
                    t += s[i];
                }
                if(sym == '*') sum *= stoll(t); 
                if(sym == '+') sum += stoll(t);
                if(sym == '-') sum -= stoll(t);
            }
        }
        else {
            if(f == 0 && s[i + 1] != '(') {
                sum = s[i + 1];
                f = 1;
            }
        }
        if(f == 0 && s[i] != '(') {
            string t = "";
            while(i != s.size() - 1 && s[i] != '+' && s[i] != '*' && s[i] != '-') {
                t += s[i];
            }
            sum = stoll(t);
            f = 1;
        }*/
        if(s[i] == '+') {
            sum += cnt++;
        }
        else if(s[i] == '-') {
            sum -= cnt++;
        }
        else if(s[i] == '*') {
            sum *= cnt++;
        }
    }
    cout << sum << '\n';
    
}
