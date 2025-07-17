#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>

using namespace std;

int main() {
    ll n;
    cin >> n;
    if(n == 1) {
        cout << 2;
    }
    else
    {
        cout << pow(2, n) - (pow(2, n-2)-1);
    }
}