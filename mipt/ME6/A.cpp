#pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

const ll inf = 1e9 + 7;

int main() {
    char A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << (9 - (D - '0') + (9 - (C - '0')) * 11 + (9 - (B - '0')) * 111 + (9 - (A - '0')) * 1111) << '\n';
}
