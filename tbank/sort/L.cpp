#pragma gcc optimize ("o3,unroll-loops")
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

const ll inf = 1e9 + 7;


int main() {
    vector<string> a;
    string s;
    while(cin >> s) a.push_back(s);
    // a = {"2", "20", "004", "66"};
    for(ll i = a.size() - 1; i >= 0; i--)
        for(ll j = 0; j < i; j++)
            if (a[j + 1] + a[j] > a[j] + a[j + 1])
                swap(a[j], a[j + 1]);
    for(int i = 0; i < a.size(); i++)
        cout << a[i];
}

/*int main() {
    string s;
    vector<string> a;
    freopen("input.txt", "r", stdin);
    while(cin >> s) a.push_back(s), cout << '!';
    sort(all(a));
    for(string & c : a) {
        cout << c;
    }
    cout << '\n';
}*/
