// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

int C(int n, int k)
{
    int B[n+1][n+1];
    for(int i=0;i<=n;++i)
    {
       B[i][0]=1;
       B[i][i]=1;
       for(int j=1;j<i;++j)
       {
           B[i][j]=B[i-1][j-1]+B[i-1][j];
       }
    }
    return B[n][k];
}

string find_path(int n, int m, int k) {
    if (k == 1) {
        return string(n, 'D') + string(m, 'R');
    }

    int tpd = 1;

    if (n > 0) {
        tpd = C(n+m, n);
    }

    if (k <= tpd) {
        return "D" + find_path(n - 1, m, k);
    } else {
        return "R" + find_path(n, m - 1, k - tpd);
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string path = find_path(n, m, k);
    cout << path << endl;
    return 0;
}



/*int main() {
    fastio;
    v(string) a;
    ll n, m, k;
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++) {
        a.push_back("D");
    }
    for (ll i = 0; i < m; i++) {
        a.push_back("R");
    }
    
    for(auto c:np(a)) {
        cout << c;
    }

    cout << "\n";
    return 0;
}*/

