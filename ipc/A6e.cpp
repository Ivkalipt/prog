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
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second

using namespace std;

bool comp(string a, ll i, string b, ll j)
{
    if (i == a.length()) return 1;
    if (j == b.length()) return 0;
    if (a[i] == b[j]) return comp(a, i+1, b, j+1);
    return a[i] < b[j];
}

int main()
{
    fastio;
    string a, b;
    cin >> a >> b;
    ll i = 0, j = 0;
    while (i < a.size() || j < b.size())
    {
        if (comp(a, i, b, j))
            cout << b[j++];
        else
            cout << a[i++];
    }
    return 0;
}

/*
int main() {
    fastio;
    string a, b, s; ll j = 0, i = 0, i2 = 0, j2 = 0;
    cin >> a >> b;
    while(i < a.size() || j < b.size()) {
        if(i < a.size() && j < b.size()) {
            if(a[i] == b[j]) {
                i2 = i;
                j2 = j;
                while(a[i2] != b[j2]) {
                    i2++; j2++;
                }
                if((a[i2] > b[j2])) {
                    s += a[i];
                    i++;
                }
                else {
                    s += b[j];
                    j++;
                }
            }
            else if(a[i] > b[j]) {
                s += a[i];
                i++;
            }
            else {
                s += b[j];
                j++;
            }
        }
        else if(i < a.size()) {
            s +=  a[i];
            i++;
        }
        else {
            s +=  b[j];
            j++;
        }

    }
    cout << s;

    return 0;
}*/

