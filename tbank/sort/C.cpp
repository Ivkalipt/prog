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

void selection_sort(vll &a)
{
   for (ll i = 0; i < (ll)a.size() - 1; i++) {
        ll mini = i;
        for(ll j = i + 1; j < a.size(); j++){
            if (a[j] < a[mini])
                mini = j;
        }
        swap(a[i], a[mini]);
   }
}

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    selection_sort(a);
    for(ll c : a) cout << c << ' ';
    cout << '\n';
}
