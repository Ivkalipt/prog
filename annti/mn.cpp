#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k_of_iter, sum=0;
    cin >> n;
    for(ll i = 0; i < n-1; i++) {
        cin >> k_of_iter;
        sum += k_of_iter;
        
    }
    cout << abs(n*(n+1)/2-sum);

}