// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

template <typename T>
string toString(T val)
{
    ostringstream oss;
    oss << val;
    return oss.str();
}

template<typename T> 
T fromString(const std::string& s) 
{
  std::istringstream iss(s);
  T res;
  iss >> res;
  return res;
}

int main() {
    fastio;
    //          0  1  2  3  4  5  6  7  8  9
    vll adds = {8, 7, 6, 9,-1, 9, 8,-1,-1, 8};
    vll del = {-1,-1,-1,-1,-1,-1, 5,-1, 9, 5};
    vll move = {9,-1, 3, 5,-1,-1, 9,-1,-1,-1};
    string s;
    ll maxi, k;
    cin >> s;
    for(ll i = 0; i < s.size(); i++) {
        if(toString(move[fromString(s[i])]) + )
    }
    cout << "\n";
    return 0;
}