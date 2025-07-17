// #pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc push_options
// #pragma gcc pop_options
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define f first
#define s second
#define all(a) a.begin(), a.end() 

using namespace std;

void rec(vector<char> & a, ll pos, ll n, string & cur, string & brakets) {
    if(pos == n) {
        if(a.empty()) cout << cur << '\n';
        /*for(char c : a) {
            cout << c;
        }*/
        //cout << '\n';
        return;
    }
    for(char c : brakets) {
        /*if((c == '(' || c == '[') && ((cur.size() + 1) * 2) > n) {
            cout << cur.size() << '\n';
            continue;
        }*/
        if(c == '(' || c == '[') { 
            a.push_back(c);
            cur.push_back(c);
            rec(a, pos + 1, n, cur, brakets);
            a.pop_back();
            cur.pop_back();
        }
        else if(c == ')' && !a.empty() && a.back() == '(') {
            a.pop_back();
            cur.push_back(c);
            rec(a, pos + 1, n, cur, brakets);
            a.push_back('(');
            cur.pop_back();
        }
        else if(c == ']' && !a.empty() && a.back() == '[') {
            a.pop_back();
            cur.push_back(c);
            rec(a, pos + 1, n, cur, brakets);
            a.push_back('[');
            cur.pop_back();
        }
    }
}

int main() {
    fastio;
    ll n;
    cin >> n;
    string cur;
    string brakets = "([)]";
    vector<char> a;
    rec(a, 0, n, cur, brakets);
}
