#include <iostream>
#include <vector>
#define ll long long
using namespace std;
int main() 
{
    vector<int> x;
    ll n, temp, s = 0;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> temp;
        x.push_back(temp);
    }
    for(ll i = 1; i < n; i++) {
        if(x[i] > x[i+1]) {
            s++;
        }
    }
    cout << s;

}