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
std::string toString(T val)
{
    std::ostringstream oss;
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

/*int main() {
    fastio;
    ll n;
    string s;
    cin >> s;
    n = s.size();
    vll dp(n);
    dp[0] = 1;
    dp[1] = 1;*/

    /*if(fromString(s[0] + s[1]) > 0 && fromString(s[0] + s[1]) <= 33) {
        dp[1] += 1;
    }
    for(ll i = 2; i < n, i++) {
        dp[i] = dp[i-1];
        if((std::stoi(s.substr(i - 2, 2)) > 0 && fromString(s[i] + s[i-1]) <= 33) {
            dp[i] += dp[i-2];
        }
    }*/
int main() {
    string s;
    cin >> s;
    int n = s.length();
    vll F(n + 1, 0);
    F[0] = 1;
    F[1] = 1;
    for (int i = 2; i <= n; i++) {
        F[i] = F[i - 1] + F[i - 2] * ((s[i - 2] != '0') && (stoi(s.substr(i - 2, 2)) <= 33));
    }
    cout << F[n] << "\n";
    return 0;
}


    /*cout << dp[n-1];
    cout << "\n";
    return 0;
}*/